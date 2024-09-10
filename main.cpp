#include <iostream>
#include <string.h>
#include <windows.h>
#include <unistd.h>
#include "authenticate.hpp"
#include "dashboard_admin.hpp"

using namespace std;

void homeScrean(){
    system("cls");
    cout << "Welcome to the Library Management System!" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
}

int main(){
    int choice, adminChoice;
    string username, password;
    do{
        homeScrean();
        cout << "Input options: ";
        cin >> choice;
        switch (choice) {
            case 1:
                if(login()) dashboard();
                break;
            case 2:
                user_register();
                sleep(1);
            default:
                break;
        }

    }while (choice != 3);
    
     
    return 0;
}