﻿# CMakeList.txt : CMake project for ADS-B_Extractor, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ADS-B_Extractor")

add_executable (ADS-B_Extractor "ADS-B_Reader.cpp" "ADS-B_Reader.h" "Reader.cpp" "Reader.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ADS-B_Extractor PROPERTY CXX_STANDARD 20)
endif()
