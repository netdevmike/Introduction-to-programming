#include<stdio.h>
#include<string.h>
#define SIZEPTRARR 3


int main(){

    // creating pointer array that can store the addresses of strings
    char *stringArray[SIZEPTRARR] ;
    // Creating a string that can be used to input the string values desired
    // Note that this array is necessary to actually store space for the input values to be stored
    char inputString[SIZEPTRARR][30];

    int counter;
    // for loop to input string values and assign them to the array of string pointers
    for (counter = 0; counter < SIZEPTRARR ; counter++) {
        printf("Enter the string you want stored to the ");
        scanf("%s", inputString[counter]);
        // this stores the address of the memory space where the input string was stored.
        stringArray[counter]=inputString[counter];
    }
    // else given string is present in stringArray
}

