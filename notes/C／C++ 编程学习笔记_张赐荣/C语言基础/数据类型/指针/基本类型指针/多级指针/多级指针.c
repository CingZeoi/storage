/*
ʱ�䣺2017��5��31��������
7��39��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
*/
#include <stdio.h>
int main(void)
{
int i = 100,j = 200;
int *p;
int **q;
int ***l;
p = &i;
q = &p;
l = &q;
printf("%d\n%d\n%d\n%d\n",***l,**q,*p,i);
**l = &j;
printf("%d\n%d\n%d\n%d\n",***l,**q,*p,j);
return 0;
}