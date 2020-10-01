//
// Created by Ismail El-Toukhy on 9/28/2020.
//

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H


#include "Node.h"

class Tree {
private:
    Node* m_root;
    set<Node> m_leaves;
    map<char, int> m_freq;
    map<char, string> m_code;
    void init();
    // Construction methods
    void calcFreq(const string&);
    void createLeaves(const map<char, int>&);
    Node merge(const Node&, const Node&);
    void construct();
    // Encoding methods
    string encodeSymbol(Node*, char);
    void generateCodes(Node*, const string& = "");
    // Decoding methods
    string decodeSymbol(Node*, string&);
    // Debugging methods
    void traverse(Node*, int) const;
public:
    Tree();
    explicit Tree(const map<char, int>&);
    explicit Tree(const string&);
    string slowEncode(const string&);
    string encode(const string&);
    string decode(string);
    void print() const;
};


#endif //HUFFMAN_TREE_H
