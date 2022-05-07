/*
时间：2017年7月3日星期一
6点52分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
int a(int,int);
int a(int,int,int);
//void a(int,int);
int a(int);
int main(void)
{
//a(1,1);
a(1,2,3);
a(5);
return 0;
}
int a(int a,int b)
{
printf("%d\n",a+b);
return 0;
}
int a(int a,int b,int c)
{
printf("%d\n",a+b+c);
return 0;
}
/*
void a(int a,int b)
{
printf("%d\n",a+b);
}
*/
int a(int a)
{
printf("%d\n",a);
return 0;
}
/*
c++支持函数同名，它会通过函数的参数列表的不同来判断调用的是哪个函数，仅是返回值不同是不行的；
int a(int,int);
int a(int);
形参不同，不冲突，可共存；
int a(int);
char a(int);
仅返回值不同，无法分辨，不可共存；
*/