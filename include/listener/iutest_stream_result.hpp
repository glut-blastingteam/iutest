//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_stream_result.hpp
 * @brief		iris unit test stream result �t�@�C��
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2013, Takazumi Shirayanagi\n
 * The new BSD License is applied to this software.
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_iutest_stream_result_HPP_1187A63F_E99B_4289_A562_3C87B9739B7D_
#define INCG_IRIS_iutest_stream_result_HPP_1187A63F_E99B_4289_A562_3C87B9739B7D_

//======================================================================
// include
#include "../iutest_core.hpp"

#if IUTEST_HAS_STREAM_RESULT
#include "../internal/iutest_socket.hpp"

namespace iutest
{

//======================================================================
// class
/**
 * @brief	stream result
*/
class StreamResultListener : public EmptyTestEventListener
{
public:
	StreamResultListener(const char* host, const char* port);

public:
	virtual void OnTestProgramStart(const UnitTest& test) IUTEST_CXX_OVERRIDE;
	virtual void OnTestIterationStart(const UnitTest& test
									, int iteration) IUTEST_CXX_OVERRIDE;
	virtual void OnTestCaseStart(const TestCase& test_case) IUTEST_CXX_OVERRIDE;
	virtual void OnTestStart(const TestInfo& test_info) IUTEST_CXX_OVERRIDE;
	virtual void OnTestPartResult(const TestPartResult& test_part_result) IUTEST_CXX_OVERRIDE;
	virtual void OnTestRecordProperty(const TestProperty& test_property) IUTEST_CXX_OVERRIDE;
	virtual void OnTestEnd(const TestInfo& test_info) IUTEST_CXX_OVERRIDE;
	virtual void OnTestCaseEnd(const TestCase& test_case) IUTEST_CXX_OVERRIDE;
	virtual void OnTestIterationEnd(const UnitTest& test
									, int iteration) IUTEST_CXX_OVERRIDE;
	virtual void OnTestProgramEnd(const UnitTest& test) IUTEST_CXX_OVERRIDE;
private:
	::std::string UrlEncode(const char* str);
	::std::string FormatBool(bool b);

	void Start();
	void SendLn(const ::std::string& message);
private:
	detail::SocketWriter m_socket;

	IUTEST_PP_DISALLOW_COPY_AND_ASSIGN(StreamResultListener);
};

}	// end of namespace iutest

#if !IUTEST_HAS_LIB
#  include "../impl/iutest_stream_result.ipp"
#endif

#endif

#endif
