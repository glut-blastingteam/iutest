//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_environment_tests.cpp
 * @brief		Environment 対応テスト
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012-2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "../include/iutest.hpp"

static int test_counter = 0;

class MyEnvironment : public ::iutest::Environment
{
public:
	static bool setup;
	static bool teardown;
	
public:
	void Reset(void)
	{
		setup = false;
		teardown = false;
	}

private:
	virtual void SetUp(void)
	{
		setup = true;
		++test_counter;
	}
	
	virtual void TearDown(void)
	{
		teardown = true;
		--test_counter;
	}
};

class MyEnvironment2 : public ::iutest::Environment
{
private:
	virtual void SetUp(void)
	{
		IUTEST_ASSERT_EQ(1, test_counter);
		++test_counter;
	}
	
	virtual void TearDown(void)
	{
		IUTEST_ASSERT_EQ(2, test_counter);
		--test_counter;
	}
};

bool MyEnvironment::setup = false;
bool MyEnvironment::teardown = false;

IUTEST(FlagTest, Check)
{
	IUTEST_ASSERT_TRUE(MyEnvironment::setup);
	IUTEST_ASSERT_FALSE(MyEnvironment::teardown);
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	IUTEST_INIT(&argc, argv);
	MyEnvironment* const env = new MyEnvironment();
	IUTEST_ASSERT( ::iutest::AddGlobalTestEnvironment(NULL) == NULL );
	IUTEST_ASSERT( ::iutest::AddGlobalTestEnvironment(env) == env );
	::iutest::AddGlobalTestEnvironment(new MyEnvironment2());
	env->Reset();
	const int ret = IUTEST_RUN_ALL_TESTS();
	
	IUTEST_ASSERT( MyEnvironment::teardown );
	
	return ret;
}
