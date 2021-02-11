#include <stdio.h>   // preproccesser directive to include contents of file stdio.h
#include <string.h>  // preproccesser directive to include contents of file string.h
#include <stdlib.h>  // preproccesser directive to include contents of file stdlib.h
#define SIZEPTRARR 5 // size of array

// prototype of the search function
int search(char *stringArray[], char str[7], int *elemententNo); // prototype of search function
int printArray(char *stringArray[]);                             // prototype of the printArray function
int input();                                                     // prototype for input function

// main function
int main()
{
    // creating pointer array of strings
    char *stringArray[] = {"Go", "Python", "C", "PHP", "JAVA"};
    int exit = 0;              // creating exit int and setting it to 0
    for (exit = 0; exit != 1;) // for loop to repeat program until exit is set to 1
    {
        int choice, num;                                                                  // initializing choice and num int variables for input and output functions
        printf("Press 1 to print a list of programming languages in the database\n");     // print option 1
        printf("Press 2 to search for a programming language in the database\n");         // print option 2
        printf("Press 3 to change the name of a programming language in the database\n"); // print option 3
        printf("Press 4 to exit the program\n");                                          // print option 4
        printf("Enter your choice:\n");                                                   // request input from user
        choice = input();                                                                 // set choice to value input by user

        switch (choice) // switch case depending on user choice
        {
        case 1: // list strings in array
        {
            // function to print stringArray
            printArray(stringArray);
            break;
        }
        case 2: // search for a string in array
        {
            // inputting a search string and calling the search function, passing stringArray and the search string
            int elmntNo;                                                             // initialize int elmntNo
            char str[10];                                                            // char value of srt with a size of 10
            printf("Search for one of the programming languages in the database\n"); // prompt user for input
            scanf("%s", str);                                                        // set user input to str
            int n = search(stringArray, str, &elmntNo);                              // set n equal to search function return
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
            break;
        }
        case 3: // change the name of a string in the array
        {
            int elmntNo;                                                               // initialize int elmntNo
            char *str;                                                                 // pointer char to str
            printf("Enter the name of the programing language you want to change:\n"); // prompt user for input
            //allocate space to char array
            str = (char *)malloc(sizeof(char) * 10);    /* Resource: https://stackoverflow.com/questions/33209654/when-we-call-charmallocsizeofchar-to-allocate-memory-for-a-string-is-it */
            scanf("%s", str);                           // set user input to str
            int n = search(stringArray, str, &elmntNo); // set n equal to search function return
            // if n==0 given string is present in stringArray
            // else given string is not present in stringArray
            if (n == 0)
            {
                printf("\n%s is present in stringArray in element %d.\n", str, elmntNo); // print user input and element position
                printf("Enter the new name:\n");                                         // ask user to unput a new name
                scanf("%s", str);                                                        // set new name to str
                stringArray[elmntNo] = str;                                              // change string in array at proper position to string input by user
                printArray(stringArray);                                                 // function to print the array
            }
            else
            {
                printf("\n%s is not present in stringArray.\n", str); // tell user the input was not in array
            }

            //make str reference to null
            str = NULL; // resource: https://stackoverflow.com/questions/4364536/is-null-reference-possible
            break;
        }
        case 4: // exit the program
        {
            exit = 1; // set exit equal to 1 which will end loop due to for condition
            break;
        }

        default:                     // default switch case if number other than 1-4
            printf("wrong Input\n"); // inform user that the input was wrong
        }
    }

    return 0; // return int 0 to show success
}

// input function
int input()
{
    int number;           // initialize int number
    scanf("%d", &number); // reads input and stores it
    return (number);      // returns user input stored at number
}

// search function, which takes in a pointer array to string and an a string
// and returns 0 if the string is present in array else return a differnt number
int search(char *stringArray[], char str[7], int *elemententNo)
{

    // calculate length of stringArray
    int i = 0; // initialize int i and set equal to 0
    int n;     // initialize int n
    // iterating over stringArray
    for (i = 0; i < SIZEPTRARR; i++)
    {
        n = strncmp(stringArray[i], str, 5); // set n to 0 if string input is equal to a value in array, will check first 5 memory addresses
        if (n == 0)                          // if n==0 given string is present in stringArray
        {
            *elemententNo = i; // set elemententNo pointer to i
            return n;          //return n and stop search if it is found
        }                      //end if
    }                          //end for
    return n;                  // if string is not found in the stringArray return the n result of the string compare
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
    }                                   // end for
    printf("\n");                       // add space

    return 0;
}