#include <stdio.h>  // preproccesser directive to include contents of file stdio.h
#include <stdlib.h> // preproccesser directive to include contents of file stdlib.h

// listNode struct definition
typedef struct listNode
{
   char data;                // each listNode contains a character
   struct listNode *nextPtr; //pointer to next node
} ListNode;                  // synonym for struct listNode

typedef ListNode *ListNodePtr; // synonym for ListNode*

// prototypes
void instructions(void);                     // prototype for instructions function
void insert(ListNodePtr *sPtr, char value);  // prototype for insert function
char delete (ListNodePtr *sPtr, char value); // prototype for delete function
char search(ListNodePtr *sPtr, char value);  // prototype for search function
void printList(ListNodePtr currentPtr);      // prototype for print function
int isEmpty(ListNodePtr sPtr);               // prototype for isempty function
void listSize(ListNodePtr currentPtr);       // prototype for listSize function

// main function
int main(void)
{
   ListNodePtr startPtr = NULL; // initially there are no nodes
   char item;                   // char entered by user

   instructions(); // display the menu
   printf("%s", "? ");
   unsigned int choice;  // user's choice
   scanf("%u", &choice); // scan user input into unsigned int choice

   // loop while user does not choose 5
   while (choice != 5)
   {

      switch (choice)
      {
      case 1:                                 // insert an element
         printf("%s", "Enter a character: "); // prompt user for input
         scanf("\n%c", &item);                // scan user input into char item
         insert(&startPtr, item);             // insert item in list
         printList(startPtr);                 // print list function
         break;
      case 2:                    // delete an element
         if (!isEmpty(startPtr)) // if list is not empty
         {
            printf("%s", "Enter character to be deleted: "); // prompt user for input
            scanf("\n%c", &item);                            // scan user input into char item

            // if character is found, remove it
            if (delete (&startPtr, item))
            { // remove item
               printf("%c deleted.\n", item);
               printList(startPtr); // print list
            }
            else // if user input not found in list
            {
               printf("%c not found.\n\n", item);
            }
         }
         else // if list is empty
         {
            puts("List is empty.\n");
         }

         break;
      case 3:                    // search list
         if (!isEmpty(startPtr)) // if list is not empty
         {
            printf("%s", "Enter character to search for: "); // prompt user for input
            scanf("\n%c", &item);                            // scan user input into char item

            // if character is found
            if (search(&startPtr, item))
            {
               printf("%c found.\n", item);
               printList(startPtr); // print list
            }
            else // if character not found
            {
               printf("%c not found.\n\n", item);
            }
         }
         else // if list is empty
         {
            puts("List is empty.\n"); // inform user that list is empty
         }

         break;
      case 4:                 // print list
         printList(startPtr); // print list function
         break;
      default:                      // default case
         puts("Invalid choice.\n"); // inform user of invalid choice
         instructions();            // instructions function
         break;
      } // end switch

      printf("%s", "? ");   // prompt user for next input
      scanf("%u", &choice); // scan user input into int choice
   }

   listSize(startPtr); // list size function

   puts("End of run."); // inform user of program end
}

// display program instructions to user
void instructions(void)
{
   puts("Enter your choice:\n"
        "   1 to insert an element into the list.\n"
        "   2 to delete an element from the list.\n"
        "   3 to search for an element in the list.\n"
        "   4 to print the list.\n"
        "   5 to end.");
}

// insert a new value into the list in sorted order
void insert(ListNodePtr *sPtr, char value)
{
   ListNodePtr newPtr = malloc(sizeof(ListNode)); // create node

   if (newPtr != NULL)
   {                          // is space available
      newPtr->data = value;   // place value in node
      newPtr->nextPtr = NULL; // node does not link to another node

      ListNodePtr previousPtr = NULL;
      ListNodePtr currentPtr = *sPtr;

      // loop to find the correct location in the list
      while (currentPtr != NULL && value > currentPtr->data)
      {
         previousPtr = currentPtr;         // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      }

      // insert new node at beginning of list
      if (previousPtr == NULL)
      {
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      }
      else
      { // insert new node between previousPtr and currentPtr
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      }
   }
   else
   {
      printf("%c not inserted. No memory available.\n", value);
   }
}

// delete a list element
char delete (ListNodePtr *sPtr, char value)
{
   // delete first node if a match is found
   if (value == (*sPtr)->data)
   {
      ListNodePtr tempPtr = *sPtr; // hold onto node being removed
      *sPtr = (*sPtr)->nextPtr;    // de-thread the node
      free(tempPtr);               // free the de-threaded node
      return value;
   }
   else
   {
      ListNodePtr previousPtr = *sPtr;
      ListNodePtr currentPtr = (*sPtr)->nextPtr;

      // loop to find the correct location in the list
      while (currentPtr != NULL && currentPtr->data != value)
      {
         previousPtr = currentPtr;         // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      }

      // delete node at currentPtr
      if (currentPtr != NULL)
      {
         ListNodePtr tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free(tempPtr);
         return value;
      }
   }

   return '\0';
}

// search for a list element
char search(ListNodePtr *sPtr, char value)
{
   // delete first node if a match is found
   if (value == (*sPtr)->data)
   {
      return value;
   }
   else
   {
      ListNodePtr previousPtr = *sPtr;
      ListNodePtr currentPtr = (*sPtr)->nextPtr;

      // loop to find the correct location in the list
      while (currentPtr != NULL && currentPtr->data != value)
      {
         previousPtr = currentPtr;         // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      }

      // delete node at currentPtr
      if (currentPtr != NULL)
      {
         ListNodePtr tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free(tempPtr);
         return value;
      }
   }

   return '\0';
}

// print the list
void printList(ListNodePtr currentPtr)
{
   // if list is empty
   if (isEmpty(currentPtr))
   {
      puts("List is empty.\n");
   }
   else
   {
      puts("The list is:");

      // while not the end of the list
      while (currentPtr != NULL)
      {
         printf("%c --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      }

      puts("NULL\n");
   }
}

// return 1 if the list is empty, 0 otherwise
int isEmpty(ListNodePtr sPtr)
{
   return sPtr == NULL;
}

// print size of list
void listSize(ListNodePtr currentPtr)
{
   int size = 0;  // declate size int variable
   int total = 0; // declate total int variable
   // if list is empty
   if (isEmpty(currentPtr))
   {
      puts("List is empty.\n");
   }
   else
   {
      // while not the end of the list
      while (currentPtr != NULL)
      {
         currentPtr = currentPtr->nextPtr;
         size++; // increment size int variable to count number of nodes
      }

      total = size * sizeof(struct listNode); // multiple size(number of nodes) by sizeof node structure
      // print number of nodes and size of linked list
      printf("%i nodes in the linked list\nSize of linked list: %i bytes \n", size, total);
   }
}
/*
Resources:
Deitel, Paul J., and Harvey M. Deitel. C: How to Program. Pearson, 2016. 
fig 12.03.c and fig 12.13.c
Search an element in a Linked List (Iterative and Recursive):
https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/
C program to search an element in linked list:
https://codeforwin.org/2018/05/c-program-to-search-an-element-in-linked-list.html
Linked List | Set 1 (Introduction)
https://www.geeksforgeeks.org/linked-list-set-1-introduction/
*/