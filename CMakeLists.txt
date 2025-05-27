cmake_minimum_required(VERSION 3.12)

# Projekto pavadinimas
project(v3.0_uzduotis)

# Naudojama C++ versija
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-O3")

# Įtraukiami header failų katalogai
include_directories(${CMAKE_SOURCE_DIR})


# Surinkti visi šie cpp failai į vieną vykdomąjį failą
add_executable(v3.0_uzduotis
    data_input.cpp
    file_skaitymas.cpp
    isvedimas.cpp
    main.cpp
    patikrinimai.cpp
    studentai_tests.cpp
    studentai.cpp
    timer.cpp
    zmogus.cpp
    file_gen.cpp
    vector_tests.cpp
)

# Header failai:
# - deklaracijos.h
# - main.h
# - strukturos.h
# Jie bus įtraukti per include_directories()