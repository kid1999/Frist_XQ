#include<stdio.h>
#include<stdlib.h>

//�ų�  ��0�Ĵ��� 
 
main(){
	
	int a = 20, b = 5,c;
	
	if(b == 0){
		fprintf(stderr,"����Ϊ0 �˳�����...\n");
		exit(EXIT_FAILURE);		//����Ĭ�Ϸ��� -1 
	} 
	c = a/b;
	fprintf(stderr,"c ��ֵΪ��%d\n",c);
	exit(EXIT_SUCCESS);		// �ɹ�Ĭ����1 
	
}
