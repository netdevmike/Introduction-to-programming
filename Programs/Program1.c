#include <stdio.h>

int main (void) 
{
    // Printing my name a few facts about me
    printf("Michael Charara\n");
    printf("3 Facts about myself\n 1. I have a bachelors of science in Biology\n 2. I love to code and excited to learn!\n 3. I am also pursuing a MBA while purusing my BS CS \n");

    // declaring 5 variables
    int integer1;
    int integer2;
    int integer3;
    int integer4;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    // reading user inputs
    printf( "Enter first integer\n" ); // prompt
    scanf( "%d", &integer1 ); // read an integer

    printf( "Enter second integer\n" ); // prompt
    scanf( "%d", &integer2 ); // read an integer

    printf( "Enter third integer\n" ); // prompt
    scanf( "%d", &integer3 ); // read an integer

    printf( "Enter fourth integer\n" ); // prompt
    scanf( "%d", &integer4 ); // read an integer

    // Adding int1 and int2 to the sum1 variable
    sum1 = integer1 + integer2;
    // adding int 3 and int 4 to sum2 variable
    sum2 = integer3 + integer4;
    // adding the sums
    sum3 = sum1 + sum2;

    // printing the sums
    printf("sum of the first number entered, %d, and the second number entered, %d, is %d\n", integer1, integer2, sum1);
    printf("sum of the third number entered, %d, and the fourth number entered, %d, is %d\n", integer3, integer4, sum2);
    printf("sum of the all numbers entered, is %d\n", sum3);

    // if statement comparing size of int1 and int2
    if(integer1 < integer2)
    {
        printf( "The first number entered, %d, is less than the second number entered, %d \n", integer1, integer2);
    } else 
    {
        printf( "The first number entered, %d, is bigger than or the same size as the second number entered, %d \n", integer1, integer2);
    }

    // if statement comparing size of int2 and int3
    if(integer3 < integer4)
    {
        printf( "The third number entered, %d, is less than the fourth number entered, %d \n", integer3, integer4);
    } else 
    {
        printf( "The third number entered, %d, is bigger than or the same size as the fourth number entered, %d \n", integer3, integer4);
    }
    
    // if statement comparing sum1 of int1 and in2 to sum2 of int2 and int3
    if(sum1 < sum2)
    {
        printf( "sum of the first number entered, %d, and the second number entered, %d, came out to, %d, which is less than the sum of the third number entered, %d, and the fourth number entered, %d, which came out to, %d \n", integer1, integer2, sum1, integer3, integer4, sum2);
    } else 
    {
        printf( "sum of the third number entered, %d, and the fourth number entered, %d, came out to, %d, which is bigger than the sum of the first number entered, %d, and the second number entered, %d, which came out to, %d \n", integer3, integer4, sum2, integer1, integer2, sum1);
    }
}
