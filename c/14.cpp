#include<stdio.h>
main()
{
	int a[10][5],xp,kp,i,z,n,x,y,max=0,xs,kc;
    for(x=0;x<10;x++)      //  输入 成绩
	{   i=0;
		for(y=0;y<5;y++)      
		{
			printf("输入:");
			scanf("%d",&n);
			a[x][y]=n;
			i=i+n;


			if(n>max)      //顺便求 最好成绩的人
			{
				max=n;
				xs=x;
				kc=y;
}
		}
		xp=i/5;
	    printf("该学生平均分:%d\n",xp);    //顺便求  学生平均分
	}


		for(y=0;y<5;y++)   //求课程平均分
		{    z=0;
			for(x=0;x<10;x++)
				z=z+a[x][y];

          	    kp=z/10;
			printf("该课程平均分:%d\n",kp);
		}
		printf("最好成绩是%d,  姓名 %d,  课程 %d\n ",max,xs,kc);
}
