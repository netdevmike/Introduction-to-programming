#include <stdio.h>
#include <string.h>
#define SIZEPTRARR 5 // size of array

int search(char *stringArray[], char str[7]); // prototype of the search function
int printArray(char *stringArray[]);          // prototype of the printArray function
int printInfo(char str[7]);                   // prototype of the pintInfo

// main function
int main()
{

    // creating pointer array of strings
    char *stringArray[] = {"Javascript", "Python", "C", "PHP", "JAVA"};

    // function to print stringArray
    printArray(stringArray);

    // inputting a search string and calling the search function, passing stringArray and the search string
    char str[7];
    printf("Input one of the programming languages to learn more:  ");
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

    // function to printInfo of selected programming language
    printInfo(str);
}

// search function, which takes in a pointer array to string and an a string
// and returns 0 if the string is present in array else return another number
int search(char *stringArray[], char str[7])
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
            return n; //return 0 and stop search if it is found
        }             //end if
    }                 //end for
    return n;         // if string is not found in the stringArray return the non zero or result of the string compare
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

// printInfo function, which checks str to string value, prints information on programming language
// source: “Top 10 Programming Languages That Will Rule in 2021.” GeeksforGeeks, 22 Dec. 2020, www.geeksforgeeks.org/top-10-programming-languages-that-will-rule-in-2021/.
int printInfo(char str[7])
{
    if (strcmp(str, "Javascript") == 0) // check if str is equal to Javascript
    {
        // print info about javascript
        printf("Though the language is primarily known for adding responsive elements on web pages it has a wide range of applications such as in web development, game development, mobile application development, and many more. Moreover, the language is being used for both – Front End Development and Back End Development.");
    }
    else if (strcmp(str, "Python") == 0) // check if str is equal to Python
    {
        // print info about python
        printf("Python has been the favorite language of almost every individual who is just starting with the programming domain for the last many years. The primary reason behind this is a quite simple syntax that makes it easy to read, learn, and use. The language is extensively used for web development, software development, etc., and with several trending technologies such as Machine Learning, Artificial Intelligence, Data Science, etc.");
    }
    else if (strcmp(str, "C") == 0) // check if str is equal to C
    {
        // print info about C
        printf("If we particularly talk about C language, the general-purpose procedural programming language is majorly used in the development of low-level systems like operating systems, kernel development, and others. And many other programming languages inherit the properties of this particular language.");
    }
    else if (strcmp(str, "PHP") == 0) // check if str is equal to PHP
    {
        // print info about PHP
        printf("The object-oriented programming language comes up with a much-celebrated principle of Write Once Run Anywhere that allows the Java code to be executed on other platforms, that supports JAVA, without doing recompilation. The language is widely used in Android development along with Web Applications, Desktop Applications, Scientific Applications, etc.");
    }
    else if (strcmp(str, "JAVA") == 0) // check if str is equal to JAVA
    {
        // print info about JAVA
        printf("The object-oriented programming language comes up with a much-celebrated principle of Write Once Run Anywhere that allows the Java code to be executed on other platforms, that supports JAVA, without doing recompilation. The language is widely used in Android development along with Web Applications, Desktop Applications, Scientific Applications, etc.");
    }
    else // default
    {
        printf("\n");
    }
    return 0;
}