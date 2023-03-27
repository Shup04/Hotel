#include <iostream>
#include <vector>
#include<string>
#include <ctime>;
using namespace std;

int vancoverseat(int ticket){
	int available_seats = 71;
	int random_ticket_number = rand() % available_seats + 1; // Generate a random ticket number between 1 and available_seats
	return random_ticket_number;
}
int kelowna(int ticket){
	int available_seats = 71;
	int random_ticket_number = rand() % available_seats + 1; // Generate a random ticket number between 1 and available_seats
	return random_ticket_number;
}

void bookFlight(string destination, string pickup, string date){
	cout << " How may ticket do you want to purchase " << endl;
	if (destination == "Vancouver" or " Kelowna "){
		int ticket;
		cin >> ticket;

		if (ticket < 0) {cout << "Invalid " << endl;}
		else if(ticket >72 ) {cout << " you cannot book that amount " << endl;}

		else{
			if (destination == "Vancouver"){
				for (int i = 0; i < ticket; i++) {
					int random_ticket = vancoverseat(ticket);
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


void input(){
	
	cout << "enter the destination " << endl;
	string destination;
	cin>> destination;
	cout << "enter the pickup " << endl;
	string pickup;
	cin>> pickup;
	cout << "enter the date " << endl;
	string date;
	cin>>date;
	bookFlight(destination, pickup, date);
}

int main(){
	while (true) {
		cout << "1. Book Flight" << endl;
		cout << "2. Exit" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			input();
			break;

		case 2:
			return 0;

		default:
			cout << "Invalid choice!" << endl;
			break;
		}
	}
	return 0;
}