#include <stdio.h>
#include <string.h>
#include "functions.h"

void printMenu(){
	printf("***Bank Account Manager***\n");
	printf("\tMenu\n");
	printf("================================\n");
	printf("[1] Hien thi danh sach nguoi dung\n");
	printf("[2] Them nguoi dung\n");
	printf("================================\n");
}

void printUser(User users[], int userCount){
	printf("| %-10s | %-20s | %-15s | %-30s | %-10s |\n", "ID", "Name", "Phone", "Email", "Status");
    printf("====================================================================================================\n");
    for (int i=0;i<userCount;i++){
        printf("| %-10s | %-20s | %-15s | %-30s | %-10s |\n",users[i].id, users[i].name, users[i].phoneNumber,users[i].email, users[i].status == 0 ? "Unlock" : "Lock");
        printf("----------------------------------------------------------------------------------------------------\n");
	}
	printf("\n");
}

void addUser(User users[],int userCount){
    if(userCount>=100){
        printf("Dat gioi han them nguoi\n");
        return;
    }
    User newUser;
    printf("Nhap ID: ");
    fgets(newUser.id,sizeof(newUser.id),stdin);
    newUser.id[strcspn(newUser.id,"\n")]='\0';
    printf("Nhap ten: ");
    fgets(newUser.name,sizeof(newUser.name),stdin);
    newUser.name[strcspn(newUser.name,"\n")]='\0';
    printf("Nhap so dien thoai: ");
    fgets(newUser.phoneNumber,sizeof(newUser.phoneNumber),stdin);
    newUser.phoneNumber[strcspn(newUser.phoneNumber, "\n")]='\0';
    printf("Nhap email: ");
    fgets(newUser.email,sizeof(newUser.email),stdin);
    newUser.email[strcspn(newUser.email, "\n")]='\0';
    printf("Nhap ten dang nhap: ");
    fgets(newUser.userName,sizeof(newUser.userName),stdin);
    newUser.userName[strcspn(newUser.userName, "\n")]='\0';
    strcpy(newUser.password,newUser.phoneNumber);
    newUser.status=0;
    users[userCount]=newUser;
    printf("Them nguoi dung thanh cong \n");
}
