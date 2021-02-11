#include <stdio.h>

int main (void) 
{
    printf( "%s", "Enter first integer(must be smaller than second number): " ); // Prompt user for first input
    unsigned int x; 
    scanf( "%u", &x ); // read value for x from user 
    printf( "%s", "Enter second integer(must be larger than first number): " ); // prompt user for second input
    unsigned int y; 
    scanf( "%u", &y ); // read value for y from user 

    int counter = x; // value will be used to increment through the while loop
    int start = x; // starting value for while statement
    int end = y; // ending value for while statement

    // loop
    while (counter <= end) // establishing the counter and its peramater for the while loop
    {
        // if else statement to check if counter is even or odd
        if (counter %2){
            printf("%d is odd and adding 10 to it is %d\n", counter, counter + 10); // add 10 if odd

        } else
        {
            printf("%d is even and 3 times it is %d\n", counter, counter * 3); // multiply by 3 if even
        }
        
        counter ++; // increment counter

    }
    

}