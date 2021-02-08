#include <stdio.h>
#include <string.h>
#define SIZEPTRARR 5

// prototype of the search function
int search(char *stringArray[], char str[7], int *elemententNo);
int printArray(char *stringArray[]); // prototype of the printArray function

// main function
int main()
{

   // creating pointer array of strings
   char *stringArray[] = {"Javascript", "Python", "C", "PHP", "JAVA"};

   // function to print stringArray
   printArray(stringArray);

   // inputting a search string and calling the search function, passing stringArray and the search string
   int elmntNo;
   char str[5];
   printf("Input one of the programming languages to learn more:  ");
   scanf("%s", str);
   int n = search(stringArray, str, &elmntNo);
   // if n==0 given string is present in stringArray
   // else given string is not present in stringArray
   if (n == 0)
   {
      printf("\n%s is present in stringArray in element %d, having value %s.\n", str, elmntNo, stringArray[elmntNo]);
   }
   else
   {
      printf("\n%s is not present in stringArray.\n", str);
   }
}

// search function, which takes in a pointer array to string and an a string
// and returns 0 if the string is present in array else return a differnt number
int search(char *stringArray[], char str[7], int *elemententNo)
{

   // calculate length of stringArray
   int i = 0;
   int n;
   // iterating over stringArray
   for (i = 0; i < SIZEPTRARR; i++)
   {
      n = strncmp(stringArray[i], str, 5);
      if (n == 0)
      {
         *elemententNo = i;
         return n; //return 0 and stop search if it is found
      }            //end if
   }               //end for
   return n;       // if string is not found in the stringArray return the non zerror result of the string compare
} //e

// printArray function, which takes the length of the array and prints each index
int printArray(char *stringArray[])
{

   // calculate length of stringArray
   int i = 0;
   // iterating over stringArray
   for (i = 0; i < SIZEPTRARR; i++)
   {
      printf("%s  ", stringArray[i]); // print each stringArray string at all indexes
   }                                  // end for
   printf("\n");                      // add space

   return 0;
}