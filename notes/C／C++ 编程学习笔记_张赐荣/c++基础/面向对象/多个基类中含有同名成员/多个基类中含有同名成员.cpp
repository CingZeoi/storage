/*
时间：2017年7月3日星期一
7点58分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
class a
{
public:
int aa(int,int);
};
class b
{
public:
int aa(int,int);
};
class c: public a,public b
{
};
int main(void)
{
c c1;
printf("%d\n%d\n",c1.a::aa(5,10),c1.b::aa(5,20));
return 0;
}
int a::aa(int a,int b)
{
return a > b ? a : b;
}
int b::aa(int a,int b)
{
	return a+b;
}
/*
如果从多个类中继承的成员同名，访问成员时，应在成员名前面说明是哪个类的成员。
*/