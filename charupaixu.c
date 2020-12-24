#include   <stdio.h>
#include  <stdlib.h>
#include    <time.h>

void printf_data(int arr[],int n)
{
    for(int i=0;i<n;i++) printf("%d ",arr[i]);printf("\n");
}

void InsertSort(int arr[], int n)
{
    int tempVal;
    /*从第一个位置开始，1~n-1，依次和前面的数据比较*/
    for (int i = 1, j; i < n; i++){
        printf("==========================\n");
        printf_data(arr,n);
        /*保存要插入的值*/
        tempVal = arr[i];
        printf("arr[%d]=[%d]\n",i,arr[i]);
        /*数据往后移动，给要插入的值腾位*/
        for (j = i - 1; tempVal < arr[j] && j >= 0; --j){
            /*用前一位的数据填充后一位的数据*/
            arr[j + 1] = arr[j];
            printf_data(arr,n);
        }
        /*插入数据*/
        arr[j + 1] = tempVal;
        printf_data(arr,n);
    }
}


#define LENGTH 30

int main()
{
    int i,j;
    int arr[LENGTH] = {0};

    /*随机数设置种子*/
    srand((unsigned)time(NULL));
    /*赋值*/
    for(i=0;i<LENGTH;i++)
        arr[i] = rand()%100;
    /*排序前*/
    for(i=0;i<LENGTH;i++)
        printf("%d ",arr[i]);printf("\n");

    InsertSort(arr,LENGTH);

    /*排序后*/
    for(i=0;i<LENGTH;i++)
        printf("%d ",arr[i]);printf("\n");
    return 0;
}
