//
//  main.c
//  多线程
//
//  Created by 何建华 on 2023/2/20.
//

/*
 编译：
 cc main.c -lpthread -o main
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//建立一个结构体
typedef struct {
    int first;
    int last;
    int result;
} My_ARGS;

int arr[5000];
//用两个全局变量来接两个线程的和

int s1 = 0;
int s2 = 0;

void* myfuncSum1(void* args){
    //强制转换参数
    int s = 0;
    My_ARGS* myargs = (My_ARGS*) args;
    int first = myargs->first;
    int last = myargs->last;
    for(int i=first;i<last;i++){
        //判断线程，并累加
        s = s + arr[i];
    }
    myargs->result = s;
    
    return NULL;//需要返回任意指针
}


void* myfunc(void* args){
    char* name = (char*)args;
    for(int i=0;i<50;i++){
        printf("%s:%d\n",name,i);
    }
    
    return NULL;//需要返回任意指针
}

void test(void);
void test1(void);

int main(int argc, const char * argv[]) {
    
    //test();
    test1();
    
    return 0;
}

void test(void)
{
    //定义两个新线程变量
    pthread_t th1;
    pthread_t th2;
    //创建线程运行myfunc函数
    pthread_create(&th1, NULL, myfunc, "th1");
    pthread_create(&th2, NULL, myfunc, "th2");
    //wait
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
}

void test1(void){
    //给数组赋值
    for(int i=0;i<5000;i++){
        arr[i] = rand() % 50;//rand()是伪随机数
    }
    
//    for(int i=0;i<5000;i++){
//        printf("arr[%d] = %d\n",i,arr[i]);
//    }
    
    //定义两个新线程变量
    pthread_t th1;
    pthread_t th2;
    //实例化两个结构体
    My_ARGS myargs1 = {0,2500,0};
    My_ARGS myargs2 = {2500,5000,0};
    //创建线程运行myfunc函数
    pthread_create(&th1, NULL, myfuncSum1, &myargs1);
    pthread_create(&th2, NULL, myfuncSum1, &myargs2);
    //wait
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    
    s1= myargs1.result;
    s2= myargs2.result;
    
    printf("s1=%d\n",s1);
    printf("s2=%d\n",s2);;
    printf("s1+s2=%d\n",s1+s2);;
    
}
