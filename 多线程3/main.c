//
//  main.c
//  多线程3
//
//  Created by 何建华 on 2023/2/20.
//

//race condition和锁的应用

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int s = 0;

//定义一个锁
pthread_mutex_t lock;

void* myfunc(void* args){
    //线程各自走了一遍
    //锁影响效率，但能保证安全
    pthread_mutex_lock(&lock);//加外面更快
    for(int i=0;i<10000;i++){
        //pthread_mutex_lock(&lock);//加锁,这种方式非常慢
        s++;
        //pthread_mutex_unlock(&lock);//解锁
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, const char * argv[]) {
    
    //申明两个线程变量
    pthread_t th1;
    pthread_t th2;
    //初始化锁
    pthread_mutex_init(&lock, NULL);
    
    pthread_create(&th1, NULL, myfunc, NULL);
    pthread_create(&th2, NULL, myfunc, NULL);
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    
    //不等于2000000是错的，所以有时候必须锁定
    //出现了racecondtion
    printf("s = %d\n",s);
    
    return 0;
}
