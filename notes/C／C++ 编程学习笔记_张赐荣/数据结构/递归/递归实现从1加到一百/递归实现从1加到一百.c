/*
时间：2017年6月27日星期二
9点3分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
int plus(int);
int main(void)
{
int n = 0;
n = plus(n);
printf("%d\n",n);
return 0;
}
int plus(int n)
{
return n != 100 ? n+plus(n+1) : n;
}