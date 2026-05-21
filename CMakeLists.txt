cmake_minimum_required(VERSION 3.22)

project(cpp_template_fun VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_C1 "Enable c1 executable" OFF)
option(ENABLE_C2 "Enable c2 executable" OFF)

if(ENABLE_C1)
	add_subdirectory(c1)
endif()
if(ENABLE_C2)
	add_subdirectory(c2)
endif()