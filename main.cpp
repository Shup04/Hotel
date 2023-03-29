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
    cout << "!!-------------------------------------!!\n\n";
}

//print all available rooms
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
    cout << "!!-------------------------------------!!\n\n";
}

// collect feedback and do nothing lmao
void feedback(){ 
    string feedback;
    vector<string> feedbackList;
    cout << "What is your feedback: ";
    cin >> feedback;
    feedbackList.push_back(feedback);
}

//generate tickets
int vancover(){
	int available_seats = 72;
	int random_ticket_number = rand() % available_seats + 1; // Generate a random ticket number between 1 and available_seats
	return random_ticket_number;
}
int kelowna(){
	int available_seats = 72;
	int random_ticket_number = rand() % available_seats + 1; // Generate a random ticket number between 1 and available_seats
	return random_ticket_number;
}

//print tickets booked
void bookFlight(){

    string destination, date;
    int ticket;
    cout << "!!------------Book Flight---------------!!\n";
	cout << " Enter destination: ";
    cin >> destination;
    
    
	if (destination == "Vancouver" or " Kelowna "){
        cout << " Enter date: ";
        cin >> date;
        cout << " Enter # of tickets to buy: ";
        cin >> ticket;

		if (ticket < 0) {cout << "Invalid " << endl;}
		else if(ticket >72 ) {cout << " you cannot book that amount " << endl;}

		else{
			if (destination == "Vancouver"){
				for (int i = 0; i < ticket; i++) {
					int random_ticket = vancover();
					cout << "Ticket #" << i + 1 << ": " << random_ticket << endl;
				}
			}
			else{
				for (int i = 0; i < ticket; i++) {
					int random_ticket = kelowna();
					cout << "Ticket #" << i + 1 << ": " << random_ticket << endl;
				}
			}
		}
	}
	else{
		cout << " is just kelowna and vancouver we offer here " << endl;
	}
    cout << "!!-------------------------------------!!\n\n";
}

void viewBooking(vector<room> &rooms, User &guest){
    for(const auto& room : rooms){
        cout << "!!-------------------------------------!!\n\n";
        cout << " Your bookings:\n";
        // find what rooms the user owns and execute
        cout << room.getRoomOwner().getName() << endl;
        cout << guest.getName() << endl;
        if(room.getRoomOwner().getName() == guest.getName()){
            cout << "Room #" << room.getRoomNumber() << endl;
        }
    }
    rooms;
}

void displayMenu(vector<room> &rooms, User &guest){

    bool reset = false;
    
    while(!reset){
        cout << "!!----------Hotel Managment------------!!\n";
        cout << "|          1. Book a room               |\n"; // done    
        cout << "|          2. Check in/out              |\n";    
        cout << "|          3. Available rooms           |\n"; // done
        cout << "|          4. Payment                   |\n";
        cout << "|          5. Feedback                  |\n"; // done
        cout << "|          6. Table reservation         |\n";
        cout << "|          7. Book Flight               |\n"; // done
        cout << "|          8. View current booking      |\n";
        cout << "|          9. Exit                      |\n"; // done
        cout << "!!-------------------------------------!!\n\n";

        int output;
        cin >> output;

        switch (output)
        {
        case 1: // room booking
            book(rooms, guest);
            break;

        case 2: // check into room and set checkout time
            cout << " check in/out " << endl;
            break;

        case 3: // print  available rooms
            avaialbleRooms(rooms);
            break;

        case 6: // book table


        case 7: // book flight tickets
            bookFlight();
            break;

        case 8:
            viewBooking(rooms, guest);
            break;

        case 9:
            reset = true;
            break;
        default:
            break;
        }
    }
     
}


int main(){
    
    const int numOfRooms = 400;
    vector<room> rooms;//vector of all rooms

    //store all rooms
    for(int i=0; i<numOfRooms; i++){
        rooms.push_back(room(i+1, "Standard Room", false, false, true));
    }

    vector<User> users; // vector of all users

    User user1("Bradley", "BradleySchmidt04@gmail.com", "778-586-8196");
    User user2("John", "JohnDoe@gmail.com", "778-420-6969");

    users.push_back(user1);
    users.push_back(user2);

    rooms.at(5).setIsDirty(true);

    while(true){
        string name;
        cout << "Enter guest name: ";
        cin >> name;

        bool userFound = false;
        User guest;
        for(const auto& user : users){
            if(user.getName() == name){
                guest = user;
                userFound = true;
                break;
            }
        }
        if(!userFound){
            string email, phone;
            cout << "Enter email: ";
            cin >> email;
            cout << "Enter phone: ";
            cin >> phone;
            guest = User(name, email, phone);
        }

        displayMenu(rooms, guest);
    }
    
}