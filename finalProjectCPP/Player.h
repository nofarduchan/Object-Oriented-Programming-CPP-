

#ifndef FINALPROJECTCPP_PLAYER_H
#define FINALPROJECTCPP_PLAYER_H

#include <iostream>
#include <fstream>
#include "cstring"
using namespace std;

class Player {
    friend ostream & operator<<(ostream &, const Player &);
public:
    int champ=0;
    int score=0;
    int bronze=0;
    int silver=0;
    int gold=0;
    Player(){ username= ""; password= "";}
    Player(string username, string password) { this->username = username; this->password= password ;}
    Player(const Player& obj){ username = obj.username; password= obj.password; }
    virtual ~Player() { }
    string getUsername() { return username; }
    string getPassword() { return password; }
    virtual string getSymbol() const=0;
    virtual string getType() const=0;
    virtual Player* clone() const=0;


protected:
    string username;
    string password;
    //string type;
};

class Mammal: public Player{
protected:
string type;
Mammal() : Player(){ type= "Mammal";}
Mammal(string username, string password, string type): Player(username,password), type(type){ }
Mammal(const Mammal& obj) : Player(obj){ type = obj.type; }
virtual ~Mammal() { }
virtual Player* clone() const=0;

public:
virtual string getType() const { return type; }

};

class Fish: public Player{
protected:
    string type;
    Fish(string username, string password, string type): Player(username,password), type(type){ }
    Fish() : Player() { type = "Fish"; }
    Fish(const Fish& obj) : Player(obj) { type = obj.type; }
    virtual ~Fish() { }
    virtual Player* clone() const = 0;
public:
    virtual string getType() const { return type; }
    virtual string getSymbol() const =0;
};

class Insect: public Player{
protected:
    string type;
    Insect(string username, string password, string type): Player(username,password), type(type){ }
    Insect() : Player() { type = "Insect"; }
    Insect(const Insect& obj) : Player(obj) { type = obj.type; }
    virtual ~Insect() { }
    virtual Player* clone() const = 0;
public:
    virtual string getType() const { return type; }

};

class Dolphin : public Mammal{
    //friend ostream & operator<<(ostream &, const Dolphin &);
private:
    string symbol;

public:
    Dolphin(): Mammal(){ symbol = "Dolphin" ;}
    Dolphin(string username, string password, string type, string symbol): Mammal(username,password,type), symbol(symbol){ }
    Dolphin(const Dolphin& obj) : Mammal(obj){ symbol = obj.symbol; }
    ~Dolphin(){ };
    virtual Mammal* clone() const {Dolphin* tmp = new Dolphin(username, password, type, symbol);
        return tmp;}
    virtual string getSymbol() const { return symbol; }
};


class Dog : public Mammal{
private:
    string symbol;

public:
    Dog() : Mammal() { symbol = "Dog"; }
    Dog(string username, string password, string type, string symbol): Mammal(username,password,type), symbol(symbol){ }
    Dog(const Dog& obj) : Mammal(obj) { symbol = obj.symbol; }
    ~Dog() { };
    virtual Mammal* clone() const {
        Dog* tmp = new Dog(username, password, type, symbol);
        return tmp;
    }
    virtual string getSymbol() const { return symbol; }
};

class Cat : public Mammal{
private:
    string symbol;

public:
    Cat() : Mammal() { symbol = "Cat"; }
    Cat(string username, string password, string type, string symbol): Mammal(username,password,type), symbol(symbol){ }
    Cat(const Cat& obj) : Mammal(obj) { symbol = obj.symbol; }
    ~Cat() { };
    virtual Mammal* clone() const {
        Cat* tmp = new Cat(username, password, type, symbol);
        return tmp;
    }
    virtual string getSymbol() const { return symbol; }
};

class Shark : public Fish{
private:
    string symbol;

public:
    Shark() : Fish() { symbol = "Shark"; }
    Shark(string username, string password, string type, string symbol): Fish(username,password,type), symbol(symbol){ }
    Shark(const Shark& obj) : Fish(obj) { symbol = obj.symbol; }
    ~Shark() { };
    virtual Fish* clone() const {
        Shark* tmp = new Shark(username, password, type, symbol);
        return tmp;
    }
    virtual string getSymbol() const { return symbol; }
};

class Barracuda : public Fish{
private:
    string symbol;

public:
    Barracuda() : Fish() { symbol = "Barracuda"; }
    Barracuda(string username, string password, string type, string symbol): Fish(username,password,type), symbol(symbol){ }
    Barracuda(const Barracuda& obj) : Fish(obj) { symbol = obj.symbol; }
    ~Barracuda() { };
    virtual Fish* clone() const {
        Barracuda* tmp = new Barracuda(username, password, type, symbol);
        return tmp;
    }
    virtual string getSymbol() const { return symbol; }
};

class Ant : public Insect{
private:
    string symbol;

public:
    Ant(string username, string password, string type, string symbol): Insect(username,password,type), symbol(symbol){ }
    Ant() : Insect() { symbol = "Ant"; }
    Ant(const Ant& obj) : Insect(obj) { symbol = obj.symbol; }
    ~Ant() { };
    virtual Insect* clone() const {
        Ant* tmp = new Ant(username, password, type, symbol);
        return tmp;
    }
    virtual string getSymbol() const { return symbol; }
};

class Grasshopper : public Insect{
private:
    string symbol;

public:
    Grasshopper(string username, string password, string type, string symbol): Insect(username,password,type), symbol(symbol){ }
    Grasshopper() : Insect() { symbol = "Grasshopper"; }
    Grasshopper(const Grasshopper& obj) : Insect(obj) { symbol = obj.symbol; }
    ~Grasshopper() { };
    virtual Insect* clone() const {
        Grasshopper* tmp = new Grasshopper(username, password, type, symbol);
        return tmp;
    }
    virtual string getSymbol() const { return symbol; }
};

class Wasp : public Insect{
private:
    string symbol;

public:
    Wasp(string username, string password, string type, string symbol): Insect(username,password,type), symbol(symbol){ }
    Wasp() : Insect() { symbol = "Wasp"; }
    Wasp(const Wasp& obj) : Insect(obj) { symbol = obj.symbol; }
    ~Wasp() { };
    virtual Insect* clone() const {
        Wasp* tmp = new Wasp(username, password, type, symbol);
        return tmp;
    }
    virtual string getSymbol() const { return symbol; }
};
#endif //FINALPROJECTCPP_PLAYER_H
