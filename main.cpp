// FILE CHÍNH
#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
#include <sstream>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <Windows.h>

using namespace std;

// làm màu
void SET_COLOR(int color){
	WORD wColor;
    
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}
// Các hàm xử lí chuỗi ( chủ yếu là làm màu )
bool isValidInteger(const string& str) {// Kiểm tra nếu chuỗi rỗng hoặc không phải là số hợp lệ
    if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+'))) return false; // Nếu ký tự đầu tiên không phải là số, dấu trừ, hoặc dấu cộng, hàm trả về false.
    char * p; 
    strtol(str.c_str(), &p, 10); // Hàm strtol chuyển đổi chuỗi str thành số nguyên theo cơ số 10. p sẽ trỏ đến ký tự đầu tiên trong chuỗi mà không thể chuyển đổi được 
    return (*p == 0); // Kiểm tra nếu không còn ký tự nào khác sau số
}
void removeBOM(string &str) {
	if (str.size() >= 3 && str[0] == (char)0xEF && str[1] == (char)0xBB && str[2] == (char)0xBF) {
		str.erase(0, 3);
	}
}
vector<string> split(const string &str, char del) { // Hàm split được dùng để chia một chuỗi str thành các phần tử con dựa trên ký tự phân tách del
	vector<string> tokens;
	string token;
	istringstream tokenStream(str); // istringstream là một luồng đầu vào từ chuỗi, giúp sử dụng hàm getline để đọc từng phần của chuỗi.
	while (getline(tokenStream, token, del)) { // Đọc từ tokenStream đến khi gặp ký tự phân tách del
		tokens.push_back(token); // Mỗi lần đọc được một phần tử con, nó được lưu vào token
	}
	return tokens;
}
string center(const string& str, int width) { // căn cho chữ ở giữa 
    int len = str.length();
    if (width <= len) return str;
    int leftPadding = (width - len) / 2;
    int rightPadding = width - len - leftPadding;
    return string(leftPadding, ' ') + str + string(rightPadding, ' ');
}
string truncateName(const string& name, size_t width) {
	if (name.length() > width) {
		return name.substr(0, width - 3) + "...";
	} else {
		return name;
	}
}
void clearInputBuffer() { // Xóa bộ đệm
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa tối ưu hơn thôi.
}
void VND(long long price){
	long long giaTien = price;
	int i = 1,j=0;
	char c[20];
	char d[20];
	while (giaTien>0){
		c[j++] = giaTien%10 + 48;
		giaTien = giaTien/10;
		if (i%3 ==0 && giaTien >0){
			c[j++] = 46;
		}
		i++;
	}
	string p = "";
	while (j--) p += c[j];
	p += " VND";
	cout << p;
}

// hàm hiển thị
void display5info(){
	cout << left << "|" << setw(15) << center("Product Code", 15)
	             << "|" << setw(25) << center("Name", 25)
	             << "|" << setw(10) << center("Quantity", 10)
	             << "|" << setw(15) << center("Price", 15)
	             << "|" << setw(20) << center("Total Value", 20)
				 << "|"
				 << endl;
	cout << string(91, '-') << endl;
}
void display6info(){
	cout << left << "|" << setw(12) << center("Product Code", 12)
	             << "|" << setw(22) << center("Name", 22)
	             << "|" << setw(10) << center("Quantity", 10)
	             << "|" << setw(15) << center("Price", 15)
	             << "|" << setw(10) << center("Date", 10)
	             << "|" << setw(25) << center("Email", 25)
	             << "|" << setw(20) << center("Address", 20)
	             << "|" << setw(11) << center("Phone", 11)
	             << "|" << endl;
	cout << string(134, '-') << endl;
}
void displayFileIO(string file,string name){
	system("cls");
	ifstream inputFileNhap(file);
	
	string line;
	vector<vector<string>> tokens;

	if (getline(inputFileNhap, line)) {
		removeBOM(line);
		vector<string> token = split(line, ',');
		tokens.push_back(token);
	}
	// Read lines from the input file
	while (getline(inputFileNhap, line)) {
		vector<string> token = split(line, ',');
		tokens.push_back(token);
	}
	cout << "\n\t\t\t\t\t\t          "<< name << endl;
	cout << "\t\t\t\t\t       ============================" << endl << endl;
	display6info();

	for (const auto &token : tokens) {
		cout << left << "|" << setw(12) << token[0] // code
					 << "|" << setw(22) << truncateName(token[1], 22) // name
			 << right<< "|" << setw(10) << token[2] // quantity
					 << "|" << setw(15); VND(stoll(token[3])); // price
		cout << right << "|" << setw(10) << token[4]	 // date
					  << "|" << setw(25) << truncateName(token[5],25)     // email
					  << "|" << setw(20) << truncateName(token[6],20)    // address
						  << "|" << setw(11) << token[7] // phone
						  << "|" ; 		
		cout << endl;
	}

	inputFileNhap.close();
}

// OOP
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
	// ham nhap
	void setInfoAddress();
	void setInfoAddress(string a,string b,string c);
	//ham gan
	void setEmail(const string& email);
	void setAddress(const string& address);
	void setPhoneNumber(const string& phoneNumber);
	friend ostream& operator<<(ostream& os, const Address& addr);
	//ham hien thi
	void display() const; 
};

class Date{
private:
	int day,month,year;
public:
	Date(int a=1, int b=1,int c=1): day(a),month(b),year(c) {}
	void setDate();
	void setDate(string date);
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

class Transaction {
private:
	string type; // "import" or "export"
	int quantity;
	long long price; // Price per unit at the time of transaction
	Date date; // Date of transaction
	Address address;
public:
	Transaction(string type, int quantity, long long price, Date date,Address address)
		: type(type), quantity(quantity), price(price), date(date), address(address) {}
	void display() const;
};

class Product { // tạo Đối tượng "sản phẩm"
private:
	string name; // TÊN sản phẩm
	string code; // MÃ ĐỊNH DANH (mỗi sản phẩm phải có 1 mã khác nhau)
	int quantity; // SỐ LƯỢNG sản phẩm
	long long price; // ĐƠN GIÁ của 1 sản phẩm, vì là VNĐ nên để long long
	vector<Transaction> transactions;
public:
	Product(string c,string n, int q, long long p) // hàm tạo, phải có đủ 4 tham số truyền vào
		:  code(c), name(n), quantity(q), price(p) {} // lệnh gán
	void addTransaction(const Transaction& transaction);
	void displayTransactions() const;
	string getName(); // Các hàm lấy và gán
	string getCode();
	int getQuantity();
	long long getPrice();
	long long int getTotalValue() const;
	void setName(string a);
	void setCode(string b);
	void setQuantity(int c);
	void setPrice(long long d);
	void display() const;
};

class Inventory { // tạo đối tượng kho hàng (để quản lí đối tượng sản phẩm)
private:
	vector<Product> products; // Tạo 1 mảng có kiểu dữ liệu là "đối tượng <Product> "

	int findProductIndexByCode(string code);
	void writeFileIO(string file,Product product,int quantity,Date A, Address B);
	void writeFileInventory(string file,Product product);
public:
	void swapProduct(Product& a, Product& b);
	void inputFileInventory(string file);
	void inputFileIO(string file);
	void updateFileInventory(string file);
	void addProduct(Product product);
	void removeProduct(string code);
	void importProduct(string code, int quantity);
	void editNameProduct(string code, string name);
	void editPriceProduct(string code, long long price);
	void exportProduct(string code, int quantity);
	void errorProduct(string code, int quantity);
	void searchProductByName(string name);
	void searchProductByCode(string code);
	void calculateTotalValue();
	int size();
	int partition(int low,int high);
	void quicksortProduct(int low,int high);
	void displayProductTransactions(string code);
	void displayInventory();
};

// ADDRESSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
void Address::setInfoAddress(){
	cout << "Enter email: ";
	clearInputBuffer(); // Nhớ xóa bộ đệm , trước khi nhập dữ liệu 
	getline(cin, email);
	cout << "Enter address: ";
	getline(cin, address);
	cout << "Enter phone number: ";
	getline(cin, phoneNumber);
}
void Address::setInfoAddress(string a,string b,string c){ 
	email = a;
	address = b;
	phoneNumber = c;
}
string Address::getEmail() const {
	return email;  // tra ve gia tri bien thanh vien email
}
void Address::setEmail(const string& email) {
	this->email = email;  //gan gia tri cua doi so cho email
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
ostream& operator<<(ostream& os, const Address& addr) {
    os << addr.email << "," << addr.address << "," << addr.phoneNumber;
    return os;
}
// DATEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
void Date::setDate(){
	while (true){ // Nhập ngày tháng năm, nếu ngày ko tồn tại thì nhập lại
		cout << "Enter dd/mm/yy: ";
		cin >> day >> month >> year;
		if (isValidDate()) break;
		cout << "Date does not exist. Try again." << endl;
	} 
}
void Date::setDate(string date){
    vector<string> token = split(date, '/');
    day = stoi(token[0]);
    month = stoi(token[1]);
    year = stoi(token[2]);
}
bool Date::isLeapYear() {
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
bool Date::isValidDate() {
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
void Date::display() const {
	cout << setw(2) << setfill('0') << day << '/'
		  << setw(2) << setfill('0') << month << '/'
		  << year ;
}
Date& Date::operator=(const Date& other) {
	if (this != &other) {
		day = other.day;
		month = other.month;
		year = other.year;
	}
	return *this;
}
bool Date::operator==(const Date& other){
	return (day == other.day && month == other.month && year == other.year);
}
bool Date::operator<(const Date& other){
	if (year<other.year) return true;
	if (year>other.year) return false;
	if (month<other.month) return true;
	if (month>other.month) return false;
	return day < other.day;
}
bool Date::operator>(const Date& other){
	return !(*this < other);
}
bool Date::operator>=(const Date& other){
	return (*this > other || *this == other);
}
bool Date::operator<=(const Date& other){
	return (*this < other || *this == other);
}
ostream& operator<<(ostream& os, const Date& dt) {
    os << setw(2) << setfill('0') << dt.day << "/"
       << setw(2) << setfill('0') << dt.month << "/"
       << setw(4) << setfill('0') << dt.year << setfill(' '); 
    return os;
}
// TRANSACTIONNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
void Transaction::display() const {
	cout << left << "|" << setw(8) << center(type, 8)
		 <<	right<< "|" << setw(8) << quantity
		         << "|" << setw(15); VND(price);
	cout << right<< "|" << setw(10) << date 
	             << "|" << setw(25) << address.getEmail()
	             << "|" << setw(30) << truncateName(address.getAddress(),30)
	             << "|" << setw(12) << center(address.getPhoneNumber(),12); 
	cout << "|";
	cout << endl;
}
// PRODUCTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
void Product::addTransaction(const Transaction& transaction) {transactions.push_back(transaction);}
void Product::displayTransactions() const {
	if (transactions.empty()) {
		cout << "No transactions found for this product." << endl;
	} else {
		cout << "\n\t\t\t\t Transactions for " << name << endl << endl;
		cout << left << "|" << setw(8) << center("Type", 8)
		             << "|" << setw(8) << center("Quantity", 8)
		             << "|" << setw(15) << center("Price", 15)
		             << "|" << setw(10) << center("Date", 10)
		             << "|" << setw(25) << center("Email", 25)
		             << "|" << setw(30) << center("Address", 30)
		             << "|" << setw(12) << center("Phone", 12)
		             << "|" << endl;
		cout << string(116, '-') << endl;
		for (const auto& transaction : transactions) {
			transaction.display();
		}
	}
}
string Product::getName() { return name; } // Các hàm lấy và gán
string Product::getCode() { return code; }
int Product::getQuantity() { return quantity; }
long long Product::getPrice() { return price; }
long long int Product::getTotalValue() const { return price * quantity; }
void Product::setName(string a) { name = a; }
void Product::setCode(string b) { code = b; }
void Product::setQuantity(int c) { quantity = c; }
void Product::setPrice(long long d) { price = d; }
void Product::display() const { // hàm hiển thị các thông số của sản phẩm
	cout << left << "|" << setw(15) << code
				 << "|" << setw(25) << truncateName(name, 25)
		 << right<< "|" << setw(10) << quantity
				 << "|" << setw(15); VND(price); 
	cout << right << "|" << setw(20); VND(getTotalValue());
	cout << "|";
	cout << endl;
}
// INVENTORYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
int Inventory::findProductIndexByCode(string code) { // Tìm vị trí của sản phẩm trong mảng sản phẩm
	for (int i = 0; i < products.size(); i++) { // size() là số phần tử đang có trong mảng
		if (products[i].getCode() == code) {
			return i;
		}
	}
	return -1; // Không tìm thấy thì trả về -1
}
void Inventory::writeFileIO(string file,Product product,int quantity,Date A, Address B){
	ofstream outputFile;
	outputFile.open(file,ios::app); // ghi đè
	outputFile << product.getCode() << "," << 
				  product.getName() << "," << 
				  product.getQuantity() << "," << 
				  product.getPrice() << "," <<
				  A << "," << 
				  B << endl;

	outputFile.close();
}
void Inventory::writeFileInventory(string file,Product product){
	ofstream outputFile;
	outputFile.open(file,ios::app); // ghi đè
	outputFile << product.getCode() << "," << 
				  product.getName() << "," << 
				  product.getQuantity() << "," << 
				  product.getPrice() << endl;
	outputFile.close();
}
void Inventory::swapProduct(Product& a, Product& b) {
	Product temp = a;
	a = b;
	b = temp;
}
void Inventory::addProduct(Product product) { // Hàm thêm sản phẩm mới
	int index = findProductIndexByCode(product.getCode());
	if (index == -1) { // Nếu ko có mặt hàng này thì mới thêm vào mảng
		products.push_back(product); // Hàm pushback là thêm phần tử vào mảng
		cout << "\n--> Product added successfully." << endl;
	}
	else {
		cout << "\n--> Product with this code already exists." << endl;
	}
}
void Inventory::removeProduct(string code) { // Hàm xóa sản phẩm khỏi kho
	int index = findProductIndexByCode(code);
	if (index != -1) { // erase(*địa chỉ cần xóa*) : để xóa sản phẩm
		products.erase(products.begin() + index); // begin() là lấy vị trí con trỏ đầu tiên của mảng
		cout << "\n--> Product removed successfully." << endl;
	}
	else {
		cout << "\n--> Product not found." << endl;
	}
}
void Inventory::importProduct(string code, int quantity) { // Tìm sản phẩm rồi thêm số lượng sản phẩm
	int index = findProductIndexByCode(code);
	if (index != -1) {
		products[index].setQuantity(products[index].getQuantity() + quantity); // Thêm số lượng
		Date A; A.setDate(); Address B; B.setInfoAddress();
		Transaction transaction("Import", quantity, products[index].getPrice(), A,B);
		products[index].addTransaction(transaction);
		cout << "\n--> Product imported successfully." << endl;
	}
	else {
		cout << "\n--> Product not found." << endl;
	}
}
void Inventory::editNameProduct(string code, string name) { // Sửa thông số của sản phâm (tên, giá)
	int index = findProductIndexByCode(code);
	if (index != -1) {
		products[index].setName(name); // SỬa lại tên
		cout << "\n--> Product edited successfully." << endl;
	}
	else {
		cout << "\n--> Product not found." << endl;
	}
}
void Inventory::editPriceProduct(string code,long long price) { // Sửa thông số của sản phâm (tên, giá)
	int index = findProductIndexByCode(code);
	if (index != -1) {
		products[index].setPrice(price); // Sửa lại giá
		cout << "\n--> Product edited successfully." << endl;
	}
	else {
		cout << "\n--> Product not found." << endl;
	}
}
void Inventory::exportProduct(string code, int quantity) { // Xuất hàng 
	int index = findProductIndexByCode(code);
	if (index != -1) {
		if (products[index].getQuantity() >= quantity) { // check xem có đủ lượng hàng để xuất hàng ko
			products[index].setQuantity(products[index].getQuantity() - quantity); // Giảm số lượng
			Date A; A.setDate(); Address B; B.setInfoAddress();
			Transaction transaction("Export", quantity, products[index].getPrice(), A,B);
			products[index].addTransaction(transaction);
			cout << "\n--> Product exported successfully." << endl;
		}
		else {
			cout << "\n--> Not enough quantity in stock." << endl;
		}
	}
	else {
		cout << "\n--> Product not found." << endl;
	}
}
void Inventory::errorProduct(string code, int quantity) { // Vứt bỏ hàng lỗi ra khỏi kho
	int index = findProductIndexByCode(code);
	if (index != -1) {
		if (products[index].getQuantity() >= quantity) { // check xem có đủ lượng hàng để trừ ko
			products[index].setQuantity(products[index].getQuantity() - quantity); // Giảm số lượng hàng hỏng
			cout << "\n--> Error Product removed successfully." << endl;
		}
		else {
			cout << "\n--> Not enough quantity in stock." << endl;
		}
	}
	else {
		cout << "\n--> Product not found." << endl;
	}
}
void Inventory::calculateTotalValue() {
	long long int totalValue = 0;
	for (const auto& product : products) {
		totalValue += product.getTotalValue();
	}
	cout << "\n--> Total Current Inventory Value: " ;VND(totalValue);
	cout << endl;
}
int Inventory::size(){
	return products.size();
}
int Inventory::partition(int low, int high) {
    Product pivot = products[high]; // pivot element
    int i = low - 1; // index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (products[j].getTotalValue() >= pivot.getTotalValue()) {
            i++; // increment the index of the smaller element
            swapProduct(products[i], products[j]); // swapproduct elements
        }
    }
    swapProduct(products[i + 1], products[high]); // swap the pivot element with the element at i+1
    return (i + 1); // return the partitioning index
}
void Inventory::quicksortProduct(int low, int high) {
    if (low < high) {
        int pi = partition(low, high); // partitioning index

        quicksortProduct(low, pi - 1); // recursively sort elements before partition
        quicksortProduct(pi + 1, high); // recursively sort elements after partition
    }
}
void Inventory::displayInventory() { // Hàm hiển thị kho hàng
	if (products.empty()) {
		cout << "\n--> Inventory is empty." << endl;
	}
	else {
		cout << "\t\t\t-Current Inventory-\n\n" ;
		display5info();
		for (const auto& product : products) {
			product.display();
		}
	}
}
void Inventory::displayProductTransactions(string code) {
	int index = findProductIndexByCode(code);
	if (index != -1) {
		products[index].displayTransactions();
	} else {
		cout << "Product not found." << endl;
	}
}
void Inventory::searchProductByName(string name) {
	bool found = false;
	for (auto& product : products) {
		if (product.getName() == name) {
			display5info();
			product.display();
			found = true;
		}
	}
	if (!found) {
		cout << "Product not found." << endl;
	}
}
void Inventory::searchProductByCode(string code) {
	int index = findProductIndexByCode(code);
	if (index != -1) {
		display5info();
		products[index].display();
	} else {
		cout << "Product not found." << endl;
	}
}
void Inventory::inputFileInventory(string file){
	products.clear();
	ifstream inputFileKho(file);

	if (!inputFileKho.is_open()) {
	}
	
	string line;
	vector<vector<string>> tokens;

	if (getline(inputFileKho, line)) { 
		removeBOM(line);
		vector<string> token = split(line, ',');
		int index = findProductIndexByCode(token[0]);
		if (index == -1) { // Nếu ko có mặt hàng này thì mới thêm vào mảng
			products.push_back(Product(token[0], token[1],stoi(token[2]),stoll(token[3]))); 
		}
	}
	// Read lines from the input file
	while (getline(inputFileKho, line)) {
		vector<string> token = split(line, ',');
		int index = findProductIndexByCode(token[0]);
		if (index == -1) { // Nếu ko có mặt hàng này thì mới thêm vào mảng
			products.push_back(Product(token[0], token[1],stoi(token[2]),stoll(token[3]))); 
		}
	}

	inputFileKho.close(); 
}
void Inventory::inputFileIO(string file){
	ifstream inputFileKho(file);

	if (!inputFileKho.is_open()) {
	}
	
	string line;
	vector<vector<string>> tokens;
	vector<string> headline = split(file,'.') ;

	if (getline(inputFileKho, line)) { 
		removeBOM(line);
		vector<string> token = split(line, ',');
		int index = findProductIndexByCode(token[0]);
		if (index != -1) { // Nếu ko có mặt hàng này thì mới thêm vào mảng
			Date A; A.setDate(token[4]); Address B; B.setInfoAddress(token[5],token[6],token[7]);
			Transaction transaction(headline[0], stoi(token[2]), stoll(token[3]), A, B);
			products[index].addTransaction(transaction);
		}
	}
	// Read lines from the input file
	while (getline(inputFileKho, line)) {
		vector<string> token = split(line, ',');
		int index = findProductIndexByCode(token[0]);
		if (index != -1) { // Nếu ko có mặt hàng này thì mới thêm vào mảng
			Date A; A.setDate(token[4]); Address B; B.setInfoAddress(token[5],token[6],token[7]);
			Transaction transaction(headline[0], stoi(token[2]), stoll(token[3]), A, B);
			products[index].addTransaction(transaction); 
		}
	}

	inputFileKho.close(); 
}
void Inventory::updateFileInventory(string file){
	ofstream outputFile(file); // mở rồi đóng để xóa dữ liệu trong file
	outputFile.close();
	for (auto& product : products){
		writeFileInventory(file,product);
	}
}

void moderator(){ // In ra thông tin các bạn bằng tiếng việt
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	system("cls");
	wcout << L"\n\n\n";
	SET_COLOR(13);
	wcout << L"\n\n\t\t\tNguyễn Bá Đức     |  20233327  |  Coder & Word & Designer" << endl;
	SET_COLOR(9);
	wcout << L"\n\n\t\t\tNguyễn Hoàng Đức  |  20233328  |  Coder & Tester" << endl;
	SET_COLOR(11);
	wcout << L"\n\n\t\t\tNguyễn Văn Hội    |  20233149  |  Word & Coder & Researcher" << endl;
	SET_COLOR(12);
	wcout << L"\n\n\t\t\tMai Ngọc Phúc     |  20233580  |  Coder & Idea & Data" << endl;
	SET_COLOR(6);
	wcout << L"\n\t\t\t\t\t                               -the liems-" << endl;
	SET_COLOR(7);
	wcout << L"\n\n\n";
}
bool password(const char* password){ // hàm điền mật khẩu
	char pass[30] = {0}; // tạo 1 biến char
	int i = 0; // vị trí đề điền kí tự 
	cout << "\n\n\n\n\n\t\t    --> Enter the password: ";
	
	// Điền kí tự cho tới khi ấn enter
	while (true) {
		char ch = _getch(); // getch() lấy kí tự mà ko hiển thị
		if (ch == 13) { // 13 là kí tự enter trong bảng ASCII
			pass[i] = '\0'; // Kí tự cuối cùng là NUL để kết thúc chuỗi
			break; // kết thúc vòng lặp
		} else if (ch == '\b' && i > 0) { // Xử lí khi ấn backspace để xóa kí tự
			cout << "\b \b"; // Xóa bỏ kí tự trên màn hình
			i--; // xóa kí tự nên vị trí điền cũng phải giảm xuống
		} else if (i < 29 && isprint(ch)) { // check xem kí tự đó có in ra màn hình đc ko
			pass[i++] = ch; // gán kí tự đó vào pass, và tăng vị trí i lên
			cout << '*'; // in ra kí tự * thay cho mỗi kí tự mình điền
		}
	}
	
	// check xem password mình nhập có đúng password cần điền ko và return
	return (strcmp(pass, password) == 0);
}
void endgame(){
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	system("cls");
	wcout << L"\n\n\n";
	wcout << L"\t\t\tCẢM ƠN VÌ ĐÃ SỬ DỤNG PHẦN MỀM CỦA CHÚNG TÔI" << endl;
	wcout << L"\t\t\t                                   -the liems-" << endl;
	wcout << L"\n\n";
}
void khungmenu(){
	cout << " __________________________________________________________________ " << endl;
	cout << "|__________________________________________________________________|" << endl;
	cout << "|                                                                  |" << endl;
	cout << "|                   Inventory Management System                    |" << endl;
	cout << "|__________________________________________________________________|" << endl;
	cout << "|*                                                                *|" << endl;
	cout << "|    1. Add Product                     __________                 |" << endl;
	cout << "|    2. Remove Product                  |____ ____|                |" << endl;
	cout << "|    3. Import Product                      | |   _                |" << endl;
	cout << "|    4. Export Product                      | |  | |               |" << endl;
	cout << "|    5. Edit Product                        | |  | |               |" << endl;
	cout << "|    6. Remove Product error                |_|he| |               |" << endl;
	cout << "|    7. Calculate Total Value                    | |____           |" << endl;
	cout << "|    8. Display Inventory                        |______|iems      |" << endl;
	cout << "|    9. Search Product                                             |" << endl;
	cout << "|    10. Display Product Transactions                              |" << endl;
	cout << "|    11. Sort by Total Value                                       |" << endl;
	cout << "|    12. Back                                                      |" << endl;
	cout << "|    13. Exit                                                      |" << endl;
	cout << "|*________________________________________________________________*|" << endl;
	cout << "                                                                    " << endl;
}
void menu1(Inventory & inventory,bool &run){	

	int choice; // lựa chọn 
	int choice2;
	do { // Vòng lặp sự kiện
		system("cls");
		khungmenu();
		string input;
		cout << "Enter your choice: ";
		cin >> input; // Nhập lựa chọn 

		if (!isValidInteger(input)) { // Nếu nhập sai kiểu dữ liệu, thì sẽ ko chạy phần dưới nữa, mà tới vòng lặp mới
			clearInputBuffer();
			cout << "Invalid input. Please enter a number between 1 and 12.\n";
			choice = 0;
			continue;
		}

		choice = stoi(input); // chuyển input từ string về int

		string name, code;
		int quantity;
		long long price;

		switch (choice) {
			case 1: // Thêm sản phẩm
				cout << "Enter product name: ";
				clearInputBuffer(); // Nhớ xóa bộ đệm , trước khi nhập dữ liệu 
				getline(cin, name);
				cout << "Enter product code: ";
				getline(cin, code);
				cout << "Enter product quantity: ";
				cin >> quantity;
				cout << "Enter product price: ";
				cin >> price;
				if (cin.fail()) { // Kiểm tra xem giá trị nhập vào "số lượng" và "giá" đã đúng chưa
					cout << "Invalid input for quantity or price. Please try again.\n";
					clearInputBuffer(); // KO đúng thì xóa bộ đệm 
					break;// thoát khỏi case luôn và quay lại vòng lặp
				}
				inventory.addProduct(Product(code, name, quantity, price));
				break;
			case 2: // Xóa sản phẩm
				cout << "Enter product code to remove: ";
				clearInputBuffer();
				getline(cin, code);
				inventory.removeProduct(code);
				break;
			case 3: // Nhập thêm số lượng sản phẩm đã có
				cout << "Enter product code to import: ";
				clearInputBuffer();
				getline(cin, code);
				cout << "Enter quantity to import: ";
				cin >> quantity;
				if (cin.fail()) {
					cout << "Invalid input for quantity. Please try again.\n";
					clearInputBuffer();
					break; // thoát khỏi case luôn và quay lại vòng lặp
				}
				inventory.importProduct(code, quantity);
				break;
			case 4:
				cout << "Enter product code to export: ";
				clearInputBuffer();
				getline(cin, code);
				cout << "Enter quantity to export: ";
				cin >> quantity;
				if (cin.fail()) {
					cout << "Invalid input for quantity. Please try again.\n";
					clearInputBuffer();
					break;
				}
				inventory.exportProduct(code, quantity);
				break;
			case 5: // chỉnh sửa thông số sản phẩm
				// int choice2; 
				cout << "Enter product code to edit: ";
				clearInputBuffer();
				getline(cin, code);
				do {
					cout << "\nWhat attribute you want to edit?\n"; // Chọn thông số để sửa
					cout << "1. Name Product" << endl;
					cout << "2. Price Product" << endl;
					cout << "3. ............." << endl;
					cout << "Enter your choice: ";
					cin >> choice2;
					switch (choice2) {
					case 1:
						cout << "Enter name to edit: ";
						clearInputBuffer();
						getline(cin, name);
						inventory.editNameProduct(code, name);
						break;
					case 2:
						cout << "Enter price to edit: ";
						cin >> price;
						inventory.editPriceProduct(code,  price);
						break;
					default:
						break;
					}
					cout << "Want edit more? y/n "; // Nhập 1 kí tự, nếu là y thì chương trình sẽ chạy tiếp
				} while (_getch() == 'y');
				if (cin.fail()) {
					cout << "Invalid input for price. Please try again.\n";
					clearInputBuffer();
					break; // thoát khỏi case luôn và quay lại vòng lặp
				}
				break;
			case 6: // Xóa sản phẩm hỏng
				cout << "Enter product error code to remove: ";
				clearInputBuffer();
				getline(cin, code);
				cout << "Enter quantity to import: ";
				cin >> quantity;
				if (cin.fail()) {
					cout << "Invalid input for quantity. Please try again.\n";
					clearInputBuffer();
					break; // thoát khỏi case luôn và quay lại vòng lặp
				}
				inventory.errorProduct(code, quantity);
				break;
			case 7:
				inventory.calculateTotalValue();
				break;
			case 8:
				inventory.displayInventory();
				break;
			case 9:
				int cs;
				cout << "1. Search by code\n";
				cout << "2. Search by name\n";
				cout << "Enter your choice: "; 
				cin >> cs;
				if (cin.fail()) {
                    cout << "Invalid input. Please enter 1 or 2.\n";
                    clearInputBuffer();
                    break;
                }
                if (cs == 1) {
                    cout << "Enter product code: ";
                    clearInputBuffer();
                    getline(cin, code);
                    inventory.searchProductByCode(code);
                } else if (cs == 2) {
                    cout << "Enter product name: ";
                    clearInputBuffer();
                    getline(cin, name);
                    inventory.searchProductByName(name);
                } else {
                    cout << "Invalid choice. Please try again.\n";
                }
				break;
			case 10:
				cout << "Enter product code to display: ";
				clearInputBuffer();
				getline(cin, code);
				inventory.displayProductTransactions(code);
				break;
			case 11:
				inventory.quicksortProduct(0,inventory.size()-1);
				cout << "Sort Product successfully";
			case 12:
				break;
			case 13:
				endgame();
				run = false;
				break;
			default:
				break;
		}
		if (choice != 12 && choice != 13) {
			clearInputBuffer();
			cin.get(); // Đợi người dùng nhấn Enter
		}
	} while (choice != 13 && choice != 12);
}
void menu2(Inventory & inventory,bool &run){

	int choice; // lựa chọn 
	int choice2;

	do { // Vòng lặp sự kiện
		system("cls");
		cout << "\n\n\t\t THE IN/OUT MANAGEMENT SYSTEM\n";
		cout << "=============================================================";
		cout << "\n\n     1. IMPORT          2. EXPORT          3. BACK ";
		cout << "\n\n=============================================================\n";
		cout << "\n\n--> Enter Your Choice: ";
		cin >> choice;

		if (cin.fail()) { // Nếu nhập sai kiểu dữ liệu, thì sẽ ko chạy phần dưới nữa, mà tới vòng lặp mới
			cout << "Invalid input. Please enter a number between 1 and 3.\n";
			continue;
		}

		switch (choice) {
			case 1:{ 
				displayFileIO("IMPORT.csv","IMPORT");
				break;
			}
			case 2: {
				displayFileIO("EXPORT.csv","EXPORT"); 		
				break;
			}
			case 3:{
				break;
			}
			default:{
				cerr << "Invalid choice. Please enter 1, 2, or 3." << endl;
				break;
			}
		}
		if (choice != 3) {
			clearInputBuffer();
			cin.get(); // Đợi người dùng nhấn Enter
		}
	} while (choice != 3);
}
int main(){
	Inventory inventory; // Tạo đối tượng KHO

	system("cls");
	int choice1; 

	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t|============ WELCOME TO INVENTORY MANAGEMENT ============|";
	getch();
	system("cls");
	cout << "\n\n\t\t\t INVENTORY PASSWORD";
	cout <<   "\n\t\t\t--------------------";

	bool running = true;
	if (password("66668888")){
		while (running){
			inventory.inputFileInventory("INVENTORY.csv");
			inventory.inputFileIO("IMPORT.csv");
			inventory.inputFileIO("EXPORT.csv");
			system("cls");
			cout << "\n\n\t\t THE LIEMS MANAGEMENT SYSTEM\n";
			cout << "=============================================================";
			// cout << "\n\n\t\t 1. Inventory\n\n\t\t 2. Import/Export\n\n\t\t 3. Moderator";
			cout << "\n\n      1. Inventory    2. Import/Export    3. Moderator";
			cout << "\n\n=============================================================\n";
			cout << "\n\n--> Enter Your Choice: ";
			string input;
			cin >> input;
			if (!isValidInteger(input)) {
				clearInputBuffer();
	            cout << "Invalid input. Please enter a number between 1 and 3.";
	            continue;
	        }
	        choice1 = stoi(input);
			if (choice1 == 1) {
				menu1(inventory,running);
			}
			if (choice1 == 2) {
				menu2(inventory,running);
			}
			if (choice1 == 3) {
				system("cls");
				moderator();
				getch();
				endgame();
				exit(0);
			}
			inventory.updateFileInventory("INVENTORY.csv");
		}
	} else {
		cout << "\n\n\nAuthorized Personnel Only\n\n";
		getch();
		exit(0);
	}
	return 0;
}