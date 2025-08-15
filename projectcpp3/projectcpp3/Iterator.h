#ifndef PROJECTCPP3_ITERATOR_H
#define PROJECTCPP3_ITERATOR_H

#include "Node.h"
//#include "Dictionary.h"

class Iterator {
    friend class Dictionary;
public:
    Iterator();
    Iterator& operator++();
    Node* operator*() const;
    Node* nextNode(Node*)const;
    Node* nextParent(Node*, Node*)const;
    Node* mostLeft(Node*) const;

    Node* Begin;

};


#endif //PROJECTCPP3_ITERATOR_H