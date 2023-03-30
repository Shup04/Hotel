/*
BILLING AND PAYMENT MANAGEMENT SYSTEM
*/
#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <string>
#include <map>
#include "user.hpp"
using namespace std;

class Bill: User{
private:
	string guestName;
	string roomType;
	int roomNumber;
	double amount;
    User guest;
		
public:
	Bill(){
        guestName = "N/A";
        roomType = "N/A";
        roomNumber = 0;
        amount = 0;
    }

    //roomType needs to include "N/A" within room class
	Bill(string &guestName, string &roomType, int &roomNumber, double &amount){
        this-> guestName = guestName;
        this-> roomType = roomType;
        this-> roomNumber = roomNumber;
        this-> amount = amount;
    }

    void setGuestName(string &guestName) {this-> guestName = guestName;}
    void setRoomType(string &roomType) {this->roomType = roomType;}
    void setRoomNumber(int &roomNumber) {this->roomNumber = roomNumber;}
    void setAmount(double &amount) {this-> amount = amount;}
        
    string getGuestName() {return guestName;}
    string getRoomType() {return roomType;}
    int getRoomNumber() {return roomNumber;} 
    double getAmount() {return amount;}
};

#endif
/*
TO IMPLEMENT

int main()
{ 
    //Dummy Code
    vector<Bill> Bills;

    // Create a Bill object and add it to the vector
    Bill b1("Alice", "Single", 207, 300);
    // Print the Bill
    b1.printBill();
    // Print Bill and Prompts Payment
    b1.payment();

    return 0;
}
*/
