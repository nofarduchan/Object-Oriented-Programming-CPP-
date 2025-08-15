
#ifndef TEST1_CALANDER_H
#define TEST1_CALANDER_H
#include "MyDate.h"
#define N 30

class Calander {
public:
    Calander();
    Calander(const Calander  &dates);
    ~Calander();
    void setDate(MyDate date, int num);
    bool isFree(int num) const;
    int firstFree() const;
    bool Insert(MyDate date);
    int oldest() const;
    int datesNum() const;
    void deleteAll();
    void deleteDate(int num);
    void print() const;

private:
    MyDate *arr[N];
    int busy;
};




#endif //TEST1_CALANDER_H
