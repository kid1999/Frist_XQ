#include<stdio.h>
#include<stdlib.h>

//排除  被0的错误 
 
main(){
	
	int a = 20, b = 5,c;
	
	if(b == 0){
		fprintf(stderr,"除数为0 退出运行...\n");
		exit(EXIT_FAILURE);		//出错默认返回 -1 
	} 
	c = a/b;
	fprintf(stderr,"c 的值为：%d\n",c);
	exit(EXIT_SUCCESS);		// 成功默认是1 
	
}
