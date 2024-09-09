#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//prototypes
int fib_rec(int);

int main(int argc, char *argv[]) {

   //inputting file name along with opening the file to scan
   char filename[100];
   printf("Enter filename here: \n");
   scanf("%99s", filename);

   //opens and reads the file content
   FILE *file = fopen(filename, "r");
   char file_content[100];
   if (fgets(file_content, sizeof(file_content), file) != NULL)
      fclose(file);

   //reads the string as an integer
   int file_number = atoi(file_content);
    
   //User inputs a number
   int i;
   printf("1st number: ", "\n");
   scanf("%d", &i);

   //Timing the event of the addition of the integers
   clock_t start_time = clock();
   int n_number = i + file_number;
   int result = fib_rec(n_number);
   clock_t end_time = clock();
   double function_timer = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;

   //simple print function for output
   printf("Fibonacci of %d is %d\n", n_number, result);
   printf("Time taken: %.1f millisecond\n", function_timer);
   return 0;
}

//recursive function of fibanacci sequence
int fib_rec (int i)
{
   if (i < 0) return -1;
   if (i == 0) return 0;
   if (i == 1) return 1;
   return fib_rec(i - 1) + fib_rec (i - 2);
}