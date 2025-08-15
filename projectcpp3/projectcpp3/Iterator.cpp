#include "Iterator.h"
#include "Node.h"

Iterator &Iterator::operator++() {
    Begin= nextNode(Begin);
    return *this;
}

Node *Iterator::operator*() const {
    return Begin;
}

Node *Iterator::nextNode(Node * node) const {
    if (node->right== nullptr)
        return nextParent(node->parent, node);
    else
        return mostLeft(node->right);
}

Node *Iterator::nextParent(Node *parent, Node *child) const {
    if (parent== nullptr)
        return nullptr;
    else if (child== parent->right)
        return nextParent(parent->parent, parent);
    else
        return parent;
}

Node *Iterator::mostLeft(Node *node) const {
    if (node== nullptr)
        return nullptr;
    else if (node->left== nullptr)
        return node;
    else
        return mostLeft(node->left);
}

Iterator::Iterator() {
    Begin= nullptr;
}
