#include<string>
using namespace std;

class User {

public:

    User(string name, string email, string phone) : name_(name), email_(email), phone_(phone) {}
    User(){
        name_=" ";
        email_=" ";
        phone_= " ";
    }
    string getName() const { return name_; }//function
    string getEmail() const { return email_; }//function
    string getPhone() const { return phone_; }//function
    void setName(string name){this->name_ = name;}
    void setEmail(string email){this->email_ = email;} 
    void setPhone(string phone){this->phone_ = phone;}
    
private:
    string name_;
    string email_;
    string phone_;
};