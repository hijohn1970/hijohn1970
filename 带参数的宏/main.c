//
//  main.c
//  带参数的宏
//
//  Created by 何建华 on 2023/2/17.
//

/*
 带参数的宏：
 1.在使用宏时，可以带参数
 在使用宏值时，直接使用这个参数。
 #define N(a) 10+20+30+a
 
 */

#define N(a,b) a + b
#define Max(a,b) a > b ? a : b

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int b = N(8,20);
    
    printf("b = %d\n",b);
    
    int a = 5;
    int c = 8;
    int max = Max(a, c);
    printf("max = %d\n",max);
    return 0;
}
