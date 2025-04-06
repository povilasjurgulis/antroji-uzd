cmake_minimum_required(VERSION 3.10)

# Projekto pavadinimas
project(v1.1_uzduotis)

# Naudojama C++ versija
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-O3")

# Įtraukiami header failų katalogai
include_directories(${CMAKE_SOURCE_DIR})

# Surinkti visi šie cpp failai į vieną vykdomąjį failą
add_executable(v1.1_uzduotis
    main.cpp
    data_input.cpp
    file_gen.cpp
    file_skaitymas.cpp
    isvedimas.cpp
    patikrinimai.cpp
    timer.cpp
    studentai.cpp
)

# Header failai:
# - deklaracijos.h
# - main.h
# - strukturos.h
# Jie bus įtraukti per include_directories()