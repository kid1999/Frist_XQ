#include<stdio.h>

main(){
	
	FILE *fp = NULL;	//�ļ���ָ�� 
	fp = fopen("C:\\Users\\Administrator\\Desktop\\C\\����.txt","w+");
	
	//д���ļ�
	
	//д���ַ�ֵ  �ɹ�����ֵelse  EOF 
	fputc('C',fp);	
	
	
	//д���ַ��� �ɹ����� �Ǹ���
	fputs("hello world \n",fp);	
	
	fprintf(fp,"This is a io program");
	 	
	fclose(fp);
	 

	
	
} 
