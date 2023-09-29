cmake_minimum_required(VERSION 3.24)
project(rsa_c__)

set(CMAKE_CXX_STANDARD 17)

add_executable(rsa_c__ main.cpp cmake-build-debug/bigint.h)
