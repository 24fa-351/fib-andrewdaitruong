#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//prototypes
int fib_rec(int);

int main() {
   //User input one.
   int i;
   printf("1st number: ", "\n");
   scanf("%d", &i);

   char filename[100];
   scanf("%99s", filename);
   int file_number = 0;
   FILE *file = fopen(filename, "r");
   if (fscanf(file, "%d", &file_number) != 1)
   {
      fclose(file);
   }

   //starts/ends the timer for the function
   clock_t start_time = clock();
   int n_number = i + file_number;
   int result = fib_rec(n_number);
   clock_t end_time = clock();
   double function_timer = (double)(end_time - start_time) / CLOCKS_PER_SEC;

   //simple print function for output
   printf("Fibonacci of %d is %d\n", i, result);
   printf("Time taken: %.6f seconds\n", function_timer);
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