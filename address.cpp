#include<bits/stdc++.h>
#include "Address.h"
using namespace std;

string Address::getEmail() const {
	return email;
}
void Address::setEmail(const string& email) {
	this->email = email;
}
string Address::getAddress() const {
	return address;
}
void Address::setAddress(const string& address) {
	this->address = address;
}
string Address::getPhoneNumber() const {
	return phoneNumber;
}
void Address::setPhoneNumber(const string& phoneNumber) {
	this->phoneNumber = phoneNumber;
}
void Address::display() const {
	cout << "Email: " << email << " | "
		 << "Address: " << address << " | "
		 << "Phone Number: " << phoneNumber << endl;
}
// int main() {
// 	Address address1("example@example.com", "123 Main St", "123-456-7890");

// 	address1.display();

// 	Address address2;
// 	string line;
// 	getline(cin,line);
// 	address2.setEmail(line);
// 	address2.setAddress("456 Elm St");
// 	address2.setPhoneNumber("0365066311");

// 	address2.display();

// 	return 0;
// }

