
#include <iostream>
#include "MyDate.h"
#include "Calander.h"
#include <cstring>

using namespace std;

int main() {
    char str[50];
    MyDate d1;

    cout << "printing constructor: " << endl;
    cout << "Enter a string"<<endl;
    cin.getline(str,50);
    MyDate d2(2, 11, 2001, str);

    MyDate d3 = d2;

    cout << "date by get function: " << d3.getDay()<< "/" << d3.getMonth()<< "/"<< d3.getYear() << endl;

    cout << "setDay printing:" << endl;
    d1.setDay(2);
    cout<< "day: " << d1.getDay() <<endl;
    d1.setDay(40); //wrong day/
    cout<< "day: " << d1.getDay() <<endl;

    cout << "setMonth printing:" << endl;
    d1.setMonth(11);
    cout<< "month: " << d1.getMonth() <<endl;
    d1.setMonth(30); //wrong month
    cout<< "month: " << d1.getMonth() <<endl;

    cout << "setYear printing:" << endl;
    d1.setYear(-5); //wrong month
    cout<< "year: " << d1.getYear() <<endl;
    d1.setYear(2001);
    cout<< "year: " << d1.getYear() <<endl;

    cout << "setDate printing:" << endl;
    d1.setDate (0, 0, 0);
    cout << "date by setDate function: ";
    d1.print();

    cout << "inc printing:" << endl;
    d1.inc();
    cout << "date by inc function: " << d1.getDay()<< "/" << d1.getMonth()<< "/"<< d1.getYear() << endl;

    cout << "init printing:" << endl;
    d1.init(13, 12, 2022);

    cout << "isBefore printing:" << endl;
    if(d1.isBefore(d2)==1)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;

    cout << "changeComment printing:" << endl;
    cout << "Enter a string" << endl;
    cin.getline(str, 50);
    d1.changeComment(str);

    Calander c1;

    Calander c2 = c1;

    MyDate d4;
    d4.setDate(2,12,2002);
    int num=0;
    while (num<1 || num>30)
    {
        cout<< "Enter a num between 1-30" << endl;
        cin >> num;
    }
    c1.setDate(d4, num);

    num=0;
    while (num<1 || num>30)
    {
        cout<< "Enter a num between 1-30" << endl;
        cin >> num;
    }
    if(c1.isFree(num)==1)
        cout << "Empty place" << endl;
    else
        cout << "Full place" << endl;


    if (c1.firstFree()!=0)
        cout<< "The first place that empty is: " << c1.firstFree() << endl;
    else
        cout<< "The array is full"<< endl;

    MyDate d5;
    if(c1.Insert(d5)==1)
        cout << "Entered" << endl;
    else
        cout << "False" << endl;

    cout << "The number of earliest date is: " << c1.oldest() << endl;

    cout << "The number of full indexes is: " << c1.datesNum() << endl;

    c2.deleteAll();
    c1.deleteDate(1);

    c1.print();

    return 0;
}