#include<stdio.h>
#include<malloc.h>

//��ά��̬���齨�� 
int **Make2DArray(int row,int col){
	int **a,i;
// ��̬���� n��int �ڴ�ռ� a ָ���׵�ַ
	a = (int **)calloc(row,sizeof(int));
	
	//ѭ������ �� �� ��
	for(i=0;i<row;i++)
		a[i] = (int*)calloc(col,sizeof(int));
	return a; 
} 

//�ͷ�
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
	
	// ��ֵ
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
