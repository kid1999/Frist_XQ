#include<stdio.h>
#include<errno.h>
#include <string.h>


extern int erron;	//���������� 

main(){
	
	FILE *fp;
	int errnum;
	fp = fopen("E:\\�е��Ʊʼ�\\C\\test1.txt","r");
	
	//  �쳣����
	if(fp == NULL)
	{
		//ʹ��stderr���� -��������д��� 
		errnum = errno;
		fprintf(stderr,"�����: %d\n",errno);
		//����һ   ���� errno�� 
		perror("ͨ�� perror �������");
		//������  ����string�� 
		fprintf(stderr,"���ļ����� %s \n",strerror(errnum)); 
	 } 
	 else{
	 	fclose(fp);
	 }
	
}
