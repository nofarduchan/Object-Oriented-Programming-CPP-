#include "Node.h"


Node::Node() {
    data = nullptr;
    key = 0;
    left= nullptr;
    right= nullptr;
    parent= nullptr;
}

Node::Node(const Node & node) {
    data = node.data;
    key = node.key;
    left= node.left;
    right = node.right;
    parent= node.parent;
}


Node::~Node() {
    delete [] data;
    data= nullptr;
    key = 0;
    left= nullptr;
    right= nullptr;
    parent= nullptr;
}