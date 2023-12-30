cmake_minimum_required(VERSION 3.10)

project(BitArrayLibrary)

set(SOURCES
    lab1.cpp
    Body.h
    BitArray.cpp
    Body.cpp
    Tests.cpp
)

add_library(BitArray SHARED ${SOURCES})

# Добавьте библиотеку Google Test
add_subdirectory(googletest)

# Добавьте тесты
add_executable(tests Tests.cpp)

# Укажите исходные файлы для тестов
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Целевая библиотека для тестов
target_link_libraries(tests PRIVATE
    BitArray
    gtest
    gtest_main
)

# Добавьте кастомную цель для запуска тестов
add_custom_target(run_tests
    COMMAND tests
    DEPENDS tests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Добавьте тесты в сборку
add_dependencies(run_tests tests)
