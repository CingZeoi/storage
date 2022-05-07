/*
时间：2017年6月26日星期一
11点43分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
int main(void)
{
int i = 5;
i++;
printf("%d\n",i);
printf("%d\n",i++);
printf("%d\n",i);
printf("%d\n",++i);
printf("%d\n",i);
printf("%d\n",i--);
printf("%d\n",i);
printf("%d\n",--i);
printf("%d\n",i);
return 0;
}
/*
本例说明，前自增自减与后自增自减对于操作对象来说是没有区别的，
对于返回值来说，前自增自减返回的值是自增自减后的值，后自增自减返回的是自增自减前的值。
*/