//
// Created by Ismail El-Toukhy on 10/1/2020.
//

#include "utils.h"

void divideBits(const string& bits, vector<Block>& blocks) {
    for(int i = 0; i < bits.size(); i += block_data_size) {
        blocks.emplace_back(block_size, bits.substr(i, block_data_size));
        cout << "Block " << blocks.size() - 1 << ":\n";
        blocks.back().print();
    }
}

void distortBlocks(vector<Block>& blocks) {
    srand(time(nullptr));
    for(int i = 0; i < blocks.size(); ++i) {
        int bit = rand() % blocks[i].size();
        blocks[i].flipBit(bit);
        // blocks[i].flipBit((bit + 1) % block_size);
        cout << "Bit " << bit << " at block " << i << " flipped" << endl;
    }
    cout << endl;
}

string retrieveBits(vector<Block>& blocks) {
    string bits = "";
    for(int i = 0; i < blocks.size(); ++i) {
        cout << "Block " << i << ": ";
        blocks[i].detectError();
        bits += blocks[i].dataBits();
    }
    cout << endl;
    return bits;
}
