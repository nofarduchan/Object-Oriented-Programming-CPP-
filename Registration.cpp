
#include "Registration.h"

Registration::Registration() {
}

void Registration::regist(Player **p, int *psize) {
    int i, size;
    string username, password, type, symbol;
    registration(&username, &password, &type, &symbol);
    size = *psize;
    while (true) {
        for (i = 0; i < size; i++) {
            if (username.compare(p[i]->getUsername()) == 0) {
                cout << "Choose another username" << endl;
                cin >> username;
                break;
            }
        }
        if (i == size)
            break;
    }
    if (symbol.compare("dolphin") == 0)
    {
        p[i] = new Dolphin(username, password, type, symbol);
        ofstream fs("mammals.txt", ios::app);
        fs<< p[i]->getUsername()<< " " << p[i]->getType()<< " "<< p[i]->getSymbol()<< endl;
        fs.close();
    }
    else if(symbol.compare("dog")==0)
    {
        p[i] = new Dog(username, password, type, symbol);
        ofstream fs("mammals.txt", ios::app);
        fs<< p[i]->getUsername()<< " " << p[i]->getType()<< " "<< p[i]->getSymbol()<< endl;
        fs.close();
    }
    else if(symbol.compare("cat")==0)
    {
        p[i] = new Cat(username, password, type, symbol);
        ofstream fs("mammals.txt", ios::app);
        fs<< p[i]->getUsername()<< " " << p[i]->getType()<< " "<< p[i]->getSymbol()<< endl;
        fs.close();
    }
    else if(symbol.compare("shark")==0)
    {
        p[i] = new Shark(username, password, type, symbol);
        ofstream fs("fish.txt", ios::app);
        fs<< p[i]->getUsername()<< " " << p[i]->getType()<< " "<< p[i]->getSymbol()<< endl;
        fs.close();
    }
    else if(symbol.compare("barracuda")==0)
    {
        p[i] = new Barracuda(username, password, type, symbol);
        ofstream fs("fish.txt", ios::app);
        fs<< p[i]->getUsername()<< " " << p[i]->getType()<< " "<< p[i]->getSymbol()<< endl;
        fs.close();
    }
    else if(symbol.compare("ant")==0)
    {
        p[i] = new Ant(username, password, type, symbol);
        ofstream fs("insects.txt", ios::app);
        fs<< p[i]->getUsername()<< " " << p[i]->getType()<< " "<< p[i]->getSymbol()<< endl;
        fs.close();
    }
    else if(symbol.compare("grasshopper")==0)
    {
        p[i] = new Grasshopper(username, password, type, symbol);
        ofstream fs("insects.txt", ios::app);
        fs<< p[i]->getUsername()<< " " << p[i]->getType()<< " "<< p[i]->getSymbol()<< endl;
        fs.close();
    }
    else if(symbol.compare("wasp")==0)
    {
        p[i] = new Wasp(username, password, type, symbol);
        ofstream fs("insects.txt", ios::app);
        fs<< p[i]->getUsername()<< " " << p[i]->getType()<< " "<< p[i]->getSymbol()<< endl;
        fs.close();
    }
    size++;
    ofstream fs("players.txt", ios::app);
    fs<< p[i]->getUsername()<< " "<< p[i]->getPassword()<< " " << p[i]->getType()<< " "<< p[i]->getSymbol()<< " ";
    fs<< p[i]->champ << " " << p[i]->gold << " " << p[i]->silver << " " << p[i]->bronze << endl;
    fs.close();
    *psize= size;
}

void Registration::registration(string* username, string* password, string* type, string* symbol) {
    int option1, option2;
    cout << "Enter your username" << endl;
    cin>> *username;
    cout << "Enter your password" << endl;
    cin>> *password;
    cout << "press:\n 1- mammal\n 2- fish\n 3- insect " << endl;
    cin>> option1;
    while(true)
    {
        switch (option1) {
            case 1:
                *type= "mammal";
                cout << "press:\n 1- dolphin\n 2- dog\n 3- cat " << endl;
                cin>> option2;
                while(true)
                {
                    switch (option2) {
                        case 1:
                            *symbol= "dolphin";
                            break;
                        case 2:
                            *symbol= "dog";
                            break;
                        case 3:
                            *symbol= "cat";
                            break;
                        default:
                            cout<< "WRONG CHOICE, try again" << endl;
                            cin >> option2;
                            continue;
                    }
                    break;
                }
                break;
            case 2:
                *type= "fish";
                cout << "press:\n 1- shark\n 2- barracuda" << endl;
                cin>> option2;
                while(true)
                {
                    switch (option2) {
                        case 1:
                            *symbol= "shark";
                            break;
                        case 2:
                            *symbol= "barracuda";
                            break;
                        default:
                            cout<< "WRONG CHOICE, try again" << endl;
                            cin >> option2;
                            continue;
                    }
                    break;
                }
                break;
            case 3:
                *type= "insect";
                cout << "press:\n 1- ant\n 2- grasshopper\n 3- wasp" << endl;
                cin>> option2;
                while(true)
                {
                    switch (option2) {
                        case 1:
                            *symbol= "ant";
                            break;
                        case 2:
                            *symbol= "grasshopper";
                            break;
                        case 3:
                            *symbol= "wasp";
                            break;
                        default:
                            cout<< "WRONG CHOICE, try again" << endl;
                            cin >> option2;
                            continue;
                    }
                    break;
                }
                break;
            default:
                cout<< "WRONG CHOICE, try again" << endl;
                cin >> option1;
                continue;
        }
        break;
    }
}

bool Registration::connection(Player **p, int *psize, string* username, string* password) {
    string type, symbol;
    int size= *psize;
    int num1=0, i;
    while(num1 == 0)
    {
        cout<< "Enter your username" << endl;
        cin>> *username;
        cout<< "Enter your password" << endl;
        cin>> *password;
        for(i=0; i<size; i++)
        {
            if (username->compare(p[i]->getUsername()) == 0 && password->compare(p[i]->getPassword()) == 0) {
                break;
            }
        }
        if(i!=size)
        {
            cout<< "You in" << endl;
            return true;
        }
        else
        {
            cout<< "One of your details is uncorrected"<<endl;
            cout<< "press: 0- Try again | else- Back to menu"<<endl;
            cin>>num1;
        }
    }
    return false;
}



