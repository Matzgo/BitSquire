#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Squire {

	class SQUIRE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};


}




//CORE LOG MACROS
#define SQ_CORE_TRACE(...)	::Squire::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SQ_CORE_INFO(...)	::Squire::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SQ_CORE_WARN(...)	::Squire::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SQ_CORE_ERROR(...)	::Squire::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SQ_CORE_FATAL(...)	::Squire::Log::GetCoreLogger()->critical(__VA_ARGS__)


//CORE LOG MACROS
#define SQ_TRACE(...)		::Squire::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SQ_INFO(...)		::Squire::Log::GetClientLogger()->info(__VA_ARGS__)
#define SQ_WARN(...)		::Squire::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SQ_ERROR(...)		::Squire::Log::GetClientLogger()->error(__VA_ARGS__)
#define SQ_FATAL(...)		::Squire::Log::GetClientLogger()->critical(__VA_ARGS__)