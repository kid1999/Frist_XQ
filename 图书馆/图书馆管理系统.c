#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxSize 100         // �������
int id =0;
int std_id = 0;
typedef struct books{			//ͼ����Ϣ
	int id;
	char name[20];
    char author[20];
	char press[50];
	int  state;
}Book;

typedef struct students{		//ѧ����Ϣ
	int std_id;
	char std_name[20];
	char cls[20];
	char sex[5];
}Student;
													           //���
//ͼ����Ϣ���
void put_book(Book *book){
	char name[20],author[20],press[50];
	if(id < MaxSize){
		printf("������ͼ����Ϣ��(���� ���� ������)\n");
		scanf("%s %s %s",name,author,press);
		strcpy(book[id].name,name);
		strcpy(book[id].author,author);
		strcpy(book[id].press,press);
		book[id].state = -1;
		printf("���:%d\t����:%s\t����:%s\t������:\%s\t�ڹ�\n",id,book[id].name,book[id].author,book[id].press);
		id ++;
	}
	else{
		printf("ͼ�������\n");
	}

}

//ѧ����Ϣ���
void put_student(Student *student){
	char name[20],cls[20],sex[5];
	if(std_id < MaxSize){
		printf("������ѧ����Ϣ�������� �༶ �Ա�\n");
		scanf("%s %s %s",name,cls,sex);
		strcpy(student[std_id].std_name,name);
		strcpy(student[std_id].cls,cls);
		strcpy(student[std_id].sex,sex);
		printf("ѧ��:%d\t����:%s\t�༶:%s\t�Ա�:%s\n",std_id,student[std_id].std_name,student[std_id].cls,student[std_id].sex);
		std_id ++;
	}
	else{
		printf("ѧ��������\n");
	}

}

																//  ��ѯ

//ͼ�����
void book_display(Book *book){
	int i = 0;
	printf("����ͼ����Ϣ:\n");
	for(i;i<id;i++){
        if(book[i].state == -1)
           printf("���:%d\t����:%s\t����:%s\t������:\%s\t�ڹ�\n",i,book[i].name,book[i].author,book[i].press);
        else
            printf("���:%d\t����:%s\t����:%s\t������:\%s\t���ڹ�\n",i,book[i].name,book[i].author,book[i].press);
	}

}
//   id��ѯ
int book_search_id(Book *book){
	printf("������Ҫ��ѯ��ͼ��id :\n");
	int i;
	scanf("%d",&i);
	if(i<id){
		if(book[i].state == -1)
           printf("���:%d\t����:%s\t����:%s\t������:\%s\t�ڹ�\n",i,book[i].name,book[i].author,book[i].press);
        else
            printf("���:%d\t����:%s\t����:%s\t������:\%s\t%dͬѧ�ѽ�\n",i,book[i].name,book[i].author,book[i].press,book[i].state);

		return 1;
	}
	else{
		printf("�����ѯ��������\n");
		return 0;
	}
}

// name ��ѯ
int book_search_name(Book *book){
	char name[20];
	int i = 0;
	printf("������Ҫ��ѯ��ͼ��name :\n");
	scanf("%s",name);
	for(i;i<id;i++){
		if(strcmp(book[i].name,name) == 0){
			if(book[i].state == -1)
                printf("���:%d\t����:%s\t����:%s\t������:\%s\t�ڹ�\n",i,book[i].name,book[i].author,book[i].press);
            else
                printf("���:%d\t����:%s\t����:%s\t������:\%s\t%dͬѧ�ѽ�\n",i,book[i].name,book[i].author,book[i].press,book[i].state);
			return 1;
		}
	}
	printf("δ�ҵ���\n");
	return 0;
}

//  student ����
void student_display(Student *student){
	printf("����ѧ����Ϣ:\n");
	int i=0;
	for(i;i<std_id;i++){
        int j = 0;
     	printf("ѧ��:%d\t����:%s\t�༶:%s\t�Ա�:%s\n",i,student[i].std_name,student[i].cls,student[i].sex);
	}
}

																			//���� ͼ��
void borrow_books(Book *book,Student *student){
	system("date/t");		//��ʾ��ǰʱ��
	int i,j;
	printf("����������ѧ���� �� ��ţ�\n");
	scanf("%d %d",&i,&j);
	if(i<=std_id && j <= id && book[j].state == -1){
		book[j].state = i;					//�鱾״̬  ��  Ӧ   ѧ����
		printf("%d ͬѧ������ɣ�\n",i);
	}
	else{
		printf("����ʧ�ܣ�\n");
	}
}

//����

void return_books(Book *book){
	system("date/t");		//��ʾ��ǰʱ��
	int i;
	printf("������������id��\n");
	scanf("%d",&i);
	book[i].state = -1;					//�鱾״̬  ��  Ӧ   -1  ��ͼ���
	printf("%d ͬѧ������ɣ�\n",i);
}


main(){
	Book book[MaxSize];
	Student student[MaxSize];

// ��ʽ����  app
int num;
printf("-----------  ͼ�����Ϣ����ϵͳ  ----------------\n");
printf("1.ͼ����Ϣ¼��             ");
printf("2.ѧ����Ϣ¼��\n");
printf("3.ͼ����Ϣ����             ");
printf("4.ѧ����Ϣ����\n");
printf("5.����Ų�����             ");
printf("6.������������\n");
printf("7.����                     ");
printf("8.����\n");
printf("--------------------------------------------------\n");
printf("�� -1 �˳�����\n");
printf("\n");
printf("��ѡ��������Ҫ�Ĺ��ܱ��:\n");
scanf("%d",&num);


//��������
while(num != -1){
    switch(num){
	case 1: put_book(book);                 printf("---��ѡ��������Ҫ�Ĺ��ܱ��:\n");  scanf("%d",&num);  break;
	case 2: put_student(student);           printf("---��ѡ��������Ҫ�Ĺ��ܱ��:\n");  scanf("%d",&num);  break;
	case 3: book_display(book);             printf("---��ѡ��������Ҫ�Ĺ��ܱ��:\n");  scanf("%d",&num);  break;
	case 4: student_display(student);       printf("---��ѡ��������Ҫ�Ĺ��ܱ��:\n");  scanf("%d",&num);  break;
	case 5: book_search_id(book);           printf("---��ѡ��������Ҫ�Ĺ��ܱ��:\n");  scanf("%d",&num);  break;
	case 6: book_search_name(book);         printf("---��ѡ��������Ҫ�Ĺ��ܱ��:\n");  scanf("%d",&num);  break;
	case 7: borrow_books(book,student);     printf("---��ѡ��������Ҫ�Ĺ��ܱ��:\n");  scanf("%d",&num);  break;
	case 8: return_books(book);             printf("---��ѡ��������Ҫ�Ĺ��ܱ��:\n");  scanf("%d",&num);  break;
        }
    }
printf("--------�������-------\n");
}
