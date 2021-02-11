#include <stdio.h>  // preproccesser directive to include contents of file stdio.h
#include <string.h> // preproccesser directive to include contents of file string.h
#include <stdlib.h> // preproccesser directive to include contents of file stdlib.h

int main()
{
    printf("Complete Chapter 9 Exercises  9.4  - 9.17\n");
    printf("\n"); // add space
    printf("Exercise 9.4\n");
    printf("a- Print unsigned integer 40000 left justified in a 15-digit field with 8 digits.\n");
    printf("%-15.8u\n", (unsigned)4000);
    /*
        - makes value left justified
        15 is field width
        period goes between field width and digit count
        8u is the digit count so it will print 8 digits, null values will be 0
    */
    printf("b- Read a hexadecimal value into variable hex.\n");
    int hex = 183; // just a random number
    printf("hex value is %X, Decimal: %d\n", hex, hex);
    /*
        declared value hex as int and set to a random number, in this case 183
        %X is used as a format specified in the printf statement
        Because the X is capital the hexadecimal format is uppercase
        Note that Hexadecimal number is not a built-in date type of the C language
    */
    printf("c- Print 200 with and without a sign.\n");
    int x = 200;
    printf("%i %i\n", x, -x);
    /*
        declared x value as int and set to 200
        %i takes the interger value
        x will be positive but if we add a negative in front of x in the printf statement it will print negative
    */
    printf("d- Print 100 in hexadecimal form preceded by 0x\n");
    printf("0x%x\n", 100);
    printf("%#x\n", 100);
    /*
        %x is used as a forma specified in the printf statement
        because x is lowercase the hexadecimal value is lowercase
        printf statement adds 0x prefix to the hexadecimal number
        you can also achieve this using the flag character #
    */
    printf("e- Read characters into array s until the letter p is encountered.\n");
    printf("Enter characters: \n");
    const int SIZE = 10;
    char s[SIZE];
    scanf("%[^p]", s);
    printf("Characters entered into array s\n");
    // calculate length of stringArray
    int i = 0;
    // iterating over stringArray
    for (i = 0; i < SIZE; i++)
    {
        printf("%c", s[i]); // print each stringArray string at all indexes
    }                       // end for loop
    printf("\n");           // add space
    /*
        using inverted scan [^p], character will read into array s until p is entered by user
        when p is entered the scanf is terminated
    */
    printf("f- Print 1.234 in a 9-digit field with preceding zeros.\n");
    float b = 1.234;
    printf("%09.3f", b);
    printf("\n");
    /*
        the period separates the width and precision of the field
        padded the flag f with the float 0
        field width is set to 9
        precision is set to 3 because of the 3 decimal places in 1.234
    */
    printf("g- Read a time of the form hh:mm:ss, storing the parts of the time in the integer variables hour, minute and second. Skip the colons : in the input stream. Use the assignment suppression character.\n");
    int hour, minute, second;
    printf("enter hours, minutes, and seconds with semicolon between each ex. hh:mm:ss:\n");
    fflush(stdin); // clear ouput buffer, source: https://www.geeksforgeeks.org/use-fflushstdin-c/
    scanf("%d%*c%d%*c%d", &hour, &minute, &second);
    printf("%d%d%d", hour, minute, second);
    printf("\n");
    /*
        ignord columns by discarding the data and the character using *%c
        this conversion can discard any data type
    */
    printf("h- Read a string of the form \"characters\" from the standard input. Store the string in character array s. Eliminate the quotation marks from the input stream.\n");
    printf("enter a word with \"\"\n");
    memset(s, 0, sizeof s);
    fflush(stdin); // clears ouput buffer
    scanf("\"%[^\"]", s);
    // iterating over stringArray
    for (i = 0; i < SIZE; i++)
    {
        printf("%c", s[i]); // print each stringArray string at all indexes
    }                       // end for loop
    printf("\n");           // add space
    /*
        escape sequence \" and blackslash(\) in font of " on scanf format the scanf()
    */
    printf("i- Read a time of the form hh:mm:ss, storing the parts of the time in the integer variables hour, minute and second. Skip the colons (:) in the input stream. Do not use the assignment suppression character.");
    printf("enter hours, minutes, and seconds with semicolon between each ex. hh:mm:ss:\n");
    fflush(stdin); // clear ouput buffer
    scanf("%d;%d;%d", &hour, &minute, &second);
    printf("%d%d%d", hour, minute, second);
    printf("\n");
    /*
        double quotes at beginning of scanf match format string
        conversion specifice in scnaf for everytime there is a " which
        they will not be entered into the array as a result
        array is returned without " symbol
    */

    printf("\n"); // add space
    printf("Exercise 9.5\n");
    printf("Write a printf or scanf statement for each of the following:\n");
    printf("%-10d\n", 10000);
    // correct
    // output: 10000
    printf("%s\n", "This is a string");
    // %c conversion specifier is used for single characters
    // replaced with %s conversion specifier  which is used for string variables
    printf("%*.*lf\n", 8, 3, 1024.987654);
    // correct
    // output: 1024.988
    printf("%#o\n%#X\n%#e\n", 17, 17, 1008.83689);
    // correct
    /* 
        output: 
        021
        0x11
        1.008837e+03
    */
    printf("%d\n%+d\n", 1000000, 1000000);
    // format type is long but the argument type is int
    // %d should be used instead of %ld
    // %ld would still work but this is used for type long
    /*
        output:
        1000000L
        +1000000L
    */
    printf("%10.2E\n", 444.93738);
    // correct
    // output: 4.45E+02
    printf("%10.2g\n", 444.93738);
    // correct
    // output: 4.4e+02
    printf("%f\n", 10.987);
    // %d should be replaced with the conversion specifier %f
    // %d represents single intergers (base 10) while %f represents floating point numbers
    // 10.987 is a floating point number so %f should be used
    // output: 10.987

    printf("\n"); // add space
    printf("Exercise 9.6\n");
    printf("Find the error(s) in each of the following program segments. Explain how each error can be corrected.");
    printf("%s\n", "Happy Birthday");
    // original 'Happy Birthday', was written using single quotes.
    // strings in c language should be represented with double quotes
    printf("%s\n", "Hello");
    // error 1: %c modifier is used to print characters %s is used to print strings
    // error 2: string was written with single quotes instead of double quotes
    printf("%s\n", "This is a string");
    // the %c modifier is used to print characters %s is used to print strings
    // The following statement should print "Bon Voyage":
    printf("\"%s\"", "Bon Voyage");
    // must put \" in the forma string for each double quote
    printf("\n"); // add space
    char day[] = "Sunday";
    printf("%s\n", &day[3]);
    // ampersand(&) is expected in front of day[3] to provide the address of the string
    printf("Enter your name: ");
    // error 1: puts() cannot directly print a statement
    // error 2: strings in c language should be represented with double quotes
    // to use puts the line must be stored in a variable and passed as a paramater of puts()
    printf("\n"); // add space
    printf("%f", 123.456);
    // in printf() all type specifiers should be within double quotes
    // The following statement should print the characters 'O' and 'K':
    printf("\n"); // add space
    printf("%c%c\n", 'O', 'K');
    // %s type specifier is for strings not characters
    // %c should be used instead which is the type specifier for characters
    char q[10];
    scanf("%c", &q[7]);
    // changed s to q because i have already used an s array
    // the & is missing from scanf in front of s[7]
    // also whenever an array is declared the input of that array cannot be take using one scanf() function
    // scanf should be used within a loop that is dependent on the size of the array

    printf("\n"); // add space
    printf("Exercise 9.7\n");
    printf("Differences Between type specifier d and type specifier i - Write a program to test the difference between the type specifier d and type specifier i conversion specifiers when used in scanf statements. Ask the user to enter two integers separated by a space. Use the statements\n");
    int m, o;
    printf("Enter two integers sperated by a space: \n");
    fflush(stdin); // clears ouput buffer
    scanf("%i %d", &m, &o);
    printf("%d %d\n", m, o);

    printf("\n"); // add space
    printf("Exercise 9.8\n");
    printf("Printing Numbers in Various Field Widths - Write a program to test the results of printing the integer value 12345 and the floating-point value 1.2345 in fields of various sizes. What happens when the values are printed in fields containing fewer digits than the values?\n");
    int t = 12345;
    float w = 1.2345;
    // integer variables
    printf("%d\n", t);          // integer sized variable
    printf("%f\n", (float)t);   // float sized variable
    printf("%lf\n", (double)t); // double sized variable
    // float variables
    printf("%d\n", (int)w);     // integer sized variable
    printf("%f\n", (float)w);   // float sized variable
    printf("%lf\n", (double)w); // double sized variable
    // when values are printed in fields containing fewer digits than the value there is a loss of precision as well as range in the variable values

    printf("\n"); // add space
    printf("Exercise 9.9\n");
    printf("Rounding Floating-Point Numbers - Write a program that prints the value 100.453627 rounded to the nearest digit, tenth, hundredth, thousandth and ten-thousandth.\n");
    double number = 100.453672;
    printf("nearest = %.0f\n", number);        // nearest digit
    printf("tenth = %1f\n", number);           // tenth
    printf("hundredth = %.2f\n", number);      // hundredth
    printf("thousandth = %.3f\n", number);     // thousandth
    printf("ten-thousandth = %.4f\n", number); // ten-thousandth

    printf("\n"); // add space
    printf("Exercise 9.10\n");
    printf("(Temperature Conversions) Write a program that converts integer Fahrenheit temperatures from 0 to 212 degrees to floating-point Celsius temperatures with 3 digits of precision. Perform the calculation using the formula The output should be printed in two right-justified columns of 10 characters each, and the Celsius temperatures should be preceded by a sign for both positive and negative values.");
    // celsius = 5.0 / 9.0 * (fahrenheit - 32);
    // value to hold temperatures
    int fahrenheit;                                // declared fahrenheit as int
    double celsius;                                // declared celsius as double
    printf("%10s%10s\n", "Fahrenheit", "Celsius"); // make rows for heading
    // for loop converts fahrenheit to temperature
    for (fahrenheit = 0; fahrenheit <= 212; ++fahrenheit) // every loop add one to temperature and stop at 212
    {
        celsius = 5.0 / 9.0 * (fahrenheit - 32);      // equation to convery fahrenheit to celsius
        printf("%10d%+10.3f\n", fahrenheit, celsius); // print fahrenheit and celsius values
    }                                                 // end for

    printf("\n"); // add space
    printf("Exercise 9.11\n");
    printf("(Escape Sequences) Write a program to test the escape sequences. For the escape sequences that move the cursor, print a character before and after printing the escape sequence so it’s clear where the cursor has moved.\n");
    // \', \", \?, \\, \a, \b, \n, \r and \t
    printf("The single quote: \'");
    printf("\n"); // add space
    printf("The double quote: \"");
    printf("\n"); // add space
    printf("The Question mark: \?");
    printf("\n"); // add space
    printf("the backslash: \\");
    printf("\n"); // add space
    printf("the bell. \a\n");
    printf("\n"); // add space
    printf("Move cursor back one position on current line. *\b*");
    printf("\n"); // add space
    printf("Move cursor to beginning of next line. *\n*");
    printf("\n"); // add space
    printf("Move cursor to beginning of current line *\r*");
    printf("\n"); // add space
    printf("Move cursor to next horizontal tab position. *\t*");
    printf("\n"); // add space

    printf("\n"); // add space
    printf("Exercise 9.12\n");
    printf("(Printing a Question Mark) Write a program that determines whether ? can be printed as part of a printf format control string as a literal character rather than using the \? escape sequence.");
    printf("The question mark *\?* did not print at the end of the sentence?");

    printf("\n"); // add space
    printf("Exercise 9.13\n");
    printf("(Reading an Integer with Each scanf Conversion Specifier) Write a program that inputs the value 437 using each of the scanf integer conversion specifiers. Print each input value using all the integer conversion specifiers.");
    int array[5]; // establish integer array which can hold 5 values, Size is 5
    size_t loop;  // will count loops
    // array table headers
    char *k[] = {"read with %d:", "Read with %i", "Read with %o:", "read with %u:", "Read with %x:"};
    // ask user to enter 437 5 times
    printf("%s", "Enter the 437 five times: \n");
    scanf("%d%i%o%u%x", &array[0], &array[1], &array[2], &array[4], &array[4]);
    // assign values input by user to positions in array
    // for loop to go through the 5 values and print them
    for (loop = 0; loop <= 4; ++loop)
    {
        // print the values
        printf("%s\n%d %i %o %u %x\n\n", k[loop], array[loop], array[loop], array[loop], array[loop], array[loop]);
    } // end for

    printf("\n"); // add space
    printf("Exercise 9.14\n");
    printf("(Outputting a Number with the Floating-Point Conversion Specifiers) Write a program that uses each of the conversion specifiers e, f and g to input the value 1.2345. Print the values of each variable to prove that each conversion specifier can be used to input this same value.\n");
    float v[3]; // establish float array which can hold 3 values

    //array of table headers
    char *d[] = {"Read with %e: ", "Read with %f: ", "Read with %g: "};
    // ask user to input 1.2345 three times
    printf("%s", "Enter 1.2345 three times: \n");
    scanf("%e%f%g", &v[0], &v[1], &v[2]);
    printf("%s%e\n\n", d[0], v[0]);
    printf("%s%f\n\n", d[0], v[0]);
    printf("%s%g\n\n", d[0], v[0]);

    printf("\n"); // add space
    printf("Exercise 9.15\n");
    printf("(Reading Strings in Quotes) In some programming languages, strings are entered surround- ed by either single or double quotation marks. Write a program that reads the three strings suzy, \" suzy \" and 'suzy'. Are the single and double quotes ignored by C or read as part of the string?\n");
    char aa[10];
    char bb[10];
    char cc[10];
    // ask user for three strings
    printf("Enter the strings suzy, \"suzy\", and 'suzy': \n");
    fflush(stdin);                    // clear ouput buffer
    scanf("%s %s %s\n", aa, bb, cc);  // store use input in arrays
    printf("%s %s %s\n", aa, bb, cc); // prints strings

    printf("\n"); // add space
    printf("Exercise 9.16\n");
    printf("(Printing a Question Mark as a Character Constant) Write a program that determines whether ? can be printed as the character constant '?' rather than the character constant escape se- quence '?' using conversion specifier type modifier c in the format control string of a printf statement.\n");
    const char questionMark = '?'; // define '?' as a char constant
    printf("This %c was printed without using the \\\?\n", questionMark);

    printf("\n"); // add space
    printf("Exercise 9.17\n");
    printf("Using type specifier g with Various Precisions - Write a program that uses the conversion specifier g to output the value 9876.12345. Print the value with precisions ranging from 1 to 9.\n");
    int value; // value integer is userd to intrate from 1-9 in the for loop
    for (value = 1; value <= 9; value++)
    {
        printf("precision: %d, value = %.*g\n", value, value, 9876.12345);
    } // end for

    return 0;
} // end main
