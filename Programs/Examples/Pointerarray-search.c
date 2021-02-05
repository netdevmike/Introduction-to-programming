#include <stdio.h>
#include <string.h>
#define SIZEPTRARR 10

// prototype of the search function
int search(char *stringArray[], char str[12]);

// main function
int main()
{

    // creating pointer array of strings
    char *stringArray[] = {"Red", "Orange", "Yellow",
                           "Green", "Blue", "Purple", "Pink", "White", "Black", "Rainbow"};

    // inputting a search string and calling the search function, passing stringArray and the search string

    char str[12];
    printf("input a color:  ");
    scanf("%s", str);
    int n = search(stringArray, str);

    // if n==0 given string is present in stringArray
    // else given string is not present in stringArray
    if (n == 0)
    {
        printf("\n%s is present in stringArray.\n", str);
    }
    else
    {
        printf("\n%s is not present in stringArray.\n", str);
    }
}

// search function, which takes in a pointer array to string and an a string
// and returns 0 if the string is present in array else return a different number
int search(char *stringArray[], char str[12])
{

    // calculate length of stringArray
    int i = 0;
    int n;
    // iterating over stringArray
    for (i = 0; i < SIZEPTRARR; i++)
    {
        n = strncmp(stringArray[i], str, 10);
        if (n == 0)
        {
            return n; //return 0 and stop search if it is found
        }             //end if
    }                 //end for
    return n;         // if string is not found in the stringArray return the non zero or result of the string compare
} //e
