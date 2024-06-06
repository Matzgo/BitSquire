#pragma once


#ifdef SQ_PLATFORM_WINDOWS
	#ifdef SQ_BUILD_DLL
		#define SQUIRE_API __declspec(dllexport)
	#else
		#define SQUIRE_API __declspec(dllimport)
	#endif // HZ_BUILD_DLL
#else
	#error BitSquire only supports Windows!
#endif // HZ_PLATFORM_WINDOWS

#define BIT(x) (1<<x)
