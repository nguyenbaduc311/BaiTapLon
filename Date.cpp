// Nguyen Ba Duc 20233327
#include<bits/stdc++.h>
#include<ctime>
using namespace std;

class Date{
private:
	int day,month,year;
public:
	Date(int a=1, int b=1,int c=1): day(a),month(b),year(c) {}
	void setDate(){
		while (true){
			cout << "INPUT D M Y: ";
			cin >> day >> month >> year;
			if (isValidDate()) break;
			cout << "Date does not exist" << endl;
		} 
	}
	bool isLeapYear() {
	   if (year % 4 != 0) {
	       return false;
	   } else if (year % 100 != 0) {
	       return true;
	   } else if (year % 400 != 0) {
	       return false;
	   } else {
	       return true;
	   }
	}
	bool isValidDate() {
	   if (year < 1 || month < 1 || month > 12 || day < 1) {
	       return false;
	   }
	   int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	   // Kiểm tra tháng 2 của năm nhuận
	   if (month == 2 && isLeapYear()) {
	       daysInMonth[1] = 29;
	   }
	   if (day > daysInMonth[month - 1]) {
	       return false;
	   }
	   return true;
	}

	void display(){
		cout << day << "/"<< month << "/"<<year;
	}
	bool operator==(const Date& other){
		return (day == other.day && month == other.month && year == other.year);
	}
	bool operator<(const Date& other){
		if (year<other.year) return true;
		if (year>other.year) return false;
		if (month<other.year) return true;
		if (month>other.year) return false;
		return day < other.day;
	}
	bool operator>(const Date& other){
		return !(*this < other);
	}
	~Date(){};
};

int main(){
	// time_t t = time(nullptr);
	// tm* now = localtime(&t);
	// int day = now->tm_mday;
	// int month = now->tm_mon+1;
	// int year = now->tm_year+1900;

	Date A;  
	Date B;
	A.setDate();
	B.setDate();
	if (A.isLeapYear()){
		cout << "kkk";
	} else cout <<"heheh";
	return 0;
}