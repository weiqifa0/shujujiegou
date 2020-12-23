
#include "stdio.h"

int main()
{
    int i,j;
    int arr[10] = {12,12,1,78,500,5,7,699,752,233};
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        printf("%d ",arr[i]);printf("\n");
    for(i=0;i<10;i++)
    {
        for(j=0;j<10-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                arr[j] ^= arr[j+1];
                arr[j+1] ^= arr[j];
                arr[j] ^= arr[j+1];
            }
        }
    }
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        printf("%d ",arr[i]);printf("\n");
    return 0;
}
