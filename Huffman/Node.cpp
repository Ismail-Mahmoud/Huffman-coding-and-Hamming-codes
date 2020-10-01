//
// Created by Ismail El-Toukhy on 9/27/2020.
//

#include "Node.h"

Node::Node() {
    m_weight = 0;
    m_symbols = "";
    m_left = nullptr;
    m_right = nullptr;
}

Node::Node(int weight, string symbols, Node* left, Node* right) {
    m_weight = weight;
    m_symbols = symbols;
    m_left = left;
    m_right = right;
}

Node::Node(const Node& that) {
    m_weight = that.m_weight;
    m_symbols = that.m_symbols;
    m_left = that.m_left;
    m_right = that.m_right;
}

void Node::setWeight(int weight) {
    m_weight = weight;
}

int Node::getWeight() const {
    return m_weight;
}

void Node::setSymbols(string& symbols) {
    m_symbols = symbols;
}

string Node::getSymbols() const {
    return m_symbols;
}

void Node::setLeft(Node* left) {
    m_left = left;
}

Node* Node::getLeft() const {
    return m_left;
}

void Node::setRight(Node* right) {
    m_right = right;
}

Node* Node::getRight() const {
    return m_right;
}

bool Node::isLeaf() const {
    return m_left == nullptr && m_right == nullptr;
}

bool Node::operator < (const Node& that) const {
    if(m_weight != that.m_weight) {
        return m_weight < that.m_weight;
    }
    return m_symbols < that.m_symbols;
}

void Node::print() const {
    cout << m_weight << " " << m_symbols << endl;
}
