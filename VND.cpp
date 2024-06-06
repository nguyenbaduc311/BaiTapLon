// Nguyen Ba Duc 20233327
#include<bits/stdc++.h>
using namespace std;

string price(long long giaTien){
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
	string price = "";
	while (j--) price += c[j];
	price += " VND";
	return price;
}

int main(){
	long long a = 14500000;
	cout << price(a); // 14.500.000 VND

	return 0;
}