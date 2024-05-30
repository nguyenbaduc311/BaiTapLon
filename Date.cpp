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
	bool operator>=(const Date& other){
		return (*this > other || *this == other);
	}
	bool operator<=(const Date& other){
		return (*this < other || *this == other);
	}

	~Date(){};
};

class LstDate {
private:
	vector<Date> dates;
public:
	int size(){
		return dates.size();
	}
	void addDate(Date date) {
		dates.push_back(date); // Hàm pushback là thêm phần tử vào mảng
	}
	void swapDate(Date& a, Date& b) {
	    Date temp = a;
	    a = b;
	    b = temp;
	}

	// Partition function
	int partition(int low, int high) {
	    Date pivot = dates[high]; // pivot element
	    int i = low - 1; // index of the smaller element

	    for (int j = low; j <= high - 1; j++) {
	        // If the current element is smaller than or equal to the pivot
	        if (dates[j] <= pivot) {
	            i++; // increment the index of the smaller element
	            swapDate(dates[i], dates[j]); // swapDate elements
	        }
	    }
	    swapDate(dates[i + 1], dates[high]); // swapDate the pivot element with the element at i+1
	    return (i + 1); // return the partitioning index
	}

	// Quicksort function

	void quicksortDate(int low, int high) {
	    if (low < high) {
	        int pi = partition(low, high); // partitioning index

	        quicksortDate(low, pi - 1); // recursively sort elements before partition
	        quicksortDate(pi + 1, high); // recursively sort elements after partition
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
	lstdate.addDate(Date(27,9,2007));
	lstdate.addDate(Date(27,9,2006));
	cout << "BEFORE: \n";
	lstdate.displayDate();
	lstdate.quicksortDate(0,lstdate.size()-1);
	cout << "AFTER: \n";
	lstdate.displayDate();


	return 0;
}