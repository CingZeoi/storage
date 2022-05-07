/*
时间：2017年7月3日星期一
9点21分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
class a
{
public:
int Get(void);
};
class b: public a
{
public:
int Get(void);
};
int main(void)
{
b b1;
printf("%d\n%d\n",b1.Get(),b1.a::Get());
return 0;
}
int a::Get(void)
{
return 5;
}
int b::Get(void)
{
return 10;
}