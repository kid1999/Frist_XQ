// �ɱ���� 
#include<stdio.h>
#include<stdarg.h>
 //num:�ɱ����������   ...�ɱ���� 
double average(int num,...)
{
	va_list valist;
	double sum =0.0;
	int i;
	
	//Ϊnum������ ��ʼ�� valist
	va_start(valist,num);
	
	// ��������valist�Ĳ���
	for(i =0;i<num;i++)
		sum += va_arg(valist,int);
	
	//����Ϊvalist�������ڴ�
	va_end(valist); 
	
	return sum/num; 
}

main(){
	printf("first: %f \n",average(4,4,5,6,7));
		printf("second: %f \n",average(3,13,14,15));
	
}

