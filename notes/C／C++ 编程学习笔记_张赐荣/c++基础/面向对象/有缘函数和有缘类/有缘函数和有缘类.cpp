/*
ʱ�䣺2017��7��2��������
14��55��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
*/
#include <stdio.h>
class a
{
public:
a(void);
~a(void);
int GetX();
void SetX(int);
friend int GetY(a &);
friend void SetY(a &,int);
friend class b;
private:
int x,y;
};
class b
{
public:
	void PrintX(a &);
void PrintY(a &);
};
int main(void)
{
a a1;
a1.SetX(100);
SetY(a1,200);
printf("x=%d\ny=%d\n",a1.GetX(),GetY(a1));
b b1;
b1.PrintX(a1);
b1.PrintY(a1);
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
int GetY(a &a1)
{
return a1.y;
}
void SetY(a &a1,int a)
{
a1.y = a;
}
void b::PrintX(a &a1)
{
	printf("%d\n",a1.x);
}
void b::PrintY(a &a1)
{
	printf("%d\n",a1.y);
}
/*
һ�������Ե����������������࣬��Ե�������Է���������г�Ա��
һ�������Ե���е����к��������Է��ʸ�������г�Ա��
*/