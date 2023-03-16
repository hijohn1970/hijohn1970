//
//  main.c
//  结构体
//
//  Created by 何建华 on 2023/2/14.
//

/*
 一、结构体初始化：
 1.先申明结构体变量，再用.给成员变量赋值
 2.在申明变量时，就给成员变量赋值。
 3.在声明结构体时，顺序初始化部份成员变量，其他值是清零的，百不是指向垃圾值。
 4.对指定成员进行初始化
 
 结构体的默认值。
 没初始化赋值，成员变量会指向垃圾值。
 
 二、结构体数组
 
 三、结构体与函数
 1.结构体作为函数的参数
 2.结构体作为函数的返回值
 
 */

#include <stdio.h>

//日期结构
struct Birthday{
    int year;
    int month;
    int day;
};

//全局给构体
struct Student{
    char* name;
    int age;
    struct Birthday birth;
};



//结构体数组
void structArr(void);
//结构体指针
void structPtr(void);
//初始化
void structInit(void);
//结构体嵌套
void structQt(void);
//判断学生年纪大于18的,把结构体传给函数
void judgeAge(struct Student stu);
//函数返回结构体
struct Student getStruct(void);

int main(int argc, const char * argv[]) {
    //赋值就是初始化
    //structInit();
    //二、结构体数组
    //structArr();
    
    //数组指针
    //structPtr();
    
    //数组嵌套
    //structQt();
    
    //把结构体专给函数
    struct Student stu;
    stu.name = "Scarllet";
    stu.age = 15;
    stu.birth.year = 2002;
    stu.birth.month = 8;
    stu.birth.day = 10;
    judgeAge(stu);
    
    //返回一个结构体
    struct Student s1;
    s1 = getStruct();
    printf("这是返回的结构体：%s\n",s1.name);
    
    return 0;
}

//二、结构体数组
void structArr(void){
    
    struct Student students[] = {
        {"西子",18},
        {"王柯",21},
        {"君君",22},
        {"涵涵",33},
        {"格格",25},
        {"老师",25},
    };
    //遍历
    //int len = sizeof(students)/sizeof(students[0]);
    int len = sizeof(students)/sizeof(struct Student);
    printf("%d\n",len);
    for(int i=0;i<len;i++)
    {
        printf("姓名：%s,年龄：%d\n",students[i].name,students[i].age);
    }
}

//结构体指针
void structPtr(void){
    struct Student xiaoming = {"小明",88};
    //申明一个指针，指向xiaoming变量
    //指针就可以访问这个变量的各个元素
    struct Student* p1;
    p1 = &xiaoming;
    //访问指针指向的元素，要用 ->号
    printf("%s\n",p1->name);
    //也可以修改
    (*p1).name = "Jack";
    p1->age = 22;
    printf("%s\n",p1->name);
    printf("%d\n",p1->age);
}

void structInit(void){
    //1.申明给构体变量，再赋值
    struct Student stu;
    stu.name = "John";
    stu.age = 19;
    
    //2.申明时就赋值
    struct Student xiaofang = {"小芳",20};
    
    //3.只赋值一部份，其余值是默认值
    struct Student xiaogui = {"小鬼"};
    //4.对指定成员进行初始化
    struct Student jim = {.name="jim",.age = 19};
    
    printf("姓名：%s,年龄：%d\n",stu.name,stu.age);
}

//结构体嵌套
void structQt(void){
    
    struct Student stu[] = {
        {"Dasy",19,{2001,8,31}},
        {"Rose",21,{1999,3,30}},
        {"桃桃",18,{2003,1,3}},
        {"丽丽",17,{2002,2,13}},
    };
    
    //修改
    stu[0].birth.year = 1988;
    
    printf("%s--%d--%d--%d--%d\n",stu[0].name,stu[0].age,stu[0].birth.year,stu[0].birth.month,stu[0].birth.day);
    
    //遍历
    int len = sizeof(stu)/sizeof(struct Student);
    for(int i = 0;i<len;i++){
        printf("%s--%d--%d--%d--%d\n",stu[i].name,stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day);
    }
}

//判断学生年纪大于18的
void judgeAge(struct Student stu){
    if(stu.age > 18){
        printf("%s你好，你已经%d，大于18岁，成年了哦。\n",stu.name,stu.age);
    }else{
        printf("哦，未成年哦。 \n");
    }
}

//函数返回结构体
struct Student getStruct(void){
    struct Student stu = {"Tom",19};
    return stu;
}
