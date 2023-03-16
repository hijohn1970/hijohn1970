//
//  main.c
//  static和extern
//
//  Created by 何建华 on 2023/2/19.
//

/*
 1.static和extern是用来修饰变量和函数的
 1）修饰局部变量的效果
 （1）static修饰局部变量
  a.局部变被static修饰，就叫表态变量，
  b.静态变量不再申明的栈区，而是在常量区
  c.函数执行完毕后，这个变量不会被回收，所以值还在。
  d.函数执行多少次，变量只会被申明一次，函数结束后，并不会释放。
    extern不能修饰局部变量
 2）修饰全局变量的效果
    写函数的步骤：先申明，后实现
    写全局量，也应该分两步：先申明，后初始化（赋值）
    int num;
    num = 0;
    我们分文件开发时，全局变量申明要写的h文件中，变量初始化
    放在c文件中。
    如果全局变量申明有模块中，就必须使用static或extern修饰
    使用extern修饰，这个全局变量就可以跨模块使用，如果使用
    static修饰，就只能在本模块中使用，虽然不报错，但拿不到值。
 
 3）修饰函数的效果
 使用extern修饰，这个函数就可以跨模块使用，如果使用
 static修饰，就只能在本模块中使用。

 
 */

#include <stdio.h>
#include "itest.h"

int bb;//如果后面不赋值，系统会自动初始化为0

void test(void){
    //int num = 0;
    static int num = 0;//它要程序结束才会释放归零
    num++;
    printf("%d\n",num);
    
}

int main(int argc, const char * argv[]) {
    
//    test();
//    test();
//    test();
    
//    printf("age = %d\n",age);
//    printf("bum = %d\n",bum);
    
    study();
    return 0;
}

bb = 10;//这样上面也能使用到
