#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int option;
	int optionAdmin;
	User users[50]={
		{"1234567899","Tran Quang Hiep","0925666555","tranquanghiep@gmail.com","tranhiep","tran",0},
		{"2345678911","Le Truong An","0925888111","letruongan@gmail.com","lean","le",0},
	};
	int userCount=2;
	int find=0;
	int choice;
	User user;
	User newUser;
	do{
		printAdmin();
		printf("Lua chon cua ban: ");
		scanf("%d",&optionAdmin);
		getchar();
		switch(optionAdmin){
			case 1:
			do{
				printMenu();
				printf("Lua chon cua ban: ");
				scanf("%d",&option);
				getchar();
				switch(option){
					case 1:
						printUser(users,userCount);
						break;
				
					case 2:
						addUser(users,&userCount);
						break;
				
					case 3:
						searchUserByName(users,userCount,&find);
						break;
				
					case 4:
						viewUserDetails(users,userCount);
						break;
				
					case 5:
						lockUnlockUser(users,userCount);
						break;
				
					case 6:
						sortUsersByName(users,userCount);
						printUser(users,userCount);
						break;
				
				    case 7:
				    	loadUsersFromFile(users,&userCount);
				    	break;
				    	
				    case 8:
				    	saveUsersToFile(users,userCount);
				    	break;
				
					case 9:
						printf("Thoat");
		        		break;
				
		        	default:
                        printf("Lua chon khong hop le. Vui long nhap lai\n");
	        	}
        	}while(option!=9);
        	
        	case 2:
        		break;
        		
        	case 3:
        		printf("Hen gap lai");
        		break;
		}
	}while(optionAdmin!=3);
	return 0;
}
