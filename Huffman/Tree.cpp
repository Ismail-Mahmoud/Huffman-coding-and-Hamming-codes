//
// Created by Ismail El-Toukhy on 9/28/2020.
//

#include "Tree.h"

void Tree::init() {
    m_root = new Node();
    m_freq = map<char, int>();
    m_code = map<char, string>();
    m_leaves = set<Node>();
}

Tree::Tree() {
    init();
}

Tree::Tree(const map<char, int>& freq) {
    init();
    m_freq = freq;
    construct();
    generateCodes(m_root);
}

Tree::Tree(const string& text) {
    init();
    calcFreq(text);
    construct();
    generateCodes(m_root);
}

void Tree::calcFreq(const string& text) {
    for(char symbol : text) {
        ++m_freq[symbol];
    }
}

void Tree::createLeaves(const map<char, int>& freq) {
    for(auto it : freq) {
        Node leaf(it.second, string("") + it.first);
        m_leaves.insert(leaf);
    }
}

Node Tree::merge(const Node& A, const Node& B) {
    Node * left = new Node(A), * right = new Node(B);
    Node parent(left->getWeight() + right->getWeight(), left->getSymbols() + right->getSymbols(), left, right);
    return parent;
}

void Tree::construct() {
    createLeaves(m_freq);
    set<Node> nodes = m_leaves;
    while(nodes.size() > 1) {
        auto second = nodes.begin();
        auto first = second++;
        Node parent = merge(*first, *second);
        nodes.erase(first);
        nodes.erase(second);
        nodes.insert(parent);
    }
    if(nodes.empty()) {
        m_root = nullptr;
    }
    else {
        *m_root = *nodes.begin();
    }
}

string Tree::encodeSymbol(Node* node, char symbol) {
    if(node->isLeaf()) {
        assert(symbol == node->getSymbols()[0]);
        return "";
    }
    if(node->getLeft()->getSymbols().find(symbol) != string::npos) {
        return "0" + encodeSymbol(node->getLeft(), symbol);
    }
    return "1" + encodeSymbol(node->getRight(), symbol);
}

string Tree::slowEncode(const string& text) {
    string bits = "";
    for(char symbol : text) {
        if(m_code.find(symbol) != m_code.end()) {
            bits += encodeSymbol(m_root, symbol);
        }
        else {
            cout << "Invalid symbol(s)\n";
            exit(0);
        }
    }
    return bits;
}

void Tree::generateCodes(Node* node, const string& bits) {
    if(node->isLeaf()) {
        char symbol = node->getSymbols()[0];
        m_code[symbol] = bits;
        return;
    }
    generateCodes(node->getLeft(), bits + '0');
    generateCodes(node->getRight(), bits + '1');
}

string Tree::encode(const string& text) {
    string bits = "";
    for(char symbol : text) {
        if(m_code.find(symbol) != m_code.end()) {
            bits += m_code[symbol];
        }
        else {
            cout << "Invalid symbol(s)\n";
            exit(0);
        }
    }
    return bits;
}

string Tree::decodeSymbol(Node* node, string& bits) {
    if(node->isLeaf()) {
        return node->getSymbols();
    }
    if(bits.empty()) {
        throw "Invalid bit sequence";
    }
    char bit = bits.back();
    bits.pop_back();
    if(bit == '0') {
        return decodeSymbol(node->getLeft(), bits);
    }
    return decodeSymbol(node->getRight(), bits);
}

string Tree::decode(string bits) {
    string text = "";
    reverse(bits.begin(), bits.end());
    while(!bits.empty()) {
        try {
            text += decodeSymbol(m_root, bits);
        }
        catch(const char* e) {
            cout << e;
            exit(0);
        }
    }
    return text;
}

void Tree::traverse(Node* node, int d = 0) const {
    if(node == nullptr) return;
    traverse(node->getRight(), d + 1);
    cout << string(5 * d, ' '); node->print();
    traverse(node->getLeft(), d + 1);
}

void Tree::print() const {
    cout << "Symbol\tFreq\tCode\n";
    for(const auto& it : m_freq){
        cout << it.first << "\t" << it.second << "\t" << m_code.at(it.first) << endl;
    }
    cout << "\nTree: (rotated 90 degrees)\n";
    traverse(m_root);
    cout << endl;
}
