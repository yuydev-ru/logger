cmake_minimum_required(VERSION 3.23)
project (Logger)
set (CMAKE_CXX_STANDARD 11)

add_library (Logger src/logger.cpp)
target_include_directories (Logger PUBLIC ${PROJECT_SOURCE_DIR}/include)

