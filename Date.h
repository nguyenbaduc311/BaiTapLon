#pragma once
#ifndef DATE_H
#define DATE_H

#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Date{
private:
	int day,month,year;
public:
	Date(int a=1, int b=1,int c=1): day(a),month(b),year(c) {}
	void setDate();
	bool isLeapYear();
	bool isValidDate();
	void display() const;
	Date& operator=(const Date& other);
	bool operator==(const Date& other);
	bool operator<(const Date& other);
	bool operator>(const Date& other);
	bool operator>=(const Date& other);
	bool operator<=(const Date& other);
    friend ostream& operator<<(ostream& os, const Date& dt);

	~Date(){};
};
class LstDate {
private:
	vector<Date> dates;
public:
	int size();
	void addDate(Date date);
	void swapDate(Date& a, Date& b);
	// Partition function
	int partition(int low, int high);
	// Quicksort function
	void quicksortDate(int low, int high) ;
	void displayDate();
};

#endif
