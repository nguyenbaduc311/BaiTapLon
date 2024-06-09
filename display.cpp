// Nguyen Ba Duc 20233327
#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
#include <io.h>
#include <fcntl.h>
using namespace std;

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
	cout << "|    1. Add Product                                                |" << endl;
	cout << "|    2. Remove Product                                             |" << endl;
	cout << "|    3. Import Product                                             |" << endl;
	cout << "|    4. Export Product                                             |" << endl;
	cout << "|    5. Edit Product                                               |" << endl;
	cout << "|    6. Remove Product error                                       |" << endl;
	cout << "|    7. Display Inventory                                          |" << endl;
	cout << "|    8. Back                                                       |" << endl;
	cout << "|    9. Exit                                                       |" << endl;
	cout << "|*________________________________________________________________*|" << endl;
	cout << "                                                                    " << endl;
	cout << "Enter your choice: ";
}
void menu(bool &run){
	int choice;
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
				break;
			case 2: // Xóa sản phẩm
				break;
			case 3: // Nhập thêm số lượng sản phẩm đã có
				break;
			case 4:
				break;
			case 5: // chỉnh sửa thông số sản phẩm
				break;
			case 6: // Xóa sản phẩm hỏng
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				endgame();
				run = false;
				break;
			default:
				break;
		}
		if (choice != 9 && choice != 8) {
			cout << "Press Enter to continue...";
			getchar();
		    cin.get(); // Đợi người dùng nhấn Enter
		}
	} while (choice != 9 && choice != 8);
}
int main(){
	system("cls");
	int j; bool running = true;

	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t|============ WELCOME TO INVENTORY MANAGEMENT ============|";
	getch();
	system("cls");
	cout << "\n\n\t\t\t INVENTORY PASSWORD";
	cout <<   "\n\t\t\t--------------------";
	if (password("20233327")){
		while (running){
			system("cls");
			cout << "\n\n\t\t THE LIEMS MANAGEMENT SYSTEM\n";
			cout << "=============================================================";
			cout << "\n\n\t\t 1. Inventory\n\n\t\t 2. Import/Export\n\n\t\t 3. Moderator";
			cout << "\n\n=============================================================\n";
			cout << "\n\n--> Enter Your Choice: ";
			cin >> j;
			if (j == 1) {
				menu(running);
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