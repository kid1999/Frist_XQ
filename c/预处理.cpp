#include<stdio.h>

//�궨�庯�� 
#define MAX(x,y) ((x) > (y) ? (x) : (y))

#define message(a,b) printf(#a " and "#b "\n");

#define tokenpaster(n) printf("token"#n " = %d",token##n) 

main(){
	
	//Ԥ����� 
	printf("1  %s\n ",__FILE__);	//���ص�ǰ�ļ��� 
	printf("2  %s\n ",__DATE__);	//���ص�ǰ���� 
	printf("3  %s\n ",__TIME__);	//���ص�ǰ��ȷʱ�� 
	printf("4  %d\n ",__LINE__);	//���ص�ǰ���� 
	printf("5  %d\n ",__STDC__);	// 

// Ԥ����꺯��  
	printf("%d \n",MAX(11,12));
	
//	��Ԥ���庯��  �ַ����������������#��
	message(git,hub);
	
//�궨���ڵı��ճ���������##����ϲ������������������ں궨�������������ı�Ǳ��ϲ�Ϊһ�����
	int token5 = 20;
	tokenpaster(5);
} 
