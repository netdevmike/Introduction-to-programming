#include <stdio.h>
#include <math.h>  // include math.h c library so i can access the round mathmatical function

/* function declaration */
int subtractNum(int num1, int num2);
int addNum(int num1, int num2);
int multiplyNum(int num1, int num2);
void acceptInt(int num1);
float roundNum(float num1);

int main(void) // main functions  that callss the 5 functions i creates
{
   int x, y; // decaling x and y ints
   float z; // declares the z float 

   /* read input from user */
   printf("Enter integer 1: ");
   scanf("%d",&x);
   printf("Enter integer 2: ");
   scanf("%d",&y);
   printf("Enter a float: ");
   scanf("%f",&z);

   /* calling the functions */
   subtractNum(x, y);
   addNum(x, y);
   multiplyNum(x, y);
   acceptInt(x);
   roundNum(z);
   
} 

int subtractNum(int num1, int num2) // function for subtracting two integers
{
   int sum = num1 - num2; // subtracts num1 and num2 from user
   printf("subtracting %d by %d results in %d\n", num1, num2, sum); // prints the results
   return (sum);
}


int addNum(int num1, int num2) // function for adding two integers
{
   int sum = num1 + num2; // adds num1 and num2 from user
   printf("adding %d by %d results in %d\n", num1, num2, sum); // prints the results
   return (sum);
}


int multiplyNum(int num1, int num2) // function for multipling two integers
{
   int sum = num1 * num2; // multiples num1 and num2 from user
   printf("multiplying %d by %d results in %d\n", num1, num2, sum); // prints the results
   return (sum);
}

void acceptInt(int num1) // function for accepting integer from first user input
{
   printf("number 1 is %d\n", num1); // prints the first integer from user input
}

float roundNum(float num1) // function for rounding floating point numbers
{
   float b = round(num1); // rounds the floated number to the nearest hole number i.e. 5.4 to 5 and 5.6 to 6
   printf("float rounded to the nearest whole number: %.0f", b); // prints the results after rounding the float number
   return (b);
}