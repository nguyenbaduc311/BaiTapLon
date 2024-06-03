#include<bits/stdc++.h> // các thư viện chuẩn của C++
#include <iostream>
#include <vector> // là thư viện để thao tác với mảng thuận lợi hơn
#include <string> // thư viện liên quan tới chuỗi kí tự 
#include <limits>
#include <conio.h>

using namespace std;

class Product { // tạo Đối tượng "sản phẩm"
private:
	string name; // TÊN sản phẩm
	string code; // MÃ ĐỊNH DANH (mỗi sản phẩm phải có 1 mã khác nhau)
	int quantity; // SỐ LƯỢNG sản phẩm
	long long price; // ĐƠN GIÁ của 1 sản phẩm, vì là VNĐ nên để long long
public:
	Product(string n, string c, int q, long long p) // hàm tạo, phải có đủ 4 tham số truyền vào
		: name(n), code(c), quantity(q), price(p) {} // lệnh gán

	string getName(); // Các hàm lấy và gán
	string getCode();
	int getQuantity();
	long long getPrice();
	void setName(string a);
	void setCode(string b);
	void setQuantity(int c);
	void setPrice(long long d);
	void display() const ;
};

string Product::getName(){ return name;} // Các hàm lấy và gán
string Product::getCode(){ return code;}
int Product::getQuan8.\n";
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
