/*
时间：2017年5月31日星期三
7点39分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
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