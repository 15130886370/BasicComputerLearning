/*
枚举是 C 语言中的一种基本数据类型，它可以让数据更简洁，更易读。
枚举语法定义格式为：
enum name { element1, element2, element3, ... };
例如:
enum Day
{
      mon=1, tue, wed, thu, fri, sat, sun
};
*/

#include "stdio.h"

enum Day
{
  mon = 1,
  tue,
  wed,
  thu,
  fri,
  sat,
  sun
};

enum Color
{
  red = 1,
  green,
  blue
};

typedef enum Day MyDay;
typedef enum Color MyColor;

void printMyDay();
void printLikeColor();

int main(int argc, char const *argv[])
{

  printMyDay();
  printLikeColor();
  return 0;
}

void printMyDay()
{
  MyDay day;

  for (day = mon; day <= sun; day++)
  {
    printf("枚举元素: %d\n", day);
  }
  return;
}

void printLikeColor()
{
  MyColor color;
  color = green;

  switch (color)
  {
  case red:
    printf("你喜欢的颜色是红色");
  case blue:
    printf("你喜欢的颜色是蓝色");
  case green:
    printf("你喜欢的颜色是绿色");
  }
  return;
}
