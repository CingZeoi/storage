/*
时间：2017年7月2日星期日
11点25分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
class a
{
public:
	a(int a) //构造函数
{
SetI(a);
}
~a(void) //析构函数
{
}
int GetI();
void SetI(int);
private:
int i;
};
int main(void)
{
a a1(5),*p;
p = &a1;
printf("i=%d\n",a1.GetI());
p->SetI(10);
printf("i=%d\n",a1.GetI());
return 0;
}
int a::GetI()
{
return i;
}
void a::SetI(int a)
{
i = a;
}
/*
定义类的格式是
class 类名
{
public:
公有成员
private:
私有成员
};
不加访问修饰符的成员，默认是private成员。
类的内部可以访问类的所有成员，类的外部只能访问类的公有成员，一个类的派生类可以访问基类的受保护成员和公有成员。
类的函数成员可以在类中定义也可以在类的外部定义，在类的外部定义时，要说明是哪个类的函数；
构造函数会在创建对象时自动调用，析构函数会在对象消亡时自动调用；
一个类可以有多个构造函数，但只能有一个析构函数；
类的构造函数必须是公有且类的构造函数的名字要和类名一致，且构造函数名前不能有返回值类型说明符，void都不能有；
类的析构函数前也不能有返回值类型说明符，析构函数名也要和类名一致，并且要在析构函数名之前加上~。
*/