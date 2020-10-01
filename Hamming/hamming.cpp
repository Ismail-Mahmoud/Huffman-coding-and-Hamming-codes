#include "Block.h"
#include <ctime>
#include <cassert>

int main() {
    string msg = "1110101111101100111100";
    vector<Block> blocks;
    for(int i = 0; i < msg.size(); i += 11) {
        blocks.emplace_back(16, msg.substr(i, 11));
    }

    string _msg = "";
    srand(time(nullptr));
    for(Block blk : blocks) {
        int bit = rand() % blk.size();
        cout << "Bit " << bit << " flipped" << endl;
        blk.flipBit(bit);
        // blk.flipBit((bit+1) % blk.size());
        blk.detectError();
        _msg += blk.dataBits();
    }

    cout << msg << endl << _msg << endl;
    assert(msg == _msg);

    return 0;
}
