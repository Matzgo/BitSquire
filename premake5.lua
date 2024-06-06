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

project "BitSquire"
	location "BitSquire"	
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"BitSquire/src",
		"BitSquire/vendor/spdlog/include/"
	}

	filter "system:Windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SQ_PLATFORM_WINDOWS",
			"SQ_BUILD_DLL"
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
		symbols "On"
			

	filter "configurations:Release"
		defines 
		{ 
			"SQ_RELEASE"
		}
		optimize "On"



	filter "configurations:Dist"
		defines 
		{ 
			"SQ_DIST"
		}
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
		symbols "On"
			
	
	filter "configurations:Release"
		defines 
		{ 
			"SQ_RELEASE"
		}
		optimize "On"
	
	
	
	filter "configurations:Release"
		defines 
		{ 
			"SQ_DIST"
		}
		optimize "On"