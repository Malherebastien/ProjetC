# cmake_minimum_required(VERSION <specify CMake version here>)
project(ProjetC C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetC SynchronizedFile.c)
add_executable(ProjetC Serveur.c)