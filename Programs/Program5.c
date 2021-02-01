// Fig. 6.5: fig06_05.c
// Initializing the elements of array s to the even integers from 2 to 20.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // maximum size of array
#define ROWS 2
#define COLUMNS 10
#define RANGE 100

void searchArray(int array[]);      // prototype function: searchArray
void printArray(int array[]);       // prototype function: printArray
void printArr(int a[][COLUMNS]);    // prototype function: printarr
void searchArr(int arr[][COLUMNS]); // prototype function: searchArr

// function main begins program execution
int main(void)
{
   // symbolic constant SIZE can be used to specify array size
   int array[SIZE]; // array s has SIZE elements
   time_t t;

   // Intializes random number generator
   srand((unsigned)time(&t));

   // creating 1D array with randome numbers
   for (size_t i = 0; i < SIZE; ++i)
   { // set the values for array 1
      array[i] = rand() % RANGE;
   }

   // creating 2D array with random number
   int arr[ROWS][COLUMNS];

   int rows;    // variable
   int columns; // variable
                // beginning forloop
   for (rows = 0; rows < ROWS; rows++)
   { // conditions for arrays rows
      for (columns = 0; columns < COLUMNS; columns++)
      {                                       // conditions for arrays columns
         arr[rows][columns] = rand() % RANGE; // loading arr with random random numbers less than 100
      }                                       // end forloop
   }

   // Print the arrays
   printf("This is the 1D array: \n");

   printArray(array);

   printf("\nThe size of the 1D array in bytes is %lu bytes:\n", sizeof(array)); // printing size of arr in bytes to the screen

   printf("\nThis is the 2D array: \n");

   printArr(arr);

   printf("\nThe size of the 2D array in bytes is %lu bytes:\n", sizeof(arr)); // printing size of arr in bytes to the screen

   // Search the arrays for numbers divisible by 3
   searchArray(array);

   searchArr(arr);

   // increment the arrays by a variable by a paramater that is passed by refernce
}

void printArr(int arr[][COLUMNS])
{ // parameters

   // beginning forloop
   for (int rows = 0; rows < ROWS; rows++)
   {                // conditions for loop
      printf("\n"); //start a new line for each row
      for (int columns = 0; columns < COLUMNS; columns++)
      {                                     // conditions for loop
         printf("%5d", arr[rows][columns]); // printing array
      }                                     // end forloop
   }                                        // end forloop
   printf("\n");                            // extra space
} // end function

void searchArr(int arr[][COLUMNS])
{ // parameters
   int found = 0;
   int holdArr[SIZE];
   int x = 0;

   // beginning forloop
   for (int rows = 0; rows < ROWS; rows++)
   {                // conditions for loop
      printf("\n"); //start a new line for each row
      for (int columns = 0; columns < COLUMNS; columns++)
      { // conditions for loop
         if (arr[rows][columns] % 3 == 0)
         {
            found++;
            holdArr[x] = arr[rows][columns];
            x++;
         }

      } // end forloop
   }    // end forloop
   printf("\nThere where, %d, numbers in the 2D array divisible by 3 which where: ", found);
   for (size_t i = 0; i < x; ++i)
   {
      printf("%d ", holdArr[i]);
   }
} // end function

void printArray(int array[])
{

   for (size_t i = 0; i < SIZE; ++i)
   {
      printf("%d ", array[i]);
   }

   printf("This is a 1D array in table format: \n");
   printf("%s%13s\n", "Element", "Array1");

   // output contents of array s in tabular format
   for (size_t i = 0; i < SIZE; ++i)
   {
      printf("%7zu%13d\n", i, array[i]);
   }
}

void searchArray(int array[])
{
   int found = 0;
   int x = 0;
   int holdArr[SIZE];

   // loop to control number of comparisons per pass
   for (size_t i = 0; i < SIZE; ++i)
   {
      // compare adjacent elements and swap them if first
      // element is greater than second element
      if (array[i] % 3 == 0)
      {
         found++;
         holdArr[x] = array[i];
         x++;
      }
   }

   printf("\nThere where, %d, numbers in the 1D array divisible by 3 which where: ", found);
   for (size_t i = 0; i < x; ++i)
   {
      printf("%d ", holdArr[i]);
   }
}

void addByReference(int array[])
{
}