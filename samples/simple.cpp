﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		simple.cpp
 * @brief		sample
 *
 * @author		t.shirayanagi
 * @par			copyright
 * Copyright (C) 2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#include "../include/iutest.hpp"

/* ---------------------------------------------------
 * 簡単なテスト
*//*--------------------------------------------------*/
IUTEST(Test, Version)
{
	unsigned long v = (IUTEST_MAJORVER << 24) | (IUTEST_MINORVER << 16) | (IUTEST_BUILD << 8) | IUTEST_REVISION;
	IUTEST_ASSERT_EQ( IUTEST_VER, v );
}

IUTEST(Test, GetName)
{
	IUTEST_ASSERT_STREQ("GetName", test_info_->name());
	RecordProperty("test_name", ::iutest::UnitTest::GetInstance()->current_test_info()->name());
	RecordProperty("number", 1);
}

IUTEST(Test, Stream)
{
	IUTEST_SUCCEED() << "OK!!";
	IUTEST_SUCCEED() << L"OK!!";
}

/* ---------------------------------------------------
 * スキップ
*//*--------------------------------------------------*/
IUTEST(SkipTest, Skip)
{
	IUTEST_SKIP() << "empty.";
}

/* ---------------------------------------------------
 * 日本語テスト名
*//*--------------------------------------------------*/
#if IUTEST_HAS_TESTNAME_ALIAS_JP

IUTEST(IUTEST_JAPANESE_NAME(テスト), IUTEST_JAPANESE_NAME(テスト))
{
}
class JapaneseFixedTest : public ::iutest::Test {};

IUTEST_F(IUTEST_JAPANESE_NAME_F(JapaneseFixedTest, あいうえお), IUTEST_JAPANESE_NAME(かきくけこ))
{
}

#endif

#if IUTEST_HAS_ASSERTION_RETURN

/* ---------------------------------------------------
 * 戻り値のある関数での使用
*//*--------------------------------------------------*/
int ReturnTest(void)
{
	IUTEST_ASSERT_TRUE(true) << ::iutest::AssertionReturn(-1);
	return 0;
}

IUTEST(ReturnTest, Test)
{
	ReturnTest();
	IUTEST_ASSERT_TRUE(true);
	IUTEST_ASSERT_TRUE(true) << ::iutest::AssertionReturn();
}

#endif

/* ---------------------------------------------------
 * パッケージ
*//*--------------------------------------------------*/
IUTEST_PACKAGE(TestPackage)
{
	IUTEST(Test, Version)
	{
		IUTEST_ASSERT_TRUE(true);
	}
}

#if IUTEST_HAS_IF_EXISTS

IUTEST_PACKAGE(TestPackage)
{
	IUTEST_PACKAGE(TestPackage)
	{
		IUTEST(Test, Version)
		{
			IUTEST_ASSERT_TRUE(true);
		}
	}
}

#endif

/* ---------------------------------------------------
 * 失敗の確認
*//*--------------------------------------------------*/
#if IUTEST_HAS_GENRAND

IUTEST(DISABLED_TestFailure, Random)
{
	IUTEST_EXPECT_EQ( genrand(), genrand() );
	IUTEST_EXPECT_EQ( genrand(), genrand() );
	IUTEST_EXPECT_EQ( genrand(), genrand() );
	IUTEST_EXPECT_EQ( genrand(), genrand() );
	IUTEST_EXPECT_EQ( genrand(), genrand() );
	IUTEST_EXPECT_EQ( genrand(), genrand() );
}

#endif

// サブルーチン
static void Sub1(int n)
{
	IUTEST_EXPECT_EQ(1, n);
}
static void Sub2(int n)
{
	IUTEST_ASSERT_EQ(1, n);
}

IUTEST(DISABLED_TestFailure, Subroutine1)
{
	{
		int x=100;
		IUTEST_SCOPED_TRACE(::iutest::Message() << "routine1. x=" << x);

		Sub1(x);
	}
	// ここの失敗には "routine1." のメッセージは表示されません。
	Sub1(3);
}

IUTEST(DISABLED_TestFailure, Subroutine2)
{
	{
		IUTEST_SCOPED_TRACE("routine2.");
		//IUTEST_SCOPED_TRACE("routine2.") << "iutest can do." ;

		Sub2(2);
	}
	// ここの失敗には "routine2." のメッセージは表示されません。
	Sub2(3);
}