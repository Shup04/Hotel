#include <iostream>
#include <vector>
using namespace std;

class Table {
public:
	int table_number;
	bool is_reserved;
	string username;
	Table(int table_number, string username) {
		this->table_number = table_number;
		this->username = username;
	}
};

vector<int> tables[10];

void booktable(int table_number)
{
	tables[table_number - 1].push_back(table_number);
}

bool available(int table_number)
{
	if (tables[table_number - 1].empty()) {
		return true;
	}
	else {
		return false;
	}
}

void book()
{
	cout << "Enter the table number you want to book from 1 to 10: ";
	int table;
	cin >> table;
	if (table < 1 || table > 10) {
		cout << "Invalid table number!" << endl;
		return;
	}
	if (available(table)) {
		cout << "Your booking is complete!" << endl;
		booktable(table);
	}
	else {
		cout << "Sorry, the table is already booked!" << endl;
		cout << "Available tables: ";
		for (int p = 0; p < 10; p++) {
			if (available(p + 1)) {
				cout << (p + 1) << " ";
			}
		}
		cout << endl;
	}
}

int main()
{
	while (true) {
		cout << "1. Book table" << endl;
		cout << "2. Exit" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			book();
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