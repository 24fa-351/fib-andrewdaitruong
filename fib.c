#include <stdio.h>

int fib_rec(int);

int main() {
   int n = 10;
   int result = fib_rec(n);
   printf("Fibonacci of %d is %d\n", n , result);
   
   return 0;
}

int fib_rec (int i)
{
   if (i < 0) return -1;
   if (i == 0) return 0;
   if (i == 1) return 1;
   return fib_rec(i - 1) + fib_rec (i - 2);
}