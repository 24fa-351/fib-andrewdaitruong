#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//prototypes
int fib_rec(int);

int main(int argc, char *argv[]) {

   if (argc < 4) return 1;
   int r = atoi(argv[1]);
   char *mode = argv[2];
   char *filename = argv[3];
   
   //inputting file name along with opening the file to scan
   FILE *file = fopen(filename, "r");
   if (!file) return 1;

   char file_content[100];
   if (fgets(file_content, sizeof(file_content), file) == NULL)
      {
         fclose(file);
         return 1;
      }
   fclose(file);

   //reads the string as an integer
   int file_number = atoi(file_content);

   //Timing the event of the addition of the integers
   clock_t start_time = clock();
   int n_number = r + file_number;
   int result = fib_rec(n_number - 1);
   clock_t end_time = clock();
   double function_timer = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;

   //simple print function for output
   printf("%d\n", result);
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