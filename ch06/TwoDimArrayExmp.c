// 2D array
#include <stdio.h>
#include <stdlib.h>
#define ROWS 2
#define COLUMNS 10


void printArr( int a[][COLUMNS]); // prototype function: printarr


int main( void ){

    int arr[ROWS][COLUMNS] ; // array

     printf("This is the 2D array: \n"); // prompt/ extra space

     int rows; // variable
     int columns; // variable
     // beginning forloop
    for( rows = 0; rows < ROWS ; rows++){ // conditions for arrays rows
        for( columns = 0; columns < COLUMNS ; columns++ ){ // conditions for arrays columns
           arr[rows][columns] =  rand() % 99; // loading arr with random random numbers less than 100
        } // end forloop
      }
    printArr(arr);

    printf("\nThe size of the 2D array in bytes is %d bytes:\n",sizeof(arr)); // printing size of arr in bytes to the screen
} //end function main


// beginning function print arr

void printArr(int arr[][COLUMNS]){ // parameters

   // beginning forloop
   for( int rows = 0; rows < ROWS ; rows++){ // conditions for loop
       printf("\n");  //start a new line for each row
    for( int columns = 0; columns < COLUMNS ; columns++){ // conditions for loop
           printf("%5d",arr[rows][columns]); // printing array
       } // end forloop
    }// end forloop
    printf("\n"); // extra space
} // end function
