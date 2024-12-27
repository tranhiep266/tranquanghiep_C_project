#include <stdio.h>
#include "functions.h"

void printMenu(){
	printf("***Bank Account Manager***\n");
	printf("\tMenu\n");
	printf("================================\n");
	printf("[1] Hien thi danh sach nguoi dung\n");
	printf("[2] Them nguoi dung\n");
	printf("================================\n");
}

void printUser(User users[], int n){
	printf("In toan bo cac nguoi dung: \n");
	for(int i=0 ;i<n;i++){
		printf("ID: %s\n", users[i].userId);
		printf("Ho va ten nguoi dung: %s\n", users[i].name);
		printf("So dien thoai nguoi dung: %s\n", users[i].phone);
	}
	printf("\n");
}


