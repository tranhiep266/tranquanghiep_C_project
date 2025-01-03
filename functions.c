#include <stdio.h>
#include <string.h>
#include "functions.h"

void printMenu(){
	printf("***Bank Account Manager***\n");
	printf("\tMenu\n");
	printf("================================\n");
	printf("[1] Hien thi danh sach nguoi dung\n");
	printf("[2] Them nguoi dung\n");
	printf("[3] Tim ten nguoi dung\n");
	printf("[4] Tim id nguoi dung\n");
	printf("[5] Khoa/Mo khoa nguoi dung\n");
	printf("[6] Sap xep nguoi dung\n");
	printf("[7] Lay du lieu\n");
	printf("[8] Luu du lieu\n");
	printf("[9] Thoat\n");
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

void addUser(User users[],int *userCount){
	*userCount=2;
    if(*userCount>=100){
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
    newUser.email[strcspn(newUser.email,"\n")]='\0';
    printf("Nhap ten dang nhap: ");
    fgets(newUser.userName,sizeof(newUser.userName),stdin);
    newUser.userName[strcspn(newUser.userName,"\n")]='\0';
    strcpy(newUser.password,newUser.phoneNumber);
    newUser.status=0;
    if(strlen(newUser.name)==0||strlen(newUser.name)>30||strlen(newUser.phoneNumber)==0||strlen(newUser.phoneNumber)>10||strlen(newUser.email)==0||strlen(newUser.email)>50||strlen(newUser.userName)>20||strlen(newUser.id)==0||strlen(newUser.id)>10){
        printf("Sai du lieu nguoi dung\n");
        return;
    }
    for(int i=0;i<*userCount;i++){
        if(strcmp(users[i].id,newUser.id)==0||strcmp(users[i].userName,newUser.userName)==0||strcmp(users[i].phoneNumber,newUser.phoneNumber)==0||strcmp(users[i].email,newUser.email)==0){
            printf("Du lieu da ton tai\n");
            return;
        }
    }
    users[*userCount]=newUser;
    (*userCount)++;
    printf("Them nguoi dung thanh cong\n");
}

void searchUserByName(User users[],int userCount,int *find){
	*find=0;
    char name[50];
    printf("Nhap ten can tim: ");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")]='\0';
    printf("\n--- Ket Qua Tim Kiem ---\n");
    printf("| %-10s | %-20s | %-15s | %-30s | %-10s |\n", "ID", "Name", "Phone", "Email", "Status");
    printf("====================================================================================================\n");
    for(int i=0;i<userCount;i++){
        if (strstr(users[i].name,name)){
            printf("| %-10s | %-20s | %-15s | %-30s | %-10s |\n",users[i].id, users[i].name, users[i].phoneNumber,users[i].email, users[i].status == 0 ? "Unlock" : "Lock");
            printf("----------------------------------------------------------------------------------------------------\n");
            (*find)++;
        }
    }
    if(*find==0){
    	printf("Khong tim thay du lieu nguoi dung\n");
	}
}

void viewUserDetails(User users[],int userCount){
    char id[20];
    printf("Nhap ID nguoi dung muon tim kiem: ");
    fgets(id,sizeof(id),stdin);
    id[strcspn(id,"\n")] = '\0';
    printf("\n--- Ket Qua Tim Kiem ---\n");
    printf("| %-10s | %-20s | %-15s | %-30s | %-10s |\n", "ID", "Name", "Phone", "Email", "Status");
    printf("====================================================================================================\n");
    for(int i=0;i<userCount;i++){
        if(strcmp(users[i].id,id)==0){
            printf("| %-10s | %-20s | %-15s | %-30s | %-10s |\n",users[i].id,users[i].name,users[i].phoneNumber,users[i].email,users[i].status == 0 ? "Unlock" : "Lock");
            printf("----------------------------------------------------------------------------------------------------\n");
            return;
        }
    }
    printf("Khong tim thay ID nguoi dung\n");
}

void choiceMenu(int choice){
	while(1){
  		printf("\n\tGo back(1)? or Exit(2): ");
	    scanf("%d", &choice);
        if(choice==1){
        	break;
        }else if(choice==2){
        	exit (1);
	    }else{
		    printf("\n\tLua chon khong hop le. Vui long nhap lai\n\n");
		    fflush(stdin);
	        continue;
	    }
	}
}

void lockUnlockUser(User users[],int userCount){
    char id[20];
    printf("Nhap ID nguoi dung de mo khoa: ");
    fgets(id,sizeof(id),stdin);
    id[strcspn(id,"\n")]='\0';
    for(int i=0;i<userCount;i++){
        if(strcmp(users[i].id,id)==0){
            users[i].status = !users[i].status;
            printf("Nguoi dung da duoc %s thanh cong.\n",users[i].status == 0 ? "Unlock" : "Lock");
            return;
        }
    }
    printf("Khong tim thay ID nguoi dung.\n");
}

void sortUsersByName(User users[],int userCount){
	int sortUser;
	printf("1.Sap xep ten theo tu a->z\n");
	printf("2.Sap xep ten theo tu z->a\n");
	printf("Lua chon cua ban:\n");
	scanf("%d",&sortUser);
	getchar();
	if(sortUser==1){
		for(int i=0;i<userCount-1;i++){
            for(int j=i+1;j<userCount;j++){
                if(strcmp(users[i].name,users[j].name)>0){
                    User temp=users[i];
                    users[i]=users[j];
                    users[j]=temp;
                }
            }
        }
	}
	if(sortUser==2){
		for(int i=0;i<userCount-1;i++){
            for(int j=i+1;j<userCount;j++){
                if(strcmp(users[i].name,users[j].name)<0){
                    User temp=users[i];
                    users[i]=users[j];
                    users[j]=temp;
                }
            }
        }
	}
}

void loadUsersFromFile(User users[],int *userCount){
    FILE *file=fopen("bankData.dat","rb");
    if(file == NULL){
        printf("Khong the mo file de doc du lieu\n");
        return;
    }
    fread(userCount,sizeof(int),1,file);
    fread(users,sizeof(User),*userCount,file);
    printf("Lay du lieu thanh cong\n");
    fclose(file);
}

void saveUsersToFile(User users[],int userCount){
    FILE *file=fopen("bankData.dat","wb");
    if(file==NULL){
        printf("Khong the mo file de ghi du lieu\n");
        return;
    }
    fwrite(&userCount,sizeof(int),1,file);
    fwrite(users,sizeof(User),userCount,file);
    printf("Luu du lieu thanh cong\n");
    fclose(file);
}

