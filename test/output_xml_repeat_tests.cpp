﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file        output_xml_repeat_tests.cpp
 * @brief       xml 出力対応テスト
 *
 * @author      t.shirayanagi
 * @par         copyright
 * Copyright (C) 2016, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "iutest.hpp"

#if !defined(IUTEST_USE_GTEST)
#  define OUTPUT_XML_TEST   1
#else
#  define OUTPUT_XML_TEST   0
#endif

#if OUTPUT_XML_TEST

IUTEST_FILESYSTEM_INSTANTIATE( ::iutest::detail::NoEffectFile );

class TestF : public ::iutest::Test
{
public:
    static int nI;
public:
    static void TearDownTestCase()
    {
        ++nI;
    }
};

int TestF::nI = 0;

IUTEST_F(TestF, XmlFilePath)
{
    char expect[256];
    ::iutest::detail::iu_snprintf(expect, sizeof(expect), "test_%d.xml", nI);
    IUTEST_ASSERT_EQ( expect
        , (reinterpret_cast< ::iutest::DefaultXmlGeneratorListener*>(::iutest::TestEnv::event_listeners().default_xml_generator())->GetFilePath()) );
}

#endif

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
#if OUTPUT_XML_TEST
    IUTEST_INIT(&argc, argv);

    ::iutest::IUTEST_FLAG(output) = "xml:test_%d.xml";
    if( ::iutest::IUTEST_FLAG(repeat) == 1 )
    {
        ::iutest::IUTEST_FLAG(repeat) = 3;
    }
    return IUTEST_RUN_ALL_TESTS();
#else
    (void)argc;
    (void)argv;
    printf("*** OUTPUT_XML_TEST=0 ***\n");
    return 0;
#endif
}
