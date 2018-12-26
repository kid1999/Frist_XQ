#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxSize 100         // 最大容量
int id =0;
int std_id = 0;
typedef struct books{			//图书信息
	int id;
	char name[20];
    char author[20];
	char press[50];
	int  state;
}Book;

typedef struct students{		//学生信息
	int std_id;
	char std_name[20];
	char cls[20];
	char sex[5];
}Student;
													           //入库
//图书信息入库
void put_book(Book *book){
	char name[20],author[20],press[50];
	if(id < MaxSize){
		printf("请输入图书信息：(书名 作者 出版社)\n");
		scanf("%s %s %s",name,author,press);
		strcpy(book[id].name,name);
		strcpy(book[id].author,author);
		strcpy(book[id].press,press);
		book[id].state = -1;
		printf("书号:%d\t书名:%s\t作者:%s\t出版社:\%s\t在馆\n",id,book[id].name,book[id].author,book[id].press);
		id ++;
	}
	else{
		printf("图书馆已满\n");
	}

}

//学生信息入库
void put_student(Student *student){
	char name[20],cls[20],sex[5];
	if(std_id < MaxSize){
		printf("请输入学生信息：（姓名 班级 性别）\n");
		scanf("%s %s %s",name,cls,sex);
		strcpy(student[std_id].std_name,name);
		strcpy(student[std_id].cls,cls);
		strcpy(student[std_id].sex,sex);
		printf("学号:%d\t姓名:%s\t班级:%s\t性别:%s\n",std_id,student[std_id].std_name,student[std_id].cls,student[std_id].sex);
		std_id ++;
	}
	else{
		printf("学生表已满\n");
	}

}

																//  查询

//图书遍历
void book_display(Book *book){
	int i = 0;
	printf("所有图书信息:\n");
	for(i;i<id;i++){
        if(book[i].state == -1)
           printf("书号:%d\t书名:%s\t作者:%s\t出版社:\%s\t在馆\n",i,book[i].name,book[i].author,book[i].press);
        else
            printf("书号:%d\t书名:%s\t作者:%s\t出版社:\%s\t不在馆\n",i,book[i].name,book[i].author,book[i].press);
	}

}
//   id查询
int book_search_id(Book *book){
	printf("请输入要查询的图书id :\n");
	int i;
	scanf("%d",&i);
	if(i<id){
		if(book[i].state == -1)
           printf("书号:%d\t书名:%s\t作者:%s\t出版社:\%s\t在馆\n",i,book[i].name,book[i].author,book[i].press);
        else
            printf("书号:%d\t书名:%s\t作者:%s\t出版社:\%s\t%d同学已借\n",i,book[i].name,book[i].author,book[i].press,book[i].state);

		return 1;
	}
	else{
		printf("输入查询参数有误\n");
		return 0;
	}
}

// name 查询
int book_search_name(Book *book){
	char name[20];
	int i = 0;
	printf("请输入要查询的图书name :\n");
	scanf("%s",name);
	for(i;i<id;i++){
		if(strcmp(book[i].name,name) == 0){
			if(book[i].state == -1)
                printf("书号:%d\t书名:%s\t作者:%s\t出版社:\%s\t在馆\n",i,book[i].name,book[i].author,book[i].press);
            else
                printf("书号:%d\t书名:%s\t作者:%s\t出版社:\%s\t%d同学已借\n",i,book[i].name,book[i].author,book[i].press,book[i].state);
			return 1;
		}
	}
	printf("未找到！\n");
	return 0;
}

//  student 遍历
void student_display(Student *student){
	printf("所有学生信息:\n");
	int i=0;
	for(i;i<std_id;i++){
        int j = 0;
     	printf("学号:%d\t姓名:%s\t班级:%s\t性别:%s\n",i,student[i].std_name,student[i].cls,student[i].sex);
	}
}

																			//借阅 图书
void borrow_books(Book *book,Student *student){
	system("date/t");		//显示当前时间
	int i,j;
	printf("借书请输入学生号 和 书号：\n");
	scanf("%d %d",&i,&j);
	if(i<=std_id && j <= id && book[j].state == -1){
		book[j].state = i;					//书本状态  对  应   学生号
		printf("%d 同学借书完成！\n",i);
	}
	else{
		printf("借书失败！\n");
	}
}

//还书

void return_books(Book *book){
	system("date/t");		//显示当前时间
	int i;
	printf("还书请输入书id：\n");
	scanf("%d",&i);
	book[i].state = -1;					//书本状态  对  应   -1  在图书馆
	printf("%d 同学还书完成！\n",i);
}


main(){
	Book book[MaxSize];
	Student student[MaxSize];

// 正式建立  app
int num;
printf("-----------  图书馆信息管理系统  ----------------\n");
printf("1.图书信息录入             ");
printf("2.学生信息录入\n");
printf("3.图书信息遍历             ");
printf("4.学生信息遍历\n");
printf("5.按书号查找书             ");
printf("6.按书名查找书\n");
printf("7.借书                     ");
printf("8.还书\n");
printf("--------------------------------------------------\n");
printf("按 -1 退出程序\n");
printf("\n");
printf("请选择你所需要的功能编号:\n");
scanf("%d",&num);


//函数主体
while(num != -1){
    switch(num){
	case 1: put_book(book);                 printf("---请选择你所需要的功能编号:\n");  scanf("%d",&num);  break;
	case 2: put_student(student);           printf("---请选择你所需要的功能编号:\n");  scanf("%d",&num);  break;
	case 3: book_display(book);             printf("---请选择你所需要的功能编号:\n");  scanf("%d",&num);  break;
	case 4: student_display(student);       printf("---请选择你所需要的功能编号:\n");  scanf("%d",&num);  break;
	case 5: book_search_id(book);           printf("---请选择你所需要的功能编号:\n");  scanf("%d",&num);  break;
	case 6: book_search_name(book);         printf("---请选择你所需要的功能编号:\n");  scanf("%d",&num);  break;
	case 7: borrow_books(book,student);     printf("---请选择你所需要的功能编号:\n");  scanf("%d",&num);  break;
	case 8: return_books(book);             printf("---请选择你所需要的功能编号:\n");  scanf("%d",&num);  break;
        }
    }
printf("--------程序结束-------\n");
}
