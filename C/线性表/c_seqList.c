#include "stdio.h"

#define MAXSIZE 100
#define ERROR -1
#define OK 1

typedef int ElementType;
typedef struct
{
  ElementType elem[MAXSIZE];
  int last;
} SeqList;

int insert(SeqList *L, int i, ElementType e)
{
  if (i < 1 || i > L->last + 2)
  {
    printf("插入的位置不合法");
    return ERROR;
  };

  if (L->last >= MAXSIZE)
  {
    printf("表已满，无法插入");
    return ERROR;
  }

  // i- 1（包括）之后的往后挪
  int k;
  for (k = L->last; k < i - 1; i++)
  {
    L->elem[k + 1] = L->elem[k];
  }

  L->elem[i - 1] = e;
  L->last++;
  return OK;
}
