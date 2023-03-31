#ifndef USER_HPP
#define USER_HPP

#include<string>
#include <vector>
#include"room.hpp"

using namespace std;

//class room;

class User{
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

    void addRoom(room &room) {roomsOwned.push_back(room);}
    vector<room> getRoomsOwned() {return roomsOwned;}

    void checkIn(int days){
        this->days = days; //save time stayed for when user checks out early.
        setAmount(days);
    }
    void checkOut(int days){

        if(days != this->days){
            setAmount(days);
        }
    }

    void setAmount(int days){
    this->days = days;//set days just incase user leaves early

        // total room cost
        for(const auto& room : roomsOwned){
            if(room.getRoomType() == "Standard Room"){
                amount += 100 * days;
            }
            else if(room.getRoomType() == "Deluxe Suite"){
                amount += 200 * days;
            }
            else if(room.getRoomType() == "Executive Suite"){
                amount += 500 * days;
            }
            else if(room.getRoomType() == "Penthouse"){
                amount += 1500 * days;
            }
        }
   }
    double getAmount(){
        return amount;
    }

private:
    string name_;
    string email_;
    string phone_;
    vector<room> roomsOwned;
    int days;
    double amount;
};
#endif