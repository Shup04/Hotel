/*
BILLING AND PAYMENT MANAGEMENT SYSTEM

#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <string>
#include <map>
//#include "user.hpp"

using namespace std;

class Bill{
private:
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
	Bill(User &guest, double &amount){
        this->guest = guest;
        this-> amount = amount;
    }

    /* commented cuz name and room stuff is under user and rooms owned already :)
    void setGuestName(string &guestName) {this-> guestName = guestName;}
    void setRoomType(string &roomType) {this->roomType = roomType;}
    void setRoomNumber(int &roomNumber) {this->roomNumber = roomNumber;}
    */

    /*
    string getGuestName() {return guestName;}
    string getRoomType() {return roomType;}
    int getRoomNumber() {return roomNumber;} 
    
   
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
