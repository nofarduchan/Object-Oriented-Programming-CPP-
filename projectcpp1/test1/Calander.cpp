
#include "Calander.h"
#include <iostream>
#include <cstring>
#define N 30
using namespace std;

Calander::Calander() {
    int i;
    for (i=0; i<N; i++)
        this-> arr[i]= nullptr;
    busy = 0;
}

Calander::Calander(const Calander &dates) {
    for (int i=0; i<N; i++)
        arr[i] = dates.arr[i];
    this->busy = dates.busy;
}

Calander::~Calander(){
    deleteAll();
}
void Calander::setDate(MyDate date, int num) {
    this->arr[num-1]= new MyDate;
    arr[num-1]->setDate(date.getDay(), date.getMonth(), date.getYear());
    arr[num-1]->changeComment(date.getNote());
    this->busy++;
    cout<< "the date in arr[" << num-1 << "] is: " << arr[num-1]->getDay() << '/' << arr[num-1]->getMonth() << '/' << arr[num-1]->getYear() << " - " << arr[num-1]->getNote() << endl;
}

bool Calander::isFree(int num) const {
    if (this->arr[num-1]== nullptr)
        return true;
    else
        return false;
}

int Calander::firstFree() const {
    for (int i=0; i<N; i++)
    {
        if(this->arr[i]== nullptr)
            return i+1;
    }
    return 0;
}

bool Calander::Insert(MyDate date) {
    int num= firstFree();
    if(num!=0)
    {
        setDate(date, num);
        return true;
    }
    else
        return false;
}

int Calander::oldest() const {
    int count=0;
    for(int i=0; i<N; i++)
    {
        if (arr[i] != nullptr)
        {
            count=1;
            break;
        }
    }
    if (count==0)
        return -1;
    else
    {
        for(int i=0; i<N; i++)
        {
            if (arr[i] == nullptr)
                i++;
            for(int j=i+1; j<N; j++)
            {
                if (arr[j]== nullptr)
                    j++;
                else if(j==N-1 && arr[j]!= nullptr && arr[i]-> isBefore(*arr[j]) == 1)
                    return i;
                else if (j==N-1 && arr[j]!= nullptr && arr[i]-> isBefore(*arr[j]) == 0)
                    return j;
                else if ((arr[i]->isBefore(*arr[j])) == 1)
                    continue;
                else if ((arr[i]->isBefore(*arr[j])) == 0)
                    i=j;
            }
        }
    }
}

int Calander::datesNum() const {
    int count=0;
    for(int i=0; i<N; i++)
    {
        if (arr[i] != nullptr)
            count++;
    }
    return count;
}

void Calander::deleteAll() {
    for(int i=0; i<N; i++)
    {
        if (arr[i]!= nullptr)
        {
            delete[] arr[i]->getNote();
            arr[i]= nullptr;
        }
        else
            continue;
    }
    this->busy=0;
}

void Calander::deleteDate(int num) {
    if (arr[num-1]!= nullptr)
    {
        delete[] arr[num-1]->getNote();
        arr[num-1]= nullptr;
        this->busy--;
    }
}

void Calander::print() const {
    for (int i = 0; i < N; ++i) {
        if(arr[i]== nullptr)
            cout << i << " - Empty Calander" << endl;
        else
        {
            cout << i << " - ";
            arr[i]->print();
        }
    }
}