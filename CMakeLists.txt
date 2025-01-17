cmake_minimum_required(VERSION 3.0.0)
project(StreamLib VERSION 0.1.0)
if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message(FATAL_ERROR "In-source builds not allowed.")
endif()
# Paths to the files that are needed in the project
SET(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Source)
SET(INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Includes)

file(GLOB_RECURSE USER_SOURCES ${SRC_PATH}/*.c  ${SRC_PATH}/*.cpp)
SET(SOURCE_DIR ${CMAKE_BINARY_DIR})
message(MESSAGE "${CMAKE_SOURCE_DIR}")
SET(DESTINATION_DIR ${CMAKE_SOURCE_DIR}/Includes)

SET(CMAKE_C_FLAGS " -std=gnu11 " CACHE INTERNAL "c compiler flags")
SET(CMAKE_CXX_FLAGS "-Wreorder -std=c++17 -fno-rtti -fno-exceptions  " CACHE INTERNAL "cxx compiler flags")

# printing the included source files in the project
# FOREACH (SRC_EACH_FILE ${USER_SOURCES})
#     message(${SRC_EACH_FILE})
# ENDFOREACH()
INCLUDE_DIRECTORIES(${INC_PATH})

# header file directory path in the project 
include(FetchContent)
FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

# output file if needed add .elf/.out to the name

add_executable(${PROJECT_NAME}.elf main.cpp ${USER_SOURCES})
target_link_libraries(${PROJECT_NAME}.elf 
  PRIVATE 
  fmt::fmt)

add_executable(tests tests/test.cpp Source/streamlib.cpp)
target_link_libraries(tests 
  PRIVATE
  Catch2::Catch2WithMain)