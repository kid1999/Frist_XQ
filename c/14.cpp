#include<stdio.h>
main()
{
	int a[10][5],xp,kp,i,z,n,x,y,max=0,xs,kc;
    for(x=0;x<10;x++)      //  ���� �ɼ�
	{   i=0;
		for(y=0;y<5;y++)      
		{
			printf("����:");
			scanf("%d",&n);
			a[x][y]=n;
			i=i+n;


			if(n>max)      //˳���� ��óɼ�����
			{
				max=n;
				xs=x;
				kc=y;
}
		}
		xp=i/5;
	    printf("��ѧ��ƽ����:%d\n",xp);    //˳����  ѧ��ƽ����
	}


		for(y=0;y<5;y++)   //��γ�ƽ����
		{    z=0;
			for(x=0;x<10;x++)
				z=z+a[x][y];

          	    kp=z/10;
			printf("�ÿγ�ƽ����:%d\n",kp);
		}
		printf("��óɼ���%d,  ���� %d,  �γ� %d\n ",max,xs,kc);
}
