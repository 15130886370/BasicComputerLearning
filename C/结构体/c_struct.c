/*
C 结构体

C 数组允许定义可存储相同类型数据项的变量，结构是 C 编程中另一种用户自定义的可用的数据类型，它允许您存储不同类型的数据项。
定义结构:
为了定义结构，您必须使用 struct 语句。struct 语句定义了一个包含多个成员的新的数据类型，struct 语句的格式如下:

struct Tag { 
    member-list
    member-list 
    member-list  
    ...
} variable-list ;

*/

#include "stdio.h"
#include "string.h"

struct Books
{
  char title[50];
  char author[50];
  char subject[100];
  int book_id;
};

typedef struct Book MyBook;

// 函数声明
void printfBook(MyBook book);
void testBook();
void printfPointerBook(MyBook *book);
void testPointerBook();

int main()
{

  testBook();
  testPointerBook();
  return 0;
}

/*
结构体作为函数参数:
我们可以把结构体作为函数参数，传参方式与其他类型的变量或指针类似。您可以使用上面实例中的方式来访问结构变量:
*/

struct Book
{
  char title[50];
  char author[50];
  char subject[100];
  int book_id;
};

void testBook()
{
  MyBook book1; /* 声明 Book1，类型为 Books */
  MyBook book2; /* 声明 Book2，类型为 Books */

  /* Book1 详述 */
  strcpy(book1.title, "C Programming");
  strcpy(book1.author, "Nuha Ali");
  strcpy(book1.subject, "C Programming Tutorial");
  book1.book_id = 6495407;

  /* Book2 详述 */
  strcpy(book2.title, "Telecom Billing");
  strcpy(book2.author, "Zara Ali");
  strcpy(book2.subject, "Telecom Billing Tutorial");
  book2.book_id = 6495700;

  /* 输出 Book1 信息 */
  printfBook(book1);

  /* 输出 Book2 信息 */
  printfBook(book2);
}

void printfBook(MyBook book)
{
  printf("Book title : %s\n", book.title);
  printf("Book author : %s\n", book.author);
  printf("Book subject : %s\n", book.subject);
  printf("Book book_id : %d\n", book.book_id);
}

/*
指向结构的指针
我们可以定义指向结构的指针，方式与定义指向其他类型变量的指针相似，如下所示：

struct Books *struct_pointer;

现在，我们可以在上述定义的指针变量中存储结构变量的地址。
为了查找结构变量的地址，把 & 运算符放在结构名称的前面，如下所示：

struct _pointer = &Book1;

为了使用指向该结构的指针访问结构的成员，您必须使用 -> 运算符，如下所示:
struct_pointer->title;

*/

void testPointerBook()
{
  MyBook book1; /* 声明 Book1，类型为 Books */
  MyBook book2; /* 声明 Book2，类型为 Books */

  /* Book1 详述 */
  strcpy(book1.title, "C Programming");
  strcpy(book1.author, "Nuha Ali");
  strcpy(book1.subject, "C Programming Tutorial");
  book1.book_id = 6495407;

  /* Book2 详述 */
  strcpy(book2.title, "Telecom Billing");
  strcpy(book2.author, "Zara Ali");
  strcpy(book2.subject, "Telecom Billing Tutorial");
  book2.book_id = 6495700;

  /* 通过传 Book1 的地址来输出 Book1 信息 */
  printfPointerBook(&book1);

  /* 通过传 Book2 的地址来输出 Book2 信息 */
  printfPointerBook(&book2);
}

void printfPointerBook(MyBook *book)
{
  printf("MyBook title: %s\n", book->title);
  printf("MyBook author: %s\n", book->author);
  printf("MyBook subject : %s\n", book->subject);
  printf("MyBook book_id : %d\n", book->book_id);
  return;
}