/*
ʱ�䣺2017��7��2��������
10��49��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
*/
#include <stdio.h>
void Replacing(int &,int &);
int main(void)
{
	int a = 5;
int &b = a;
int x = 10,y = 20;
printf("a=%d\na=%d\n",a,b);
Replacing(x,y);	
printf("x=%d\ny=%d\n",x,y);
return 0;
}
void Replacing(int &a,int &b)
{
int o;
o = a;
a = b;
b = o;
}

/*
�������õĸ�ʽ�ǣ�
int &������ = ������;
���ñ����ʼ����
����ı������Ǳ�ʾ���еı����������õ�������Ǹ����б���ȡ������
���ñ����Ǳ��������ó�ʼ��ʱ���ܸ�������
*/