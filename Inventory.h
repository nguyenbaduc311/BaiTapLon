
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Product {
private:
    string name;
    string code;
    int quantity;
    long long price;

public:
    Product(string n, string c, int q, long long p);

    string getName();
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

class Inventory {
private:
    vector<Product> products;

    int findProductIndexByCode(string code);

public:
	void swapProduct(Product& a,Product& b);
    void addProduct(const Product &product);
    void importProduct(string code, int quantity);
    void exportProduct(string code, int quantity);
    void errorProduct(string code, int quantity);
    void editProduct(string code, string name, long long price);
    void displayInventory() const;
    void caculateTotalValue();
    void removeProduct(string code);
};

void clearInputBuffer();


