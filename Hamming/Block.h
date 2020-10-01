//
// Created by Ismail El-Toukhy on 9/30/2020.
//

#ifndef HAMMING_BLOCK_H
#define HAMMING_BLOCK_H


#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Block {
private:
    int m_size;
    int m_data_size;
    string m_bits;
    enum Parity {even, odd};
    Parity parity() const;
    int countOnBits() const;
    int xorOnBits() const;
    void setDataBits(const string&);
    void setParityBits();
    void handleError(int);
public:
    Block();
    Block(int, const string&);
    int size() const;
    string bits() const;
    string dataBits() const;
    void flipBit(int);
    void detectError();
    void print() const;
};


#endif //HAMMING_BLOCK_H
