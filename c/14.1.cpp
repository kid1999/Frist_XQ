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
		    for(x=0;x<10;x++)      //  ���� �ɼ�
		    for(y=0;y<5;y++)      
		{
			printf("����:");
			scanf("%d",&n);
			a[x][y]=n;
		}
		f();
		s();
		t();
		r();
		 
	}
   
    
	


	   



	int f()            //�� ѧ��ƽ����
	{
	   int i,x,y;
	   float xp;
       for(x=0;x<10;x++)
	   { 
		   i=0;
       for(y=0;y<5;y++)
	   i=i+a[x][y];
	   
	   xp=i/5.0;
	   printf("�����ѧ��ƽ���� %.2f\n",xp);
	   }
	   
	   }



	int s()
	{    int x,y,z;
		float kp;
for(y=0;y<5;y++)   //��γ�ƽ����
		{    z=0;
			for(x=0;x<10;x++)
				z=z+a[x][y];

          	    kp=z/10.0;
				  printf("����ÿγ�ƽ��ֵ %.2f\n",kp);
}
   
	}



int t()
{
	int x,y,xs,kc,max=0;
for(x=0;x<10;x++)
for(y=0;y<5;y++)
if(a[x][y]>max)      //�� ��óɼ�����
{	max=a[x][y];
	xs=x;
	kc=y;
}
printf("�ɼ���õ�%d  ���� %d  �γ�  %d\n",max,xs,kc);
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
	   printf("������%f",s);
       
        	
}
	   
