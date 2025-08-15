#include "Dictionary.h"
#include "Node.h"
#include "Iterator.h"
#include <iostream>
#include <cstring>


Dictionary ::Dictionary() {
    root = nullptr;
}

Dictionary::Dictionary(const Dictionary &dict) {
    operator=(dict);
}

Dictionary &Dictionary::operator=(const Dictionary &dict) {
    root = deepCopy(dict.root); //recursive function
    return *this;
}

Dictionary::~Dictionary() {
    clear(root);
}

Node *Dictionary::deepCopy(Node *dict) {
    if (dict)
    {
        Node* node = new Node();
        node->data = new char [strlen(dict->data)+1];
        strcpy(node->data, dict->data);
        node->key = dict->key;
        node->parent = dict->parent;
        node->left = deepCopy(dict->left);
        node->right = deepCopy(dict->right);
        return node;
    }
    else
        return nullptr;
}

void Dictionary::insert(int key, char* data) {
    Node* node= new Node();
    node->key= key;
    node->data= new char [strlen(data)+1];
    strcpy(node->data, data);
    if (root== nullptr)
    {
        root=node;
        return;
    }
    else
        insertion(root, node); //recursive function
}

void Dictionary::insertion(Node *oldNode, Node *newNode) {
    if (oldNode->key > newNode->key)
    {
        if (oldNode->left == nullptr)
        {
            oldNode->left = newNode;
            newNode->parent = oldNode;
            return;
        }
        else
            return insertion(oldNode->left, newNode);
    }
    else
    {
        if (oldNode->right == nullptr)
        {
            oldNode->right = newNode;
            newNode->parent = oldNode;
            return;
        }
        else
            return insertion(oldNode->right, newNode);
    }
}

Node *Dictionary::search(int key) const {
    return find(root, key);
}

Node *Dictionary::find(Node * node, int key) const {
    if(node == nullptr)
        return nullptr;
    else if(node->key == key)
        return node;
    else if(node->key > key)
        return find(node->left, key);
    else
        return find(node->right, key);
}

void Dictionary::deletion(int key) {
    Node *node = search(key);
    if (node == nullptr)
        cout<< "The element does not exist"<< endl;
    else if (node->left == nullptr && node->right == nullptr)
    {
        if (node->parent->left!= nullptr && node->parent->left->key == node->key)
            node->parent->left = nullptr;
        else if (node->parent->right!= nullptr && node->parent->right->key == node->key)
            node->parent->right = nullptr;
        delete node;
    }
    else if (node->left != nullptr && node->right == nullptr || node->left == nullptr && node->right != nullptr)
    {
        if (node->left != nullptr)
        {
            if (node->parent->left!= nullptr && node->parent->left->key == node->key)
            {
                node->left->parent = node->parent;
                node->parent->left = node->left;
            }
            else if (node->parent->right!= nullptr && node->parent->right->key == node->key)
            {
                node->left->parent = node->parent;
                node->parent->right = node->left;
            }
        }
        else
        {
            if (node->parent->left!= nullptr && node->parent->left->key == node->key)
            {
                node->right->parent = node->parent;
                node->parent->left = node->right;
            }
            else if (node->parent->right!= nullptr && node->parent->right->key == node->key)
                node->right->parent = node->parent;
            node->parent->right = node->right;
        }
        delete node;
    }
    else
    {
        if (node->parent->left!= nullptr && node->parent->left->key == node->key)
        {
            node->right->parent = node->parent;
            node->parent->left = node->right;
            node->left->parent = mostLeft(node->right);
            mostLeft(node->right)->left = node->left;
        }
        else if (node->parent->right != nullptr && node->parent->right->key == node->key)
        {
            node->right->parent = node->parent;
            node->parent->right = node->right;
            node->left->parent = mostLeft(node->right);
            mostLeft(node->right)->left = node->left;
        }
        delete node;
    }
}

Node *Dictionary::mostLeft(Node *node) const {
    if (node== nullptr)
        return nullptr;
    else if (node->left== nullptr)
        return node;
    else
        return mostLeft(node->left);
}

Iterator Dictionary::begin() {
    Iterator iter;
    iter.Begin = mostLeft(root);
    return iter;
}

Iterator Dictionary::end() {
    Iterator iter;
    iter.Begin = nullptr;
    return iter;
}

void Dictionary::print() {
    Iterator iter;
    for(iter=begin(); iter.Begin != end().Begin; ++iter)
        cout << "key:"<< (*iter)->key << "\t  name: " << (*iter)->data << endl;
}

void Dictionary::clear(Node *&ptr) {
    if (ptr)
    {
        clear(ptr->left);
        clear(ptr->right);
        delete ptr;
        ptr = nullptr;
    }
}


