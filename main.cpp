#include<iostream>
#include"room.hpp"
#include<vector>
using namespace std;


void book(int numOfBooking, int roomNum, vector<room> &rooms, User guest){

    bool booked = false;
    int i=0, j=0;
    while(!booked){
        int roomsBooked[numOfBooking];
        if (rooms.at(roomNum+i).getStatus() == "Ready"){
            rooms.at(roomNum+i).setRoomOwner(guest);
            roomsBooked[j] = rooms.at(roomNum+i).getRoomNumber();
            j++;
        }

        if(j == numOfBooking){
            cout << "Rooms Booked:\n";
            for(int k=0; k<numOfBooking; k++){
                cout << "#" << roomsBooked[k] << endl;
            }
        }
        i++;
    }
}




void displayMenu(vector<room> rooms, User guest){
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

                book(numOfBooking, roomNum, rooms, guest);

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
    User guest1("Bradley", "BradleySchmidt04@gmail.com", "778-586-8196");

    displayMenu(rooms, guest1);
    
}