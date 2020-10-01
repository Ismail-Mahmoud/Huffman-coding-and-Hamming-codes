cmake_minimum_required(VERSION 3.15)
project(Huffman_coding_and_Hamming_codes)

set(CMAKE_CXX_STANDARD 17)

add_executable(Huffman_coding_and_Hamming_codes main.cpp Huffman/Node.cpp Huffman/Node.h Huffman/Tree.cpp Huffman/Tree.h Hamming/Block.cpp Hamming/Block.h utils.cpp utils.h)