#include<iostream>
#include"room.hpp"
#include<vector>
using namespace std;

//book rooms
void book(vector<room> &rooms, User &guest){
    int numOfBooking;

    cout << "!!------------Book Room----------------!!\n";
    cout << "Enter number of rooms: ";
    cin >> numOfBooking;

    for(int i=0;i<numOfBooking;i++){
        int roomNum;
        cout << "Enter room #" << i+1 << ": ";
        cin >> roomNum;
        room room = rooms[roomNum-1];
        if(room.getStatus() == "Ready"){
            rooms[i].setRoomOwner(guest);
            rooms[i].setOccupied(true);
            cout << "Room #" << roomNum << " Booked.\n";
        }
        else if(room.getStatus() == "Not Ready"){
            i--;
            cout << "Room #" << roomNum << " not ready, please enter another room.\n";
        }
    }
}

void avaialbleRooms(vector<room> &rooms){
    vector<room> availableRooms;
    
    //add rooms with ready status to new vector
    for(int i=0; i<rooms.size(); i++){
        if(rooms[i].getStatus() == "Ready"){
            availableRooms.push_back(rooms[i]);
        }
    }

    cout << "!!----------Available Rooms------------!!\n ";
    const int numRows = 20;
    const int numCols = 20;

    for (int row = 0; row < numRows; row++) {
        int startIndex = row * numCols; // calculate the index of the first element in the current row

        // ite erate through each column of the grid
        for (int col = 0; col < numCols; col++) {
            int index = startIndex + col; // calculate the index of the current element

            // print the current element of the vector
            cout << availableRooms[index].getRoomNumber() << " ";
        }
        cout << endl << " ";
    }
}

int vancover(int ticket){
	int available_seats = 71;
	int random_ticket_number = rand() % available_seats + 1; // Generate a random ticket number between 1 and available_seats
	return random_ticket_number;
}

int kelowna(int ticket){
	int available_seats = 71;
	int random_ticket_number = rand() % available_seats + 1; // Generate a random ticket number between 1 and available_seats
	return random_ticket_number;
}

void bookFlight(){

    string destination, pickup, date;
    cout << "!!------------Book Flight---------------!!\n";
	cout << " Enter destination: ";
    cin >> destination;
    cout << " Enter date: ";
    cin >> date;
    
	if (destination == "Vancouver" or " Kelowna "){
		int ticket;
		cin >> ticket;

		if (ticket < 0) {cout << "Invalid " << endl;}
		else if(ticket >72 ) {cout << " you cannot book that amount " << endl;}

		else{
			if (destination == "Vancouver"){
				for (int i = 0; i < ticket; i++) {
					int random_ticket = vancover(ticket);
					cout << "Ticket #" << i + 1 << ": " << random_ticket << endl;
				}
			}
			else{
				for (int i = 0; i < ticket; i++) {
					int random_ticket = kelowna(ticket);
					cout << "Ticket #" << i + 1 << ": " << random_ticket << endl;
				}
			}
		}
	}
	else{
		cout << " is just kelowna and vancouver we offer here " << endl;
	}
}



void displayMenu(vector<room> &rooms, User &guest){
    cout << "!!----------Hotel Managment------------!!\n";
    cout << "|          1. Book a room               |\n";           
    cout << "|          2. Check in/out              |\n";    
    cout << "|          3. Available rooms           |\n";
    cout << "|          4. Payment                   |\n";
    cout << "|          5. Feebback                  |\n";
    cout << "|          6. Table reservation         |\n";
    cout << "|          7. Book Flight               |\n";
    cout << "|          8. View current booking      |\n";
    cout << "!!-------------------------------------!!\n";

    int output;
    cin >> output;
    
    switch (output)
    {
    case 1:
        book(rooms, guest);
        break;

    case 2:
        cout << " check in/out " << endl;
        break;

    case 3:
        avaialbleRooms(rooms);

    case 7:
        bookFlight();
        break;

    default:
        break;
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

    while(true){
        displayMenu(rooms, guest1);
    }
    
}