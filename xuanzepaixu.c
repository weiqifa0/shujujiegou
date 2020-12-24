#include   <stdio.h>
#include  <stdlib.h>
#include    <time.h>

/***********************************************
选择排序（Selection sort）是一种简单直观的排序算法。
它的工作原理是：第一次从待排序的数据元素中选出最小（或最大）
的一个元素，存放在序列的起始位置，然后再从剩余的未排序元素中寻找到最小（大）元素，
然后放到已排序的序列的末尾。以此类推，直到全部待排序的数据元素的个数为零。
***********************************************/
void SelectSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++,printf("\n=====\n"))
        for (int j = i + 1; j < n; j++){
            printf("%d,%d ",i,j);
            if (arr[i] > arr[j])
            {
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }}
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

    SelectSort(arr,LENGTH);

    /*排序后*/
    for(i=0;i<LENGTH;i++)
        printf("%d ",arr[i]);printf("\n");
    return 0;
}
