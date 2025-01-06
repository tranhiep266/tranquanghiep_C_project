#include <stdio.h>
#include <string.h>
#include "functions.h"

void printAdmin(){
	system("cls");
	printf("***Bank Account Manager***\n");
	printf("================================\n");
	printf("[1]. Quan tri vien\n");
	printf("[2]. nguoi dung\n");
	printf("[3]. Thoat\n");
	printf("================================\n");
}

void printMenu(){
	system("cls");
	printf("***Bank Account Manager***\n");
	printf("\tMenu\n");
	printf("================================\n");
	printf("[1]. Hien thi danh sach nguoi dung\n");
	printf("[2]. Them nguoi dung\n");
	printf("[3]. Tim ten nguoi dung\n");
	printf("[4]. Tim id nguoi dung\n");
	printf("[5]. Khoa/Mo khoa nguoi dung\n");
	printf("[6]. Sap xep nguoi dung\n");
	printf("[7]. Lay du lieu\n");
	printf("[8]. Luu du lieu\n");
	printf("[9]. Thoat\n");
	printf("================================\n");
}

void printUser(User users[], int userCount){
	system("cls");
	printf("| %-10s | %-25s | %-15s | %-30s | %-10s |\n", "ID", "Name", "Phone", "Email", "Status");
    printf("==========================================================================================================\n");
    for (int i=0;i<userCount;i++){
        printf("| %-10s | %-25s | %-15s | %-30s | %-10s |\n",users[i].id, users[i].name, users[i].phoneNumber,users[i].email, users[i].status == 0 ? "Unlock" : "Lock");
        printf("----------------------------------------------------------------------------------------------------------\n");
	}
	printf("\n");
	int choice;
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

void addUser(User users[],int *userCount){
	system("cls");
	*userCount=2;
    if(*userCount>=100){
        printf("Dat gioi han them nguoi\n");
        return;
    }
    User newUser;
//Them ID
    while(1){
        int isValid=1;
        printf("ID (10 ky tu): ");
        fgets(newUser.id, sizeof(newUser.id), stdin);
        newUser.id[strcspn(newUser.id, "\n")] = '\0'; 
        if(strlen(newUser.id)<10){
            printf("Nhap thieu chu so. Vui long nhap lai\n");
            isValid=0;
        }else if(strlen(newUser.id)>10){
            printf("Nhap thua chu so. Vui long nhap lai\n");
            isValid=0;
        }else{
            for(int i=0;i<*userCount;i++){
                if(strcmp(newUser.id,users[i].id)==0){
                    printf("ID da ton tai\n");
                    isValid=0;
                    break;
                }
            }
        }
        for(int i=0;i<strlen(newUser.id);i++){
        	if(newUser.id[i]>='a'&&newUser.id[i]<='z'||newUser.id[i]>='A'&&newUser.id[i]<='z'||newUser.id[i]==' '){
        		printf("Nhap chua ky tu. Vui long nhap lai\n");
                isValid=0;
                break;
			}
		}
        if(isValid){
            break;
        }
    }
//Them Name
    while(1){
        int isValid=1;
        printf("Nhap ho va ten: ");
        fgets(newUser.name,sizeof(newUser.name),stdin);
        newUser.name[strcspn(newUser.name, "\n")]='\0';
        for(int i=0;i<strlen(newUser.name);i++){
        	if(newUser.name[i]>='0'&&newUser.name[i]<='9'){
        		printf("Nhap chua chu so. Vui long nhap lai\n");
                isValid=0;
                break;
			}
		}
        if(isValid){
            break;
        }
    }
//Them Phone
    while(1){
        int isValid=1;
        printf("Nhap so dien thoai: ");
        fgets(newUser.phoneNumber, sizeof(newUser.phoneNumber), stdin);
        newUser.phoneNumber[strcspn(newUser.phoneNumber, "\n")] = '\0'; 
        if(strlen(newUser.phoneNumber)<10){
            printf("Nhap thieu chu so. Vui long nhap lai\n");
            isValid=0;
        }else if(strlen(newUser.phoneNumber)>10){
            printf("Nhap thua chu so. Vui long nhap lai\n");
            isValid=0;
        }else{
            for(int i=0;i<*userCount;i++){
                if(strcmp(newUser.phoneNumber,users[i].phoneNumber)==0){
                    printf("So dien thoai da ton tai\n");
                    isValid=0;
                    break;
                }
            }
        }
        for(int i=0;i<strlen(newUser.phoneNumber);i++){
        	if(newUser.phoneNumber[i]>='a'&&newUser.phoneNumber[i]<='z'||newUser.phoneNumber[i]>='A'&&newUser.phoneNumber[i]<='z'||newUser.phoneNumber[i]==' '){
        		printf("Nhap chua ky tu. Vui long nhap lai\n");
                isValid=0;
                break;
			}
		}
        if(isValid){
            break;
        }
    }
//Them Email
    while(1){
        int isValid=1;
        printf("Nhap email: ");
        fgets(newUser.email, sizeof(newUser.email), stdin);
        newUser.email[strcspn(newUser.email, "\n")] = '\0'; 
            for(int i=0;i<*userCount;i++){
                if(strcmp(newUser.email,users[i].email)==0){
                    printf("email da ton tai\n");
                    isValid=0;
                    break;
                }
            }
        if(isValid){
            break;
        }
    }
//Them userName&password
    while(1){
        int isValid=1;
        printf("Nhap ten dang nhap: ");
        fgets(newUser.userName,sizeof(newUser.userName),stdin);
        newUser.userName[strcspn(newUser.userName,"\n")]='\0'; 
            for(int i=0;i<*userCount;i++){
                if(strcmp(newUser.email,users[i].email)==0){
                    printf("email da ton tai\n");
                    isValid=0;
                    break;
                }
            }
        if(isValid){
        	newUser.status=0;
        	strcpy(newUser.password,newUser.phoneNumber);
            break;
        }
    }
//Them vao danh sach
    users[*userCount]=newUser;
    (*userCount)++;
    printf("Them nguoi dung thanh cong\n");
    int choice;
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

void searchUserByName(User users[],int userCount,int *find){
	system("cls");
	*find=0;
    char name[50];
    printf("Nhap ten can tim: ");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")]='\0';
    printf("\n--- Ket Qua Tim Kiem ---\n");
    printf("| %-10s | %-20s | %-15s | %-30s | %-10s |\n", "ID", "Name", "Phone", "Email", "Status");
    printf("====================================================================================================\n");
    for(int i=0;i<userCount;i++){
        if(strstr(users[i].name,name)){
            printf("| %-10s | %-20s | %-15s | %-30s | %-10s |\n",users[i].id, users[i].name, users[i].phoneNumber,users[i].email, users[i].status == 0 ? "Unlock" : "Lock");
            printf("----------------------------------------------------------------------------------------------------\n");
            (*find)++;
        }
    }
    if(*find==0){
    	printf("Khong tim thay du lieu nguoi dung\n");
	}
	int choice;
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

void viewUserDetails(User users[],int userCount){
	system("cls");
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
    int choice;
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
	system("cls");
    char id[20];
    int check=0;
    printf("Nhap ID nguoi dung de mo khoa: ");
    fgets(id,sizeof(id),stdin);
    id[strcspn(id,"\n")]='\0';
    for(int i=0;i<userCount;i++){
        if(strcmp(users[i].id,id)==0){
            users[i].status = !users[i].status;
            printf("Nguoi dung da duoc %s thanh cong.\n",users[i].status == 0 ? "Unlock" : "Lock");
            check=1;
        }
    }
	if(check==0){
    	printf("Khong tim thay ID nguoi dung.\n");
	}
    
    int choice;
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

void sortUsersByName(User users[],int userCount){
	system("cls");
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
        printf("Sap xep nguoi dung thanh cong\n");
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
        printf("Sap xep nguoi dung thanh cong\n");
	}
	int choice;
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

void loadUsersFromFile(User users[],int *userCount){
	system("cls");
    FILE *file=fopen("bankData.dat","rb");
    if(file == NULL){
        printf("Khong the mo file de doc du lieu\n");
        return;
    }
    fread(userCount,sizeof(int),1,file);
    fread(users,sizeof(User),*userCount,file);
    printf("Lay du lieu thanh cong\n");
    fclose(file);
    int choice;
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

void saveUsersToFile(User users[],int userCount){
	system("cls");
    FILE *file=fopen("bankData.dat","wb");
    if(file==NULL){
        printf("Khong the mo file de ghi du lieu\n");
        return;
    }
    fwrite(&userCount,sizeof(int),1,file);
    fwrite(users,sizeof(User),userCount,file);
    printf("Luu du lieu thanh cong\n");
    fclose(file);
    int choice;
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


