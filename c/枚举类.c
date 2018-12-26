#include<stdio.h>
void print(int arr[],int j){
    for(int i = j-1;i>=0;i--)
    {
        printf("%d  ",arr[i]);
    }
}

main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,0};
   // print(array,10);

    //Ã¶¾ÙÀà
    enum Day
    {
        mon=1,tue,wed,thu,fri,sat,sun
    };

    enum Day day;

    printf("%d ",tue);
}
