/*
ʱ�䣺2017��7��3������һ
8��57��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
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
��������󴴽��Ĺ����ǣ��ȴ�����������ڴ�����������������Ĺ����ǣ��������ȣ������
����ڴ������������ʱ��Ҫ���û��๹�캯����������๹�캯�����Σ�������Ҫ�������๹�캯���и����๹�캯�����Ρ�
*/