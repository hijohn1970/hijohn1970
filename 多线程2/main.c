//
//  main.c
//  多线程2
//
//  Created by 何建华 on 2023/2/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//建立一个结构体
typedef struct {
    int first;
    int last;
} My_ARGS;

int arr[5000];
//用两个全局变量来接两个线程的和

int s = 0;

void* myfunc(void* args){
    My_ARGS* myargs = (My_ARGS*) args;
    int first = myargs->first;
    int last = myargs->last;
    for(int i=first;i<last;i++){
        //判断线程，并累加
        s = s + arr[i];
    }
    return NULL;//需要返回任意指针
}


void test(void);

int main(int argc, const char * argv[]) {
    
    test();
    
    return 0;
}

void test(void){
    //给数组赋值
    for(int i=0;i<5000;i++){
        arr[i] = rand() % 50;//rand()是伪随机数
    }
    
    //定义两个新线程变量
    pthread_t th1;
    pthread_t th2;
    //实例化两个结构体
    My_ARGS myargs1 = {0,2500};
    My_ARGS myargs2 = {2500,5000};
    //创建线程运行myfunc函数
    pthread_create(&th1, NULL, myfunc, &myargs1);
    pthread_create(&th2, NULL, myfunc, &myargs2);
    //wait
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    
    printf("s=%d\n",s);
    
}

