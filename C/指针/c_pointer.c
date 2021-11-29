
/*
1.指针概念：
每一个变量都有一个内存位置，每一个内存位置都定义了可使用 &运算符访问的地址，它表示了在内存中的一个地址。
什么是指针？
指针 就是内存地址，指针变量是用来存放内存地址的变量。就像其他变量或常量一样，您必须在使用指针存储其他变量地址之前，对其进行声明。
指针变量声明的一般形式为：
type *var-name;

在这里，type 是指针的基类型，它必须是一个有效的 C 数据类型，var - name 是指针变量的名称。用来声明指针的星号 *与乘法中使用的星号是相同的。
但是，在这个语句中，星号是用来指定一个变量是指针。以下是有效的指针声明：
int *ip;    一个整型的指针 
double *dp; 一个 double 型的指针
float *fp;  一个浮点型的指针
char *ch;   一个字符型的指针

2. C 中的 NULL 指针:
在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。赋为 NULL 值的指针被称为空指针。
NULL 指针是一个定义在标准库中的值为零的常量. 见 testNull() 函数

3. C 指针的算术运算:
C 指针是一个用数值表示的地址。因此，您可以对指针执行算术运算。可以对指针进行四种算术运算：++、--、+、-。

假设 ptr 是一个指向地址 1000 的整型指针，是一个 32 位的整数，让我们对该指针执行下列的算术运算：ptr ++
在执行完上述的运算之后，ptr 将指向位置 1004，因为 ptr 每增加一次，它都将指向下一个整数位置，即当前位置往后移 4 字节。
这个运算会在不影响内存位置中实际值的情况下，移动指针到下一个内存位置。如果 ptr 指向一个地址为 1000 的字符，
上面的运算会导致指针指向位置 1001，因为下一个字符位置是在 1001。

概括一下：

指针的每一次递增，它其实会指向下一个元素的存储单元。
指针的每一次递减，它都会指向前一个元素的存储单元。
指针在递增和递减时跳跃的字节数取决于指针所指向变量数据类型长度，比如 int 就是 4 个字节。

指针的比较:
指针可以用关系运算符进行比较，如 ==、< 和 >。如果 p1 和 p2 指向两个相关的变量，比如同一个数组中的不同元素，则可对 p1 和 p2 进行大小比较。

4. 指针数组:
可能有一种情况，我们想要让数组存储指向 int 或 char 或其他数据类型的指针。

5. 指向指针的指针:
指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。通常，一个指针包含一个变量的地址。
当我们定义一个指向指针的指针时，第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置。
一个指向指针的指针变量必须如下声明，即在变量名前放置两个星号。例如，下面声明了一个指向 int 类型指针的指针：int **var;

6. 传递指针给函数:
C 语言允许您传递指针给函数，只需要简单地声明函数参数为指针类型即可。

📢📢📢 下面demo 对应章节编号
*/

#include <stdio.h>
#include <time.h>

const int MAX = 3;
// 一定要在main函数前声明函数，才可以调用
void example();          // 1. 指针概念
void testNull();         // 2. C 中的 NULL 指针
void increasePointer();  // 3. C指针的算术运算: 递增
void decreasePointer();  // 3. C指针的算术运算: 递减
void comparePointer();   // 3. C指针的算术运算: 比较指针
void pointerArray();     // 4. 指针数组
void pointerArrayChar(); // 4. 指针数组: 字符串列表
void pointerToPointer(); // 5. 指向指针的指针
void getSeconds(unsigned long *par);

int main()
{
  example();
  testNull();
  increasePointer();
  decreasePointer();
  comparePointer();
  pointerArray();
  pointerArrayChar();
  pointerToPointer();

  unsigned long sec;
  getSeconds(sec);

  printf("----getSeconds----\n");
  printf("Number of seconds: %ld", sec);

  return 0;
}

void example()
{
  printf("--example--\n");
  int var_runoob = 10;
  int *p;
  p = &var_runoob;
  printf("var_runoob 变量的地址: %p\n", &var_runoob);
  printf("p 地址: %p\n", p);
  printf("var_runoob 变量的值: %d\n", *p);
  return;
}

void testNull()
{
  printf("--testNull--\n");
  int *pp = NULL;
  printf("pp 的地址是 %p\n", pp);
  return;
}

void increasePointer()
{
  printf("--increasingPointer--\n");
  int var[] = {10, 100, 200};
  int i, *ptr;

  ptr = var;
  for (i = 0; i < MAX; i++)
  {
    printf("存储地址: var[%d] = %p\n", i, ptr);
    printf("存储值: var[%d] = %d\n", i, *ptr);

    // 指向下一个位置
    ptr++;
  }
  return;
}

void decreasePointer()
{
  printf("--decreasePointer--\n");
  int var[] = {10, 100, 200};
  int i, *ptr;
  ptr = &var[MAX - 1];
  for (i = MAX; i > 0; i--)
  {
    printf("存储地址: var[%d] = %p \n", i, ptr);
    printf("存储值: var[%d] = %d\n", i, *ptr);
    ptr--;
  }
  return;
}

void comparePointer()
{
  printf("--comparePointer--\n");
  int var[] = {10, 20, 100};
  int i, *ptr;

  ptr = var;
  i = 0;
  while (ptr <= &var[MAX - 1])
  {
    printf("存储地址：var[%d] = %p\n", i, ptr);
    printf("存储值：var[%d] = %d\n", i, *ptr);
    ptr++;
    i++;
  }
  return;
}

void pointerArray()
{
  printf("--pointerArray--\n");
  int var[] = {10, 20, 100};
  int i, *ptr[MAX];

  for (i = 0; i < MAX; i++)
  {
    ptr[i] = &var[i];
  }

  for (i = 0; i < MAX; i++)
  {
    printf("Value of var[%d] = %d\n", i, *ptr[i]);
  }
  return;
}

void pointerArrayChar()
{
  printf("--pointerArrayChar--\n");
  const char *names[] = {"张三", "李四", "王五", "麻六"};
  int i;
  for (i = 0; i < 4; i++)
  {
    printf("Value of names[%d] = %s\n", i, names[i]);
  }
  return;
}

void pointerToPointer()
{
  printf("--pointerToPointer--\n");
  int v;
  int *pt1;
  int **pt2;

  v = 100;
  pt1 = &v;
  pt2 = &pt1;

  printf("var = %d\n", v);
  printf("pt1 = %p\n", pt1);
  printf("*pt1 = %d\n", *pt1);
  printf("pt2 = %p\n", pt2);
  printf("**pt2 = %d\n", **pt2);
}

void getSeconds(unsigned long *par)
{
  *par = time(NULL);
  return;
}