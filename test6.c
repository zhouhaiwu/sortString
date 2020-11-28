/*
代码分成两个部分：
1、变量字符串，把所有不同的英文字符和他们的数量分别放到不同的数组里面；
2、然后循环遍历两个数组，直到他们的数量全部为0；
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * sortString(char * s){
    char s1[500] = "0";
    int s2[500];
    int flag1 = 0;
    int len = strlen(s);
    int i = 0;
    int j = 0;
    int num = 0;
    int num1 = 0;
    char c;
    while(flag1 == 0) {
        for (i=0; i < len; i++) {
            if (s[i] != '0') {
                c = s[i];
                break;
            }
        }
        for (i=0; i < len; i++) {
            if (s[i] != '0') {
                if (s[i] < c) {
                    c = s[i];
                }
            }
        }
        for(i=0; i < len; i++) {
            if (c == s[i]) {
                s[i] = '0';
                num++;
            }
        }
        for(i=0; i < len; i++) {
            if (s[i] == '0') {
                num1++;
            }
        }
        if (num1 < len) {
            s1[j] = c;
            s2[j] = num;
            num = 0;
            num1 = 0;
            j++;
        }
        if (num1 == len) {
            s1[j] = c;
            s2[j] = num;
            flag1 = 1;
        }

    }

    int flag = 0;  // 标识，用来判断该从小到大执行，还是从大到小执行
    int num2 = 0;  // 判断s2数组中的元素为0的个数
    int num6 = 0;  // s数组的下标
    while(flag < 2) {
        while (flag == 0) {
            for(i = 0; i <= j; i++) {
                if (s2[i] == 0) {
                    num2++;
                }
            }
            if ((num2-1) < j) {
                for(i = 0; i <= j; i++) {
                    if (s2[i] == 0) {
                        continue;
                    }
                    else {
                        s[num6] = s1[i];
                        s2[i] = s2[i] - 1;
                        num6++;
                    }
                }
                num2 = 0;
            }
            if ((num2-1) == j) {
                flag = 2;
                break;
            }
            flag = 1;
            //printf("s3:%s\n", s3);
        }
        while (flag == 1) {
            //printf("AAAA\n");
            for(i = 0; i <= j; i++) {
                if (s2[i] == 0) {
                    num2++;
                }
            }
            if (num2 < j) {
                for(i = j; i >= 0; i--) {
                    if (s2[i] == 0) {
                        continue;
                        }
                    else {
                        s[num6] = s1[i];
                        s2[i] = s2[i] - 1;
                        num6++;
                    }
                }
                num2 = 0;
            }
            if ((num2-1) == j) {
                //printf("BBBB\n");
                flag = 2;
                break;
            }
            flag = 0;
        }
    }
    return s;
}

int main() {
    //char s[] = "aaaabbbbcccc";
    //char s[] = "rat";
    //char s[] = "spo";
    //char s[] = "ggggggg";
    //char s[] = "leetcode";
    char s[] = "jkzkydvxewqjfx";
    char *dst;
    //char dst[500] = '0';
    //char s[] = "spo";
    //sortString(s);
    dst = sortString(s);
    printf("dst:%s\n", dst);
    return 0;
}