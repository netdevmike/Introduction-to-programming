/* This program demonstrates calling a function that returns a value as well as a function that does not return any value.
It also shows one way of rounding the value of a function to the nearest whole number */
# include<stdio.h>

// Below are the prototypes of the functions I have created.  The code for the functions is listed below the main function.
float roundNo(float num);
void printmessage (int x);

//this is the main function that calls the two functions I have created to 1). round a float and 2). print a message.
int main()
{
    int intNum = 5; // This creates an integer and assigns a value for main to call the function printmessage()
    float floatNum = 1.777; //this creates the float number that will be used in main's call of the roundNo() function
    float floatRounded;  // This creates a value that main will use to call the roundNo() function by assigning its return value to floatRounded
    floatRounded = roundNo(floatNum);  // this is how main calls the function roundNo() which will return a value to be assigned to floatRounded
    printf("%f \n", floatRounded);
    printmessage(intNum);  //This is how main calls a function that does not return any value
    return 0;
}

float roundNo(float num) // function for rounding floating point numbers
{
    int x;
    float y;
    if (num >= 0.0){ // This selection control (if/else) increases the value by 1.5 so that the float will round correctly
        x = num + 0.5;
    }
    else {
        x = num - 0.5;
    }

    y = (float)x;  // this takes the interger value used to truncate the float back into a float before returning it
    return y;  //this returns the float number truncated
}

void printmessage (int x) // This a function that does not return any value but just prints a message
{
    printf("I am printing the pasted integer %d\n", x);
}
