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


#ifdef SQ_ENABLE_ASSERTS
	#define SQ_ASSERT(x,...) {if(!(x)){ SQ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define SQ_CORE_ASSERT(x,...) {if(!(x)){ SQ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define SQ_ASSERT(x,...)
	#define SQ_CORE_ASSERT(x,...)
#endif