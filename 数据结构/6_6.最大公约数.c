// m  n  ���Լ��
#include<stdio.h>

int Gcd(int n,int m){		//�ݹ�д�� 
	if(n<0 || m<0) return -1;
	if(m ==0) return n;
	else if(m >n) return Gcd(m,n);		//��ĳ�С�� 
	else return Gcd(m,n%m); 	// �ݹ�����
	} 
	
int Gcd2(int n,int m){		// ѭ��д��
	int tn,tm,tmp;
	if(n<0 || m<0) return -1;
	if(m>n){	//�������� 
		tn = m;
		tm = n;
	} 
	else{
		tn = n;
		tm = m;
	} 
	while(tm != 0){
		tmp = tn;
		tn = tm;
		tm = tmp % tm;
	}
	return tn;	
} 

main(){
	printf("%d\n",Gcd(50,25));
	printf("%d",Gcd2(50,25));
}
