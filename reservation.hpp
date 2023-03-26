#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

class Hotel {

public:

    Hotel(string name, int numRooms) : name_(name), numRooms_(numRooms) {
        for (int i = 1; i <= numRooms_; i++) {
            rooms_.push_back(Room(i, 2));
        }
    }

private:

    string name_;
    int numRooms_;
    vector<Room> rooms_;
    map<int, Reservation> reservations_;
    map<string, Guest> guests_;

public:

    void printRooms() const{
        cout << "Rooms:\n";
        for (int i = 1; i <= numRooms_; i++) {
            cout << "Room " << i << "\n";
        }
    }

    int book(int numR,int numRooms_)

    {

        for (int i = 1; i <= numRooms_; i++){
            cin >> numR;

            if (numR == i){
                numRooms_ -= 1;
                return(numRooms_);
            }
        }
    }

    void bookRoom(int numR,string guestName, string checkInDate, string checkOutDate){
        cout << " enter the room " << endl;
        cin >> numR;
        if (numR){
            book(numR, numRooms_);
            cout << " Your room is successfully book " << endl;
            cout << "from " << checkInDate << "to " << checkOutDate << endl;
        }
    }
};

    int getId() const { return id; }
    string getGuestName() const { return guestName; }
    string getCheckInDate() const { return checkInDate; }
    string getCheckOutDate() const { return checkOutDate; }
    string getRoomType() const { return roomType; }

private:

    int id;

    string guestName;

    string checkInDate;

    string checkOutDate;

    string roomType;

};

 

class Room {

public:

    Room(int number, int capacity)

    {

        this->number = number;

        this->capacity;

    }

    int getNumber() const { return number; }//function
    int getCapacity() const { return capacity; }//function

 

private:

    int number;

    string type;

    int capacity;

};

 

class Guest {

public:

    Guest(string name, string email, string phone) : name_(name), email_(email), phone_(phone) {}

 

    string getName() const { return name_; }//function

    string getEmail() const { return email_; }//function

    string getPhone() const { return phone_; }//function

 

private:

    string name_;

    string email_;

    string phone_;

};

 

class Hotel {

public:

    Hotel(string name, int numRooms) : name_(name), numRooms_(numRooms) {

        for (int i = 1; i <= numRooms_; i++) {

            rooms_.push_back(Room(i, 2));

        }

    }

private:

    string name_;

    int numRooms_;

    vector<Room> rooms_;

    map<int, Reservation> reservations_;

    map<string, Guest> guests_;

 

 

 

 

public:

   /*
    void printRooms() const

    {

        cout << "Rooms:\n";

        for (int i = 1; i <= numRooms_; i++) {

            cout << "Room " << i << "\n";

        }

    }
*/
    int book(int numR,int numRooms_){
        for (int i = 1; i <= numRooms_; i++){
            cin >> numR;

            if (numR == i){
                numRooms_ -= 1;
                return(numRooms_);
            }
        }
    }

 

    void bookRoom(int numR,string guestName, string checkInDate, string checkOutDate){
        cout << " enter the room " << endl;
        cin >> numR;

        if (numR){
            book(numR, numRooms_);
            cout << " Your room is successfully book " << endl;
            cout << "from " << checkInDate << "to " << checkOutDate << endl;
        }
    }
};