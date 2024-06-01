#include<bits/stdc++.h> // các thư viện chuẩn của C++
#include <iostream>
#include <vector> // là thư viện để thao tác với mảng thuận lợi hơn
#include <string> // thư viện liên quan tới chuỗi kí tự 
#include <limits>
#include <conio.h>
// #include "Date.h"

using namespace std;

class Product { // tạo Đối tượng "sản phẩm"
private:
	string name; // TÊN sản phẩm
	string code; // MÃ ĐỊNH DANH (mỗi sản phẩm phải có 1 mã khác nhau)
	int quantity; // SỐ LƯỢNG sản phẩm
	long long price; // ĐƠN GIÁ của 1 sản phẩm, vì là VNĐ nên để long long
	// Date date; // THỜI GIAN (nhập xuất)	
public:
	Product(string n, string c, int q, long long p) // hàm tạo, phải có đủ 4 tham số truyền vào
		: name(n), code(c), quantity(q), price(p) {} // lệnh gán

	string getName(){ return name;} // Các hàm lấy và gán
	string getCode(){ return code;}
	int getQuantity(){ return quantity;}
	long long getPrice(){ return price;}
	void setName(string a){ name = a;}
	void setCode(string b){ code = b;}
	void setQuantity(int c){ quantity = c;}
	void setPrice(long long d){ price = d;}
	void display() const { // hàm hiển thị các thông số của sản phẩm
		cout << "Product Code: " << code 
			 << " | Name: " << name 
			 << " | Quantity: " << quantity 
			 << " | Price: " << price << endl;
	}
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
	void swapProduct(Product& a, Product& b) {
	    Product temp = a;
	    a = b;
	    b = temp;
	}

	void addProduct(Product product) { // Hàm thêm sản phẩm mới
		int index = findProductIndexByCode(product.getCode()); 
		if (index == -1) { // Nếu ko có mặt hàng này thì mới thêm vào mảng
			products.push_back(product); // Hàm pushback là thêm phần tử vào mảng
			cout << "Product added successfully." << endl;
		} else {
			cout << "Product with this code already exists." << endl;
		}
	}
	void removeProduct(string code) { // Hàm xóa sản phẩm khỏi kho
		int index = findProductIndexByCode(code);
		if (index != -1) { // erase(*địa chỉ cần xóa*) : để xóa sản phẩm
			products.erase(products.begin() + index); // begin() là lấy vị trí con trỏ đầu tiên của mảng
			cout << "Product removed successfully." << endl;
		} else {
			cout << "Product not found." << endl;
		}
	}
	void importProduct(string code, int quantity) { // Tìm sản phẩm rồi thêm số lượng sản phẩm
		int index = findProductIndexByCode(code); 
		if (index != -1) {
			products[index].setQuantity(products[index].getQuantity() + quantity); // Thêm số lượng
			cout << "Product imported successfully." << endl;
		} else {
			cout << "Product not found." << endl;
		}
	}
	void editProduct(string code, string name, long long price) { // Sửa thông số của sản phâm (tên, giá)
		int index = findProductIndexByCode(code); 
		if (index != -1) {
			products[index].setName(name); // SỬa lại tên
			products[index].setPrice(price); // Sửa lại giá
			cout << "Product edited successfully." << endl;
		} else {
			cout << "Product not found." << endl;
		}
	}
	void exportProduct(string code, int quantity) { // Xuất hàng 
		int index = findProductIndexByCode(code);
		if (index != -1) {
			if (products[index].getQuantity() >= quantity) { // check xem có đủ lượng hàng để xuất hàng ko
				products[index].setQuantity(products[index].getQuantity() - quantity); // Giảm số lượng
				cout << "Product exported successfully." << endl;
			} else {
				cout << "Not enough quantity in stock." << endl;
			}
		} else {
			cout << "Product not found." << endl;
		}
	}
	void errorProduct(string code,int quantity){ // Vứt bỏ hàng lỗi ra khỏi kho
		int index = findProductIndexByCode(code);
		if (index != -1) {
			if (products[index].getQuantity() >= quantity) { // check xem có đủ lượng hàng để trừ ko
				products[index].setQuantity(products[index].getQuantity() - quantity); // Giảm số lượng hàng hỏng
				cout << "Error Product removed successfully." << endl;
			} else {
				cout << "Not enough quantity in stock." << endl;
			}
		} else {
			cout << "Product not found." << endl;
		}
	}
	void displayInventory() { // Hàm hiển thị kho hàng
		cout << "Inventory List:" << endl;
		for (const auto& product : products) { // vòng lặp lấy từng phần tử trong mảng
			product.display(); // In ra từng sản phẩm một
		}
	}
};

void clearInputBuffer() { // Xóa bộ đệm
	cin.clear(); 
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa tối ưu hơn thôi.
}

int main() {
	Inventory inventory; // Tạo đối tượng KHO

	int choice; // lựa chọn 
	int choice2;
	do { // Vòng lặp sự kiện
		cout << "\nInventory Management System\n"; // MENUUUUUUU
		cout << "1. Add Product\n";
		cout << "2. Remove Product\n";
		cout << "3. Import Product\n";
		cout << "4. Export Product\n";
		cout << "5. Edit Product\n";
		cout << "6. Remove Product error\n";
		cout << "7. Display Inventory\n";
		cout << "8. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice; // Nhập lựa chọn 

		if (cin.fail()) { // Nếu nhập sai kiểu dữ liệu, thì sẽ ko chạy phần dưới nữa, mà tới vòng lặp mới
			cout << "Invalid input. Please enter a number between 1 and 6.\n";
			clearInputBuffer();
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
					switch (choice2){
						case 1:
							cout << "Enter name to edit: ";
							clearInputBuffer();
							getline(cin, name);
							break;
						case 2:
							cout << "Enter price to edit: ";
							cin >> price;		
							break;	
					}
					cout << "Want edit more? y/n "; // Nhập 1 kí tự, nếu là y thì chương trình sẽ chạy tiếp
				} while (getch() == 'y');
				if (cin.fail()) {
					cout << "Invalid input for price. Please try again.\n";
					clearInputBuffer();
					break; // thoát khỏi case luôn và quay lại vòng lặp
				}
				inventory.editProduct(code, name,price);
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
				inventory.displayInventory();
				break;

			case 8:
				cout << "Exiting program." << endl; // Thoát chương trình
				break;

			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
	} while (choice != 8);

	return 0;
}
