//
//  main.c
//  内存管理
//
//  Created by 何建华 on 2023/2/19.
//

/*
 1.内存五大区域：
 栈：存储局部变量
 堆：只有这个内存，允许程序员手动申请（申请指定个字节）
 BSS段：未初始化的全局变量、静态变量
 数据段：已初始化的全局变量、静态变动和常量数据。
 代码段：存储代码
 
 2.如何向堆区申请字节空间来使用
 1）我们在堆中申请的字节空间，如果我们不主动释放，直到程序结
 束才会释放。
 2）步骤：申请，使用，释放。
 3）如何申请：
 a.有三个函数：malloc() calloc() realloc()
 都在stdlib.h中
 b.malloc(),作用是向堆申请指定字节的连续的空间来使用，只有一个参数
 unsigned long(size_t)
 c.返回值是没有类型的指针：void*,指向的是第一个字节的地址
 d.可以用指定的类型的指针来接收，根据需要就行，从char int
 doble一类的
 
 3.从堆区中申请地址，是从低地址向高地址分配。
 每次申请两个指指针，并不一定连续。每次申请的地址都从0开始。
 在堆区申请的字节，里面是有垃圾值的，所以初始化赋值很重要。
 4.申请的时候，有可能申请失败。
 所以最好做个判断。
 5.申请空间用完后，一定要释放。
 
 6.calloc函数
 1）向堆申请指定字节数的空间
 参数一：申请多少个单位
 参数二：每个单位所占字节
 
 比malloc有如下优势：
 a.不用计算分配给多少个单位
 b.自动清零，初始化
 
 7.realloc函数：
 作用是扩容。
 我们有了指针，几乎可以操作内容上的每一个字节。
 可以循环给所有内在空间赋值，试一下，肯定死机。
 
 申请字节空间不够用时，用realloc函数来扩容，如果能连续就连续，
 不能连续就新开一个空间。
 
 */

#include <stdio.h>
#include <stdlib.h>

void test(void);
void test1(void);
void test2(void);
void test3(void);

int main(int argc, const char * argv[]) {
    
    //test();
    
    //test1();
    
    //test2();
    test3();
    return 0;
}

void test(void){
    int* p1 = malloc(24);
    *p1 = 100;
    *(p1+1) = 200;
    *(p1+2) = 300;
    *(p1+3) = 400;
    *(p1+4) = 500;
    *(p1+5) = 600;
    for(int i=0;i<6;i++){
        printf("%d\n",p1[i]);
    }
    
    free(p1);
}

void test1(void){
    //下面两个指针指向的地址并不一定相邻
    int* p1 = malloc(4);
    if(p1 != NULL){
        //说明申请成功。可以操作内存空间
    }
    int* p2 = malloc(4);
    if(p2){
        //说明申请成功，可以操作内容空间
    }
    printf("%p\n",p1);
    printf("%p\n",p2);
    
    free(p1);
    free(p2);
    
    //程序闪退，原因之一就可能是内在没释放，尤其闪退位置不同的。
    
}

void test2(void){
    //申请3个int类型的字节空间
    int* p1 = calloc(3, sizeof(int));
    if(p1){
        //说明申请成功
        for(int i=0;i<3;i++){
            p1[i] = 10 + i;
        }
        for(int i=0;i<3;i++){
            printf("%d\n",p1[i]);
        }
    }
}

void test3(void){
    int* p1 = calloc(4, sizeof(int));
    if(p1){
        //说明申请成功
        for(int i=0;i<3;i++){
            p1[i] = 10 + i;
        }
        for(int i=0;i<3;i++){
            printf("%d\n",p1[i]);
        }
        printf("-----\n");
        //扩容，已把p1原来的三个数拷过来
        int* p2 = realloc(p1, 4);//从3个扩成4个
        *(p2+3) = 100;
        for(int i=0;i<4;i++){
            printf("p2 = %d\n",p1[i]);
        }
    }
    
}
