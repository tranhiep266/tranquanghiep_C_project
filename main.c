#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	User users[50]={
		{"1","Tran Quang Hiep","0987"},
		{"2","Le Truong An","0789"},
	};
	int n=2;
	do{
		printMenu();
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printUser(users,n);
				break;
				
			case 2:
				break;
				
			default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
		}
	}while(choice!=2);
	return 0;
}
