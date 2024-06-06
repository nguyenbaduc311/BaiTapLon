#pragma once
#include<bits/stdc++.h>
using namespace std;

class Address { //tao lop dia chi  
private:
	string email;
	string address;
	string phoneNumber;
public:
	Address(const string& email, const string& address, const string& phoneNumber) //ham tao truyen 3 tham so 
		: email(email), address(address), phoneNumber(phoneNumber) {}  //Lenh gan 
	Address() : email(""), address(""), phoneNumber("") {} // Ham tao khoi tao bien thanh vien rong 
	
	//ham lay
	string getEmail() const;
	string getAddress() const;
	string getPhoneNumber() const;
	
	//ham gan
	void setEmail(const string& email);
	void setAddress(const string& address);
	void setPhoneNumber(const string& phoneNumber);
	
	//ham hien thi
	void display() const; 
};
