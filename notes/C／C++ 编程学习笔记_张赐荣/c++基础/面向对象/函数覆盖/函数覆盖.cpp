/*
ʱ�䣺2017��7��3������һ
9��21��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
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