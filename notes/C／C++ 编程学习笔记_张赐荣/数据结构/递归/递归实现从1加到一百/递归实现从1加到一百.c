/*
ʱ�䣺2017��6��27�����ڶ�
9��3��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
*/
#include <stdio.h>
int plus(int);
int main(void)
{
int n = 0;
n = plus(n);
printf("%d\n",n);
return 0;
}
int plus(int n)
{
return n != 100 ? n+plus(n+1) : n;
}