#include<stdio.h>
int a[10][5];
main()
{
	int i,z,n,x,y,max=0,xs,kc;
    float xp,kp;
    int f();
	int s();
	int t(); 
	int r();
		    for(x=0;x<10;x++)      //  输入 成绩
		    for(y=0;y<5;y++)      
		{
			printf("输入:");
			scanf("%d",&n);
			a[x][y]=n;
		}
		f();
		s();
		t();
		r();
		 
	}
   
    
	


	   



	int f()            //求 学生平均分
	{
	   int i,x,y;
	   float xp;
       for(x=0;x<10;x++)
	   { 
		   i=0;
       for(y=0;y<5;y++)
	   i=i+a[x][y];
	   
	   xp=i/5.0;
	   printf("输出该学生平均分 %.2f\n",xp);
	   }
	   
	   }



	int s()
	{    int x,y,z;
		float kp;
for(y=0;y<5;y++)   //求课程平均分
		{    z=0;
			for(x=0;x<10;x++)
				z=z+a[x][y];

          	    kp=z/10.0;
				  printf("输出该课程平均值 %.2f\n",kp);
}
   
	}



int t()
{
	int x,y,xs,kc,max=0;
for(x=0;x<10;x++)
for(y=0;y<5;y++)
if(a[x][y]>max)      //求 最好成绩的人
{	max=a[x][y];
	xs=x;
	kc=y;
}
printf("成绩最好的%d  姓名 %d  课程  %d\n",max,xs,kc);
}

int r()
{  
	   int i,x,y,n=0,b[10];
	   float xp,s,t;
       for(x=0;x<10;x++)
	   { 
		   i=0;
       for(y=0;y<5;y++)
	   i=i+a[x][y];
	   
	   xp=i/5.0; 
	   b[x]=xp;
}
       for(i=0;i<10;i++)
       {
       	n=n+b[i]*b[i];
       	t=t+(b[i]/10)*(b[i]/10);
	   }
	   s=0.1*n-t;
	   printf("输出方差：%f",s);
       
        	
}
	   
