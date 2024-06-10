// FILE CHÍNH
#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
#include <io.h>
#include <fcntl.h>

using namespace std;

void clearInputBuffer() { // Xóa bộ đệm
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa tối ưu hơn thôi.
}

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
	//ham gan
	void setEmail(const string& email);
	void setAddress(const string& address);
	void setPhoneNumber(const string& phoneNumber);
	
	//ham hien thi
	void display() const; 
};

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
	Product(string n, string c, int q, long long p) // hàm tạo, phải có đủ 4 tham số truyền vào
		: name(n), code(c), quantity(q), price(p) {} // lệnh gán
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

	int findProductIndexByCode(string code) { // Tìm vị trí của sản phẩm trong mảng sản phẩm
		for (int i = 0; i < products.size(); i++) { // size() là số phần tử đang có trong mảng
			if (products[i].getCode() == code) {
				return i;
			}
		}
		return -1; // Không tìm thấy thì trả về -1
	}

public:
	void swapProduct(Product& a, Product& b);
	void addProduct(Product product);
	void removeProduct(string code);
	void importProduct(string code, int quantity);
	void editProduct(string code, string name, long long price);
	void exportProduct(string code, int quantity);
	void errorProduct(string code, int quantity);
	void searchProductByName(string name);
	void searchProductByCode(string code);
	void calculateTotalValue();
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
// DATEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
void Date::setDate(){
	while (true){ // Nhập ngày tháng năm, nếu ngày ko tồn tại thì nhập lại
		cout << "Enter dd/mm/yy: ";
		cin >> day >> month >> year;
		if (isValidDate()) break;
		cout << "Date does not exist. Try again." << endl;
	} 
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
// TRANSACTIONNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
void Transaction::display() const {
	cout << "Type: " << type
		 << " | Quantity: " << quantity
		 << " | Price: " << price 
		 << " | Date: " ;
	date.display();
	cout << endl; 
	address.display(); cout << endl;
}
// PRODUCTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
void Product::addTransaction(const Transaction& transaction) {transactions.push_back(transaction);}
void Product::displayTransactions() const {
	if (transactions.empty()) {
		cout << "No transactions found for this product." << endl;
	} else {
		cout << "\t\t Transactions for " << name << endl;
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
	cout << "Product Code: " << code
		<< " | Name: " << name
		<< " | Quantity: " << quantity
		<< " | Price: " << price << endl;
}
// INVENTORYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
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
void Inventory::editProduct(string code, string name, long long price) { // Sửa thông số của sản phâm (tên, giá)
	int index = findProductIndexByCode(code);
	if (index != -1) {
		products[index].setName(name); // SỬa lại tên
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
	cout << "\n--> Total Current Inventory Value: " << totalValue << endl;
}
void Inventory::displayInventory() { // Hàm hiển thị kho hàng
	if (products.empty()) {
		cout << "\n--> Inventory is empty." << endl;
	}
	else {
		cout << "\t\t\t   Current Inventory" << endl;
		cout << "\t\t\t------------------------" << endl;
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
        products[index].display();
    } else {
        cout << "Product not found." << endl;
    }
}

void moderator(){ // In ra thông tin các bạn bằng tiếng việt
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	system("cls");
	wcout << L"\n\n\n";
	wcout << L"\n\n\t\t\tNguyễn Bá Đức     |  20233327  |  Designer" << endl;
	wcout << L"\n\n\t\t\tNguyễn Hoàng Đức  |  20233328  |  Coder" << endl;
	wcout << L"\n\n\t\t\tNguyễn Văn Hội    |  20233149  |  Coder" << endl;
	wcout << L"\n\n\t\t\tMai Ngọc Phúc     |  20233580  |  Coder" << endl;
	wcout << L"\n\t\t\t\t\t                               -the liems-" << endl;
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
	cout << "|    11. Back                                                      |" << endl;
	cout << "|    12. Exit                                                      |" << endl;
	cout << "|*________________________________________________________________*|" << endl;
	cout << "                                                                    " << endl;
	cout << "Enter your choice: ";
}
void menu(Inventory & inventory,bool &run){	

	int choice; // lựa chọn 
	int choice2;

	do { // Vòng lặp sự kiện
		system("cls");
		khungmenu();
		cin >> choice; // Nhập lựa chọn 

		if (cin.fail()) { // Nếu nhập sai kiểu dữ liệu, thì sẽ ko chạy phần dưới nữa, mà tới vòng lặp mới
			cout << "Invalid input. Please enter a number between 1 and 6.\n";
			continue;
		}

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
				inventory.addProduct(Product(name, code, quantity, price));
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
						break;
					case 2:
						cout << "Enter price to edit: ";
						cin >> price;
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
				inventory.editProduct(code, name, price);
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
				cout << "Enter your choice: "; cin >> cs;
				if (cs == 1){
					cout << "Enter product code: ";
					clearInputBuffer();
					getline(cin,code);
					inventory.searchProductByCode(code);
				}
				if (cs == 2){
					cout << "Enter product name: ";
					clearInputBuffer();
					getline(cin,name);
					inventory.searchProductByName(name);
				}
				break;
			case 10:
				cout << "Enter product code to display: ";
				clearInputBuffer();
				getline(cin, code);
				inventory.displayProductTransactions(code);
				break;
			case 11:
				break;
			case 12:
				endgame();
				run = false;
				break;
			default:
				break;
		}
		if (choice != 11 && choice != 12) {
			clearInputBuffer();
		    cin.get(); // Đợi người dùng nhấn Enter
		}
	} while (choice != 12 && choice != 11);
}
int main(){
	Inventory inventory; // Tạo đối tượng KHO

	system("cls");
	int j; 

	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t|============ WELCOME TO INVENTORY MANAGEMENT ============|";
	getch();
	system("cls");
	cout << "\n\n\t\t\t INVENTORY PASSWORD";
	cout <<   "\n\t\t\t--------------------";

	bool running = true;
	if (password("20233327")){
		while (running){
			system("cls");
			cout << "\n\n\t\t THE LIEMS MANAGEMENT SYSTEM\n";
			cout << "=============================================================";
			// cout << "\n\n\t\t 1. Inventory\n\n\t\t 2. Import/Export\n\n\t\t 3. Moderator";
			cout << "\n\n      1. Inventory    2. Import/Export    3. Moderator";
			cout << "\n\n=============================================================\n";
			cout << "\n\n--> Enter Your Choice: ";
			cin >> j;
			if (j == 1) {
				menu(inventory,running);
			}
			if (j == 2) {
				system("cls");
				cout << "Hello World";
				getch();
			}
			if (j == 3) {
				system("cls");
				moderator();
				exit(0);
			}
		}
	} else {
		cout << "\n\n\nAuthorized Personnel Only\n\n";
		getch();
		exit(0);
	}
	return 0;
}