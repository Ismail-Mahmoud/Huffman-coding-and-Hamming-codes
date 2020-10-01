//
// Created by Ismail El-Toukhy on 10/1/2020.
//

#ifndef HUFFMAN_CODING_AND_HAMMING_CODES_UTILS_H
#define HUFFMAN_CODING_AND_HAMMING_CODES_UTILS_H


#include "Hamming/Block.h"
#include <ctime>

const int p2 = 4;
const int block_size = 1 << p2;
const int block_data_size = block_size - p2 - 1;

void divideBits(const string&, vector<Block>&);
void distortBlocks(vector<Block>&);
string retrieveBits(vector<Block>&);


#endif //HUFFMAN_CODING_AND_HAMMING_CODES_UTILS_H
