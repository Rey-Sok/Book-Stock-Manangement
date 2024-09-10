#include <fstream>
#include "users.hpp"
#include <iomanip>

using namespace std;
class Admin: public User{
    // Add admin-specific methods here
    private:
    string password;

    public:
    Admin(string name, string email, string role, string password): 
    User(name, email, role), password(password)  {}

   string getPassword() const {return this->password;}
   void setPassword(string password) {this->password = password;}

   void save() const {
    ofstream outfile("admins.txt", ios::app);
    outfile <<setw(10)<<"Name"
            <<setw(20)<<"Email"
            <<setw(10)<<"Role"
            <<setw(10)<<"Password" << endl;      
    outfile <<setw(10)<< this->name
            <<setw(20)<< this->email
            <<setw(10)<< this->role
            <<setw(10)<< this->password << endl;
    outfile.close();
   }
};