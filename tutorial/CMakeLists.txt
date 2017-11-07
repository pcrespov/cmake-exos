# https://cmake.org/cmake-tutorial
cmake_minimum_required(VERSION 2.6)
project(tutorial)

set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)

# OPTIONS
option(USE_MYMATH
  "Uses my own math functions"
  ON
)

message(STATUS ${PROJECT_SOURCE_DIR} )
message(STATUS ${PROJECT_BINARY_DIR} )

# Replaces
configure_file(
  ${PROJECT_SOURCE_DIR}/tutorial_config.h.in
  ${PROJECT_BINARY_DIR}/tutorial_config.h
)

include_directories( "${PROJECT_BINARY_DIR}")

if (USE_MYMATH)
  add_subdirectory(MathFunctions)
  include_directories("${CMAKE_CURRENT_SOURCE_DIR}/MathFunctions")
  # accumulats in variable, all dependencies
  set(EXTERNAL_DEPENDENCY_LIBS ${EXTERNAL_DEPENDENCY_LIBS} MathFuntions)
endif (USE_MYMATH)

# configures executable
set(MY_TARGET_NAME tutorial)

file(GLOB SOURCE_FILES *.cxx)
add_executable(${MY_TARGET_NAME} ${SOURCE_FILES})
target_link_libraries(${MY_TARGET_NAME} ${EXTERNAL_DEPENDENCY_LIBS})
