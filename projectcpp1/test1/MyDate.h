
#ifndef TEST1_MYDATE_H
#define TEST1_MYDATE_H


class MyDate {
public:
    MyDate();
    MyDate(int, int, int, char*);
    MyDate(const MyDate &date);
    ~MyDate();
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setDate(int day, int month, int year);
    void inc();
    void init(int day, int month, int year);
    bool isBefore(MyDate &date) const;
    void changeComment(char* note);
    void print() const;
    char* getNote() const;
    MyDate& operator=(const MyDate&);

private:
    int day;
    int month;
    int year;
    char *note;
};



#endif //TEST1_MYDATE_H
