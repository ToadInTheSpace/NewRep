cmake_minimum_required(VERSION 3.10)

project(BitArrayLibrary)

set(SOURCES
    lab1.cpp
    BitArray.cpp
    Body.cpp
    Tests.cpp
)

set(HEADERS
    Body.h
)

add_executable(TESTS ${SOURCES} ${HEADERS})