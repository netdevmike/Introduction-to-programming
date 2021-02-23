#include <stdio.h>  // preproccesser directive to include contents of file stdio.h
#include <stdlib.h> // preproccesser directive to include contents of file stdlib.h

typedef struct listNode
{
   char data;                // each listNode contains a character
   struct listNode *nextPtr; //pointer to next node
} ListNode;                  // synonym for struct listNode

typedef ListNode *ListNodePtr; // synonym for ListNode*

// prototypes
void insert(ListNodePtr *sPtr, char value);
void printList(ListNodePtr currentPtr);
char delete (ListNodePtr *sPtr, char value);
void searchData(ListNodePtr *sPtr); // prototype for search user data function
int isEmpty(ListNodePtr sPtr);
void instructions(void);

int main(void)
{
   ListNodePtr startPtr = NULL; // initially there are no nodes
   char item;                   // char entered by user

   instructions(); // display the menu
   printf("%s", "? ");
   unsigned int choice; // user's choice
   scanf("%u", &choice);
}