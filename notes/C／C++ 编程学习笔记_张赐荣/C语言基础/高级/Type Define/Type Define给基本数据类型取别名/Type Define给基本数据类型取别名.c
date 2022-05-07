/*
时间：2017年5月30日星期二
12点15分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
typedef int Integer;
int main(void)
{
Integer a = 5,b = 10;
printf("%d\n",a+b);
return 0;
}
/*
typedef不是必须声明在函数外，也可以声明在一个函数中，只不过只有该函数才可以使用声明的类型别名；
typedef修饰的语句看起来像是定义了一个变量，其实变量的位置只是类型的别名，如果把类型说明符后面的当作变量，编译器会提示变量未定义。
*/