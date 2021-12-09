#include "stdio.h"
#include "stdlib.h"

#define ElementType int
typedef struct Node
{
  ElementType data;
  struct Node *next;
} Node, *LinkList;

// 头插法
void creatFromHead(LinkList L)
{
  LinkList s;
  int c;
  int c = 10;
  while (c > 0)
  {
    s = (Node *)malloc(sizeof(Node));
    s->data = c;
    // 注意头插法的两个交换顺序，从右向左
    s->next = L->next;
    L->next = s;
    c--;
  }
}

// 尾插法
void creatFromTail(LinkList L)
{
  LinkList r, s;
  int c = 10;
  while (c > 0)
  {
    s = (Node *)malloc(sizeof(Node));
    s->data = c;
    r->next = s;
    r = s;
    c--;
  }
  r->next = NULL;
}