//
//  main.c
//  宏定义
//
//  Created by 何建华 on 2023/2/17.
//

/*
 1.宏定义
 1）它是一个预处理指令，所以它在编译之前执行。
 2）作用：可以为一段c代码建立一段标识，如果要使用这段代码，
 使用这个标识就可以。
 3）语法
 #define 宏名 宏值
 #define N 10
 4）如何使用宏
 在c代码中直接使用宏名字
 int a = N + 1;
 5）宏的原理
 在编译时见到c代码中的宏变量，就全变成宏变量的值，这叫宏替换。
 
 2.在使用宏时的注意事项
 1）宏值可以是任意的东西，比如表达式，#define N 10+10+30
 在定义时并不会做语法检查,只有在完成宏替换后才会检查
 2)使用宏变量，必须保证先有这个变量
 3）无法通过赋值符号改变宏值
 4）宏的作用域
 从定义宏的地方起，以后所有地方都能。哪怕在函数里
 这行代码后面都能访问。
 5） #undef 宏名   解除宏定义
 6）字符串中出现宏名不会替换
 7）宏变量可以使用其他宏变量，叫宏的层层替换
 
 
 */
#include <stdio.h>

#define N 10 //表示N=10，编译时见到N就全变成10
#define N2 10+10+30
#define K sososos
#define BB 10;
#define FOR for(int i=0;i<5;i++)
#define STRING char*

int main(int argc, const char * argv[]) {
#define W 100 //这个就是局部

    int a = N + 1;

#undef N
    //int b = N + 1;
    printf("N=%d\n",a);
    
    int c = BB //分号在宏值里
    STRING nn = "我小宝宝";
    FOR{
        
        printf("哼...%s",nn);
    }
    
    return 0;
}
