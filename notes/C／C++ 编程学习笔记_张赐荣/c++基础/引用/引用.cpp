/*
时间：2017年7月2日星期日
10点49分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
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
定义引用的格式是：
int &引用名 = 变量名;
引用必须初始化；
上面的变量名是表示已有的变量名，引用的意义就是给已有变量取别名，
引用本身不是变量，引用初始化时不能副常量。
*/