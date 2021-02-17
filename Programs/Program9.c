#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CLIENTS 10

// clientData structure definition
typedef struct client
{
   const int id;                     // account id number
   char lastName[15], firstName[10]; // account last and first name
   double salary;                    // account salary
   int age;                          // account age
} Client;                            // new type name for struct client

// prototypes
unsigned int enterChoice(void);
void printData(Client *cPtr);
void searchData(Client *cPtr);
void totalSalaries(Client *cPtr);
void updateRecords(Client *cPtr);

// char *wLastName, char *wFistName, double *wSalary, int *wAge

int main()
{
   Client user[CLIENTS] = {
       {1275, "Hander", "Jack", 20.00, 38},    // user1 default value
       {9098, "Smith", "Ann", 25.22, 45},      // user2 default value
       {6731, "Webber", "Susanne", 18.55, 21}, // user3 default value
       {0176, "West", "Bill", 30.18, 34},      // user4 default value
       {1762, "Davis", "Mike", 22.15, 31}      // user5 default value
   };

   unsigned int choice; // user's choice
   // enable user to specify action
   while ((choice = enterChoice()) != 7)
   {
      switch (choice)
      {
      // create text file from record file
      case 1:
         printData(user);
         break;
      // search account data from record file
      case 2:
         searchData(user);
         break;
      // total salaries from account data
      case 3:
         totalSalaries(user);
         break;
      // update record
      case 4:
         updateRecords(user);
         break;
      // create record
      case 5:
         break;
      // delete existing record
      case 6:
         break;
      case 7:
         return 0;
         break;
      // display message if user does not select valid choice
      default:
         puts("Incorrect choice");
         break;
      }
   }

   return 0;
}

// enable user to input menu choice
unsigned int enterChoice(void)
{
   // display available options
   printf("%s", "\nEnter your choice\n"
                "1 - Print all account data\n"
                "2 - Search account data\n"
                "3 - Total Salaries\n"
                "4 - update an account\n"
                "5 - add a new account\n"
                "6 - delete an account\n"
                "7 - end program\n? ");
   int number;           // initialize int number
   scanf("%d", &number); // reads input and stores it
   return (number);      // returns user input stored at number
}

// print all user data
void printData(Client *cPtr)
{
   // loop through cPtr
   for (size_t i = 0; i < CLIENTS; ++i)
   {
      if (cPtr[i].id != 0)
      {
         printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);
      }
   }
}

void searchData(Client *cPtr)
{
   // display available options
   printf("%s", "\nWhat variable would you like to search through?\n"
                "1 - ID\n"
                "2 - Last Name\n"
                "3 - First Name\n"
                "4 - Age\n"
                "5 - return to main menu\n"
                "6 - end the program\n");
   int number;           // initialize int number
   scanf("%d", &number); // reads input and stores it
   unsigned int choice;  // user's choice
   int k, i;
   char lname[15];

   while ((choice = number) != 6)
   {
      switch (choice)
      {
      // Search for client based on ID number
      case 1:
         printf("\nEnter client ID number to search\n");
         scanf("%i", &k);
         for (i = 0; i < CLIENTS; i++)
         {
            if (k == cPtr[i].id)
            {
               break;
            }
         }
         if (i < CLIENTS)
         {
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);
            main();
         }
         else
         {
            printf("\nemployee not found\n");
            main();
         }
         break;
      // search for client based on last name
      case 2:
         printf("\nEnter employee last name to search\n");
         scanf("%s", lname);
         printf("%s", lname);
         for (i = 0; i < CLIENTS; i++)
         {
            if (strcmp(lname, cPtr[i].lastName) == 0)
            {
               break;
            }
         }
         if (i < CLIENTS)
         {
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);
            main();
         }
         else
         {
            printf("\nemployee not found\n");
            main();
         }
         break;
      // search for client based on first name
      case 3:
         printf("\nEnter employee last name to search\n");
         scanf("%s", lname);
         for (i = 0; i < CLIENTS; i++)
         {
            if (strcmp(lname, cPtr[i].firstName) == 0)
            {
               break;
            }
         }
         if (i < CLIENTS)
         {
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);
            main();
         }
         else
         {
            printf("\nemployee not found\n");
            main();
         }
         break;
      // search for client based on salary
      case 4:
         printf("\nEnter client age to search\n");
         scanf("%i", &k);
         for (i = 0; i < CLIENTS; i++)
         {
            if (k == cPtr[i].age)
            {
               break;
            }
         }
         if (i < CLIENTS)
         {
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);
            main();
         }
         else
         {
            printf("\nemployee not found\n");
            main();
         }
         break;
      case 5:
         main();
         break;
      // display message if user does not select valid choice
      default:
         printf("Incorrect choice");
         break;
      }
   }
}

void totalSalaries(Client *cPtr)
{
   double total = 0;
   // loop through cPtr
   for (size_t i = 0; i < CLIENTS; ++i)
   {
      if (cPtr[i].id != 0)
      {
         total += cPtr[i].salary;
      }
   }

   printf("%.2lf\n", total);
}

void updateRecords(Client *cPtr)
{
   int number;          // initialize int number
   unsigned int choice; // user's choice
   int k, i;
   char name[15];
   double m;

   printf("\nInput the ID number of the user you would like to update\n");
   scanf("%i", &k);
   for (i = 0; i < CLIENTS; i++)
   {
      if (k == cPtr[i].id)
      {
         break;
      }
   }
   if (i < CLIENTS)
   {
      printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);

      // display available options
      printf("%s", "\nWhat variable would you like to update for this user?\n"
                   "1 - Last Name\n"
                   "2 - First Name\n"
                   "3 - Salary\n"
                   "4 - Age\n"
                   "5 - return to main menu\n");
      scanf("%d", &number); // reads input and stores it

      while ((choice = number) != 6)
      {
         switch (choice)
         {
         // case to update client last name
         case 1:
            printf("\nCurrent last name of client %i is %s, what would you like the new last name to be?\n", cPtr[i].id, cPtr[i].lastName);
            scanf("%s", name);
            strcpy(cPtr[i].lastName, name);

            printf("\nupdated client file:\n");
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);

            break;
         // case to update client first name
         case 2:
            printf("\nCurrent first name of client %i is %s, what would you like the new first name to be?\n", cPtr[i].id, cPtr[i].firstName);
            scanf("%s", name);
            strcpy(cPtr[i].firstName, name);

            printf("\nupdated client file:\n");
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);

            break;
         // case to update client salary
         case 3:
            printf("\nCurrent salary of client %i is %lf, what would you like the new salary to be?\n", cPtr[i].id, cPtr[i].salary);
            scanf("%lf", &m);
            cPtr[i].salary = m;

            printf("\nupdated client file:\n");
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);
            break;
         // case to update client age
         case 4:
            printf("\nCurrent age of client %i is %i, what would you like the new age to be?\n", cPtr[i].id, cPtr[i].age);
            scanf("%i", &k);
            cPtr[i].age = k;

            printf("\nupdated client file:\n");
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);

            break;
         case 5:
            main();
            break;
         }
      }
   }
   else
   {
      printf("\nemployee not found\n");
   }
}

/*
Resources:
https://overiq.com/c-programming-101/typedef-statement-in-c/
*/
