/*
ʱ�䣺2017��7��3������һ
7��58��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
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
����Ӷ�����м̳еĳ�Աͬ�������ʳ�Աʱ��Ӧ�ڳ�Ա��ǰ��˵�����ĸ���ĳ�Ա��
*/