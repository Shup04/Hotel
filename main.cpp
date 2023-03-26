#include<iostream>
#include"room.hpp"
#include<vector>
using namespace std;


int checkAvailable(int numOfBooking, int roomNum, vector<room> rooms){
    for (int i = 1; i <= numOfBooking; i++){

        if (rooms.at(roomNum+1)){
            numOfBooking -= 1;
            return(roomNumber);
        }
    }
}


void bookRoom(int numOfBooking, int roomNum, vector<room> rooms){
    room room = rooms.at(roomNum+1);

    if (checkAvailable(numOfBooking, room.getRoomNumber()) == true){
        book(numR, room.getRoomNumber());

        cout << " Your room is successfully book " << endl;
        cout << "from " << room.getCheckInDate() << "to " << room.getCheckOutDate() << endl;
    }
}



void displayMenu(vector<room> rooms){
    cout << "!!----------Hotel Managment------------!!\n";
    cout << "|          1. Book a room               |\n";           
    cout << "|          2. Check in/out              |\n";    
    cout << "|          3. Available rooms           |\n";
    cout << "|          4. Payment                   |\n";
    cout << "|          5. Feebback                  |\n";
    cout << "|          6. Table reservation         |\n";
    cout << "|          7. View current booking      |\n";
    cout << "!!-------------------------------------!!\n";
    while(true)
    {
        int output;
        cin >> output;
        while(true)
        {
            switch (output)
            {
            case 1:
                int roomNum, numOfBooking;

                cout << "!!------------Book Room----------------!!\n";
                cout << "Enter number of rooms: ";
                cin >> numOfBooking;

                cout << "Enter room number: ";
                cin >> roomNum;

                bookRoom(numOfBooking, roomNum, rooms);

                break;

            case 2:

                cout << " check in/out " << endl;
                break;


            default:
                break;
            }
            break;
        }
    }
  
    
    
}



int main(){
    
    const int numOfRooms = 400;

    vector<room> rooms;//vector of all floors

    //store all floors in a vector
    for(int i=0; i<numOfRooms; i++){
        rooms.push_back(room(i+1, "Standard Room", false, false, true));
    }

    //floors.at(2).at(20).roomStatus();

    displayMenu(rooms);
    
}