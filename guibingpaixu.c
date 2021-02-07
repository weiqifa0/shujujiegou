#include <stdio.h>
#include <stdlib.h>

/*
 * r[] : 需要排序的数组
 * s[] : 排序后保存数据的数组
 * left: 排序的起始位置
 * mid : 排序的中间位置
 * right:排序的最右边位置
 */
int merge(int r[],int s[],int left,int mid,int right)
{
    int i,j,k;
    i=left;
    j=mid+1;
    k=left;
    for(;i <= mid && j<=right;){
        if(r[i]<=r[j])
            s[k] = r[i++];
        else
            s[k] = r[j++];
        k++;
    }
    for(;i<=mid;)
        s[k++]=r[i++];
    for(;j<=right;)
        s[k++]=r[j++];
    return 0;
}

/*
 * r[] : 需要排序的数组
 * s[] : 排序后保存数据的数组
 * left: 排序的起始位置
 * right:排序的最右边位置
 */
int merge_sort(int r[],int s[],int left,int right)
{
    int mid;
    int t[20];
    if(left==right)
        s[left]=r[right];
    else
    {
        mid=(left+right)/2;
        merge_sort(r,t,left,mid);/*sort left~mid*/
        merge_sort(r,t,mid+1,right);/*sort mid+1~right*/
        merge(t,s,left,mid,right);/*merge sort left,mid,right*/
    }
    return 0;
}

int main()
{
    int a[8] = {6,5,3,1,8,7,2,4};
    int i;

    merge_sort(a,a,0,7);

    for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
        printf("%d ",a[i]);

    printf("\n");
    return 0;
}
