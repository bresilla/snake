cmake_minimum_required(VERSION 3.0.0)
project(UniBonn VERSION 0.1.0)

include(CTest)
enable_testing()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_INCLUDE_PATH "/usr/include")
set(CMAKE_LIBRARY_PATH "/usr/lib")

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${CMAKE_INCLUDE_PATH})

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/test)
add_subdirectory(${PROJECT_SOURCE_DIR}/thrd)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
