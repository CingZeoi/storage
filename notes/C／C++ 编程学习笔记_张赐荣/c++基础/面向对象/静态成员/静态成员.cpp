/*
时间：2017年7月2日星期日
19点5分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
class a
{
public:
a(void);
~a(void);
	int GetX(void);
void SetX(int);
private:
static int x;
};
class b
{
public:
	static void print();
};
int a::x = 5;
int main(void)
{
a a1,a2;
a1.SetX(100);
printf("%d\n%d\n",a1.GetX(),a2.GetX());
b::print();
return 0;
}
a::a(void)
{
}
a::~a(void)
{
}
int a::GetX(void)
{
	return x;
}
void a::SetX(int a)
{
	x = a;
}
void b::print(void)
{
	a a1;
a1.SetX(555);
	printf("%d\n",a1.GetX());
}
/*
无论创建多少个同类对象，他的静态成员变量永远只有一份，多个对象共享这一个静态成员变量。
静态成员变量除了在类中声明，还要在类外部进行初始化。
静态成员函数可以在不创建对象的情况下调用。
*/