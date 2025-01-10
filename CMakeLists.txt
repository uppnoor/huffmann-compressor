cmake_minimum_required(VERSION 3.29)
project(huffman_compressor C)

set(CMAKE_C_STANDARD 11)

add_executable(huffman_compressor src/main.c
        src/frequency_table.h
        src/huffman_tree.h
        src/frequency_table.c
        src/huffman_tree.c
)
