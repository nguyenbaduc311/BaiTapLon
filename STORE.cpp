#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
struct product {
	char name[50];
	int q, p, sq, sp, tq;
};
struct product p[50];
char AUserName[] = "admin";
char APass[] = "123";
char UserName[] = "";
char Pass[] = "";
int tp = 10, PName;
void Items()
{
	printf("We have the following items available to select from:\n");
	printf("\n\tProduct\t\tQuantity");
	for (int i = 0; i < tp; i++) {
		printf("\n%d\t%s\t\t%d", i + 1, p[i].name, p[i].tq);
	}
	printf("\n");
}
void OrderInstructions()
{
	printf("Step 1: Tell us how many products you want to order\n");
	printf("Step 2: Tell us no of each of the products you want to order\n");
	printf("For example:\n1 for Bread\n2 for Chips\netc..\n");
	printf("Step 3: Enter how many of each product you want (quantity)\n");
	printf("And you're done! Happy Shopping!");
}
void OrderTaker(int PNum)
{
	for (int i = 0; i < 50; i++) {
		p[i].q = 0;
	}
	int i = 0, PQuantity = 0;
	for (i = 0; i < PNum; i++)
	{
		printf("Product %d: ", i + 1);
		scanf("%d", &PName);
		printf("Enter the quantity of selected product: ");
	there:
		scanf("%d", &PQuantity);
		for (int j = 0; j < tp; j++) {
			if (PName == j + 1)
			{
				if (PQuantity > p[j].tq)
				{
					printf("Please enter available amount of quantity only\n");
					printf("Enter the quantity of %d: ", PName);
					goto there;
				}
				p[j].q = PQuantity;
				p[j].tq = p[j].tq - p[j].q;
				p[j].sq = p[j].sq + p[j].q;
			}
		}
		if (PName > tp)
		{
			printf("Please enter a product no from the available list");
			i--;
			printf("\n%d out of %d products entered\n", i + 1, PNum);
		}
	}
}
void BillMaker()
{
	int total = 0, collected;
	printf("\nYour Cart:\n");
	printf("Item\t\tQuantity\tTotal\n");
	for (int i = 0; i < tp; i++) {
		if (p[i].q > 0)
		{
			printf("%s\t\t%d\t\t%d\n", p[i].name, p[i].q, p[i].q * p[i].p);
			total = total + (p[i].q * p[i].p);
		}
	}
	if (total >= 100 && total < 200) {
		printf("\nTotal Amount:%d", total);
		printf("\nDiscount 5%%");
		total = total * 0.95;
	}
	else if (total >= 200 && total < 300) {
		printf("\nTotal Amount:%d", total);
		printf("\nDiscount 10%%");
		total = total * 0.9;
	}
	else if (total >= 300 && total < 400) {
		printf("\nTotal Amount:%d", total);
		printf("\nDiscount 15%%");
		total = total * 0.85;
	}
	else if (total >= 400 && total < 500) {
		printf("\nTotal Amount:%d", total);
		printf("\nDiscount 20%%");
		total = total * 0.8;
	}
	else if (total >= 500) {
		printf("\nTotal Amount:%d", total);
		printf("\nDiscount 25%%");
		total = total * 0.75;
	}
	printf("\nTotal Amount after discount: %d", total);
	printf("\nAmount given by the customer: ");
	scanf("%d", &collected);
	printf("\nChange due: %d", collected - total);
	printf("\n----------------------------------------------\nThanks for shopping with us! Hope to see you again!");
}
int main()
{
	strcpy(p[0].name, "Bread");
	p[0].q = 0; p[0].p = 10; p[0].sq = 0; p[0].sp = 0; p[0].tq = 10;
	strcpy(p[1].name, "Chips");
	p[1].q = 0; p[1].p = 15; p[1].sq = 0; p[1].sp = 0; p[1].tq = 10;
	strcpy(p[2].name, "Biscuit");
	p[2].q = 0; p[2].p = 5; p[2].sq = 0; p[2].sp = 0; p[2].tq = 10;
	strcpy(p[3].name, "Juice");
	p[3].q = 0; p[3].p = 30; p[3].sq = 0; p[3].sp = 0; p[3].tq = 10;
	strcpy(p[4].name, "Drinks");
	p[4].q = 0; p[4].p = 50; p[4].sq = 0; p[4].sp = 0; p[4].tq = 10;
	strcpy(p[5].name, "Rice");
	p[5].q = 0; p[5].p = 200; p[5].sq = 0; p[5].sp = 0; p[5].tq = 10;
	strcpy(p[6].name, "Grain");
	p[6].q = 0; p[6].p = 100; p[6].sq = 0; p[6].sp = 0; p[6].tq = 10;
	strcpy(p[7].name, "Noodles");
	p[7].q = 0; p[7].p = 20; p[7].sq = 0; p[7].sp = 0; p[7].tq = 10;
	strcpy(p[8].name, "Nuggets");
	p[8].q = 0; p[8].p = 125; p[8].sq = 0; p[8].sp = 0; p[8].tq = 10;
	strcpy(p[9].name, "Bubble");
	p[9].q = 0; p[9].p = 2; p[9].sq = 0; p[9].sp = 0; p[9].tq = 10;
	for (int i = 10; i < 50; i++) {
		strcpy(p[i].name, " ");
		p[i].q = 0; p[i].p = 0; p[i].sq = 0; p[i].sp = 0; p[i].tq = 10;
	}
	int PNum = 0, total = 0, program;
	char OIns;
	printf("\n\nMain Menu\nFor admin             Enter 1\nFor user              Enter 2\nFor exiting software  Enter 3\n: ");
	scanf("%d", &program);
	for (; program != 3;) {
		if (program == 2) {
			p[0].q = 0; p[1].q = 0; p[2].q = 0; p[3].q = 0; p[4].q = 0; p[5].q = 0; p[6].q = 0; p[7].q = 0; p[8].q = 0; p[9].q = 0;
			Items();
			printf("Do you want to know how to order? (y/n): ");
			scanf(" %c", &OIns);
			if (OIns == 'y')
			{
				OrderInstructions();
			}
		products:
			printf("\n----------------------------------\nEnter how many type of products you want to buy: ");
			scanf("%d", &PNum);
			if (PNum < 1 || PNum>10)
			{
				printf("\nPlease enter a number between 1 to 10");
				goto products;
			}
			else
			{
				OrderTaker(PNum);
				BillMaker();
			}
		}
		if (program == 1) {
		check1:
			printf("Enter username: ");
			scanf("%s", &UserName);
			if (strcmp(AUserName, UserName) != 0)
			{
				printf("Wrong username entered. Please enter again.\n");
				goto check1;
			}
		check2:
			printf("Enter password: ");
			scanf("%s", &Pass);
			if (strcmp(APass, Pass) != 0)
			{
				printf("Wrong password entered. Please enter again.\n");
				goto check2;
			}
			int adm = 1, addquan, prodno, netprice=1;
			for (; adm != 0;) {
				printf("\nIf you want to go to the Main Menu            enter 0 ");
				printf("\nIf you want to see quantity of your products  enter 1 ");
				printf("\nIf you want to add quantity to your products  enter 2 ");
				printf("\nIf you want to see price of your products     enter 3 ");
				printf("\nIf you want to change price of your products  enter 4 ");
				printf("\nIf you want to see sales report               enter 5 ");
				printf("\nIf you want to add a product                  enter 6 ");
				printf("\nIf you want to change username                enter 7 ");
				printf("\nIf you want to change password                enter 8\n: ");
				scanf("%d", &adm);
				if (adm == 1) {
					for (int i = 0; i < tp; i++) {
						printf("\n%d\t%s\t\t%d", i + 1, p[i].name, p[i].tq);
					}
					printf("\n");
				}
				if (adm == 2) {
					printf("Enter the quantity you want to add: ");
					scanf("%d", &addquan);
					printf("Enter the no of product you want to add quantity to: ");
					for (int i = 0; i < tp; i++) {
						printf("\n%d\t%s\t\t%d", i + 1, p[i].name, p[i].tq);
					}
					printf("\n");
					scanf("%d", &prodno);
					for (int i = 0; i < tp; i++) {
						if (prodno == (i + 1)) {
							p[i].tq = p[i].tq + addquan;
						}
					}
					printf("\n");
				}
				if (adm == 3) {
					for (int i = 0; i < tp; i++) {
						printf("\n%d\t%s\t\t%d", i + 1, p[i].name, p[i].p);
					}
					printf("\n");
				}
				if (adm == 4) {
					printf("\nEnter the no of product you want to change price of: ");
					for (int i = 0; i < tp; i++) {
						printf("\n%d\t%s\t\t%d", i + 1, p[i].name, p[i].p);
					}
					printf("\n:");
					scanf("%d", &prodno);
					for (int i = 0; i < 50; i++) {
						if (prodno == i + 1) {
							printf("\nEnter the new price of %s: ", p[i].name);
							scanf("%d", &p[i].p);
						}
					}
				}
				if (adm == 5) {
					for (int i = 0; i < tp; i++) {
						p[i].sp = p[i].sq * p[i].p;
					}
					for (int i = 0; i < tp; i++) {
						netprice = netprice + p[i].sp;
					}
					printf("\nTotal Sales of products:");
					printf("\nProduct\t\tQuantity\tPrice\n");
					for (int i = 0; i < tp; i++) {
						printf("\n%s\t\t%d\t\t%d", p[i].name, p[i].sq, p[i].sp);
					}
					printf("\n------------------------------------\nTotal\t\t\t\t%d\n", netprice - 1);
				}
				if (adm == 6) {
					printf("\nEnter the name of the product: ");
					scanf("%s", &p[tp].name);
					printf("Enter price of your product:");
					scanf("%d", &p[tp].p);
					printf("Enter quantity of your product:");
					scanf("%d", &p[tp].tq);
					tp++;
				}
				if (adm == 7)
				{
					printf("What username you want to change to? Kindly enter: \n");
					scanf("%s", &AUserName);
					printf("Username successfully changed!\n");
				}
				if (adm == 8)
				{
					printf("Kindly enter your new password: \n");
					scanf("%s", &APass);
					printf("Password changed successfully!\n");
				}
			}
		}
		for (int i = 0; i < 50; i++) {
			if (p[i].tq < 5) {
				printf("\n\nStock Alert!\n");
				break;
			}
		}
		for (int i = 0; i < 50; i++) {
			if (p[i].tq < 5)
			{
				printf("\nQuantity of %s is less than 5", p[i].name);
			}
		}
		printf("\n\nMain Menu\nFor admin             Enter 1\nFor user              Enter 2\nFor exiting software  Enter 3\n: ");
		scanf("%d", &program);
		for (; program <= 1 && program >= 3;)
			scanf("%d", &program);
	}
}