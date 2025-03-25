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
    deque_main.cpp
    deque_data_input.cpp
    deque_file_gen.cpp
    deque_file_skaitymas.cpp
    deque_isvedimas.cpp
    deque_patikrinimai.cpp
    deque_rikiavimas.cpp
    deque_vid_mediana.cpp
)

# Header failai:
# - deque_deklaracijos.h
# - deque_main.h
# - deque_strukturos.h
# Jie bus įtraukti per include_directories()