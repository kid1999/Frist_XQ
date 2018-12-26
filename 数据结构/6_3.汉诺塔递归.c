// 汉诺塔 递归问题
#include<stdio.h> 
void Towers(int n,char fromPeg,char toPeg,char auxPeg){
	if(n == 1){
		// 递归出口
		printf("move disk 1 from peg %c to peg %c\n",fromPeg,toPeg); 
		return ;
	}
	
	// n-1 个圆盘 从 from 借助 topeg  移动到 aux
	Towers(n-1,fromPeg,auxPeg,toPeg);
	
	//把圆盘 n 由 from 直接移动到 topeg
	printf("move disk %d from peg %c to peg %c\n",n,fromPeg,toPeg);
	
	// 把 n-1 个圆盘 从aux 借助 frompeg 移到 topeg
	Towers(n-1,auxPeg,toPeg,fromPeg); 
} 

main(){
	Towers(4,'A','C','B');	// from  to aux
}
