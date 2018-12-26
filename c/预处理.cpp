#include<stdio.h>

//宏定义函数 
#define MAX(x,y) ((x) > (y) ? (x) : (y))

#define message(a,b) printf(#a " and "#b "\n");

#define tokenpaster(n) printf("token"#n " = %d",token##n) 

main(){
	
	//预定义宏 
	printf("1  %s\n ",__FILE__);	//返回当前文件名 
	printf("2  %s\n ",__DATE__);	//返回当前日期 
	printf("3  %s\n ",__TIME__);	//返回当前精确时间 
	printf("4  %d\n ",__LINE__);	//返回当前行数 
	printf("5  %d\n ",__STDC__);	// 

// 预定义宏函数  
	printf("%d \n",MAX(11,12));
	
//	对预定义函数  字符串常量化运算符（#）
	message(git,hub);
	
//宏定义内的标记粘贴运算符（##）会合并两个参数。它允许在宏定义中两个独立的标记被合并为一个标记
	int token5 = 20;
	tokenpaster(5);
} 
