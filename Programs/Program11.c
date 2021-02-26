#include <stdio.h>  // preproccesser directive to include contents of file stdio.h
#include <stdlib.h> // preproccesser directive to include contents of file stdlib.h

// self-referential structure
typedef struct stackNode
{
   int data;                  // define data as an int
   struct stackNode *nextPtr; // stackNode pointer
} StackNode;                  // synonym for struct stackNode

typedef StackNode *StackNodePtr; // synonym for StackNode*

// prototypes
void push(StackNodePtr *topPtr, int info); // prototype for push function
int pop(StackNodePtr *topPtr);             // prototype for pop function
int isEmpty(StackNodePtr topPtr);          // prototype for isEmpty function
void printStack(StackNodePtr currentPtr);  // prototype for printStack function
void instructions(void);                   // prototype for instructions function

// function main begins program execution
int main(void)
{
   printf("__DATE__ = %s\n", __DATE__); // print predefined date value macro
   printf("__TIME__ = %s\n", __TIME__); // print predefined time value macro
   printf("\n");                        // add space

   StackNodePtr stackPtr = NULL; // points to stack top
   int value;                    // int input by user

   instructions(); // display the menu
   printf("%s", "? ");
   unsigned int choice;  // user's choice
   scanf("%u", &choice); // scan user input into unsigned int choice

   // while user does not enter 4
   while (choice != 4)
   {

      switch (choice)
      {
      // push value onto stack
      case 1:
         printf("%s", "Enter an integer: "); //prompt user for input
         scanf("%d", &value);                // scan user input into int value
         push(&stackPtr, value);             // push value into stackPtr
         printStack(stackPtr);               // print stackPtr using printStack function
         break;
      // pop value off stack
      case 2:
         // if stack is not empty
         if (!isEmpty(stackPtr))
         {
            printf("The popped value is %d.\n", pop(&stackPtr)); // pop value off stack using pop function
         }

         printStack(stackPtr); // print stackPtr using printStack function
         break;
      // print stack
      case 3:
         printStack(stackPtr); // print stackPtr using printStack function
         break;
      // default case
      default:
         puts("Invalid choice.\n"); // inform user of invalid choice
         instructions();            // instructions function
         break;
      } // end switch

      printf("%s", "? ");   // prompt user for next input
      scanf("%u", &choice); // scan user input into int choice
   }

   puts("End of run."); // inform user of program end
}

// display program instructions to user
void instructions(void)
{
   puts("Enter choice:\n"
        "1 to push a value on the stack\n"
        "2 to pop a value off the stack\n"
        "3 to print the stack\n"
        "4 to end program");
}

// insert a node at the stack top
void push(StackNodePtr *topPtr, int info)
{
   StackNodePtr newPtr = malloc(sizeof(StackNode)); // create node

   // insert the node at stack top
   if (newPtr != NULL)
   {                             // space available
      newPtr->data = info;       // place value in node
      newPtr->nextPtr = *topPtr; // walk to ...
      *topPtr = newPtr;          // ... next node
   }
   else
   { // no space available
      printf("%d not inserted. No memory available.\n", info);
   }
}

// remove a node from the stack top
int pop(StackNodePtr *topPtr)
{
   StackNodePtr tempPtr = *topPtr;
   int popValue = (*topPtr)->data;
   *topPtr = (*topPtr)->nextPtr;
   free(tempPtr);
   return popValue;
}

// print the stack
void printStack(StackNodePtr currentPtr)
{
   // if stack is empty
   if (currentPtr == NULL)
   {
      puts("The stack is empty.\n");
   }
   else
   {
      puts("The stack is:");

      // while not the end of the stack
      while (currentPtr != NULL)
      {
         printf("%d --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      }

      puts("NULL\n");
   }
}

// return 1 if the stack is empty, 0 otherwise
int isEmpty(StackNodePtr topPtr)
{
   return topPtr == NULL;
}

/*
Resources:
Deitel, Paul J., and Harvey M. Deitel. C: How to Program. Pearson, 2016. 
fig 12.08.c and ex 13.02.c
*/