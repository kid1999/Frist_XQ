#include<stdio.h>
#include<stdlib.h>

//�ų�  ��0�Ĵ��� 
 
main(){
	
	int a = 20, b = 0,c;
	
	if(b == 0){
		fprintf(stderr,"����Ϊ0 �˳�����...\n");
		exit(-1);
	} 
	c = a/b;
	fprintf(stderr,"c ��ֵΪ��%d\n",c);
	exit(0);
	
}
