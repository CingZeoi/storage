/*
时间：2017年5月9日星期二
20点42分
编译器：Visual C++ 6.0
*/
#include <stdio.h>
void tihuan(int *,int *);
int main(void)
{
int a=100,b=200;
tihuan(&a,&b);
printf("%d\n%d\n",a,b);
return 0;
}
void tihuan(int *a,int *b)
{
int o;
o=*a;
*a=*b;
*b=o;
}