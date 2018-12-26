#include<stdio.h>
#include<stdlib.h>

//排除  被0的错误 
 
main(){
	
	int a = 20, b = 0,c;
	
	if(b == 0){
		fprintf(stderr,"除数为0 退出运行...\n");
		exit(-1);
	} 
	c = a/b;
	fprintf(stderr,"c 的值为：%d\n",c);
	exit(0);
	
}
