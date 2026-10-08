cmake_minimum_required(VERSION 3.20)

project(VideoAnalyzer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(VideoAnalyzer SHARED
    src/analyzer.cpp
)

add_executable(TestDLL
    src/test_dll.cpp
)
