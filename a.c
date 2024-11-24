/* ************************************************************************
> File Name:     a.c
> Author:        程序员Carl
> 微信公众号:    代码随想录
> Created Time:  Sat 23 Nov 2024 08:02:06 PM CST
> Description: Permutation  
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DEBUG.h"



static int count = 0;

void swap(int* a,int*b){
    int tmp = *a;
    *a = *b,*b = tmp;
}

void helper(int* nums,int numsSize,int** res,int cur_index,int tail_index,int** returnColSize){

    if(cur_index == tail_index){
        res[count] = malloc(sizeof(int)*numsSize);
        memcpy(res[count],nums,sizeof(int)*numsSize);
        (*returnColSize)[count] = numsSize;
        count++;
        return;
    }
    for(int i=cur_index;i<numsSize;i++){
        swap(nums+cur_index,nums+i);
        helper(nums,numsSize,res,cur_index+1,tail_index,returnColSize);
        swap(nums+cur_index,nums+i);
    }
}



int** Permutation(int* nums,int numsSize,int *returnSize,int** returnColSize){
    
    int** res;
    int res_len = 1;
    LOG_DEBUG("returnSize = %d\n",*returnSize);
    LOG_DEBUG("Permutation numsSize=%d\n",numsSize);
    for(int i = numsSize;i>=1;i--){
        res_len*=i;
    }
    LOG_DEBUG("before res malloc\n");
    res = malloc(sizeof(int*)*res_len);
    LOG_DEBUG("before returnColSize malloc\n");
    (*returnColSize) = malloc(sizeof(int)*res_len);
    LOG_DEBUG("before returnSize\n");
    *returnSize = res_len;
    count = 0;
    LOG_DEBUG("Permutation before helper\n");
    helper(nums,numsSize,res,0,numsSize-1,returnColSize);
    return res;
}


int main(){
   
    int* nums;
    int numsSize;
    int**res,**returnColSize,*returnSize;
    scanf("%d",&numsSize);
    nums = malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        scanf("%d",nums+i);
    }
    returnSize = malloc(sizeof(int));
    returnColSize = malloc(sizeof(int*));
    LOG_DEBUG("normal\n");
    *returnSize = 6;
    LOG_DEBUG("returnSize = 6\n");
    res = Permutation(nums,numsSize,returnSize,returnColSize);
    LOG_DEBUG("normal\n");
    for(int i=0;i<*returnSize;i++){
        printf("[");
        for(int j= 0;j<(*returnColSize)[i];j++){
            if(j == (*returnColSize)[i]-1){
                printf("%d]\n",res[i][j]);
                continue;
            }
            printf("%d ",res[i][j]);
        }
    }
    for(int i = 0;i<*returnSize;i++){
        free(res[i]);
    }
    free(returnSize);
    free(nums);
    free(res);
    free(*returnColSize);

    return 0;
}








