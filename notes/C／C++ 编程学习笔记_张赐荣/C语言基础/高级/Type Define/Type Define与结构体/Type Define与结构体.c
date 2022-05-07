/*
时间：2017年5月30日星期二
12点32分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
typedef struct student
{
char *name;
int age;
}stu,*s;
int main(void)
{
stu a;
s b;
a.name = "sam";
a.age = 15;
b = &a;
printf("%s\n%d\n",b->name,b->age);
return 0;
}
/*
可以看出，在使用student的别名定义结构体变量与结构体指针变量时，并没有使用struct关键字，所以用typedef修饰的结构体，在定义变量时可以不使用struct关键字；
typedef在给基本数据类型取别名时，类型说明符后面的是类型的别名，不是变量，那么同样，在student结构体的最后是student类型的别名和一个指向student的指针类型的别名，不是结构体变量和结构体指针变量。
*/