#include "Tree.h"

int main() {
    Tree tree(map<char, int>({{'a', 3}, {'b', 4}, {'c', 1}, {'d', 6}}));
    string bits = tree.encode("daabdc");
    cout << bits << endl;

    Tree tree2("aaabbbbcdddddd");
    string bits2 = tree2.slowEncode("daabdc");
    cout << bits2 << endl;

    assert(bits == bits2);

    tree.print();

    string text = tree.decode(bits);
    cout << text << endl;

    string text2 = tree.decode(bits2);
    cout << text2 << endl;

    assert(text == text2);

    return 0;
}
