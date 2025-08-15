#include <iostream>
#include "Dictionary.h"

int main() {
    Dictionary d1;
    Dictionary d2= d1;
    char str[] = "Nofar";
    char str1[] = "Shiran";
    d2.insert(10, str);
    d2.insert(7, str1);
    d2.insert(13, str1);
    d2.insert(13, str1);
    try
    {
        Iterator iter;
        int i=0;
        char str2[]= "exception- 2 keys equal";
        for(iter=d2.begin(); iter.Begin != d2.end().Begin; ++iter)
        {
            if((*iter)->key == d2.search(13)->key)
                i++;
        }
        if (i>1)
            throw str2;
    }
    catch(char* str2)
    {
        cout<< str2 << endl;
        d2.deletion(13);
    }
    d2.insert(8, str1);
    d2.insert(9, str1);
    d2.insert(6, str1);
    d2.insert(11, str1);
    d2.insert(15, str1);
    if (d2.search(1)== nullptr)
        cout<< "The element n1 does not exist!!"<< endl;
    else
        cout << "The element exists: "<< d2.search(1)->data << "   " << d2.search(1)->key<< endl;

    if (d2.search(13)== nullptr)
        cout<< "The element n2 does not exist!!"<< endl;
    else
        cout << "The element n2 exists: "<< d2.search(13)->data << "   " << d2.search(13)->key<< endl;
    d2.deletion(7); // 7 exist in the tree
    d2.deletion(1); // 1 does not exist
    d2.deletion(7); // now 7 does not exist in the tree

    cout<< "printing preorder after screening and delete number 7 from the tree"<< endl;
    d2.print(); // PreOrder screening





    return 0;


}