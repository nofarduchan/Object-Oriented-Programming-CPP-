#include <iostream>
#include "Names.h"
#include <cstring>
using namespace std;

int Names::total;

Names::Names() {
    names = nullptr;
    size = 0;
}

Names::Names(const Names &obj) {
    operator=(obj);
}

Names::~Names() {
    if(size!=0)
    {
        for(int i; i<size; i++)
            delete[] names[i];
    }
    delete[] names;
    //total= total-size;
}

ostream &operator<<(ostream &, const Names &obj) {
    for(int i=0; i<obj.size; i++)
        cout<< "name " << i+1 << ": " << obj.names[i]<<endl;
    return cout;
}

Names &Names::operator+=(const char* str) {
    for(int i=0; i<size; i++)
    {
        if(strcmp(names[i], str)==0) //the strings are equal
            return *this;
    }
    //if str have not found in the array
    Names tmp;
    tmp = *this; //copying the class's object
    total= total-tmp.size;
    delete[] names;
    names=new char*[size+1];
    for(int i=0; i<size; i++)
    {
        names[i]=new char[strlen(tmp.names[i])+1];
        strcpy(names[i], tmp.names[i]);
    }
    names[size]= new char[strlen(str)+1];
    strcpy(names[size], str);
    size= size+1;
    total= total+1;
    return *this;
}

Names &Names::operator-=(const char *str) {
    int flag=0;
    int j=0;
    for(int i =0; i<size; i++)
    {
        if (strcmp(names[i], str) == 0) //the strings are equal
        {
            flag = 1;
            break;
        } else
            flag = 0;
    }
    if(flag==1)
    {
        Names tmp;
        tmp = *this; //copying the class's object
        total = total - tmp.size;
        delete[] names;
        names = new char *[size - 1];
        if (tmp.size == 1 && strcmp(tmp.names[0], str) == 0)
            names[0]= nullptr;
        else
        {
            for(int i=0; i<tmp.size; i++)
            {
                if (strcmp(tmp.names[i], str)!=0)
                {
                    names[j]=new char[strlen(tmp.names[i])+1];
                    strcpy(names[j], tmp.names[i]);
                    j++;
                }
            }
        }
        size= size-1;
        total= total-1;
        return *this;
    }
    else
        return *this;
}

Names &Names::operator=(const Names &obj) {
    if (this == &obj)
        return *this;
    total = total - size;
    size = obj.size;
    if(size==0)
    {
        names= nullptr;
        size=0;
    }
    else
    {
        delete []names;
        names = new char* [size];
        for (int i=0; i < size; i++)
        {
            names[i] = new char[strlen(obj.names[i]) + 1];
            if(!names[i])
            {
                cout<< "error"<<endl;
            }
            strcpy(names[i], obj.names[i]);
        }
    }
    total = total+ size;
    return *this;
}

bool Names::operator==(const Names &obj) const{
    int j;
    if(size!= obj.size)
        return false;
    for (int i=0; i<size; i++)
    {
        for (j=0; j<size; j++)
        {
            if (strcmp(names[i], obj.names[j])==0) //strings are equal
                break;
        }
        if (j==size)
            return false;
    }
    return true;
}

bool Names::operator<=(const Names &obj) const {
    int i, j;
    if(size > obj.size)
        return false;
    for(i=0; i < size; i++)
    {
        for(j=0; j < obj.size; j++)
            if(strcmp(names[i], obj.names[j])==0)
                break;
        if(j==obj.size)
            return false;
    }
    return true;
}

bool Names::operator>=(const Names &obj) const {
    int i, j;
    if(size < obj.size)
        return false;
    for(i=0; i < obj.size; i++)
    {
        for(j=0; j < size; j++)
            if(strcmp(names[j], obj.names[i])==0)
                break;
        if(j==size)
            return false;
    }
    return true;
}

Names Names::operator*(const Names &obj) const {
    Names tmp;
    int i, j, x=0, count=0;
    for(i=0; i < obj.size; i++)
    {
        for(j=0; j < size; j++)
            if(strcmp(names[j], obj.names[i])==0)
            {
                count++;
                break;
            }
    }
    tmp.size= count;
    tmp.names = new char*[count];
    for(i=0; i < obj.size; i++)
    {
        for(j=0; j < size; j++)
            if(strcmp(names[j], obj.names[i])==0)
            {
                tmp.names[x]=new char[strlen(names[j])+1];
                strcpy(tmp.names[x], names[j]);
                x++;
            }
    }
    return tmp;
}

bool Names::operator&&(const char *str) {
    for(int i=0; i<size; i++)
    {
        if (strcmp(names[i], str) == 0) //the strings are equal//
           return true;
    }
    return false;
}

int Names::getTotal(){
    return total;
}







