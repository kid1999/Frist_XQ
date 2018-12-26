#include<stdio.h>
#include<string.h>

//定义一个结构体
struct books{     //标签
	char title[50];
	char author[50];
	char subject[100];
	int book_id;    //声明变量
};      //自然初始化

void print(struct books book)   //结构体做变量
{
	printf("%s  %s  %s  %d \n",book.title,book.author,book.subject,book.book_id);

}



main()
{
	struct books Book1;
	   /* Book1 详述 */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
   
   print(Book1);
   
   //指向结构的指针
   struct books *struct_pointer;
   struct_pointer = &Book1;
   print(*struct_pointer);
   
   //指针指向成员
   printf("%d",struct_pointer->book_id);
}
	


