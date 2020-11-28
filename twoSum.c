#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int j = 0, k = 0;
    int i = 0;
    int *dst;
    dst = (int *)malloc(sizeof(int)*2);
    dst[0] = 0;
    dst[1] = 0;
    //static int dst[4] = {};
    //len = strlen(nums);
    int mid = 0;
    int num = 0;
    //for(i =0; i < 4; i++) {
    //    returnSize[i] = (int *)malloc(4);
    //    }    
    for(j=0; j<numsSize; j++) {
        //if(nums[j] != target) {
        mid = target - nums[j];
        printf("mid:%d\n", mid);
        printf("j:%d\n", j);
        for (k=j+1; k < numsSize; k++) {
            //printf("nums[k]:%d\n", nums[k]);
            if (nums[k] == mid) {
                printf("BBBB\n");
                dst[num] = j;
                num++;
                dst[num] = k;
                num++;
                printf("j:%d, k:%d\n", j, k);
                printf("num:%d\n", num);
            }
        }
    }
    printf("BBB\n");
    *returnSize = num;
    printf("CCCC\n");
    for (i=0; i<num; i++) {
        //returnSize[i] = dst[i];
        printf("returnSize:%d\n", dst[i]);
    }
    return dst;
}

int main() {
    //int nums[] = {2, 7, 11, 15};
    //int nums[] = {-1,-2,-3,-4,-5};
    int nums[] = {0,4,3,0};
    int *returnSize;
    returnSize = (int *)malloc(sizeof(int)*1);
    int *dst;
    int numsSize = 4;
    int target = 0;
    dst = twoSum(nums, numsSize, target, returnSize);
    //printf("dst:%d\n", dst);
    return 0;
}