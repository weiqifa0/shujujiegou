#include "stdio.h"

int main()
{
    int i,j;
    int arr[10] = {12,12,1,78,500,5,7,699,752,233};
    /*定义跟数字一样大小的数组*/
    int arrout[752] ={0};
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        arrout[arr[i]]++;
    }
    
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        printf("%d ",arr[i]);printf("\n");
    }
    return 0;
}
