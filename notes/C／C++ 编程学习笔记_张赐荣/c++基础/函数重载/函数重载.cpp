/*
ʱ�䣺2017��7��3������һ
6��52��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
*/
#include <stdio.h>
int a(int,int);
int a(int,int,int);
//void a(int,int);
int a(int);
int main(void)
{
//a(1,1);
a(1,2,3);
a(5);
return 0;
}
int a(int a,int b)
{
printf("%d\n",a+b);
return 0;
}
int a(int a,int b,int c)
{
printf("%d\n",a+b+c);
return 0;
}
/*
void a(int a,int b)
{
printf("%d\n",a+b);
}
*/
int a(int a)
{
printf("%d\n",a);
return 0;
}
/*
c++֧�ֺ���ͬ��������ͨ�������Ĳ����б�Ĳ�ͬ���жϵ��õ����ĸ����������Ƿ���ֵ��ͬ�ǲ��еģ�
int a(int,int);
int a(int);
�ββ�ͬ������ͻ���ɹ��棻
int a(int);
char a(int);
������ֵ��ͬ���޷��ֱ棬���ɹ��棻
*/