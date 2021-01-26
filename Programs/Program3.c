#include <stdio.h>

int main(void)
{
   // for statement to count from 1 to 100 displaying each number
   // initialization, iteration condition, and increment are all included in the for statement header.
   for (unsigned int counter = 1; counter <= 100; ++counter) {
      printf("%u ", counter); // printing the counter
      if (counter == 100) // move to next line when loop gets to 100
      {
         printf("\n");
      }     
   } 
   
   // while statement to count from 1 to 100.
   // counter incremented in each switch case
   unsigned int counter = 1; // initialization of counter
   while (counter <= 100) { // iteration condition
      switch (counter) {
         case 1 ... 10: // if counter == 1-10
            printf("%u is less than or equal to 10 \n", counter);
            counter++; 
            break;
         case 11 ... 19: // if counter == 11-19
            printf("%u is greater than or equal to 11 but less than 20 \n", counter);
            counter++;
            break;
         case 21 ... 100: // if counter == 21-100
            printf("%u is greater than 21 \n", counter);
            counter++;
            break;
         default: // if no other cases are satisfied, print counter
            printf("%u \n", counter);
            counter++;
            break;
      }
   }

   // do while statement to count from 1 to 100.
   unsigned int count = 1; // initialization
   do {                                               
      printf("%u  ", count); // print count  
   } while (++count <= 100); // increment counter and iteration condition
} 