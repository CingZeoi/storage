/*
ʱ�䣺2017��7��2��������
12��45��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
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
���һ����Ķ��󴴽�ʱ�����˳�ʼ�������ҳ�ʼ����ֵ��ͬ���͵Ķ�����ʱ��ͻ���ÿ������캯����
���һ����û�ж��忽�����캯����ϵͳ���Զ����壻
ϵͳ����Ŀ������캯�����������ʼ���Ķ����е�ÿ����Ա��ֵ��һһ��Ӧ�ĸ��������Ķ���
�籾���У�a2����ʱ����a2��ʼ���Ķ�����a1����a����û�ж��忽�����캯������˵�����ϵͳ�����Ŀ������캯��������a2�е�ÿ����Ա��ֵ����a1һ����
b2����ʱ��������ʼ���Ķ�����b1��b���ж����˿������캯���������н��´��x��y�����b2.x=b1.x��b2.y=b1.y��b2.z!=b1.z��
*/