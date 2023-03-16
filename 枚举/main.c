//
//  main.c
//  枚举
//
//  Created by 何建华 on 2023/2/16.
//

/*
 枚举的作用是，限定变量。
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    enum Direction{
        East,
        South,
        West,
        North,
    };
    
    //使用
    enum Direction dir;
    dir = South;
    printf("你选了的方向是：%u\n",dir);
    
    typedef char* String;
    String name = "Jack";
    printf("typedef：%s\n",name);
    return 0;
}
