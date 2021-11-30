#include "stdio.h"

int fibonaci(int i);

double factorial(unsigned int i)
{
  if (i <= 1)
  {
    return 1;
  }
  return i * factorial(i - 1);
}

int main(int argc, char const *argv[])
{
  int i = 10;
  printf("%d 的阶乘为 %f\n", i, factorial(i));

  for (i = 0; i < 10; i++)
  {
    printf("%d\t\n", fibonaci(i));
  }

  return 0;
}

// 斐波那契数列
int fibonaci(int i)
{
  if (i == 0)
  {
    return 0;
  }

  if (i == 1)
  {
    return 1;
  }

  return fibonaci(i - 1) + fibonaci(i - 2);
}