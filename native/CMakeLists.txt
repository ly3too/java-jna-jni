cmake_minimum_required(VERSION 3.2)
project(jni-demo)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

file(GLOB SRCS src/*.c src/*.cpp)

add_library(jni-demo SHARED ${SRCS})
target_link_libraries(jni-demo ${JNI_LIBRARIES})
target_include_directories(jni-demo PUBLIC ${CMAKE_SOURCE_DIR}/src/include)

enable_testing()