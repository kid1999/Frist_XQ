#include<stdio.h>
#include<string.h>

//����һ���ṹ��
struct books{     //��ǩ
	char title[50];
	char author[50];
	char subject[100];
	int book_id;    //��������
};      //��Ȼ��ʼ��

void print(struct books book)   //�ṹ��������
{
	printf("%s  %s  %s  %d \n",book.title,book.author,book.subject,book.book_id);

}



main()
{
	struct books Book1;
	   /* Book1 ���� */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
   
   print(Book1);
   
   //ָ��ṹ��ָ��
   struct books *struct_pointer;
   struct_pointer = &Book1;
   print(*struct_pointer);
   
   //ָ��ָ���Ա
   printf("%d",struct_pointer->book_id);
}
	


