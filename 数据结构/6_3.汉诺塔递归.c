// ��ŵ�� �ݹ�����
#include<stdio.h> 
void Towers(int n,char fromPeg,char toPeg,char auxPeg){
	if(n == 1){
		// �ݹ����
		printf("move disk 1 from peg %c to peg %c\n",fromPeg,toPeg); 
		return ;
	}
	
	// n-1 ��Բ�� �� from ���� topeg  �ƶ��� aux
	Towers(n-1,fromPeg,auxPeg,toPeg);
	
	//��Բ�� n �� from ֱ���ƶ��� topeg
	printf("move disk %d from peg %c to peg %c\n",n,fromPeg,toPeg);
	
	// �� n-1 ��Բ�� ��aux ���� frompeg �Ƶ� topeg
	Towers(n-1,auxPeg,toPeg,fromPeg); 
} 

main(){
	Towers(4,'A','C','B');	// from  to aux
}
