/*
ʱ�䣺2017��7��2��������
19��5��
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
���۴������ٸ�ͬ��������ľ�̬��Ա������Զֻ��һ�ݣ������������һ����̬��Ա������
��̬��Ա����������������������Ҫ�����ⲿ���г�ʼ����
��̬��Ա���������ڲ��������������µ��á�
*/