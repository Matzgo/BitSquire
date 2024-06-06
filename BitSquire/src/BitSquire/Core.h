#pragma once


#ifdef BS_PLATFORM_WINDOWS
	#ifdef BS_BUILD_DLL
		#define BITSQUIRE_API __declspec(dllexport)
	#else
		#define BITSQUIRE_API __declspec(dllimport)
	#endif // HZ_BUILD_DLL
#else
	#error BitSquire only supports Windows!
#endif // HZ_PLATFORM_WINDOWS
