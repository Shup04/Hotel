#include<iostream>
#include"room.hpp"
#include<vector>
using namespace std;

void book(vector<room> rooms, User guest){
    int roomNum, numOfBooking;

    cout << "!!------------Book Room----------------!!\n";
    cout << "Enter number of rooms: ";
    cin >> numOfBooking;

    cout << "Enter room number: ";
    cin >> roomNum;

    /*
    if room is ready, add user to room object and to vector of booked rooms, increment.
    if room is not ready, increment.
    if number of rooms booked equal to desired, break.
    */
    vector<int> roomsBooked;

    while(roomsBooked.size() != numOfBooking){
        room room = rooms.at(roomNum-1);
        if(room.getStatus() == "Ready"){
            cout << roomsBooked.size() << endl;
            room.setRoomOwner(guest);
            roomsBooked.push_back(room.getRoomNumber());
            roomNum++;
        }
    }





    //print booked rooms
    /*
    if (booked) {
        cout << "Rooms booked successfully!\n";
        cout << "Booked rooms:\n";
        for(int i=0;i<numOfBooking;i++){
            cout << "#" << bookedRooms.at(i) << endl;
        }
    } else {
        cout << "Sorry, the room(s) are not available.\n";
    }
    */
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
                
                book(rooms, guest);

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

    rooms.at(5).setIsDirty(true);

    displayMenu(rooms, guest1);
    
}