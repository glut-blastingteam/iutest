﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file        package_tests.hpp
 * @brief       package test
 *
 * @author      t.shirayanagi
 * @par         copyright
 * Copyright (C) 2012-2016, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IUTEST_PACKAGE_TESTS_HPP_
#define INCG_IUTEST_PACKAGE_TESTS_HPP_

//======================================================================
// include
#include "iutest.hpp"

#if IUTEST_HAS_PACKAGE

#define IUTEST_EXPECT_PACKAGENAME(package_name, testcase_name)  \
    IUTEST_EXPECT_PACKAGENAME_( package_name, testcase_name, ::iutest::UnitTest::GetInstance()->current_test_case()->name())

#define IUTEST_EXPECT_PACKAGENAME_(package_name, testcase_name, name)   \
    IUTEST_EXPECT_STREQ( #package_name "." #testcase_name, name)

#else

#define IUTEST_EXPECT_PACKAGENAME(package_name, testcase_name)  \
    IUTEST_EXPECT_PACKAGENAME_( package_name, testcase_name, ::iutest::UnitTest::GetInstance()->current_test_case()->name())

#define IUTEST_EXPECT_PACKAGENAME_(package_name, testcase_name, name)   \
    IUTEST_EXPECT_STREQ( #testcase_name, name)

#endif


IUTEST_PACKAGE(pkg1)
{
    class PackageTestFixed : public ::iutest::Test {};


#if IUTEST_HAS_PARAM_METHOD_TEST
    inline void TestFunction(int x, int y)
    {
        IUTEST_ASSERT_EQ(x, y);
        IUTEST_EXPECT_PACKAGENAME(pkg1, ParamMethodTest);
    }
#endif

#if IUTEST_HAS_PARAM_TEST
    class PackageParamTest : public ::iutest::TestWithParam<int> {};
#endif

#if IUTEST_HAS_TYPED_TEST
    template<typename T>
    class PackageTypedTest : public ::iutest::Test {};

    typedef ::iutest::Types<int, float> TypedTestTypes;
    IUTEST_TYPED_TEST_CASE(PackageTypedTest, TypedTestTypes);
#endif

#if IUTEST_HAS_TYPED_TEST_P
    template<typename T>
    class PackageTypeParamTest : public ::iutest::Test {};

    IUTEST_TYPED_TEST_CASE_P(PackageTypeParamTest);

    IUTEST_TYPED_TEST_P(PackageTypeParamTest, A)
    {
        const char* name = ::iutest::UnitTest::GetInstance()->current_test_case()->name();
        IUTEST_EXPECT_PACKAGENAME_(pkg1, PackageTypeParamTest, ::iuutil::TestCaseNameRemoveInstantiateAndIndexName(name));
    }

    IUTEST_REGISTER_TYPED_TEST_CASE_P(PackageTypeParamTest, A);
#endif
}

#endif

