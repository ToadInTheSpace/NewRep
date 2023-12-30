cmake_minimum_required(VERSION 3.10)

project(BitArrayLibrary)

# Добавьте ваши исходные файлы
set(SOURCES
    BitArray.cpp
    Body.cpp
    Body.h
    Tests.cpp
    lab1.cpp
)

# Добавьте исполняемый файл
add_library(BitArray SHARED ${SOURCEs})

# Добавьте библиотеку Google Test
add_subdirectory(googletest)

# Добавьте тесты
add_executable(tests Tests.cpp)

# Укажите исходные файлы для тестов
target_include_directories(BitArray PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR} # Путь к корневой директории программы
)
# Целевая библиотека для тестов
target_link_libraries(YourLibraryName PUBLIC
    OtherLibraryName
    ${CMAKE_CURRENT_SOURCE_DIR}/Googletest/lib/libgtest.a
    ${CMAKE_CURRENT_SOURCE_DIR}/Googletest/lib/libgtest_main.a
)
