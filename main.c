#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	User users[50]={
		{"1234567899","Tran Quang Hiep","0925666555","tranquanghiep@gmail.com","tranhiep","tran",0},
		{"2345678911","Le Truong An","0925888111","letruongan@gmail.com","lean","le",0},
	};
	int userCount=2;
	do{
		printMenu();
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1:
				printUser(users,userCount);
				break;
				
			case 2:
				addUser(users,userCount);
				userCount++;
				break;
				
			case 3:
				printf("Thoat");
				break;
				
			default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
		}
	}while(choice!=3);
	return 0;
}
