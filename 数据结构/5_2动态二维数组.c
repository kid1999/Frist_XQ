#include<stdio.h>
#include<malloc.h>

//二维动态数组建立 
int **Make2DArray(int row,int col){
	int **a,i;
// 动态申请 n个int 内存空间 a 指向首地址
	a = (int **)calloc(row,sizeof(int));
	
	//循环建立 行 内 存
	for(i=0;i<row;i++)
		a[i] = (int*)calloc(col,sizeof(int));
	return a; 
} 

//释放
void Deliver2DArray(int **a,int row){
	int i;
	for(i=0;i<row;i++)
		free(a[i]);
	free(a); 
} 
 
main(){
	int i,j,c;
	int row=3,col=4,**a;
	
	a = Make2DArray(row,col);
	c = 1;
	
	// 赋值
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			a[i][j] = c;
			c++;
		}
	}
	
	//dispaly()
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
			printf("%d  ",a[i][j]);		
		printf("\n");
	}
	
	Deliver2DArray(a,row);
} 
