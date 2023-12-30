cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Добавьте ваши исходные файлы
set(SOURCES
    BitArray.cpp
    Body.cpp
    Body.h
    README.md
    Tests.cpp
    lab1.cpp
)

# Добавьте исполняемый файл
add_executable(my_executable ${SOURCES})

# Добавьте библиотеку Google Test
add_subdirectory(googletest)

# Добавьте тесты
add_executable(tests Tests.cpp)

# Укажите исходные файлы для тестов
target_sources(tests PRIVATE Tests.cpp)

# Целевая библиотека для тестов
target_link_libraries(tests PRIVATE my_executable gtest gtest_main)

# Добавьте зависимость от цели my_executable
add_dependencies(tests my_executable)

# Создание цели для тестирования с помощью CTest
enable_testing()
add_test(NAME my_tests COMMAND tests)