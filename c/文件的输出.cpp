#include<stdio.h>

main(){
	
	//ָ�� 
	FILE *fp = NULL;	
	fp = fopen("C:\\Users\\Administrator\\Desktop\\C\\����.txt","r");
	
	//����
	char buff[255]; 
	
	//��ȡ��ʾ�ļ����� 
	fscanf(fp,"%s",buff);		//���� �ո�ͷ��� 
	printf("1 : %s \n",buff);
	
	fgets(buff,255,(FILE*)fp);	//���� ��һ��ʣ�µ�  
	printf("2 : %s \n",buff);
	
	fgets(buff,255,(FILE*)fp);		//���������ĵڶ��� 
	printf("3: %s \n",buff); 
	
	
} 
