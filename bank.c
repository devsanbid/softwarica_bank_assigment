#include "stdio.h"
#include "stdlib.h"

// Structure of customer information
struct Customer {
  char name[50];
  int accountNumber;
  float balance;
};

// function to add customer detail
void addCustomer(struct Customer customers[], int *count) {
  printf("\n");
  printf(" \tEnter customer \033[0;0;1mname\033[0m: ");
  scanf("%s", customers[*count].name);
  printf(" \tEnter account \033[0;0;1mnumber\033[0m: ");
  scanf("%d", &customers[*count].accountNumber);
  printf(" \tEnter initial \033[0;0;1mbalance\033[0m: ");
  scanf("%f", &customers[*count].balance);
  (*count)++;
  printf("\033[1;32m");
  system("clear");
  printf("\t  Customer added successfully!\n");
  printf("\033[0m");
}

// Function to display customer information
void displayCustomer(struct Customer customers[], int count) {
  int accountNumber;
  printf("\t Enter account number: ");
  scanf("%d", &accountNumber);
  int customerFound = 0;

  for (int i = 0; i < count; i++) {
    if (customers[i].accountNumber == accountNumber) {
      system("clear");
      printf(" \t ------------------------\n");
      printf(" \t Name: \033[34m%s\033[0m \n ", customers[i].name);
      printf(" \t Account Number: \033[35m%d\033[0m  \n",
             customers[i].accountNumber);
      printf(" \t Balance: \033[36m$%.2f\033[0m \n", customers[i].balance);
      printf(" \t ------------------------- \n");
      customerFound = 1;
      break;
    }
  }
  if (!customerFound) {
    system("clear");
    printf("\t \033[31m󰀕 Customer not found!\033[0m\n");
  }
}

// function to deposit money
void deposit(struct Customer customers[], int count) {
  int accountNumber;
  float amount;
  printf("\t Enter account number: ");
  scanf("%d", &accountNumber);
  printf("\t Enter amount to deposit: ");
  scanf("%f", &amount);

  for (int i = 0; i < count; i++) {
    if (customers[i].accountNumber == accountNumber) {
      customers[i].balance += amount;
      system("clear");
      printf("\033[1;32m");
      printf("\t \033[32m 󱉡 %0.2f$ deposited successfully!\033[0m\n",
             amount);
      printf("\033[0m");
      return;
    }
  }
  system("clear");
  printf("\t \033[31m󰀕 Customer not found!\033[0m\n");
}


void withdraw(struct Customer customers[], int count) {
  int accountNumber;
  float amount;
  printf("\t Enter account number: ");
  scanf("%d", &accountNumber);
  printf("\t Enter amount to withdraw: ");
  scanf("%f", &amount);

  for (int i = 0; i < count; i++) {
    if (customers[i].accountNumber == accountNumber) {
      if (customers[i].balance >= amount) {
        customers[i].balance -= amount;
        system("clear");
        printf("\033[1;32m");
        printf("\t \033[35m󱓮 %0.2f$ withdrawn successfully! \033[0m\n",
               amount);
        printf("\033[0m");
      } else {

        system("clear");
        printf("\t \033[31m󱉢 Insufficient balance!\033[0m\n");
      }
      return;
    }
  }
  system("clear");
  printf("\033[31m󰀕 Customer not found!\033[0m\n");
}

int main() {
  struct Customer customers[100];

  int count = 0;
  int choice;

  while (1) {
    printf("\n");
    printf(" \t |   Bank Management System  |\n");
    printf(" \t ------------------------------\n");
    printf("\033[0m");

    printf("\t 1.   Add Customer\n");
    printf("\t 2.   Display Customer\n");
    printf("\t 3. 󱉡 Deposit\n");
    printf("\t 4. 󱉠 Withdraw\n");
    printf("\t 5. 󰗼 Exit \n");
    printf("\n");
    printf("\t Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      addCustomer(customers, &count);
      break;
    case 2:
      displayCustomer(customers, count);
      break;
    case 3:
      deposit(customers, count);
      break;
    case 4:
      withdraw(customers, count);
      break;
    case 5:
      printf("\n");
      printf("\t \033[31m Exiting program...\033[0m\n");
      return 0;
    default:
      printf("\t Invalid choice! Please try again.\n");
    }
  }

  return 0;
}
