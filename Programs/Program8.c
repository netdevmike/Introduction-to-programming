#include <stdio.h>  // preproccesser directive to include contents of file stdio.h
#include <stdlib.h> // preproccesser directive to include contents of file stdlib.h
#include <time.h>   // preproccesser directive to include contents of file time.h
#include <string.h> // preproccesser directive to include contents of file string.h

#define CLIENTS 10 // maximum number of clients

// clientData structure definition
typedef struct client
{
   const int id;                     // account id number
   char lastName[15], firstName[10]; // account last and first name
   double salary;                    // account salary
   int age;                          // account age
} Client;                            // new type name for struct client

// prototypes
unsigned int enterChoice(void);   // prototype for choice function
void printData(Client *cPtr);     // prototype for print user data function
void searchData(Client *cPtr);    // prototype for search user data function
void totalSalaries(Client *cPtr); // prototype for total salariesfunction
void updateRecords(Client *cPtr); // prototype for update user data function

// main function
int main()
{
   Client user[CLIENTS] = {
       {1275, "Hander", "Jack", 20.00, 38},    // user1 default value
       {9098, "Smith", "Ann", 25.22, 45},      // user2 default value
       {6731, "Webber", "Susanne", 18.55, 21}, // user3 default value
       {8755, "West", "Bill", 30.18, 34},      // user4 default value
       {1762, "Davis", "Mike", 22.15, 31}      // user5 default value
   };

   unsigned int choice; // user choice int value
   // enable user to specify action
   while ((choice = enterChoice()) != 5) // enter choice function, if 5 end program
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
      // display message if user does not select valid choice
      default:
         printf("Incorrect choice");
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
                "5 - end program\n? ");
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
         // print data if user id is present
         printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);
      }
   }
}

// search all user data
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
   int k, i;             // initialize int k & i
   char lname[15];       // initialize char lname

   while ((choice = number) != 6)
   {
      switch (choice)
      {
      // Search for client based on ID number
      case 1:
         printf("\nEnter client ID number to search\n");
         scanf("%i", &k); // assign user input to k
         // loop through cPtr
         for (i = 0; i < CLIENTS; i++)
         {
            if (k == cPtr[i].id) // check if ID input from user is present
            {
               break;
            }
         }
         if (i < CLIENTS) // i should be less than number of clients of user input was present
         {
            // print client data
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);
            return;
         }
         else
         {
            // if user ID input not present
            printf("\nClient not found\n");
            return;
         }
         break;
      // search for client based on last name
      case 2:
         printf("\nEnter client last name to search\n");
         scanf("%s", lname); // assign user input to lname
         // loop through cPtr
         for (i = 0; i < CLIENTS; i++)
         {
            if (strcmp(lname, cPtr[i].lastName) == 0) // check if user input is present
            {
               break;
            }
         }
         if (i < CLIENTS) // i should be less than number of clients if user input was present
         {
            // print client data
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);
            return;
         }
         else
         {
            // if user last name input not present
            printf("\nClient not found\n");
            return;
         }
         break;
      // search for client based on first name
      case 3:
         printf("\nEnter client last name to search\n");
         scanf("%s", lname); // assign user input to lname
         // loop through cPtr
         for (i = 0; i < CLIENTS; i++)
         {
            if (strcmp(lname, cPtr[i].firstName) == 0) // check if user input is present
            {
               break;
            }
         }
         if (i < CLIENTS) // i should be less than number of clients if user input was present
         {
            // print user data
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);
            return;
         }
         else
         {
            // if user input last name input not present
            printf("\nClient not found\n");
            return;
         }
         break;
      // search for client based on age
      case 4:
         printf("\nEnter client age to search\n");
         scanf("%i", &k); // assign user input to k
         // loop through cPtr
         for (i = 0; i < CLIENTS; i++)
         {
            if (k == cPtr[i].age) // check if user input is present
            {
               break;
            }
         }
         if (i < CLIENTS) // i should be less than number of clients if user input was present
         {
            // print user data
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);
            return;
         }
         else
         {
            // if user input age not present
            printf("\nClient not found\n");
            return;
         }
         break;
      case 5:
         // return to main function
         return;
         break;
      // display message if user does not select valid choice
      default:
         printf("Incorrect choice");
         break;
      }
   }
}

// total all client salaries
void totalSalaries(Client *cPtr)
{
   double total = 0; // initialize double total
   // loop through cPtr
   for (size_t i = 0; i < CLIENTS; ++i)
   {
      if (cPtr[i].id != 0) // if client exists
      {
         total += cPtr[i].salary; // add salary to total
      }
   }

   printf("%.2lf\n", total); // print total salary of all clients
}

// update client records
void updateRecords(Client *cPtr)
{
   int number, k, i;    // initialize int number k and i
   unsigned int choice; // user's choice
   char name[15];       // initialize name char
   double m;            // initialize m double

   printf("\nInput the ID number of the user you would like to update\n");
   scanf("%i", &k); // assign user input to k
   // loop through cPtr
   for (i = 0; i < CLIENTS; i++)
   {
      if (k == cPtr[i].id) // if id from user input is present
      {
         break;
      }
   }
   if (i < CLIENTS) // i should be less than number of clients if user input was present
   {
      // print client data
      printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);

      // display available options to update client data
      printf("%s", "\nWhat variable would you like to update for this user?\n"
                   "1 - Last Name\n"
                   "2 - First Name\n"
                   "3 - Salary\n"
                   "4 - Age\n"
                   "5 - return to main menu\n"
                   "6 - end the program\n");
      scanf("%d", &number); // reads input and stores it

      while ((choice = number) != 6)
      {
         switch (choice)
         {
         // case to update client last name
         case 1:
            printf("\nCurrent last name of client %i is %s, what would you like the new last name to be?\n", cPtr[i].id, cPtr[i].lastName);
            scanf("%s", name);              // assign user input to name
            strcpy(cPtr[i].lastName, name); // assign name to lastName of client

            // print updated client file
            printf("\nupdated client file:\n");
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);

            // return to main
            return;
            break;
         // case to update client first name
         case 2:
            printf("\nCurrent first name of client %i is %s, what would you like the new first name to be?\n", cPtr[i].id, cPtr[i].firstName);
            scanf("%s", name);               // assign user input to name
            strcpy(cPtr[i].firstName, name); // assign name to firstName of client

            // print updated client file
            printf("\nupdated client file:\n");
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);

            // return to main
            return;
            break;
         // case to update client salary
         case 3:
            printf("\nCurrent salary of client %i is %lf, what would you like the new salary to be?\n", cPtr[i].id, cPtr[i].salary);
            scanf("%lf", &m);   // assign user input to m
            cPtr[i].salary = m; // assign m to salary of client

            // print updated client file
            printf("\nupdated client file:\n");
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);

            // return to main
            return;
            break;
         // case to update client age
         case 4:
            printf("\nCurrent age of client %i is %i, what would you like the new age to be?\n", cPtr[i].id, cPtr[i].age);
            scanf("%i", &k); // assign user input to k
            cPtr[i].age = k; // assign k to age of client

            // print updated client file
            printf("\nupdated client file:\n");
            printf("\nUser Id: %i\nLast Name: %s\nFirst Name: %s\nSalary: %.2lf\nAge: %i\n ", cPtr[i].id, cPtr[i].lastName, cPtr[i].firstName, cPtr[i].salary, cPtr[i].age);

            // return to main
            return;
            break;
         case 5:
            // return to main
            return;
            break;
         }
      }
   }
   else
   {
      printf("\nClient not found\n");
   }
}

/*
Resources:
Deitel, Paul J., and Harvey M. Deitel. C: How to Program. Pearson, 2016. 
https://beginnersbook.com/2014/01/c-structures-examples/
https://www.programiz.com/c-programming/c-structures
https://www.geeksforgeeks.org/structures-c/
https://overiq.com/c-programming-101/typedef-statement-in-c/
fig 10.03.c and fig 11.15.c
*/
