// Fig. 6.5: fig06_05.c
// Initializing the elements of array s to the even integers from 2 to 20.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // maximum size of array
#define ROWS 2
#define COLUMNS 10
#define RANGE 100

void searchArray(int array[]);          // prototype function: searchArray
void printArray(int array[]);           // prototype function: printArray
void printArr(int a[][COLUMNS]);        // prototype function: printarr
void searchArr(int arr[][COLUMNS]);     // prototype function: searchArr
void modifyArray(int b[], size_t size); //prototype function: modifyArray

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

   int rows;                           // variable rows
   int columns;                        // variable columns
                                       // beginning forloop
   for (rows = 0; rows < ROWS; rows++) // beginning forloop
   {                                   // conditions for arrays rows
      for (columns = 0; columns < COLUMNS; columns++)
      {                                       // conditions for arrays columns
         arr[rows][columns] = rand() % RANGE; // loading arr with random random numbers less than 100
      }                                       // end forloop
   }

   // Print the 1D array
   printf("This is the 1D array: \n");
   printArray(array); //function to print the 1D array
   printf("\nThis is a 1D array in table format: \n");
   printf("%s%13s\n", "Element", "Array1"); // table headers

   // output contents of 1D array in tabular format
   for (size_t i = 0; i < SIZE; ++i)
   {
      printf("%7zu%13d\n", i, array[i]);
   }
   printf("\nThe size of the 1D array in bytes is %lu bytes\n", sizeof(array)); // printing size of 1D array in bytes to the screen

   // print the 2D array
   printf("\nThis is the 2D array: \n");
   printArr(arr);                                                             // function to print the 2D array
   printf("\nThe size of the 2D array in bytes is %lu bytes\n", sizeof(arr)); // printing size of arr in bytes to the screen

   // Functions to Search the arrays for numbers divisible by 3
   searchArray(array);
   searchArr(arr);

   // increment the 1D array by *=2, a paramater that is passed by refernce
   puts("\n\nEffects of passing entire 1D array by reference:\nThe "
        "values of the original 1D array are:");
   printArray(array); // outputs original 1D array

   modifyArray(array, SIZE); // function to modify all 1D array values by *=2

   // output modified array
   puts("\nThe values of the modified 1D array are:");
   printArray(array);                                                                 // outputs modified 1D array
   printf("\nThe size of the 1D array in bytes is still %lu bytes\n", sizeof(array)); // printing size of array in bytes to the screen

   // increment the 2D array by *=2, a paramater that is passed by refernce
   puts("\n\nEffects of passing entire 2D array by reference:\nThe "
        "values of the original 2D array are:");
   printArr(arr);          // outputs original 2D array
   modifyArray(arr, SIZE); // function to modify all 2D array values by *=2

   // output modified array
   puts("\nThe values of the modified 2D array are:");
   printArr(arr);                                                                   // outputs modifed 2D array
   printf("\nThe size of the 2D array in bytes is still %lu bytes\n", sizeof(arr)); // printing size of arr in bytes to the screen
}

void printArr(int arr[][COLUMNS])
{

   // beginning forloop
   for (size_t rows = 0; rows < ROWS; rows++)
   {                // conditions for loop
      printf("\n"); //start a new line for each row
      for (size_t columns = 0; columns < COLUMNS; columns++)
      {                                     // conditions for loop
         printf("%5d", arr[rows][columns]); // printing array
      }                                     // end forloop
   }                                        // end forloop
   printf("\n");                            // extra space
} // end function

void searchArr(int arr[][COLUMNS])
{
   int found = 0;     // found variable to hold total numbers divisible by 3
   int holdArr[SIZE]; // new array to store values divisible by 3 to print later
   int x = 0;         // variable used to move through holdArr

   // beginning forloop
   for (size_t rows = 0; rows < ROWS; rows++) // conditions for loop
   {
      printf("\n");                                          //start a new line for each row
      for (size_t columns = 0; columns < COLUMNS; columns++) // conditions for loop
      {
         if (arr[rows][columns] % 3 == 0) // if condition to check if value is divisible by 3
         {
            found++;                         // increment found variable
            holdArr[x] = arr[rows][columns]; // add value to new hold array
            x++;                             // increment x value to move to next holdArr location
         }

      }                                                                               // end forloop
   }                                                                                  // end forloop
   printf("There are, %d, numbers in the 2D array divisible by 3 which are ", found); // print the number of 2D array values divisible by 3
   for (size_t i = 0; i < x; ++i)                                                     // for loop to print holdArr
   {
      printf("%d ", holdArr[i]);
   }
   printf("\n"); // add space
} // end function

void printArray(int array[])
{

   for (size_t i = 0; i < SIZE; ++i) // for loop to print array
   {
      printf("%d ", array[i]);
   }
}

void searchArray(int array[])
{
   int found = 0;     // found variable to hold total numbers divisible by 3
   int holdArr[SIZE]; // new array to store values divisible by 3 to print later
   int x = 0;         // variable used to move through holdArr

   // loop to control number of comparisons per pass
   for (size_t i = 0; i < SIZE; ++i) // conditions for loop
   {
      if (array[i] % 3 == 0) // if condition to check if value is divisible by 3
      {
         found++;               // increment found variable
         holdArr[x] = array[i]; // add value to new hold array
         x++;                   // increment x value to move to next holdArr location
      }
   }

   printf("\nThere are, %d, numbers in the 1D array divisible by 3 which are: ", found); // print the number of 1D array values divisible by 3
   for (size_t i = 0; i < x; ++i)                                                        // for loop to print holdArr
   {
      printf("%d ", holdArr[i]);
   }
}

void modifyArray(int b[], size_t size)
{
   // multiply each array element by 2
   for (size_t j = 0; j < size; ++j)
   {
      b[j] *= 2; // actually modifies original array
   }
}