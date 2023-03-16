//
//  main.c
//  多线程false sharing1
//
//  Created by 何建华 on 2023/2/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 50000000

typedef struct {
    int first;
    int last;
    int result;
} MY_ARGS;

int* arr;
int results[2];

void* myfunc(void* args){
    int i = 0;
    MY_ARGS* myargs = (MY_ARGS*)args;
    int first = myargs->first;
    int last = myargs->last;
    int s = 0;
    for(i=first;i<last;i++){
        s = s + arr[i];
    }
    myargs->result = s;
    return NULL;
}

int main(int argc, const char * argv[]) {
    
    arr = malloc(sizeof(int)*MAX_SIZE);
    for(int i=0;i<MAX_SIZE;i++){
        arr[i] = rand() % 5;
    }
    
    results[0] = 0;
    results[1] = 0;
    
    pthread_t th1;
    pthread_t th2;
    
    int mid = MAX_SIZE/2;
    MY_ARGS args1 = {0,mid,0};
    MY_ARGS args2 = {mid,MAX_SIZE,0};
    
    pthread_create(&th1, NULL, myfunc, &args1);
    pthread_create(&th2, NULL, myfunc, &args2);
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    
    int s1 = args1.result;
    int s2 = args2.result;
    
    printf("s1=%d\n",s1);
    printf("s2=%d\n",s2);
    printf("s1+s2=%d\n",s1+s2);
    
    return 0;
}
