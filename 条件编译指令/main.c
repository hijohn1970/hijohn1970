//
//  main.c
//  条件编译指令
//
//  Created by 何建华 on 2023/2/19.
//

/*
 
 1.条件编译指令：
 1）它是一个预处理指令，所以在预编译阶段执行
 2）作用
 默认情况下，所有的c代码都会被编译成二进制代码，条件编译指令
 的作用是，可以让我们的编译器只编译符合条件的代码。
 
 2.第一种用法：
 
 #if 条件
    c代码一
 #endif
 如果条件成立，则编译c代码一，如果不成立，则不编译。
 条件只能是宏，不能是变量
 
 3.第二种用法
 #if N>0
     printf("大于零哦\n");
 #elif N>5
     printf("大于5哦\n");
 #else
     printf("你奶奶个腿。\n");
     
 #endif
 
 只编译第一个条件成立的代码
 
 
 */

#include <stdio.h>

#define N 20

int main(int argc, const char * argv[]) {

#if N==100
    
    printf("Hello, World!\n");
    printf("Hello, World!\n");
    printf("Hello, World!\n");
#endif
    
    printf("Hello, World!\n");
    
#if N>200
    printf("大于零哦\n");
#elif N>15
    printf("大于5哦\n");
#else
    printf("你奶奶个腿。\n");
    
#endif

    return 0;
}
