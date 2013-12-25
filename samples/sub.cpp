//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		sub.cpp
 * @brief		sample sub ファイル
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2011-2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

/*
 * is not available vprintf, can be replaced.
*/
//#define IUTEST_VPRINTF

/*
 * include testing framework
*/
#include "../include/iutest.hpp"

#if 1	// Success Tests

/** --------------------------------------------------
 * パッケージ
*//*--------------------------------------------------*/
IUTEST_PACKAGE(TestPackage)
{
	IUTEST(Test, Package)
	{
		IUTEST_ASSERT_TRUE(true);
	}
}

/** --------------------------------------------------
 * PrintTo
*//*--------------------------------------------------*/
#if IUTEST_HAS_PRINT_TO

struct Bar
{
	int x, y, z;
	bool operator == (const Bar& rhs) const
	{
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}
};

::iutest::iu_ostream& operator << (::iutest::iu_ostream& os, const Bar& bar) 
{
	return os << "X:" << bar.x << " Y:" << bar.y << " Z:" << bar.z;
}

void PrintTo(const Bar& bar, ::iutest::iu_ostream* os)
{
	*os << "x:" << bar.x << " y:" << bar.y << " z:" << bar.z;
}

IUTEST(PrintToTest, Test1)
{
	::std::vector<int> a;
	for( int i=0; i < 10; ++i )
		a.push_back(i);
	IUTEST_SUCCEED() << ::iutest::PrintToString(a);

	int* pi=NULL;
	void* p=NULL;
	IUTEST_SUCCEED() << ::iutest::PrintToString(p);
	IUTEST_SUCCEED() << ::iutest::PrintToString(pi);

	Bar bar = {0, 1, 2};
	IUTEST_SUCCEED() << ::iutest::PrintToString(bar);
}

IUTEST(PrintToTest, Test2)
{
	Bar bar1 = {0, 1, 2};
	Bar bar2 = {0, 1, 2};
	IUTEST_ASSERT_EQ(bar1, bar2);
}

IUTEST(PrintToTest, RawArray)
{
	{
		unsigned char a[3] = {0, 1, 2};
		const unsigned char b[3] = {0, 1, 2};
		const volatile unsigned char c[3] = {0, 1, 2};
		volatile unsigned char d[3] = {0, 1, 2};

		IUTEST_SUCCEED() << ::iutest::PrintToString(a);
		IUTEST_SUCCEED() << ::iutest::PrintToString(b);
		IUTEST_SUCCEED() << ::iutest::PrintToString(c);
		IUTEST_SUCCEED() << ::iutest::PrintToString(d);
	}
	{
		char a[3] = {0, 1, 2};
		const char b[3] = {0, 1, 2};
		const volatile char c[3] = {0, 1, 2};
		volatile char d[3] = {0, 1, 2};

		IUTEST_SUCCEED() << ::iutest::PrintToString(a);
		IUTEST_SUCCEED() << ::iutest::PrintToString(b);
		IUTEST_SUCCEED() << ::iutest::PrintToString(c);
		IUTEST_SUCCEED() << ::iutest::PrintToString(d);
	}
}

#if IUTEST_HAS_TYPED_TEST

template<typename T>
class TypedPrintToTest : public ::iutest::Test {};
typedef ::iutest::Types<char, unsigned char, short, unsigned short, int, unsigned int, long, unsigned long, int*> PrintStringTestTypes;
IUTEST_TYPED_TEST_CASE(TypedPrintToTest, PrintStringTestTypes);

IUTEST_TYPED_TEST(TypedPrintToTest, Print)
{
	TypeParam a = 0;
	TypeParam& b = a;
	const TypeParam c = a;
	const volatile TypeParam d = a;

	IUTEST_SUCCEED() << ::iutest::PrintToString(a);
	IUTEST_SUCCEED() << ::iutest::PrintToString(b);
	IUTEST_SUCCEED() << ::iutest::PrintToString(c);
	IUTEST_SUCCEED() << ::iutest::PrintToString(d);
}

#endif

#endif

// DISABLED Test Tips.
#define DISABLED_MacroTest	EnabledTest
#define MacroTest			DISABLED_Test

IUTEST(DISABLED_MacroTest, Enable)
{
	IUTEST_ASSERT_EQ(0, 0);
}

IUTEST(EnabledTest, Count)
{
	const ::iutest::TestCase* testcase = ::iutest::UnitTest::GetInstance()->current_test_case();
	IUTEST_ASSERT_NOTNULL(testcase);
	IUTEST_ASSERT_EQ(2, testcase->total_test_count());
	IUTEST_ASSERT_EQ(2, testcase->test_to_run_count());
	IUTEST_ASSERT_EQ(0, testcase->disabled_test_count());
	IUTEST_ASSERT_TRUE(testcase->Passed());
	IUTEST_ASSERT_FALSE(testcase->Failed());
}

IUTEST(MacroTest, NotRun)
{
	IUTEST_ASSERT_EQ(2, 3);
}

class EnabledTestFixed : public ::iutest::Test {};

typedef EnabledTestFixed	DISABLED_TestFixed;

#define MacroTestF	DISABLED_TestFixed
#define DISABLED_MacroTestF	EnabledTestFixed

IUTEST_F(MacroTestF, NotRun)
{
	IUTEST_ASSERT_EQ(2, 3);
}

IUTEST_F(DISABLED_MacroTestF, Run)
{
	IUTEST_ASSERT_EQ(0, 0);
}

IUTEST_F(EnabledTestFixed, Count)
{
	const ::iutest::TestCase* testcase = ::iutest::UnitTest::GetInstance()->current_test_case();
	IUTEST_ASSERT_NOTNULL(testcase);
	IUTEST_ASSERT_EQ(2, testcase->total_test_count());
	IUTEST_ASSERT_EQ(2, testcase->test_to_run_count());
	IUTEST_ASSERT_EQ(0, testcase->disabled_test_count());
	IUTEST_ASSERT_TRUE(testcase->Passed());
	IUTEST_ASSERT_FALSE(testcase->Failed());
}

#endif

#if 0
#ifdef _MSC_VER
// cppcheck-suppress syntaxError
IUTEST(Japanese, テスト)
{
	IUTEST_FAIL() << ::iutest::UnitTest::GetInstance()->current_test_info()->name();
}
#endif
#endif

#if 0

#ifdef _MSC_VER
#include <process.h>

void TheadTest(void)
{
	IUTEST_ASSERT_EQ(0, 1);
}

unsigned int WINAPI thread_func(void*)
{
	TheadTest();
	return 0;
}

IUTEST(ThreadTest, Basic)
{
	HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, thread_func, NULL, 0, NULL);
	WaitForSingleObject(hThread, INFINITE);
}

#endif

#endif
