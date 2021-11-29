/*
c 函数指针与回调函数

1. 函数指针:
函数指针是指向函数的指针变量。
通常我们说的指针变量是指向一个整型、字符型或数组等变量，而函数指针是指向函数。
函数指针可以像一般函数一样，用于调用函数、传递参数。

2. 回调函数: 函数指针作为某个函数的参数
函数指针变量可以作为某个函数的参数来使用的，回调函数就是一个通过函数指针调用的函数。
简单讲：回调函数是由别人的函数执行时调用你实现的函数。

以下是来自知乎作者常溪玲的解说：

你到一个商店买东西，刚好你要的东西没有货，于是你在店员那里留下了你的电话，过了几天店里有货了，
店员就打了你的电话，然后你接到电话后就到店里去取了货。在这个例子里，你的电话号码就叫回调函数，
你把电话留给店员就叫登记回调函数，店里后来有货了叫做触发了回调关联的事件，店员给你打电话叫做调用回调函数，你到店里去取货叫做响应回调事件。

*/
#include <stdio.h>
#include <stdlib.h>

int max(int x, int y)
{
  return x > y ? x : y;
}

int getNextRandomValue(void)
{
  return rand();
}

void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
  for (size_t i = 0; i < arraySize; i++)
  {
    array[i] = getNextValue();
  }
}

int main(void)
{
  int (*p)(int, int) = max;
  int a, b, c, d;

  a = 5;
  b = 6;
  c = 2;

  d = p(p(a, b), c);
  printf("最大的数字是: %d\n", d);

  printf("---callBack----\n");
  int myArray[10];
  populate_array(myArray, 10, getNextRandomValue);

  for (int i = 0; i < 10; i++)
  {
    printf("%d  ", myArray[i]);
  }
  printf("\n");
  return 0;
}
