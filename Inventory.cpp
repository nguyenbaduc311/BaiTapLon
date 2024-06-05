#include "Inventory.h"
#include <conio.h>

Product::Product(string n, string c, int q, long long p) 
    : name(n), code(c), quantity(q), price(p) {}

string Product::getName() { return name; }
string Product::getCode() { return code; }
int Product::getQuantity() { return quantity; }
long long Product::getPrice() { return price; }
long long int Product::getTotalValue() const { return price * quantity; }
void Product::setName(string a) { name = a; }
void Product::setCode(string b) { code = b; }
void Product::setQuantity(int c) { quantity = c; }
void Product::setPrice(long long d) { price = d; }
void Product::display() const {
    cout << "Product Code: " << code 
         << " | Name: " << name 
         << " | Quantity: " << quantity 
         << " | Price: " << price << endl;
}

int Inventory::findProductIndexByCode(string code) {
    for (int i = 0; i < products.size(); i++) {
        if (products[i].getCode() == code) {
            return i;
        }
    }
    return -1;
}
void Inventory::swapProduct(Product& a, Product& b) {
    Product temp = a;
    a = b;
    b = temp;
    }
void Inventory::addProduct(Product product) { 
	int index = findProductIndexByCode(product.getCode()); 
	if (index == -1) { 
		products.push_back(product); 
		cout << "Product added successfully." << endl;
	} else {
		cout << "Product with this code already exists." << endl;
	}


void Inventory::importProduct(string code, int quantity) {
    int index = findProductIndexByCode(code);
    if (index != -1) {
        products[index].setQuantity(products[index].getQuantity() + quantity);
    } else {
        cout << "Product not found." << endl;
    }
}

void Inventory::exportProduct(string code, int quantity) {
    int index = findProductIndexByCode(code);
    if (index != -1) {
        int current_quantity = products[index].getQuantity();
        if (current_quantity >= quantity) {
            products[index].setQuantity(current_quantity - quantity);
        } else {
            cout << "Not enough stock." << endl;
        }
    } else {
        cout << "Product not found." << endl;
    }
}

void Inventory::errorProduct(string code, int quantity) {
    int index = findProductIndexByCode(code);
    if (index != -1) {
        int current_quantity = products[index].getQuantity();
        if (current_quantity >= quantity) {
            products[index].setQuantity(current_quantity - quantity);
            cout<<"Error Product removed succesfully. "<<endl;
        } else {
            cout << "Not enough quantity in   stock." << endl;
        }
    } else {
        cout << "Product not found." << endl;
    }
}

void Inventory::editProduct(string code, string name, long long price) {
    int index = findProductIndexByCode(code);
    if (index != -1) {
        products[index].setName(name);
        products[index].setPrice(price);
        cout<<"Product edited successfully "<<endl;
    } else {
        cout << "Product not found." << endl;
    }
}
void Inventory::removeProduct(string code) { // Hàm xóa s?n ph?m kh?i kho
	int index = findProductIndexByCode(code);
	if (index != -1) { // erase(*d?a ch? c?n xóa*) : d? xóa s?n ph?m
		products.erase(products.begin() + index); // begin() là l?y v? trí con tr? d?u tiên c?a m?ng
		cout << "Product removed successfully." << endl;
	} else {
		cout << "Product not found." << endl;
	}
}
void Inventory::calculateTotalValue(){
    long long int totalValue = 0;
    for (const auto &product : products) {
        totalValue += product.getTotalValue();
    }
    cout << "Total Current Inventory Value: " << totalValue << endl;
}

void Inventory::displayInventory() const {
    for (const auto &product : products) {
        product.display();
    }
}

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

