cmake_minimum_required(VERSION 3.10)
project(cpp-lexer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CPP_FILES 
    main.cc
    lexer.cc
)

set(HEADER_FILES
    lexer.hpp
)

add_executable(lexer ${CPP_FILES} ${HEADER_FILES})
target_include_directories(lexer PRIVATE include/)
