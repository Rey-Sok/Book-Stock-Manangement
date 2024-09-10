using namespace std;
class User{
    public:
    string name;
    string email;
    string role;
    // Constructor
    User(string name, string email, string role){
        this->name = name;
        this->email = email;
        this->role = role;
    }

    // Getters
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getRole() const { return role; }
    
    // Setters 
    void setName(string name) { this->name = name; }
    void setEmail(string email) { this->email = email; }
    void setRole(string role) { this->role = role; }
};