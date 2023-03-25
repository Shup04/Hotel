using namespace std;
#include<string>
#include<map>
#include<tuple>

class room{
    private:
        
        int roomNumber, roomCapacity, numberOfBeds;
        string roomType, bedType; //standard, deluxe, executive, penthouse rooms
        bool occupied, isDirty, amenitiesStocked;

        //map each room type to capacities, bettypes ecte
        const std::map<string, std::tuple<int, int, string>> roomPropertes = {

            //room type -> capacity, bednumber, bedsize
            {"Standard Room", {2, 1, "double"}},
            {"Deluxe Suite", {4, 2, "double"}},
            {"Executive Suite", {8, 4, "queen"}},
            {"Penthouse", {14, 8, "king"}}
        };

    
    public:
        //constructos
        room(int roomNumber, string roomType, bool occupied){
            this->roomNumber = roomNumber;
            this->roomType = roomType;
            this->occupied = occupied;
        }
        room(){
            roomNumber = 0;
            roomType = "Standard Room";
            occupied = false;
            isDirty = false;
            amenitiesStocked = false;
        }
        //set and get
        void setRoomNumber(int &roomNumber) {this->roomNumber = roomNumber;}
        void setRoomType(string &roomType) {this->roomType = roomType;}
        void setOccupied(bool &occupied) {this->occupied = occupied;}
        void setIsDirty(bool &isDirty) {this->isDirty = isDirty;}
        
        int getRoomNumber() {return roomNumber;}
        string getRoomType() {return roomType;}
        bool getOccupied() {return occupied;}
        bool getIsDirty() {return isDirty;}
        bool getAmenitiesStocked() {return amenitiesStocked;}

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
            cout << "  Status: \n\n";
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