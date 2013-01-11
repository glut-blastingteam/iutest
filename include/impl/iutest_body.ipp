//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_body.ipp
 * @brief		iris unit test �e�X�g�P�̃N���X �t�@�C��
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2011-2012, Takazumi Shirayanagi\n
 * The new BSD License is applied to this software.
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_iutest_body_IPP_3EEA6706_9954_4330_B292_129667FA6B96_
#define INCG_IRIS_iutest_body_IPP_3EEA6706_9954_4330_B292_129667FA6B96_

//======================================================================
// include
#include "../iutest_body.hpp"

namespace iutest
{

IUTEST_IPP_INLINE void Test::RecordProperty(const char* key, const char* value)
{
	// �s���ȃL�[�̃`�F�b�N
	const char* ban[] = { "name", "status", "time", "classname", "type_param", "value_param" };
	::std::string key_ = key;
	for( int i=0, n=sizeof(ban)/sizeof(ban[0]); i < n; ++i )
	{
		if( key_ == ban[i] )
		{
			key_ += "_";
			break;
		}
	}
	TestProperty prop(key_.c_str(), value);
	if( GetCurrentTest() != NULL && GetCurrentTest()->m_test_info != NULL )
	{
		GetCurrentTest()->m_test_info->RecordProperty(prop);
	}
	
	TestEnv::event_listeners().OnTestRecordProperty(prop);
};

IUTEST_IPP_INLINE 	void Test::Run(detail::iuITestInfoMediator* test_info)
{
	m_test_info = test_info;
	test_info_ = test_info->ptr();
	unsigned int seed = TestEnv::get_random_seed();
	if( seed == 0 )
	{
		seed = detail::GetIndefiniteValue();
	}
	m_random_seed = seed;
	m_random.init(seed);

	SetUp();
	Body();
	TearDown();

	test_info_ = NULL;
	m_test_info = NULL;
}

}	// end of namespace iutest

#endif