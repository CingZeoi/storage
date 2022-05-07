/*
时间：2017年7月2日星期日
21点40分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
class a
{
public:
int GetX(void);
void SetX(int);
private:
int x;
};
class b{
public:
int GetY(void);
void SetY(int);
private:
int y;
};
class c: public a,public b
{
public:
int GetZ(void);
void SetZ(int);
private:
int z;
};
int main(void)
{

c c1;
c1.SetX(100);
c1.SetY(200);
c1.SetZ(300);
printf("%d\n%d\n%d\n",c1.GetX(),c1.GetY(),c1.GetZ());
return 0;
}
int a::GetX(void)
{
return x;
}
void a::SetX(int a)
{
x = a;
}
int b::GetY(void)
{
return y;
}
void b::SetY(int a)
{
y = a;
}
int c::GetZ(void)
{
return z;
}
void c::SetZ(int a)
{
z = a;
}
/*
一个类可以从多个类继承，并且可以多重继承，这个类被称为派生类，继承的类被称为基类。
继承的方式有三种：public和protected和private。
public继承，基类中的public成员继承过来后仍是公有成员，protected仍是受保护成员，private不能继承；
protected继承，从基类继承过来的public的成员，在派生类中就变成了protected成员，protected还是受保护成员，private不能继承；
private继承，public成员会变成私有成员，protected也会变成私有成员，private不能继承。
*/