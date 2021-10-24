cmake_minimum_required(VERSION 3.20)
project(avs_hw2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

add_executable(avs_hw2 main.cpp Container.cpp Matrix.cpp DiagMatrix.cpp SqMatrix.cpp TrMatrix.cpp Matrix.h SqMatrix.h TrMatrix.h DiagMatrix.h Container.h)
