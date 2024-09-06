
cmake_minimum_required(VERSION 3.10)

project(geobishtu_test)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)  

file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HDR_FILES "${CMAKE_SOURCE_DIR}/include/*.h")

add_executable(geobishtu_test geobishtu_test.cpp)

target_include_directories(geobishtu_test PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(geobishtu_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

enable_testing()
add_test(NAME geobishtu_test COMMAND geobishtu_test)
target_compile_options(geobishtu_test PRIVATE -Wall)
        