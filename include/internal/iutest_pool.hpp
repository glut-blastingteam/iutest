//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_pool.hpp
 * @brief		iris unit test memory pool �t�@�C��
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2011, Takazumi Shirayanagi\n
 * The new BSD License is applied to this software.
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_iutest_pool_HPP_60F7CC27_EA15_4ac7_BCA6_80FFDCBC890E_
#define INCG_IRIS_iutest_pool_HPP_60F7CC27_EA15_4ac7_BCA6_80FFDCBC890E_

//======================================================================
// include
#include <vector>

namespace iutest {
namespace detail
{

/**
 * @brief	new �����I�u�W�F�N�g���Ǘ�
*/
template<typename T>
class iuPool
{
	typedef iuPool<T>		_Myt;
	typedef ::std::vector<T*>	pool;
	pool	m_pool;
public:
	typedef T				value_type;
	typedef T				*value_ptr;

public:
	~iuPool(void)
	{
		// ���ׂĉ������
		for( typename pool::iterator it=m_pool.begin(); it != m_pool.end(); )
		{
			value_ptr p = *it;
			it = m_pool.erase(it);
			delete p;
		}
	}
public:
	void	push(value_ptr ptr)			{ m_pool.push_back(ptr); }
public:
	static _Myt&	GetInstance(void)	{ static _Myt inst; return inst; }
};

}	// end of namespace detail
}	// end of namespace iutest

#endif