
#include "MyDate.h"
#include <iostream>
#include <cstring>

using namespace std;

MyDate::MyDate(){
    this->day= 1;
    this->month=1;
    this->year=2013;
    note= new char[50];
    char str[]= "First date";
    strcpy(this->note, str);
    //cout<< "date by default constructor: " << this->day<< "/" <<this->month << "/" << this->year << "  -  " <<this->note <<endl;
}

MyDate::MyDate(int day, int month, int year, char* note){
    setDate (day, month, year);
    this->note= new char[50];
    strcpy(this->note, note);
    //cout<< "date by constructor: " << this->day<< "/" <<this->month << "/" << this->year << "  -  " <<this->note <<endl;
}

MyDate:: MyDate(const MyDate &date){
    operator=(date);
    //cout<<  "date by copy constructor and get functions: " << this->day<< "/" << this->month << "/" <<  this->year << "  -  " << this->note <<endl;
}

MyDate::~MyDate(){
    delete[] note;
}

int MyDate:: getDay() const{
    return day;
}

int MyDate:: getMonth() const{
    return month;
}

int MyDate:: getYear() const{
    return year;
}

void MyDate:: setDay(int day){
    if (this->month ==1 || this->month ==3 || this->month ==5 || this->month ==7 || this->month ==8 || this->month ==10 || this->month ==12)
    {
        if (day>=1 && day<=31)
        {
            this->day = day;
        }
        else
            cout<< "error day"<<endl;
    }
    else if (this->month ==4 || this->month ==6 || this->month ==9 || this->month ==11)
    {
        if (day>=1 && day<=30)
        {
            this->day = day;
        }
        else
            cout<< "error day"<<endl;
    }
    else if (this->month ==2)
    {
        if (day>=1 && day<=28)
        {
            this->day = day;
        }
        else
            cout<< "error day"<<endl;
    }
}

void MyDate:: setMonth(int month){
    if (month>=1 && month<=12)
    {
        this->month=month;
    }
    else
        cout<< "error month"<<endl;
}

void MyDate:: setYear(int year){
    if(year > 0)
    {
        this->year = year;
    }
    else
        cout<< "error year"<<endl;
}

void MyDate:: setDate(int day, int month, int year){
    if(year > 0)
        setYear(year);
    else
        setYear(1900);
    if (month>=1 && month<=12)
        setMonth(month);
    else
        setMonth(1);
    if (this->month ==1 || this->month ==3 || this->month ==5 || this->month ==7 || this->month ==8 || this->month ==10 || this->month ==12)
    {
        if (day>=1 && day<=31)
            setDay(day);
        else
            setDay(1);
    }
    else if (this->month ==4 || this->month ==6 || this->month ==9 || this->month ==11)
    {
        if (day>=1 && day<=30)
            setDay(day);
        else
            setDay(1);
    }
    else if (this->month ==2)
    {
        if (day>=1 && day<=28)
            setDay(day);
        else
            setDay(1);
    }
}

void MyDate:: inc(){
    this->day++;
    if(this->month ==1 || this->month ==3 || this->month ==5 || this->month ==7 || this->month ==8 || this->month ==10 || this->month ==12)
    {
        if(this->day > 31)
        {
            this->day= 1;
            this->month++;
            if (this->month > 12)
            {
                this->month = 1;
                this->year++;
            }
        }
    }
    else if (this->month ==4 || this->month ==6 || this->month ==9 || this->month ==11)
    {
        if(this->day > 30)
        {
            this->day = 1;
            this->month++;
            if (this->month > 12)
            {
                this->month = 1;
                this->year++;
            }
        }
    }
    else if (this->month ==2)
    {
        if(this->day > 28)
        {
            this->day = 1;
            this->month++;
            if (this->month > 12)
            {
                this->month = 1;
                this->year++;
            }
        }
    }
}

void MyDate:: init(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
    char str[]="submitting an exercise";
    strcpy(this->note, str);
    cout<< "date by init: " << this->day<< "/" <<this->month << "/" << this->year << "  -  " <<this->note <<endl;
}

bool MyDate:: isBefore(MyDate &d2) const{
    if (d2.year > this->year)
        return true;
    else if (d2.year == this->year)
    {
        if(d2.month > this->month)
            return true;
        else if (d2.month == this->month)
        {
            if (d2.day > this->day)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

void MyDate:: changeComment(char* note){
    strcpy(this->note, note);
    //cout << "note by changeComment: " << this->note << endl;
}

void MyDate:: print() const{
    cout << day << "/" << month << "/" << year << endl;
}

char* MyDate:: getNote() const{
    return note;
}

MyDate& MyDate:: operator=(const MyDate &date) {
    setDate(date.day, date.month, date.year);
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
    note= nullptr;
    this->note = new char[50];
    strcpy(this->note, date.note);
    return *this;
}
