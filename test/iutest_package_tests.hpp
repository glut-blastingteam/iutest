//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_package_tests.hpp
 * @brief		iutest_package test
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012, Takazumi Shirayanagi\n
 * The new BSD License is applied to this software.
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_iutest_package_tests_HPP_
#define INCG_iutest_package_tests_HPP_

//======================================================================
// include
#include "../include/iutest.hpp"

#if IUTEST_HAS_PACKAGE

#define IUTEST_EXPECT_PACKAGENAME(package_name, testcase_name)	\
	IUTEST_EXPECT_PACKAGENAME_( package_name, testcase_name, ::iutest::UnitTest::GetInstance()->current_test_case()->name())

#define IUTEST_EXPECT_PACKAGENAME_(package_name, testcase_name, name)	\
	IUTEST_EXPECT_STREQ( #package_name "." #testcase_name, name)

#else

#define IUTEST_EXPECT_PACKAGENAME(package_name, testcase_name)	\
	IUTEST_EXPECT_PACKAGENAME_( package_name, testcase_name, ::iutest::UnitTest::GetInstance()->current_test_case()->name())

#define IUTEST_EXPECT_PACKAGENAME_(package_name, testcase_name, name)	\
	IUTEST_EXPECT_STREQ( #testcase_name, name)

#endif


IUTEST_PACKAGE(pkg1)
{
	class TestFixed : public ::iutest::Test {};

	
#if IUTEST_HAS_PARAM_METHOD_TEST
	void TestFunction(int x, int y)
	{
		IUTEST_ASSERT_EQ(x, y);
		IUTEST_EXPECT_PACKAGENAME(pkg1, ParamMethodTest);
	}
#endif
	
#if IUTEST_HAS_PARAM_TEST
	class ParamTest : public ::iutest::TestWithParam<int> {};
#endif

#if IUTEST_HAS_TYPED_TEST
	template<typename T>
	class TypedTest : public ::iutest::Test {};

	typedef ::iutest::Types<int, float> TypedTestTypes;
	IUTEST_TYPED_TEST_CASE(TypedTest, TypedTestTypes);
#endif

#if IUTEST_HAS_TYPED_TEST_P
	template<typename T>
	class TypeParamTest : public ::iutest::Test {};

	IUTEST_TYPED_TEST_CASE_P(TypeParamTest);

	IUTEST_TYPED_TEST_P(TypeParamTest, A)
	{
		const char* name = ::iutest::UnitTest::GetInstance()->current_test_case()->name();
		IUTEST_EXPECT_PACKAGENAME_(pkg1, TypeParamTest, ::iuutil::TestCaseNameRemoveInstantiateAndIndexName(name));
	}

	IUTEST_REGISTER_TYPED_TEST_CASE_P(TypeParamTest, A);
#endif

}

#endif
