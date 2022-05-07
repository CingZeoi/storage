/*
时间：2017年7月2日星期日
12点45分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
class a
{
public:
a(void);
~a();
int GetX();
int GetY();
int GetZ();
void SetX(int);
void SetY(int);
void SetZ(int);
private:
int x,y,z;
};
class b
{
public:
b(void);
b(const b &);
~b();
int GetX();
int GetY();
int GetZ();
void SetX(int);
void SetY(int);
void SetZ(int);
private:
int x,y,z;
};
int main(void)
{
a a1;;
a1.SetX(100);
a1.SetY(200);
a1.SetZ(300);
a a2 = a1;
printf("a1x=%d\na1y=%d\na1z=%d\n",a1.GetX(),a1.GetY(),a1.GetZ());
printf("a2x=%d\na2y=%d\na2z=%d\n",a2.GetX(),a2.GetY(),a2.GetZ());
b b1;
b1.SetX(400);
b1.SetY(500);
b1.SetZ(600);
b b2 = b1;
printf("b1x=%d\nb1y=%d\nb1z=%d\n",b1.GetX(),b1.GetY(),b1.GetZ());
printf("b2x=%d\nb2y=%d\nb2z=%d\n",b2.GetX(),b2.GetY(),b2.GetZ());
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
int a::GetY(void)
{
return y;
}
int a::GetZ(void)
{
return z;
}
void a::SetX(int a)
{
	x = a;
}
void a::SetY(int a)
{
	y = a;
}
void a::SetZ(int a)
{
	z = a;
}
b::b(void)
{
}
b::b(const b &object)
{
		x = object.x;
	y = object.y;
}
b::~b(void)
{
}
int b::GetX(void)
{
return x;
}
int b::GetY(void)
{
return y;
}
int b::GetZ(void)
{
return z;
}
void b::SetX(int a)
{
	x = a;
}
void b::SetY(int a)
{
	y = a;
}
void b::SetZ(int a)
{
	z = a;
}
/*
如果一个类的对象创建时进行了初始化，并且初始化的值是同类型的对象，这时候就会调用拷贝构造函数；
如果一个类没有定义拷贝构造函数，系统将自动定义；
系统定义的拷贝构造函数会把用来初始化的对象中的每个成员的值都一一对应的副给创建的对象；
如本例中，a2创建时，对a2初始化的对象是a1，而a类中没有定义拷贝共造函数，因此调用了系统创建的拷贝构造函数，所以a2中的每个成员的值都与a1一样。
b2创建时，用来初始化的对象是b1，b类中定义了拷贝构造函数，函数中仅会拷贝x和y，因此b2.x=b1.x，b2.y=b1.y，b2.z!=b1.z。
*/