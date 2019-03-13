cmake_minimum_required(VERSION 3.9)
project(ProjV2 C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjV2 main.c data_structures.h list_operations.h list_operations.c file_operations.h file_operations.c buffer_operations.h buffer_operations.c menu_handler.h menu_handler.c adjuvant_functions.h adjuvant_functions.c)