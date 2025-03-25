cmake_minimum_required(VERSION 3.10)

# Projekto pavadinimas
project(v1.0_uzduotis)

# Naudojama C++ versija
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-O3")

# Įtraukiami header failų katalogai
include_directories(${CMAKE_SOURCE_DIR})

# Surinkti visi šie cpp failai į vieną vykdomąjį failą
add_executable(v1.0_uzduotis
    list_main.cpp
    list_data_input.cpp
    list_file_gen.cpp
    list_file_skaitymas.cpp
    list_isvedimas.cpp
    list_patikrinimai.cpp
    list_rikiavimas.cpp
    list_vid_mediana.cpp
)

# Header failai:
# - list_deklaracijos.h
# - list_main.h
# - list_strukturos.h
# Jie bus įtraukti per include_directories()