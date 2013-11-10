//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_spi_tests.cpp
 * @brief		iutest spi test
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
#include "../include/gtest/iutest_spi_switch.hpp"

namespace spitest
{

class SPITest : public ::iutest::Test
{
public:
#if IUTEST_HAS_SPI_LAMBDA_SUPPORT
	const char* null_str;
	int a, b;
	int  aa[5];
	int  ab[6];
	char ac[5];
	
	SPITest()
		: null_str(NULL)
		, a(0), b(0)
	{
		int  aa_[5] = { 0, 1, 2, 3, 4 };
		int  ab_[6] = { 0, 1, 2, 3, 4, 5 };
		char ac_[5] = { 0, 0, 2, 3, 5 };
		for( int i=0; i < 5; ++i )
		{
			aa[i] = aa_[i];
			ab[i] = ab_[i];
			ac[i] = ac_[i];
		}
		ab[5] = 5;
	}
#endif
	
public:
	void FatalFailure_Sub(int& count);
	void FatalFailure2_Sub(int& count);
};

#if !IUTEST_HAS_SPI_LAMBDA_SUPPORT
const char* null_str = NULL;
int a=0, b=0;
int  aa[] = { 0, 1, 2, 3, 4 };
int  ab[] = { 0, 1, 2, 3, 4, 5 };
char ac[] = { 0, 0, 2, 3, 5 };
#endif

void SPITest::FatalFailure_Sub(int& count)
{
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_TRUE(false), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_FALSE(true), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NULL((void*)1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NOTNULL((void*)0), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_SAME(a, b), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_EQ(0, 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NE(1, 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_LE(1, 0), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_LT(1, 0), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_GE(0, 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_GT(0, 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_FLOAT_EQ(0, 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_DOUBLE_EQ(0, 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NEAR(0, 100, 2), "" );

	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STREQ("A", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STREQ("A", null_str), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STREQ(null_str, "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRNE("a", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRNE(null_str, null_str), "" );

	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ("b", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ("b", null_str), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ(null_str, "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE("a", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE("A", "a"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE(null_str, null_str), "" );

#if IUTEST_HAS_EXCEPTIONS
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_THROW(throw "test", int), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_ANY_THROW((void)0), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NO_THROW(throw 1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NO_THROW(throw "error"), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_NO_THROW(throw ::std::bad_exception()), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_EQ(throw 2, char, 2), "");
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_EQ(throw 2, int, 0), "");
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_NE(throw 2, char, 0), "");
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_NE(throw 2, int, 2), "");
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_STREQ(throw 1, const char*, "Error"), "");
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_STREQ(throw "error", const char*, "Error"), "");
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_STRCASEEQ(throw 1, const char*, "Error"), "");
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_STRCASEEQ(throw "test", const char*, "Error"), "");
#endif

#if defined(IUTEST_OS_WINDOWS)
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_SUCCEEDED(-1), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_FAILED(0), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_FAILED(100), "" );
#endif
	
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ab, ab+(sizeof(ab)/sizeof(ab[0]))), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_EQ_COLLECTIONS(ab, ab+(sizeof(ab)/sizeof(ab[0])), aa, aa+(sizeof(aa)/sizeof(aa[0]))), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ac, ac+(sizeof(ac)/sizeof(ac[0]))), "" );

	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_EQ_RANGE(aa, ab), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_EQ_RANGE(ab, aa), "" );
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_EQ_RANGE(aa, ac), "" );

	count++;
}
	
IUTEST_F(SPITest, FatalFailure)
{
	int count=0;
#if IUTEST_HAS_EXCEPTIONS
	try {
		FatalFailure_Sub(count);
	} catch(...) {
	}
#else
	FatalFailure_Sub(count);
#endif
	IUTEST_ASSERT_EQ(1, count);
}

void SPITest::FatalFailure2_Sub(int& count)
{
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_TRUE(false), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_FALSE(true), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NULL((void*)1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NOTNULL((void*)0), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_SAME(a, b), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_EQ(0, 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NE(1, 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_LE(1, 0), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_LT(1, 0), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_GE(0, 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_GT(0, 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_FLOAT_EQ(0, 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_DOUBLE_EQ(0, 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NEAR(0, 100, 2), "" );

	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STREQ("A", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STREQ("A", null_str), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STREQ(null_str, "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRNE("a", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRNE(null_str, null_str), "" );

	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ("b", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ("b", null_str), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASEEQ(null_str, "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE("a", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE("A", "a"), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_STRCASENE(null_str, null_str), "" );

#if IUTEST_HAS_EXCEPTIONS
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_THROW(throw "test", int), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_ANY_THROW((void)0), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_NO_THROW(throw 1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_EQ(throw 2, char, 2), "");
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_EQ(throw 2, int, 0), "");
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_NE(throw 2, char, 0), "");
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_NE(throw 2, int, 2), "");
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_STREQ(throw 1, const char*, "Error"), "");
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_STREQ(throw "error", const char*, "Error"), "");
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_STRCASEEQ(throw 1, const char*, "Error"), "");
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_THROW_VALUE_STRCASEEQ(throw "test", const char*, "Error"), "");
#endif

#if defined(IUTEST_OS_WINDOWS)
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_SUCCEEDED(-1), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_FAILED(0), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_HRESULT_FAILED(100), "" );
#endif
	
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ab, ab+(sizeof(ab)/sizeof(ab[0]))), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_EQ_COLLECTIONS(ab, ab+(sizeof(ab)/sizeof(ab[0])), aa, aa+(sizeof(aa)/sizeof(aa[0]))), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ac, ac+(sizeof(ac)/sizeof(ac[0]))), "" );

	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_EQ_RANGE(aa, ab), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_EQ_RANGE(ab, aa), "" );
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_EQ_RANGE(aa, ac), "" );

	count++;
}
	
IUTEST_F(SPITest, FatalFailure2)
{
	int count=0;
#if IUTEST_HAS_EXCEPTIONS
	try {
		FatalFailure2_Sub(count);
	} catch(...) {
	}
#else
	FatalFailure2_Sub(count);
#endif
	IUTEST_ASSERT_EQ(1, count);
}

IUTEST_F(SPITest, NonFatalFailure)
{
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_TRUE(false), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_FALSE(true), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NULL((void*)1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NOTNULL((void*)0), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_SAME(a, b), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ(0, 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NE(1, 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_LE(1, 0), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_LT(1, 0), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_GE(0, 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_GT(0, 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_FLOAT_EQ(0, 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_DOUBLE_EQ(0, 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NEAR(0, 100, 2), "" );

	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ("A", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ("A", null_str), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ(null_str, "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRNE("a", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRNE(null_str, null_str), "" );

	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ("b", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ("b", null_str), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ(null_str, "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE("a", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE("A", "a"), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE(null_str, null_str), "" );

#if IUTEST_HAS_EXCEPTIONS
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW(throw "test", int), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_ANY_THROW((void)0), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_NO_THROW(throw 1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_EQ(throw 2, char, 2), "");
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_EQ(throw 2, int, 0), "");
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_NE(throw 2, char, 0), "");
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_NE(throw 2, int, 2), "");
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_STREQ(throw 1, const char*, "Error"), "");
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_STREQ(throw "error", const char*, "Error"), "");
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_STRCASEEQ(throw 1, const char*, "Error"), "");
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_STRCASEEQ(throw "test", const char*, "Error"), "");
#endif

#if defined(IUTEST_OS_WINDOWS)
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_SUCCEEDED(-1), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_FAILED(0), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_FAILED(100), "" );
#endif

	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ab, ab+(sizeof(ab)/sizeof(ab[0]))), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_COLLECTIONS(ab, ab+(sizeof(ab)/sizeof(ab[0])), aa, aa+(sizeof(aa)/sizeof(aa[0]))), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ac, ac+(sizeof(ac)/sizeof(ac[0]))), "" );

	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_RANGE(aa, ab), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_RANGE(ab, aa), "" );
	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_RANGE(aa, ac), "" );
}

IUTEST_F(SPITest, NonFatalFailure2)
{
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_TRUE(false), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_FALSE(true), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NULL((void*)1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NOTNULL((void*)0), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_SAME(a, b), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ(0, 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NE(1, 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_LE(1, 0), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_LT(1, 0), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_GE(0, 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_GT(0, 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_FLOAT_EQ(0, 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_DOUBLE_EQ(0, 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NEAR(0, 100, 2), "" );

	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ("A", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ("A", null_str), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STREQ(null_str, "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRNE("a", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRNE(null_str, null_str), "" );

	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ("b", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ("b", null_str), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASEEQ(null_str, "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE("a", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE("A", "a"), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_STRCASENE(null_str, null_str), "" );

#if IUTEST_HAS_EXCEPTIONS
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW(throw "test", int), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_ANY_THROW((void)0), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_NO_THROW(throw 1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_EQ(throw 2, char, 2), "");
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_EQ(throw 2, int, 0), "");
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_NE(throw 2, char, 0), "");
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_NE(throw 2, int, 2), "");
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_STREQ(throw 1, const char*, "Error"), "");
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_STREQ(throw "error", const char*, "Error"), "");
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_STRCASEEQ(throw 1, const char*, "Error"), "");
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_THROW_VALUE_STRCASEEQ(throw "test", const char*, "Error"), "");
#endif

#if defined(IUTEST_OS_WINDOWS)
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_SUCCEEDED(-1), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_FAILED(0), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_HRESULT_FAILED(100), "" );
#endif

	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ab, ab+(sizeof(ab)/sizeof(ab[0]))), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_COLLECTIONS(ab, ab+(sizeof(ab)/sizeof(ab[0])), aa, aa+(sizeof(aa)/sizeof(aa[0]))), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_COLLECTIONS(aa, aa+(sizeof(aa)/sizeof(aa[0])), ac, ac+(sizeof(ac)/sizeof(ac[0]))), "" );

	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_RANGE(aa, ab), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_RANGE(ab, aa), "" );
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_EQ_RANGE(aa, ac), "" );
}

#if IUTEST_HAS_VARIADIC_TEMPLATES

bool pred_test(int a0, int a1, int a2, int a3, int a4, int a5)
{
	return a0+a2+a4 == a1+a3+a5;
}

IUTEST_F(SPITest, VariadicPredTest)
{
	IUTEST_ASSERT_FATAL_FAILURE( IUTEST_ASSERT_PRED(pred_test, 1, 0, a, a, a, 0), "");
	IUTEST_EXPECT_FATAL_FAILURE( IUTEST_ASSERT_PRED(pred_test, 1, 0, a, a, a, 0), "");

	IUTEST_ASSERT_NONFATAL_FAILURE( IUTEST_EXPECT_PRED(pred_test, 1, 0, a, a, a, 0), "");
	IUTEST_EXPECT_NONFATAL_FAILURE( IUTEST_EXPECT_PRED(pred_test, 1, 0, a, a, a, 0), "");
}

#endif

}

