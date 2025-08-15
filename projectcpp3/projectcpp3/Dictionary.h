#ifndef PROJECTCPP3_DICTIONARY_H
#define PROJECTCPP3_DICTIONARY_H

#include "Node.h"
#include "Iterator.h"

class Dictionary {
public:
    Dictionary();
    Dictionary(const Dictionary &);
    ~Dictionary();
    Dictionary & operator=(const Dictionary &);
    Node* deepCopy(Node*);
    void insert(int, char*);
    void insertion(Node*, Node*);
    Node* search(int) const;
    Node* find(Node*, int) const;
    void deletion(int);
    Node* mostLeft(Node*) const;
    Iterator begin();
    Iterator end();
    void print();
    void clear(Node* &);

private:
    Node* root;
};



#endif //PROJECTCPP3_DICTIONARY_H