#include "dataType.h"

void printAdmin();
void printMenu();
void printUser(User users[50],int userCount);
void addUser(User users[50],int *userCount);
void searchUserByName(User users[],int userCount,int *find);
void viewUserDetails(User users[],int userCount);
void lockUnlockUser(User users[],int userCount);
void sortUsersByName(User users[],int userCount);
void loadUsersFromFile(User users[],int *userCount);
void saveUsersToFile(User users[],int userCount);
