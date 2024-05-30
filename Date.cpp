// Nguyen Ba Duc 20233327
#include<bits/stdc++.h>
#include <vector>
// #include<ctime>
using namespace std;

class Date{
private:
	int day,month,year;
public:
	Date(int a=1, int b=1,int c=1): day(a),month(b),year(c) {}
	void setDate(){
		while (true){ // Nhập ngày tháng năm, nếu ngày ko tồn tại thì nhập lại
			cout << "INPUT D M Y: ";
			cin >> day >> month >> year;
			if (isValidDate()) break;
			cout << "Date does not exist. Try again." << endl;
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

	void display() const {
		cout << day << "/"<< month << "/"<< year;
	}
	bool operator==(const Date& other){
		return (day == other.day && month == other.month && year == other.year);
	}
	bool operator<(const Date& other){
		if (year<other.year) return true;
		if (year>other.year) return false;
		if (month<other.month) return true;
		if (month>other.month) return false;
		return day < other.day;
	}
	bool operator>(const Date& other){
		return !(*this < other);
	}
	~Date(){};
};

class LstDate {
private:
	vector<Date> dates;
public:
	void addDate(Date date) {
		dates.push_back(date); // Hàm pushback là thêm phần tử vào mảng
	}
	void sort(){
		Date temp;
		for (int i=0;i<dates.size()-1;i++){
			for(int j=i;j<dates.size();j++)
			if (dates[i] > dates[j]){
				temp = dates[i];
				dates[i] = dates[j];
				dates[j] = temp; 
			}
		}
	}
	void displayDate() { // Hàm hiển thị kho hàng
		// cout << "Date List:" << endl;
		for (const auto& date : dates) { // vòng lặp lấy từng phần tử trong mảng
			date.display(); // In ra từng sản phẩm một
			cout << endl;
		}
	}
};


int main(){
	// time_t t = time(nullptr);
	// tm* now = localtime(&t);
	// int day = now->tm_mday;
	// int month = now->tm_mon+1;
	// int year = now->tm_year+1900;
	int d,m,y;

	LstDate lstdate;
	lstdate.addDate(Date(24,9,2005));
	lstdate.addDate(Date(3,11,2005));
	lstdate.addDate(Date(28,3,2005));
	lstdate.addDate(Date(27,9,2006));
	cout << "BEFORE: \n";
	lstdate.displayDate();
	lstdate.sort();
	cout << "AFTER: \n";
	lstdate.displayDate();


	return 0;
}