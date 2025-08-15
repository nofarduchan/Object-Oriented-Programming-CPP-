
#ifndef PROJECTCPP2_NAMES_H
#define PROJECTCPP2_NAMES_H
#include <iostream>
#include <cstring>
using namespace std;

class Names {
    friend ostream & operator<<(ostream &, const Names &);
public:
    Names();
    Names(const Names &names);
    ~Names();
    Names & operator+=(const char* str);
    Names & operator-=(const char* str);
    bool operator>=(const Names &) const;
    bool operator<=(const Names &) const;
    bool operator==(const Names &) const;
    Names & operator=(const Names &);
    Names operator*(const Names &) const;
    bool operator&&(const char* str);
    static int getTotal();


private:
    char **names;
    int size;
    static int total;


};

#endif //PROJECTCPP2_NAMES_H
