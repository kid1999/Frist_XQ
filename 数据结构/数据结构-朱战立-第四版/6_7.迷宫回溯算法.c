#include<stdio.h>
#include<stdlib.h>

//  �Թ�����  �����㷨

typedef struct{
	// ·�ڵĽṹ�嶨��  ���� �� 
	int left;	
	int forward;
	int right; 
}InterSection;

typedef struct {
	// �Թ��ṹ�嶨��
	int mazeSize;	//·�ڸ���
	InterSection *intSec;	//·�ڼ���
	int Exit;		//���� 
}Maze;


// ���Թ� 
int TravMaze(Maze *m,int currSetValue){
	// �û����㷨 �������з�֧ currΪ ��ǰ·��
	if(currSetValue > 0){
		if(currSetValue == m->Exit)		//�ݹ����
		{
			printf("%d  <==",currSetValue);
			return 1; 
		} 
		else if(TravMaze(m,m->intSec[currSetValue].forward) == 1)	//��ǰ 
		{
			printf("%d  <==",currSetValue);
			return 1; 
		} 
		else if(TravMaze(m,m->intSec[currSetValue].right) == 1)	//���� 
		{
			printf("%d  <==",currSetValue);
			return 1; 
		} 
		else if(TravMaze(m,m->intSec[currSetValue].left) == 1)	//����
		{
			printf("%d  <==",currSetValue);
			return 1; 
		} 
	} 
	return 0;		//��ʾ�˽ڵ㲻ͨ   
}

// �����Թ�
int CreatMaze(char *filename,Maze *m){
	// ��ȡ filename �ļ��е����ݹ����Թ�
	FILE *fp;
	int i;
	fp = fopen(filename,"r");	//���ļ�
	if(!fp){
		printf("�����ļ��޷���!\n");
		return ;
	} 
	
	fscanf(fp,"%d",&m->mazeSize);		//����·������
	
	// ���� mazeSize+1��Ԫ�ص�����
	m->intSec = (InterSection*)malloc(sizeof(InterSection)*(m->mazeSize+1));
	
	for(i =1;i<=m->mazeSize;i++){
			fscanf(fp,"%d%d%d",&m->intSec[i].left,&m->intSec[i].forward,&m->intSec[i].right);	//·����Ϣ 
	}
	fscanf(fp,"%d",&m->Exit);	//���� 
	fclose(fp); 	
} 


main(){
	Maze m;
	int start = 1;
	
	CreatMaze("Maze1.dat",&m);
	if(TravMaze(&m,start))
		printf("\n ���Թ���һ��ͨ·������ʾ!");
	else
		printf("\n ���Թ��޽�!"); 
}
