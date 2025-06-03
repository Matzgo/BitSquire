workspace "BitSquire"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	architecture "x64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "BitSquire/vendor/GLFW/include"
IncludeDir["Glad"] = "BitSquire/vendor/Glad/include"
IncludeDir["ImGui"] = "BitSquire/vendor/imgui"

include "BitSquire/vendor/GLFW"
include "BitSquire/vendor/Glad"
include "BitSquire/vendor/imgui"

project "BitSquire"
	location "BitSquire"	
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sqpch.h"
	pchsource "BitSquire/src/sqpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"BitSquire/src",
		"BitSquire/vendor/spdlog/include/",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}


	filter "system:Windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SQ_PLATFORM_WINDOWS",
			"SQ_BUILD_DLL",
			"SQ_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE"
		}



		

	postbuildcommands 
	{
		("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir.."/Sandbox/\"")
	}


	filter "configurations:Debug"
		defines 
		{  
			"SQ_DEBUG"
		}
		buildoptions "/MDd"
		symbols "On"
			

	filter "configurations:Release"
		defines 
		{ 
			"SQ_RELEASE"
		}
		buildoptions "/MD"
		optimize "On"



	filter "configurations:Dist"
		defines 
		{ 
			"SQ_DIST"
		}
		buildoptions "/MDd"
		optimize "On"

project "Sandbox"
	location "Sandbox"	
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs{
		"BitSquire/vendor/spdlog/include",
		"BitSquire/src"
	}
	
	links{
		"BitSquire"
	}

	filter "system:Windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
		defines
		{
			"SQ_PLATFORM_WINDOWS"
		}
	
	
	
	
	filter "configurations:Debug"
		defines 
		{  
			"SQ_DEBUG"
		}
		buildoptions "/MDd"
		symbols "On"
			
	
	filter "configurations:Release"
		defines 
		{ 
			"SQ_RELEASE"
		}
		buildoptions "/MD"
		optimize "On"
	
	
	
	filter "configurations:Release"
		defines 
		{ 
			"SQ_DIST"
		}
		buildoptions "/MD"
		optimize "On"