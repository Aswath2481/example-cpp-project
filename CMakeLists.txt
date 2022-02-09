cmake_minimum_required(VERSION 3.0.0)
project(CPP_learning VERSION 0.1.0)

# Paths to the files that are needed in the project
SET(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Source)
SET(INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Includes)

file(GLOB_RECURSE USER_SOURCES ${SRC_PATH}/*.c  ${SRC_PATH}/*.cpp)
SET(SOURCE_DIR ${CMAKE_BINARY_DIR})
message(MESSAGE "${CMAKE_SOURCE_DIR}")
SET(DESTINATION_DIR ${CMAKE_SOURCE_DIR}/Includes)

# printing the included source files in the project
# FOREACH (SRC_EACH_FILE ${USER_SOURCES})
#     message(${SRC_EACH_FILE})
# ENDFOREACH()

# header file directory path in the project 
INCLUDE_DIRECTORIES(${INC_PATH} ${NANO_LIB_PATH})
SET(CMAKE_C_FLAGS " -std=gnu11 " CACHE INTERNAL "c compiler flags")
SET(CMAKE_CXX_FLAGS "-Wreorder -std=c++17 -fno-rtti -fno-exceptions  " CACHE INTERNAL "cxx compiler flags")
# output file if needed add .elf/.out to the name
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")
add_executable(${PROJECT_NAME}.elf main.cpp ${USER_SOURCES})
