//preprocessor directives
#include <stdio.h>
#include <stdlib.h>

// defined values
#define ARR1 10 // size of array 1
#define ARR2 10 // size of array 2

//main function
int main()
{
   //declaring variables
   int i, j, count = 0;
   //declaring 1D array of size 10
   int *arr1 = (int *)malloc(ARR1 * sizeof(int));
   //declaring 2D array of size 5 x 5
   int *arr2 = (int *)malloc(ARR2 * ARR2 * sizeof(int));

   //loop for iteration of arr1
   for (i = 0; i < ARR1; i++)
   {
      //storing value
      *(arr1 + i) = i;
   }
   //loop for row of arr2
   for (i = 0; i < ARR2; i++)
   {
      //loop for column of arr2
      for (j = 0; j < ARR2; j++)
      {
         //storing value
         *(arr2 + i * ARR2 + j) = ++count;
      }
   }

   //print 1 dimensional array
   printf("Dynamic 1 dimmensional array: ");
   for (i = 0; i < ARR1; i++)
   {
      //iterating through array and printing values
      printf("%d ", *(arr1 + i));
   }

   //printing 2 dimensional array
   printf("\nDynamic 2 dimmensional array: ");
   // loop for row of arr2
   for (i = 0; i < ARR2; i++)
   {
      //loop for column of arr2
      for (j = 0; j < ARR2; j++)
      {
         //iterating through array and printing values
         printf("%d ", *(arr2 + i * ARR2 + j));
      }
   }

   return 0;
}

/*
Resources:
How to dynamically allocate a 1D and 2D array in c.
https://aticleworld.com/dynamically-allocate-2d-array-c/
*/