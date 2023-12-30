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

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0  # Укажите необходимую версию
)
FetchContent_MakeAvailable(googletest)

add_executable(TESTS ${SOURCES} ${HEADERS})

# Свяжите исполняемый файл с библиотекой gtest
target_link_libraries(TESTS gtest_main)