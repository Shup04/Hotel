#ifndef TABLE_HPP
#define TABLE_HPP

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
#endif




/*

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
*/