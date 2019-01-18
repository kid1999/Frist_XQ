#include "stdio.h"
#include "stdlib.h"
#include "time.h"//用于获取程序运行时间  

void quick_sort(int s[],int l,int r)
{
    if(l < r)		//大于一个间距开始 
    {
        int i=l,j=r,x=s[l];	//选第一个元素为基准 
        while(i<j)
        {
            while(i<j && s[j]>=x)//从右到左找到第一个小于x的数  
                j--;
            if(i<j)
                s[i++]=s[j];
            
            while(i<j && s[i]<=x)//从左往右找到第一个大于x的数  
                i++;
            if(i<j)
                s[j--]=s[i]; 
            
        }
        
        s[i]=x;//i = j的时候，将x填入中间位置  
        quick_sort(s,l,i-1);//递归调用 
        quick_sort(s,i+1,r);        
    }
}


int main()
{
    clock_t start,finish;
    double totaltime;
    start=clock();
    
    /****下面为需要运行的主程序****/ 
    int i; 
    int a[] = {1,8,44,77,35,65,78,12,25,455,20,15,45};
    int length = sizeof(a)/sizeof(int);//求数组的长度  
    
    printf("原序列为： ");
    for(i=0;i<length;i++)
    {
        printf("%d ",a[i]);
    }
    
    quick_sort(a,0,length);
    
    printf("\n排序后的序列为：");
    for(i=1;i<=length;i++)
    {
        printf("%d ",a[i]);
    }

    /********************************/
        
   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   
   printf("\n程序运行的时间为: %.5f 秒",totaltime);

}
