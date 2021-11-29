/*
C 共用体
共用体是一种特殊的数据类型，允许您在相同的内存位置存储不同的数据类型。
我们可以定义一个带有多成员的共用体，但是任何时候只能有一个成员带有值。
共用体提供了一种使用相同的内存位置的有效方式。

定义共用体

union Data
{
   int i;
   float f;
   char  str[20];
}
现在，Data 类型的变量可以存储一个整数、一个浮点数，或者一个字符串。
这意味着一个变量（相同的内存位置）可以存储多个多种类型的数据。
我们可以根据需要在一个共用体内使用任何内置的或者用户自定义的数据类型。
共用体占用的内存应足够存储共用体中最大的成员。
*/

#include "stdio.h"
#include "string.h"

union Data
{
  int i;
  float f;
  char str[20];
};

typedef union Data Data;

int main(int argc, char const *argv[])
{
  Data data;
  data.i = 10;
  printf("----i-----\n");
  printf("data.i = %d\n", data.i);
  printf("data.f = %f\n", data.f);
  printf("data.str = %s\n", data.str);

  printf("----str-----\n");

  strcpy(data.str, "C Programming");
  printf("data.i = %d\n", data.i);
  printf("data.f = %f\n", data.f);
  printf("data.str = %s\n", data.str);

  return 0;
}
