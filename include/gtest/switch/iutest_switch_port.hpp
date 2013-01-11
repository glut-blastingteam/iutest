//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_switch_port.hpp
 * @brief		portable ��`�؂�ւ� �t�@�C��
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
#ifndef INCG_IRIS_iutest_switch_port_HPP_2B432CD6_18CE_4d0c_B0CD_4E4D5B8E34F4_
#define INCG_IRIS_iutest_switch_port_HPP_2B432CD6_18CE_4d0c_B0CD_4E4D5B8E34F4_

#if !defined(IUTEST_USE_GTEST)

//======================================================================
// undef
#ifdef GTEST_INCLUDE_GTEST_GTEST_H_

#ifdef GTEST_OS_CYGWIN
#  undef GTEST_OS_CYGWIN
#endif
#ifdef GTEST_OS_WINDOWS
#  undef GTEST_OS_WINDOWS
#  ifdef GTEST_OS_WINDOWS_MOBILE
#	 undef GTEST_OS_WINDOWS_MOBILE
#  endif
#  ifdef GTEST_OS_WINDOWS_MINGW
#	 undef GTEST_OS_WINDOWS_MINGW
#  endif
#  ifdef GTEST_OS_WINDOWS_DESKTOP
#	 undef GTEST_OS_WINDOWS_DESKTOP
#  endif
#endif
#ifdef GTEST_OS_MAC
#  undef GTEST_OS_MAC
#endif
#ifdef GTEST_OS_LINUX
#  undef GTEST_OS_LINUX
#  ifdef GTEST_OS_LINUX_ANDROID
#	 undef GTEST_OS_LINUX_ANDROID
#  endif
#endif
#ifdef IUTEST_OS_NACL
#  undef IUTEST_OS_NACL
#endif

#endif

//======================================================================
// define
#ifdef IUTEST_OS_CYGWIN
#  define GTEST_OS_CYGWIN		IUTEST_OS_CYGWIN
#endif
#ifdef IUTEST_OS_WINDOWS
#  define GTEST_OS_WINDOWS		IUTEST_OS_WINDOWS
#  ifdef IUTEST_OS_WINDOWS_MOBILE
#	 define GTEST_OS_WINDOWS_MOBILE		IUTEST_OS_WINDOWS_MOBILE
#  endif
#  ifdef IUTEST_OS_WINDOWS_MINGW
#	 define GTEST_OS_WINDOWS_MINGW		IUTEST_OS_WINDOWS_MINGW
#  endif
#  ifdef IUTEST_OS_WINDOWS_DESKTOP
#	 define GTEST_OS_WINDOWS_DESKTOP	IUTEST_OS_WINDOWS_DESKTOP
#  endif
#endif
#ifdef IUTEST_OS_MAC
#  define GTEST_OS_MAC	IUTEST_OS_MAC
#endif
#ifdef IUTEST_OS_LINUX
#  define GTEST_OS_LINUX		IUTEST_OS_LINUX
#  ifdef IUTEST_OS_LINUX_ANDROID
#	 define GTEST_OS_LINUX_ANDROID	IUTEST_OS_LINUX_ANDROID
#  endif
#endif
#ifdef IUTEST_OS_NACL
#  define GTEST_OS_NACL	IUTEST_OS_NACL
#endif

#else

//======================================================================
// undef
#ifdef INCG_IRIS_iutest_HPP_

#ifdef IUTEST_OS_CYGWIN
#  undef IUTEST_OS_CYGWIN
#endif
#ifdef IUTEST_OS_WINDOWS
#  undef IUTEST_OS_WINDOWS
#  ifdef IUTEST_OS_WINDOWS_MOBILE
#	 undef IUTEST_OS_WINDOWS_MOBILE
#  endif
#  ifdef IUTEST_OS_WINDOWS_MINGW
#	 undef IUTEST_OS_WINDOWS_MINGW
#  endif
#  ifdef IUTEST_OS_WINDOWS_DESKTOP
#	 undef IUTEST_OS_WINDOWS_DESKTOP
#  endif
#endif
#ifdef IUTEST_OS_MAC
#  undef IUTEST_OS_MAC
#endif
#ifdef IUTEST_OS_LINUX
#  undef IUTEST_OS_LINUX
#  ifdef IUTEST_OS_LINUX_ANDROID
#	 undef IUTEST_OS_LINUX_ANDROID
#  endif
#endif
#ifdef IUTEST_OS_NACL
#  undef IUTEST_OS_NACL
#endif

#endif

//======================================================================
// define
#ifdef GTEST_OS_CYGWIN
#  define IUTEST_OS_CYGWIN		GTEST_OS_CYGWIN
#endif
#ifdef GTEST_OS_WINDOWS
#  include <windows.h>
#  define IUTEST_OS_WINDOWS		GTEST_OS_WINDOWS
#  ifdef GTEST_OS_WINDOWS_MOBILE
#	 define IUTEST_OS_WINDOWS_MOBILE	GTEST_OS_WINDOWS_MOBILE
#  endif
#  ifdef GTEST_OS_WINDOWS_MINGW
#	 define IUTEST_OS_WINDOWS_MINGW		GTEST_OS_WINDOWS_MINGW
#  endif
#  ifdef GTEST_OS_WINDOWS_DESKTOP
#	 define IUTEST_OS_WINDOWS_DESKTOP	GTEST_OS_WINDOWS_DESKTOP
#  endif
#endif
#ifdef GTEST_OS_MAC
#  define IUTEST_OS_MAC	GTEST_OS_MAC
#endif
#ifdef GTEST_OS_LINUX
#  define IUTEST_OS_LINUX		GTEST_OS_LINUX
#  ifdef GTEST_OS_LINUX_ANDROID
#	 define IUTEST_OS_LINUX_ANDROID	GTEST_OS_LINUX_ANDROID
#  endif
#endif
#ifdef GTEST_OS_NACL
#  define IUTEST_OS_NACL	GTEST_OS_NACL
#endif

#endif

#endif