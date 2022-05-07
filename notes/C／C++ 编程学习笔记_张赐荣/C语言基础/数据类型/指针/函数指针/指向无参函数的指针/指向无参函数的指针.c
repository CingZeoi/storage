/*
时间：2017年5月29日星期一
22点37分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
int Integer(void);
char Char(void);
int main(void)
{
int (*a)() = Integer;
char (*b)() = Char;;
printf("%d\n%c\n",a(),b());
a = Char;
b = Integer;
printf("%d\n%c\n",b(),a());
return 0;
}
int Integer(void)
{
return 5;
}
char Char(void)
{
return 'A';
}
/*
定义函数指针的格式是
函数返回值类型 (*指针变量名)();
因为在定义指针变量时，变量名用圆括号括了起来，由此编译器认为该指针变量是函数指针变量；
函数名表示函数的首地址，把函数的首地址付给函数指针变量，就可以通过函数指针变量来调用函数。
给函数指针变量付值的格式是：
函数指针变量名 = 函数名;
通过函数指针变量调用所指向的函数的格式是：
函数指针变量名();
无参函数指针变量可以指向返回值不同于该指针变量的类型的函数，同样可以正常调用。
*/