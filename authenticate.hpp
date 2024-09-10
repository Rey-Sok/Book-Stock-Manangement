#include <vector>
#include <sstream>
#include "admin.hpp"
using namespace std;

vector<Admin> load_admins() {
    vector<Admin> admins_data;
    ifstream admins("admins.txt");
    string line;

    // Skip the header line
    getline(admins, line);

    // Read each line of admin data
    while (getline(admins, line)) {
        stringstream ss(line);
        string name, email, role, password;

        // Use stringstream to extract the fields from the line
        ss >> setw(10) >> name >> setw(20) >> email >> setw(10) >> role >> setw(10) >> password;

        // Create an Admin object and add it to the vector
        if (!name.empty() && !email.empty() && !role.empty() && !password.empty()) {
            admins_data.emplace_back(name, email, role, password);
        }
    }

    admins.close();
    return admins_data;
}

bool validate(string user, string pass){
    vector<Admin> admins = load_admins();
    for(auto& admin : admins){
        cout << "passward" << endl;
        bool is_admin = admin.getName().compare(user) == 0;
        bool is_password = admin.getPassword().compare(pass) == 0;
        if (is_admin==0 && is_password==0) return true;
    }
    return false; 
}

bool login(){
    char ch;
    string username, password;
    do{
        system ("cls");
        cout<<"Welcome To Book Stock Management System"<<endl;
        cout<<"Please Login"<<endl;
        cout<<"Please Enter your Useername  : "; cin.ignore ();getline(cin,username);
        cout<<"Please Enter your Password   : "; cin>>password;
        if(validate(username, password)){
            cout<<"Login successful"<<endl;
            return true;
       
        }else{
            cout <<"Login failed"<<endl;
            cout <<"Please Login again "<<endl;
            cout <<"Do you want to Login again?(Y/N) : "; cin >> ch;
        }
    }while (ch !='n' && ch!='N');

    return false;
}

void user_register(){
    ofstream file("users.txt",ios::app);
    string username, email, role = "admin", password;
    cout<<"Enter your username  : ";cin.ignore ();getline(cin,username);
    cout<<"Enter your password   : "; cin>>password;
    cout<<"Enter your email : "; cin>>email;
    Admin admin(username, email, role, password);
    admin.save();
    cout<<"User Created!"<<endl;
}