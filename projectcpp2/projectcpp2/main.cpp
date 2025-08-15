#include <iostream>
#include "Names.h"
#include <cstring>
using namespace std;
int main() {
    int size, num, option, num1, num2, num3;
    char str[20];
    cout << "Enter size of array" << endl;
    cin >> size;
    Names* arr;
    arr = new Names[size];
    cout<< "1 Print all\n"<< "2 Add\n"<< "3 Remove\n"<< "4 Assign\n"<< "5 Is equal\n"<< "6 Is contain\n";
    cout<< "7 Is contained\n"<< "8 Intersection\n"<< "9 Belong\n"<< "10 Total size\n"<< "11 Quit"<< endl;
    cout<< "Enter an number option" << endl;
    cin >> option;
    while(option!=11)
    {
        switch(option)
        {
            case 1:
                for(int i=0; i<size; i++) {
                    cout << "GROUP NUMBER " << i << ":" << endl;
                    cout << arr[i] << endl;
                }
                cout<< "Enter an number option" << endl;
                cin >> option;
                break;
            case 2:
                cout << "Enter number of group between 0-"<< size-1 << endl;
                cin >> num;
                if(num<0 || num>=size)
                    cout<< "error- group do not exist"<<endl;
                else
                {
                    cout << "Enter a name"<< endl;
                    cin >> str;
                    arr[num] += str;
                    cout<<arr[num];
                    cout<< "Enter an number option" << endl;
                    cin >> option;
                }
                break;
            case 3:
                cout << "Enter number of group between 0-"<< size-1 << endl;
                cin >> num;
                if(num<0 || num>=size)
                    cout<< "error- group do not exist"<<endl;
                else
                {
                    cout << "Enter a name"<< endl;
                    cin >> str;
                    arr[num] -= str;
                    cout<<arr[num];
                    cout<< "total: "<< arr[num].getTotal()<<endl;
                    cout<< "Enter an number option" << endl;
                    cin >> option;
                }
                break;
            case 4:
                cout<< "Enter 2 numbers of groups between 0-"<< size-1 << endl;
                cin>> num1 >> num2;
                if(num1<0 || num1>=size || num2<0 || num2>=size)
                    cout<< "error- group do not exist"<<endl;
                else
                {
                    arr[num2]=arr[num1];
                    cout<< "total: "<< arr[num].getTotal()<<endl;
                    cout<< "Enter an number option" << endl;
                    cin >> option;
                }
                break;
            case 5:
                cout<< "Enter 2 numbers of groups between 0-"<< size-1 << endl;
                cin>> num1 >> num2;
                if(num1<0 || num1>=size || num2<0 || num2>=size)
                    cout<< "error- group do not exist"<<endl;
                else
                {
                    if((arr[num2]==arr[num1])==0)
                        cout<<"THE GROUPS ARE DIFFERENT" << endl;
                    else
                        cout<<"THE GROUPS ARE EQUAL" << endl;
                    cout<< "Enter an number option" << endl;
                    cin >> option;
                }
                break;
            case 6:
                cout<< "Enter 2 numbers of groups between 0-"<< size-1 << endl;
                cout<< "Enter num of group 1: "<< endl;
                cin>> num1;
                cout<< "Enter num of group 2: "<< endl;
                cin>>num2;
                if(num1<0 || num1>=size || num2<0 || num2>=size)
                    cout<< "error- group do not exist"<<endl;
                else
                {
                    if((arr[num2]<=arr[num1])==0)
                        cout<<"GROUP 1 DOES NOT CONTAIN GROUP 2" << endl;
                    else
                        cout<<"GROUP 1 CONTAINS GROUP 2" << endl;
                    cout<< "Enter an number option" << endl;
                    cin >> option;
                }
                break;
            case 7:
                cout<< "Enter 2 numbers of groups between 0-"<< size-1 << endl;
                cout<< "Enter num of group 1: "<< endl;
                cin>> num1;
                cout<< "Enter num of group 2: "<< endl;
                cin>>num2;
                if(num1<0 || num1>=size || num2<0 || num2>=size)
                    cout<< "error- group do not exist"<<endl;
                else
                {
                    if((arr[num2]>=arr[num1])==0)
                        cout<<"GROUP 1 IS NOT CONTAINED IN GROUP 2" << endl;
                    else
                        cout<<"GROUP 1 IS CONTAINED IN GROUP 2" << endl;
                    cout<< "Enter an number option" << endl;
                    cin >> option;
                }
                break;
            case 8:
                cout<< "Enter 3 numbers of groups between 0-"<< size-1 << endl;
                cout<< "Enter num of group 1: (destination)"<< endl;
                cin>> num1;
                cout<< "Enter num of group 2: (source)"<< endl;
                cin>>num2;
                cout<< "Enter num of group 3: (source)"<< endl;
                cin>>num3;
                if(num1<0 || num1>=size || num2<0 || num2>=size || num3<0 || num3>=size)
                    cout<< "error- group do not exist"<<endl;
                else
                    arr[num1]=arr[num2]*arr[num3];
                cout<< arr[num1] << endl;
                cout<< "Enter an number option" << endl;
                cin>>option;
                break;
            case 9:
                cout << "Enter a name"<< endl;
                cin >> str;
                cout<< "The indexs of the groups that contain '" << str << "' :" << endl;
                for(int i=0; i<size; i++)
                {
                    if((arr[i] && str)==1)
                        cout<< i << "  ";
                }
                cout<<endl;
                cout<< "Enter an number option" << endl;
                cin>>option;
                break;
            case 10:
                cout<< "The total size of all the groups is: "<< arr->getTotal() << endl;
                cout<< "Enter an number option" << endl;
                cin>>option;
                break;
            default:
                cout<< "ERROR!!"<<endl;
                cout<< "Enter an number option" << endl;
                cin >> option;
        }
    }

    delete[] arr;
    cout<< "Goodbye :)" << endl;
    return 0;
}
