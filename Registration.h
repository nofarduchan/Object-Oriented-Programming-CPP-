

#ifndef FINALPROJECTCPP_REGISTRATION_H
#define FINALPROJECTCPP_REGISTRATION_H

#include <iostream>
#include <fstream>
#include "cstring"
#include "Player.h"

class Registration {
public:
    Registration();
    void regist(Player**, int*);
    bool connection(Player**, int*, string*, string*);
private:
    void registration(string*, string*, string*, string*);

};


#endif //FINALPROJECTCPP_REGISTRATION_H
