﻿//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_output_xml_tests.cpp
 * @brief		xml 出力対応テスト
 *
 * @author		t.shirayanagi
 * @par			copyright
 * Copyright (C) 2013-2014, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================

//======================================================================
// include
#include "iutest.hpp"

#if IUTEST_HAS_STREAMCAPTURE

::iutest::detail::IUStreamCapture stderr_capture(stderr);

#endif

#if !defined(IUTEST_USE_GTEST)
#  define OUTPUT_XML_TEST	1
#else
#  define OUTPUT_XML_TEST	0
#endif

IUTEST(Foo, Bar)
{
	IUTEST_ASSERT_EQ(3, 3);
}

#ifdef UNICODE
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
#if OUTPUT_XML_TEST
	IUTEST_INIT(&argc, argv);

	::iutest::IUTEST_FLAG(output) = "xml:invalid_path?/test.xml";

	{
		const int ret = IUTEST_RUN_ALL_TESTS();
		
		if( ret != 0 ) return 1;
#if IUTEST_HAS_STREAMCAPTURE && IUTEST_HAS_ASSERTION_RETURN
		IUTEST_ASSERT_STRIN("Unable to open file \"invalid_path?/test.xml\".", stderr_capture.GetStreamString())
			<< ::iutest::AssertionReturn<int>(1);
#endif
	}

	printf("*** Successful ***\n");
#else
	(void)argc;
	(void)argv;
	printf("*** OUTPUT_XML_TEST=0 ***\n");
#endif
	return 0;
}