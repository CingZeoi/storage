/*
时间：2017年7月3日星期一
8点57分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
class a
{
public:
a(int,int);
int GetX(void);
void SetX(int);
int GetY(void);
void SetY(int);
private:
int x,y;
};
class b
{
public:
b(int,int,int);
int GetP(void);
void SetP(int);
int GetQ(void);
void SetQ(int);
int GetR(void);
void SetR(int);
private:
int p,q,r;
};
class c: public a,public b
{
public:
c(int,int,int,int,int,int,int);
int GetI(void);
void SetI(int);
int GetJ(void);
void SetJ(int);
private:
int i,j;
};
int main(void)
{
c c1(100,200,300,400,500,600,700);
printf("%d\n%d\n",c1.GetX(),c1.GetY());
printf("%d\n%d\n%d\n",c1.GetP(),c1.GetQ(),c1.GetR());
printf("%d\n%d\n",c1.GetI(),c1.GetJ());
c1.SetX(1000);
c1.SetY(2000);
c1.SetP(3000);
c1.SetQ(4000);
c1.SetR(5000);
c1.SetI(6000);
c1.SetJ(7000);
printf("%d\n%d\n",c1.GetX(),c1.GetY());
printf("%d\n%d\n%d\n",c1.GetP(),c1.GetQ(),c1.GetR());
printf("%d\n%d\n",c1.GetI(),c1.GetJ());c1.SetJ(7000);
return 0;
}
a::a(int a,int b)
{
	x = a;
	y = b;
}
b::b(int a,int b,int c)
{
	p = a;
	q = b;
	r = c;
}
c::c(int a,int b,int c,int d,int e,int f,int g):a(a,b),b(c,d,e)
{
	i = f;
	j = g;
}
int a::GetX(void)
{
return x;
}
void a::SetX(int a)
{
x = a;
}
int a::GetY(void)
{
return y;
}
void a::SetY(int a)
{
y = a;
}
int b::GetP(void)
{
return p;
}
void b::SetP(int a)
{
p = a;
}
int b::GetQ(void)
{
return q;
}
void b::SetQ(int a)
{
q = a;
}
int b::GetR(void)
{
return r;
}
void b::SetR(int a)
{
r = a;
}
int c::GetI(void)
{
return i;
}
void c::SetI(int a)
{
i = a;
}
int c::GetJ(void)
{
return j;
}

void c::SetJ(int a)
{
j = a;
}
/*
派生类对象创建的过程是，先创建基类对象，在创建派生类对象，消亡的过程是，派生类先，基类后；
因此在创建派生类对象时，要调用基类构造函数，如果基类构造函数带参，我们需要在派生类构造函数中给基类构造函数传参。
*/