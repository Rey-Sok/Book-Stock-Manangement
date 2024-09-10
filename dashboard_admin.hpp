#include <iostream>
#include "bookBMS.hpp"
using namespace std;

void dashboard(){
    int option;
    do{
        system ("cls");
        cout << "Welcome to Book Management System !" << endl;
        cout << "1. Book Management " << endl;
        cout << "2. Buyer Management " << endl;
        cout << "3. Paymemt History " << endl;
        cout << "4. Logout" << endl;

        cout<<"Option: ";cin>>option;
        switch(option){
            case 1: {
                bookManagementSystem();
                int option;
                cout << "Input Option: ";cin>>option;
                switch(option){
                    case 1: {stockIn(); break;}
                    // case 2: {stockOut(); break;}
                    // case 3: {sale(); break;}
                    default: cout<<"Invalid option. Please try again."<<endl;
                }
                break;
            };
           
            case 4: cout<<"Logging out..."<<endl; sleep(1); break;
            default: cout<<"Invalid option. Please try again."<<endl;
        }
    }while(option != 4);
}