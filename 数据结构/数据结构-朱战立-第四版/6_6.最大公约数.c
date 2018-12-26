// m  n  最大公约数
#include<stdio.h>

int Gcd(int n,int m){		//递归写法 
	if(n<0 || m<0) return -1;
	if(m ==0) return n;
	else if(m >n) return Gcd(m,n);		//大的除小的 
	else return Gcd(m,n%m); 	// 递归主体
	} 
	
int Gcd2(int n,int m){		// 循环写法
	int tn,tm,tmp;
	if(n<0 || m<0) return -1;
	if(m>n){	//交换参数 
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
