# https://cmake.org/cmake-tutorial

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(tutorial)

SET(MAJOR_VERSION 1)
SET(MINOR_VERSION 0)


CONFIGURE_FILE(
${PROJECT_SOURCE_DIR}/tutorial_config.h.in
${PROJECT_BINARY_DIR}/tutorial_config.h
)

INCLUDE_DIRECTORIES( "${PROJECT_BINARY_DIR}")

ADD_EXECUTABLE(Tutorial tutorial.cxx)
