#include<stdio.h>
#include<stdlib.h>
int comp(const void *a, const void *b){
    int intA = *(const int*)a;
    int intB = *(const int*)b;
    return intA - intB;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), comp);
    int **result = (int **)malloc((numsSize/3)*sizeof(int*));
    *returnSize = numsSize/3;
    *returnColumnSizes = (int *)malloc((numsSize/3)*sizeof(int));
    int count = 0;
    int flag = 0;
    for(int i = 0; i < (numsSize/3); i++){
        (*returnColumnSizes)[i] = 3;
        result[i] = (int *)malloc(3*sizeof(int));
        for(int j = 0; j < 3; j++){
            result[i][j] = nums[count++];
        }
        if(result[i][2] - result[i][0] > k){
            flag = 1;
            break;
        }
    }
    if(flag){
        free(result);
        *returnSize = 0;
        free(*returnColumnSizes);
        *returnColumnSizes = (int * )malloc(sizeof(int));
        (*returnColumnSizes)[0] = 0;
        return result;
    }
    return result;
}