#include "Huffman/Tree.h"
#include "Hamming/Block.h"
#include "utils.h"

int main() {
    // http://pi.math.cornell.edu/~mec/2003-2004/cryptography/subs/frequencies.html
    map<char, int> freq = {{'e', 21912}, {'t', 16587}, {'a', 14810}, {'o', 14003}, {'i', 13318}, {'n', 12666}, {'s', 11450}, {'r', 10977}, {'h', 10795}, {'d', 7874}, {'l', 7253}, {'u', 5246}, {'c', 4943}, {'m', 4761}, {'f', 4200}, {'y', 3853}, {'w', 3819}, {'g', 3693}, {'p', 3316}, {'b', 2715}, {'v', 2019}, {'k', 1257}, {'x', 315}, {'q', 205}, {'j', 188}, {'z', 128}};

    Tree tree(freq);
//    Tree tree("aaabbbbcdddddd");
    tree.print();

    // Sender
    string message = "helloworldz";
//    string message = "daabdcabcda";
    string bits = tree.encode(message);
    vector<Block> blocks;
    divideBits(bits, blocks);

    // Transmission medium
    distortBlocks(blocks);

    // Reciever
    string _bits = retrieveBits(blocks);
    string _message = tree.decode(_bits);

    cout << message << " " << bits << endl << _message << " " << _bits << endl;

    assert(message == _message);

    return 0;
}
