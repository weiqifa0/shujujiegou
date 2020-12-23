#include "stdio.h"
#include "string.h"

#define BUCKET_NUM  5   /*桶排序中桶的个数*/
#define BUCKET_STEP 200 /*假设需要排序的最大数值是 1000/5，10个桶，每个桶的范围是 1000/10 =  100*/

int bucket_sort(int *arr,int n)
{
    int i,j,k,m;
    int buck[BUCKET_NUM][n];
    memset(buck,0,sizeof(buck));

    /*数据放到对应的桶里面*/
    for(i=0;i<n;i++)
    {
        if(arr[i]<=BUCKET_STEP){  
            for(j=0;j<n;j++){
                if(buck[0][j] == 0){
                    buck[0][j] = arr[i];
                    break;
                }
            }
        }else if(arr[i] > BUCKET_STEP && arr[i]   <= 2*BUCKET_STEP){
            for(j=0;j<n;j++){
                if(buck[1][j] == 0){
                    buck[1][j] = arr[i];
                    break;
                }
            }
        }else if(arr[i] > 2*BUCKET_STEP && arr[i] <= 3*BUCKET_STEP){
            for(j=0;j<n;j++){
                if(buck[2][j] == 0){
                    buck[2][j] = arr[i];
                    break;
                }
            }
        }else if(arr[i] > 3*BUCKET_STEP && arr[i] <= 4*BUCKET_STEP){
            for(j=0;j<n;j++){
                if(buck[3][j] == 0){
                    buck[3][j] = arr[i];
                    break;
                }
            }
        }else if(arr[i] > 4*BUCKET_STEP && arr[i] <= 5*BUCKET_STEP){
            for(j=0;j<n;j++){
                if(buck[4][j] == 0){
                    buck[4][j] = arr[i];
                    break;
                }
            }
        }else{printf("error arr[%d]=%d \n",i,arr[i]);}
    }

    /*调试打印*/
    for(i=0;i<BUCKET_NUM;i++)
        for(j=0;j<n;j++)
         if(buck[i][j]!= 0) printf("%d ",buck[i][j]);printf("\n");

    /*对桶里面的数据进行排序*/
    for(i=0;i<BUCKET_NUM;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n-1-j;k++){ 
                if( buck[i][k] > buck[i][k+1]) {/*交换*/
                    buck[i][k] ^= buck[i][k+1];
                    buck[i][k+1] ^= buck[i][k];
                    buck[i][k] ^= buck[i][k+1];
                }
            }
        }
    }
    /*打印*/
    for(i=0;i<BUCKET_NUM;i++)
        for(j=0;j<n;j++)
         if(buck[i][j]!= 0) printf("%d ",buck[i][j]);
    printf("\n");
}

int main()
{
    int i;
    int arr[10] = {12,12,1,78,500,5,7,699,752,233};
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        printf("%d ",arr[i]);printf("\n");
    bucket_sort(arr,10);
    return 0;
}
