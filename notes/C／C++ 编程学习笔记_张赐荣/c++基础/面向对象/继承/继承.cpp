/*
ʱ�䣺2017��7��2��������
21��40��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
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
һ������ԴӶ����̳У����ҿ��Զ��ؼ̳У�����౻��Ϊ�����࣬�̳е��౻��Ϊ���ࡣ
�̳еķ�ʽ�����֣�public��protected��private��
public�̳У������е�public��Ա�̳й��������ǹ��г�Ա��protected�����ܱ�����Ա��private���ܼ̳У�
protected�̳У��ӻ���̳й�����public�ĳ�Ա�����������оͱ����protected��Ա��protected�����ܱ�����Ա��private���ܼ̳У�
private�̳У�public��Ա����˽�г�Ա��protectedҲ����˽�г�Ա��private���ܼ̳С�
*/