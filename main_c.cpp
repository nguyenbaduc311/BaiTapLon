#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_PRODUCTS 100 // Số lượng sản phẩm tối đa trong kho
#define NAME_LENGTH 50 // Độ dài tối đa của tên sản phẩm
#define CODE_LENGTH 20 // Độ dài tối đa của mã sản phẩm

// Cấu trúc dữ liệu để lưu thông tin sản phẩm
typedef struct {
    char name[NAME_LENGTH]; // Tên sản phẩm
    char code[CODE_LENGTH]; // Mã sản phẩm
    int quantity; // Số lượng sản phẩm
    long price; // Giá sản phẩm
} Product;

// Cấu trúc dữ liệu để lưu kho hàng
typedef struct {
    Product products[MAX_PRODUCTS]; // Mảng các sản phẩm
    int size; // Số lượng sản phẩm hiện tại trong kho
} Inventory;

// Hàm thêm sản phẩm mới vào kho
void addProduct(Inventory *inventory, Product product) {
    // Kiểm tra xem sản phẩm có mã code đã tồn tại trong kho chưa
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i].code, product.code) == 0) {
            printf("Product with this code already exists.\n");
            return;
        }
    }
    // Nếu kho còn chỗ thì thêm sản phẩm vào
    if (inventory->size < MAX_PRODUCTS) {
        inventory->products[inventory->size++] = product;
        printf("Product added successfully.\n");
    } else {
        // Nếu kho đầy thì thông báo
        printf("Inventory is full.\n");
    }
}

// Hàm xóa sản phẩm khỏi kho
void removeProduct(Inventory *inventory, char *code) {
    // Tìm sản phẩm có mã code trong kho
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i].code, code) == 0) {
            // Xóa sản phẩm bằng cách dịch chuyển các sản phẩm phía sau lên
            for (int j = i; j < inventory->size - 1; j++) {
                inventory->products[j] = inventory->products[j + 1];
            }
            inventory->size--; // Giảm số lượng sản phẩm trong kho
            printf("Product removed successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

// Hàm nhập sản phẩm vào kho
void importProduct(Inventory *inventory, char *code, int quantity) {
    // Tìm sản phẩm có mã code trong kho
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i].code, code) == 0) {
            inventory->products[i].quantity += quantity; // Cập nhật số lượng sản phẩm
            printf("Product imported successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

// Hàm xuất sản phẩm ra khỏi kho
void exportProduct(Inventory *inventory, char *code, int quantity) {
    // Tìm sản phẩm có mã code trong kho
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i].code, code) == 0) {
            if (inventory->products[i].quantity >= quantity) {
                inventory->products[i].quantity -= quantity; // Cập nhật số lượng sản phẩm
                printf("Product exported successfully.\n");
            } else {
                printf("Not enough quantity in stock.\n");
            }
            return;
        }
    }
    printf("Product not found.\n");
}

void searchProduct(Inventory *inventory, char *code) {
    // Tìm sản phẩm có mã code trong kho
    for (int i = 0; i < inventory->size; i++) {
        if (strcmp(inventory->products[i].code, code) == 0) {
            printf("| %-15s | %-25s | %-10s | %-14s |\n", "Product Code", "Name", "Quantity", "Price");
            printf("-----------------------------------------------------------------------------\n");
            printf("| %-15s | %-25s | %-10d | %-11ld VND|\n",
                   inventory->products[i].code,
                   inventory->products[i].name,
                   inventory->products[i].quantity,
                   inventory->products[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}
// Hàm hiển thị danh sách sản phẩm trong kho
void displayInventory(const Inventory *inventory) {
    printf("| %-15s | %-25s | %-10s | %-14s |\n", "Product Code", "Name", "Quantity", "Price");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < inventory->size; i++) {
        printf("| %-15s | %-25s | %-10d | %-11ld VND|\n",
               inventory->products[i].code,
               inventory->products[i].name,
               inventory->products[i].quantity,
               inventory->products[i].price);
    }
}
// Hàm xóa bộ đệm nhập liệu để tránh lỗi khi nhập liệu
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Hàm chính điều khiển chương trình
int main() {
    Inventory inventory = { .size = 0 }; // Khởi tạo kho với kích thước 0
    int choice;

    do {
        system("cls");
        // Hiển thị menu quản lý kho
        printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Import Product\n");
        printf("4. Export Product\n");
        printf("5. Search Product\n");
        printf("6. Display Inventory\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        // Nhập lựa chọn từ người dùng
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            clearInputBuffer();
            continue;
        }

        char name[NAME_LENGTH], code[CODE_LENGTH];
        int quantity;
        long price;

        switch (choice) {
            case 1:
                // Thêm sản phẩm mới
                printf("Enter product name: ");
                clearInputBuffer();
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Xóa ký tự xuống dòng

                printf("Enter product code: ");
                fgets(code, CODE_LENGTH, stdin);
                code[strcspn(code, "\n")] = '\0'; // Xóa ký tự xuống dòng

                printf("Enter product quantity: ");
                if (scanf("%d", &quantity) != 1) {
                    printf("Invalid input for quantity. Please try again.\n");
                    clearInputBuffer();
                    break;
                }

                printf("Enter product price: ");
                if (scanf("%lf", &price) != 1) {
                    printf("Invalid input for price. Please try again.\n");
                    clearInputBuffer();
                    break;
                }

                // Tạo sản phẩm mới và thêm vào kho
                Product newProduct;
                strcpy(newProduct.name, name);
                strcpy(newProduct.code, code);
                newProduct.quantity = quantity;
                newProduct.price = price;

                addProduct(&inventory, newProduct);
                break;

            case 2:
                // Xóa sản phẩm khỏi kho
                printf("Enter product code to remove: ");
                clearInputBuffer();
                fgets(code, CODE_LENGTH, stdin);
                code[strcspn(code, "\n")] = '\0'; // Xóa ký tự xuống dòng

                removeProduct(&inventory, code);
                break;

            case 3:
                // Nhập sản phẩm vào kho
                printf("Enter product code to import: ");
                clearInputBuffer();
                fgets(code, CODE_LENGTH, stdin);
                code[strcspn(code, "\n")] = '\0'; // Xóa ký tự xuống dòng

                printf("Enter quantity to import: ");
                if (scanf("%d", &quantity) != 1) {
                    printf("Invalid input for quantity. Please try again.\n");
                    clearInputBuffer();
                    break;
                }

                importProduct(&inventory, code, quantity);
                break;

            case 4:
                // Xuất sản phẩm ra khỏi kho
                printf("Enter product code to export: ");
                clearInputBuffer();
                fgets(code, CODE_LENGTH, stdin);
                code[strcspn(code, "\n")] = '\0'; // Xóa ký tự xuống dòng

                printf("Enter quantity to export: ");
                if (scanf("%d", &quantity) != 1) {
                    printf("Invalid input for quantity. Please try again.\n");
                    clearInputBuffer();
                    break;
                }

                exportProduct(&inventory, code, quantity);
                break;

            case 5:
                // Tìm sản phẩm
                printf("Enter product code: ");
                clearInputBuffer();
                fgets(code, CODE_LENGTH, stdin);
                code[strcspn(code, "\n")] = '\0'; // Xóa ký tự xuống dòng

                searchProduct(&inventory, code);
                break;
            case 6:
                // Hiển thị danh sách sản phẩm trong kho
                displayInventory(&inventory);
                break;

            case 7:
                // Thoát chương trình
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        } 
        if (choice != 7) {
            clearInputBuffer();
            getch(); // Đợi người dùng nhấn Enter
        }
    } while (choice != 7);

    return 0;
}
