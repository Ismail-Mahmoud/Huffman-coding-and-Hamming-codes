//
// Created by Ismail El-Toukhy on 9/30/2020.
//

#include "Block.h"

Block::Block() {
    m_size = 0;
    m_data_size = 0;
    m_bits = "";
}

Block::Block(int size, const string& bits) {
    m_size = size;
    m_data_size = bits.size();
    m_bits.resize(m_size, '0');
    setDataBits(bits);
    setParityBits();
}

int Block::size() const {
    return m_size;
}

string Block::bits() const {
    return m_bits;
}

string Block::dataBits() const {
    string data_bits = "";
    for(int b = 1; data_bits.size() < m_data_size; ++b) {
        if(__builtin_popcount(b) == 1) continue;
        data_bits += m_bits[b];
    }
    return data_bits;
}

Block::Parity Block::parity() const {
    if(countOnBits() & 1) return odd;
    return even;
}

void Block::flipBit(int b) {
    m_bits[b] ^= 1;
}

int Block::countOnBits() const {
    return count(m_bits.begin(), m_bits.end(), '1');
}

int Block::xorOnBits() const {
    int res = 0;
    for(int b = 0; b < m_size; ++b) {
        if(m_bits[b] == '1') {
            res ^= b;
        }
    }
    return res;
}

void Block::setDataBits(const string& bits) {
    for(int block_bit = 1, data_bit = 0; data_bit < m_data_size; ++block_bit) {
        // powers of 2 => reserved for parity bits
        if(__builtin_popcount(block_bit) == 1) continue;
        m_bits[block_bit] = bits[data_bit++];
    }
}

void Block::setParityBits() {
    int parities = xorOnBits();
    for(int b = 1; b < m_size; b <<= 1) {
        if(parities & b) {
            m_bits[b] = '1';
        }
    }
    // zero-th bit
    if(parity() == odd) {
        m_bits[0] = '1';
    }
}

void Block::detectError() {
    int errorBit = xorOnBits();
    handleError(errorBit);
}

void Block::handleError(int errorBit) {
    if(errorBit == 0) {
        if(parity() == even) {
            cout << "No error detected.\n";
        }
        else {
            flipBit(0);
            cout << "1-Bit error detected at bit 0, successfully corrected.\n";
        }
    }
    else {
        if(parity() == odd) {
            flipBit(errorBit);
            cout << "1-Bit error detected at bit " << errorBit << ", successfully corrected.\n";
        }
        else {
            cout << "2-Bit error detected, couldn't correct it.\n";
            exit(0);
        }
    }
}

void Block::print() const {
    cout << "(" << m_size << ", " << m_data_size << ")\n";
    int d = round(sqrt(m_size));
    for(int i = 0; i < d; ++i) {
        cout << "\t" << m_bits.substr(i * d, d) << endl;
    }
    cout << endl;
}
