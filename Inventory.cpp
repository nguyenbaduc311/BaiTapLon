#include "Inventory.h"

void Transaction::display() const {
	cout << "Type: " << type
		 << " | Quantity: " << quantity
		 << " | Price: " << price
		 << " | Date: " << date << endl;
}

void Product::addTransaction(const Transaction& transaction) {transactions.push_back(transaction);}
void Product::displayTransactions() const {
	if (transactions.empty()) {
		cout << "No transactions found for this product." << endl;
	} else {
		cout << "=== Transactions for " << name << " ===" << endl;
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

void Inventory::swapProduct(Product& a, Product& b) {
	Product temp = a;
	a = b;
	b = temp;
}
void Inventory::addProduct(Product product) { // Hàm thêm sản phẩm mới
	int index = findProductIndexByCode(product.getCode());
	if (index == -1) { // Nếu ko có mặt hàng này thì mới thêm vào mảng
		products.push_back(product); // Hàm pushback là thêm phần tử vào mảng
		cout << "Product added successfully." << endl;
	}
	else {
		cout << "Product with this code already exists." << endl;
	}
}
void Inventory::removeProduct(string code) { // Hàm xóa sản phẩm khỏi kho
	int index = findProductIndexByCode(code);
	if (index != -1) { // erase(*địa chỉ cần xóa*) : để xóa sản phẩm
		products.erase(products.begin() + index); // begin() là lấy vị trí con trỏ đầu tiên của mảng
		cout << "Product removed successfully." << endl;
	}
	else {
		cout << "Product not found." << endl;
	}
}
void Inventory::importProduct(string code, int quantity) { // Tìm sản phẩm rồi thêm số lượng sản phẩm
	int index = findProductIndexByCode(code);
	if (index != -1) {
		products[index].setQuantity(products[index].getQuantity() + quantity); // Thêm số lượng
		cout << "Product imported successfully." << endl;
	}
	else {
		cout << "Product not found." << endl;
	}
}
void Inventory::editProduct(string code, string name, long long price) { // Sửa thông số của sản phâm (tên, giá)
	int index = findProductIndexByCode(code);
	if (index != -1) {
		products[index].setName(name); // SỬa lại tên
		products[index].setPrice(price); // Sửa lại giá
		cout << "Product edited successfully." << endl;
	}
	else {
		cout << "Product not found." << endl;
	}
}
void Inventory::exportProduct(string code, int quantity) { // Xuất hàng 
	int index = findProductIndexByCode(code);
	if (index != -1) {
		if (products[index].getQuantity() >= quantity) { // check xem có đủ lượng hàng để xuất hàng ko
			products[index].setQuantity(products[index].getQuantity() - quantity); // Giảm số lượng
			cout << "Product exported successfully." << endl;
		}
		else {
			cout << "Not enough quantity in stock." << endl;
		}
	}
	else {
		cout << "Product not found." << endl;
	}
}
void Inventory::errorProduct(string code, int quantity) { // Vứt bỏ hàng lỗi ra khỏi kho
	int index = findProductIndexByCode(code);
	if (index != -1) {
		if (products[index].getQuantity() >= quantity) { // check xem có đủ lượng hàng để trừ ko
			products[index].setQuantity(products[index].getQuantity() - quantity); // Giảm số lượng hàng hỏng
			cout << "Error Product removed successfully." << endl;
		}
		else {
			cout << "Not enough quantity in stock." << endl;
		}
	}
	else {
		cout << "Product not found." << endl;
	}
}
void Inventory::calculateTotalValue() {
	long long int totalValue = 0;
	for (const auto& product : products) {
		totalValue += product.getTotalValue();
	}
	cout << "Total Current Inventory Value: " << totalValue << endl;
}
void Inventory::displayInventory() { // Hàm hiển thị kho hàng
	if (products.empty()) {
		cout << "Inventory is empty." << endl;
	}
	else {
		cout << "=== Current Inventory ===" << endl;
		cout << "-------------------------" << endl;
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
