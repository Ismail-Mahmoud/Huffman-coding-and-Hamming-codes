//
// Created by Ismail El-Toukhy on 9/27/2020.
//

#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H


#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cassert>

using namespace std;

class Node {
private:
    int m_weight;
    string m_symbols;
    Node * m_left, * m_right;
public:
    Node();
    Node(int, string, Node* = nullptr, Node* = nullptr);
    Node(const Node& that);
    void setWeight(int);
    int getWeight() const;
    void setSymbols(string&);
    string getSymbols() const;
    void setLeft(Node*);
    Node* getLeft() const;
    void setRight(Node*);
    Node* getRight() const;
    bool isLeaf() const;
    void print() const;
    bool operator < (const Node&) const;
};


#endif //HUFFMAN_NODE_H
