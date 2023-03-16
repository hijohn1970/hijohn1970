//
//  itest.c
//  static和extern
//
//  Created by 何建华 on 2023/2/19.
//

#include "itest.h"

int age = 10;
static int bum = 100;

//static void study(void){
//    printf("好好学习哦。\n");
//}

extern void study(void){
    printf("好好学习哦。\n");
}
