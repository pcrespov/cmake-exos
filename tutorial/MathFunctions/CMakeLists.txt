set(MY_TARGET_NAME MathFunctions)

message(WARNING "Processing ${MY_TARGET_NAME} ...")

file(GLOB SOURCE_FILES *.cxx)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
add_library($(MY_TARGET_NAME) ${SOURCE_FILES})
