/*  1370
给你一个字符串 s ，请你根据下面的算法重新构造字符串：

1、从 s 中选出 最小 的字符，将它 接在 结果字符串的后面。
2、从 s 剩余字符中选出 最小 的字符，且该字符比上一个添加的字符大，将它 接在 结果字符串后面。
3、重复步骤 2 ，直到你没法从 s 中选择字符。
4、从 s 中选出 最大 的字符，将它 接在 结果字符串的后面。
5、从 s 剩余字符中选出 最大 的字符，且该字符比上一个添加的字符小，将它 接在 结果字符串后面。
6、重复步骤 5 ，直到你没法从 s 中选择字符。
7、重复步骤 1 到 6 ，直到 s 中所有字符都已经被选过。
在任何一步中，如果最小或者最大字符不止一个 ，你可以选择其中任意一个，并将其添加到结果字符串。

请你返回将 s 中字符重新排序后的 结果字符串 。*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * sortString(char * s){
    int len = strlen(s);
    int i = 0, num = 0, j = 0;//num是循环次数
    int k = 0;

    int flag3 = 0; //  while循环(1，2步骤)，结束标识符

    int flag = 0;  //  标识：第一次取英文字符(1，2步骤)
    int flag2 = 0; //  标识：通过该标识判断是否有过替换最小字符 
    int flag4 = 0; //  标识符(1，2步骤)，通过该标识符，执行数组移位操作

    int flag5 = 0; //  标识：第一次取英文字符(4，5步骤)
    int flag6 = 0; // 标识：通过该标识判断是否有过替换最大字符
    int flag8 = 0; //  标识符（4，5步骤），通过该标识符，执行数组移位操作


    int flag15 = 0;//  首次给c一个值当作最小值(4,5步骤)
    int flag16 = 0; //  首次给c一个值当作最大值(4,5步骤)


    char c, temp;   //  temp (1,2,4,5步骤)的临时变量

    while(len > num) {
        while(flag3 == 0) {
            printf("CCC\n");
            for (i = 0; i < len - num; i++) {
                if (flag == 0) {
                    if (flag15 == 0) {
                        c = s[0];
                        flag15 = 1;
                    }
                    printf("c5:%c\n", c);
                    printf("i:%d\n", i);
                    if(s[i] <= c) {
                        c = s[i];
                        k = i;
                        printf("EEE\n");
                    }
                    printf("c:%c\n", c);
                    if (flag15 == 1) {
                        if (i == (len - num -1)) {
                            flag15 = 0;
                            printf("DDD\n");
                            i = -1;
                            flag4 = 1;
                        }
                    }
                }
                if (flag == 1) {
                    if ((s[i] > temp) && (flag2 == 0)) {
                        flag2 = 1;
                        c = s[i];
                        k = i;
                        printf("i:%d\n", i);
                        printf("c1:%c\n", c);
                        printf("*************\n");
                     } 

                    if (i == (len - num - 1)) {
                        if (flag2 == 0) {
                            printf("flag7flag7\n");
                            flag5 = 0;
                            flag3 = 1;
                            i = -1;
                            break;
                        }
                    }
                    if ((flag2 == 1) && (s[i] > temp)) {
                        if (s[i] <= c) {
                            printf("c2:%c\n", c);
                            printf("i:%d\n", i);
                            c = s[i];
                            k = i;
                            printf("c3:%c\n", c);
                        }
                    }

                    if (flag2 == 1) {
                        if (i == (len - num - 1)) {
                            flag4 = 1;
                            i = -1;
                            printf("iiiii:%d\n", i);
                         }
                     }
                }
                if (flag4 == 1) {
                    printf("AAAflag4\n");
                    for(j = k; j < len - 1; j++) {
                        s[j] = s[j+1];
                    }
                    flag = 1;
                    flag4 = 0;
                    flag2 = 0;
                    temp = c;
                    s[len - 1] = c;
                    num++;
                    printf("i:%d\n", i);
                    printf("temp:%c\n", temp);
                    printf("k0:%d\n", k);
                    printf("num:%d\n", num);
                    printf("s:%s\n", s);
                    printf("len:%d\n", len);
                    if (len == num) {
                        flag3 = 2;
                        break;
                    }
                }
            }
        }
	    
        while(flag3 == 1) {
            for (i = 0; i < len - num; i++) {
                if (flag5 == 0) {
                    if (flag16 == 0) {
                        c = s[0];
                        flag16 = 1;
                    }
                    if(s[i] >= c) {
                        c = s[i];
                        k = i;
                    }
                    if ((flag16 == 1) && (i == (len - num -1))) {
                        flag16 = 0;
                        i = -1;
                        flag8 = 1;
                    }
                }
                if (flag5 == 1) {
                    if ((s[i] < temp) && (flag6 == 0)) {
                        flag6 = 1;
                        c = s[i];
                        k = i;
                     }
                     if (i == len - num - 1) {
                        if (flag6 == 0) {
                            flag = 0;
                            flag3 = 0;
                            i = -1;
                            break;
                            c = temp;
                            flag6 = 1; 
                        }
                     }
                    if ((s[i] < temp) && (flag6 == 1)) {
                         if(s[i] >= c) {
                            c = s[i];
                            k = i;
                        }
                     }
                     if (flag6 == 1) {
                        if (i == (len - num - 1)) {
                            flag8 = 1;
                            i = -1;
                        }
                     }
                }
                if (flag8 == 1) {
                    for(j = k; j < len - 1; j++) {
                        s[j] = s[j+1];
                    }
                    flag8 = 0;
                    flag6 = 0;
                    flag5 = 1;
                    temp = c;
                    s[len - 1] = c;
                    num++;
                    if (len == num) {
                        flag3 = 2;
                        break;
                    }
                }
            }
        }
    }
    return s;
}

int main() {
    //char s[] = "aaaabbbbcccc";
    char s[] = "rat";
    //char s[] = "spo";
    //char s[] = "ggggggg";
    //char s[] = "leetcode";
    char *dst;
    //char s[] = "spo";
    dst = sortString(s);
    printf("dst:%s\n", dst);
    return 0;

}