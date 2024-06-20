#ifndef INVENTORY_H
#define INVENTORY_H
#pragma once
#include <iostream>
#include <vector> // là thư viện để thao tác với mảng thuận lợi hơn
#include <string> // thư viện liên quan tới chuỗi kí tự 
#include <conio.h>
#include "Date.h"

using namespace std;


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


#endif
