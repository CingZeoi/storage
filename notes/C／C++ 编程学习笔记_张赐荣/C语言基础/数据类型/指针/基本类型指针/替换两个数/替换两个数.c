/*
ʱ�䣺2017��5��9�����ڶ�
20��42��
��������Visual C++ 6.0
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