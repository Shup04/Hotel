#ifndef ROOM_HPP
#define ROOM_HPP

using namespace std;
#include<string>
#include<map>
#include<tuple>
#include<iomanip>

class room{
    private:
        
        int roomNumber, roomCapacity, numberOfBeds;
        string roomType, bedType; //standard, deluxe, executive, penthouse rooms
        bool occupied, isDirty, amenitiesStocked;
        string checkInDate, checkOutDate, status;

        //User roomOwner;

        
        //map each room type to capacities, bettypes ecte
        std::map<string, std::tuple<int, int, string>> roomPropertes = {

            //room type -> capacity, bednumber, bedsize
            {"Standard Room", {2, 1, "double"}},
            {"Deluxe Suite", {4, 2, "double"}},
            {"Executive Suite", {8, 4, "queen"}},
            {"Penthouse", {14, 8, "king"}}
        };
    
    public:
        //constructos
        room(int roomNumber, string roomType, bool occupied, bool isDirty, bool amenitiesStocked){
            this->roomNumber = roomNumber;
            this->roomType = roomType;
            this->occupied = occupied;
            this->isDirty = isDirty;
            this->amenitiesStocked = amenitiesStocked;

            this->checkInDate = checkInDate;
            this->checkOutDate = checkOutDate;

            //this->roomOwner = roomOwner;
            
        }
        room(){
            roomNumber = 0;
            roomType = "Standard Room";
            occupied = false;
            isDirty = false;
            amenitiesStocked = false;
        }

        void setRoomNumber(int roomNumber) {this->roomNumber = roomNumber;}
        void setRoomType(string roomType) {this->roomType = roomType;}
        void setOccupied(bool occupied) {this->occupied = occupied;}
        void setIsDirty(bool isDirty) {this->isDirty = isDirty;}
        //void setRoomOwner(User roomOwner) {this->roomOwner = roomOwner;}
        
        int getRoomNumber() const {return roomNumber;}
        string getRoomType() const {return roomType;}
        bool getOccupied() const {return occupied;}
        bool getIsDirty() const {return isDirty;}
        bool getAmenitiesStocked() const {return amenitiesStocked;}
        //User getRoomOwner() const {return roomOwner;}

        string getCheckInDate() const { return checkInDate; }
        string getCheckOutDate() const { return checkOutDate; }
        string getStatus() const {
            if((occupied == true) or (isDirty == true) or (amenitiesStocked == false)) return "Not Ready";
            else return "Ready";
        }
     

        //other functions
        int getRoomCapacity()const{ 
            return std::get<0>(roomPropertes.at(roomType));
        }
        int getNumberofBeds()const{ 
            return std::get<1>(roomPropertes.at(roomType));
        }
        string getBedType()const{ 
            return std::get<2>(roomPropertes.at(roomType));
        }
        void resetRoom(){
            occupied = isDirty = false;
        }
        void roomStatus(){
            
            cout << "!!-----------------------------!!\n";
            cout << "  Room #" << roomNumber << " information:\n\n";
            cout << "  Room Type: " << roomType << endl;
            cout << "  Beds: " << getNumberofBeds() << endl;
            cout << "  Bed Size: " << getBedType() << "\n\n";
            cout << "  Status: ";
            if((isDirty == true) or (occupied == true) or (amenitiesStocked == false)) cout << "Not Ready\n\n";
            else cout << "Ready\n\n";
            cout << "  Availability: ";
            if(occupied == true) cout << "Occupied\n";
            else cout << "Available\n";
            cout << "  Dirty: " << std::boolalpha << isDirty << endl;
            cout << "  Amenities: ";
            if(amenitiesStocked == true) cout << "Stocked\n";
            else cout << "Not Stocked\n";
            cout << "!!-----------------------------!!\n";

        }
};
#endif