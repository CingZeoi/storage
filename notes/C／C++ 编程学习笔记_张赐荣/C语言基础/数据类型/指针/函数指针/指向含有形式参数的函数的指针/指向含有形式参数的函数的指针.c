/*
ʱ�䣺2017��5��29������һ
23��0��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
*/
#include <stdio.h>
int max(int,int);
int plus(int,int);
int main(void)
{
int (*p)(int,int) = max;
printf("%d\n",p(3,2));
p = plus;
printf("%d\n",p(100,200));
return 0;
}
int max(int a,int b)
{
int o = 0;
if(a == b)
return 0;
if(a < b)
o = a;
a = b;
b = o;
return a;
}
int plus(int a,int b)
{
return a+b;
}
/*
�ϸ��˵�����庯��ָ������ĸ�ʽ�ǣ�
��������ֵ���� (*����ָ�������)(�����β��б�);
�ڶ��庯��ָ�����ʱ���;����˸ú���ָ�������ָ�������ĺ������ú���ָ�����ֻ��ָ���붨��ʱ��ͬ����Բ�εĺ�����
�ڱ����У�����max�뺯��plus��Բ��һ�������Һ���ָ�����p����ָ��ĺ�����Բ����max��plusҲһ�������Ժ���ָ�����p��������ָ�������������������������á�
*/