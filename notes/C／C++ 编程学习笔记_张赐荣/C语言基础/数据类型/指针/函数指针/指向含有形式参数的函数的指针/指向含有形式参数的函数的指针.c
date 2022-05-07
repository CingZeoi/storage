/*
时间：2017年5月29日星期一
23点0分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
int max(int,int);
int plus(int,int);
int main(void)
{
int (*p)(int,int) = max;
printf("%d\n",p(3,2));
p = plus;
printf("%d\n",p(100,200));
return 0;
}
int max(int a,int b)
{
int o = 0;
if(a == b)
return 0;
if(a < b)
o = a;
a = b;
b = o;
return a;
}
int plus(int a,int b)
{
return a+b;
}
/*
严格的说，定义函数指针变量的格式是：
函数返回值类型 (*函数指针变量名)(函数形参列表);
在定义函数指针变量时，就决定了该函数指针变量能指向怎样的函数，该函数指针变量只能指向与定义时相同函数圆形的函数；
在本例中，函数max与函数plus的圆形一样，并且函数指针变量p所能指向的函数的圆形与max和plus也一样，所以函数指针变量p可以随意指向这两个函数，并能正常调用。
*/