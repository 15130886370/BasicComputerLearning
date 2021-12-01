/*
C 内存管理
本章将讲解 C 中的动态内存管理。C 语言为内存的分配和管理提供了几个函数。这些函数可以在 <stdlib.h> 头文件中找到。
1.	void *calloc(int num, int size);
在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。所以它的结果是分配了 num*size 个字节长度的内存空间，并且每个字节的值都是0。
2.	void free(void *address);
该函数释放 address 所指向的内存块,释放的是动态分配的内存空间。
3.	void *malloc(int num);
在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。
4.	void *realloc(void *address, int newsize);
该函数重新分配内存，把内存扩展到 newsize。

⚠️⚠️注意⚠️⚠️：void * 类型表示未确定类型的指针。C、C++ 规定 void * 类型可以通过类型转换强制转换为任何其它类型的指针。

动态分配内存:
编程时，如果预先知道数组的大小，那么定义数组时就比较容易。例如，一个存储人名的数组，它最多容纳 100 个字符，所以我们可以定义数组，如下所示：

char name[100];

但是，如果预先不知道需要存储的文本长度，例如您想存储有关一个主题的详细描述。
在这里，我们需要定义一个指针，该指针指向未定义所需内存大小的字符，后续再根据需求来分配内存，如下所示：

dynamicManagerMemory()

上面的程序也可以使用 calloc() 来编写，只需要把 malloc 替换为 calloc 即可，如下所示：

calloc(200, sizeof(char));

当动态分配内存时，您有完全控制权，可以传递任何大小的值。而那些预先定义了大小的数组，一旦定义则无法改变大小。


*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void dynamicManagerMemory();

int main(int argc, char const *argv[])
{
  dynamicManagerMemory();
  return 0;
}

void dynamicManagerMemory()
{
  char name[100];
  char *description;

  strcpy(name, "ittmomWang");
  // 动态分配内存
  description = (char *)malloc(1 * sizeof(char));

  printf("---sizeOf----%lu\n", sizeof(description));
  if (description == NULL)
  {
    fprintf(stderr, "Error = unalble to allocate required memory\n");
  }
  else
  {
    strcpy(description, "let's play with c programming");
  }

  printf("Name = %s\n", name);
  printf("Description: %s\n sizeof: %ld", description, sizeof(description));
}

void reallocMemory()
{
  char name[100];
  char *description;

  strcpy(name, "ittmomWang");
  // 动态分配内存
  description = (char *)malloc(1 * sizeof(char));

  printf("---sizeOf----%lu\n", sizeof(description));
  if (description == NULL)
  {
    fprintf(stderr, "Error = unalble to allocate required memory\n");
  }
  else
  {
    strcpy(description, "let's play with c programming");
  }

  // 假设我们想要存储更大的描述信息
  description = (char *)realloc(description, 100 * sizeof(char));
  if (description == NULL)
  {
    fprintf(stderr, "Error - unable to allocate required memory\n");
  }
  else
  {
    strcat(description, "She is in class 10th");
  }

  printf("Name = %s\n", name);
  printf("Description: %s\n", description);

  // 使用 free 函数释放内存
  free(description);
}