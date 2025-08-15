#ifndef PROJECTCPP3_NODE_H
#define PROJECTCPP3_NODE_H

#include <iostream>
#include <cstring>
using namespace std;


class Node {
    friend class Dictionary;
    friend class Iterator;
public:
    Node();
    Node(const Node &);
    ~Node();
    char *data;
    int key;
    Node* left= nullptr;
    Node* right= nullptr;
    Node* parent= nullptr;

};


#endif //PROJECTCPP3_NODE_H