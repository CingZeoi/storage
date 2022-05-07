/*
时间：2017年7月3日星期一
12点33分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
class a
{
public:
virtual int aa(void);
};
class b: public a
{
public:
int aa(void);
};
int main(void)
{
a *a1;
b b1;
a1 = &b1;
printf("%d\n%d\n",b1.aa(),b1.a::aa());
return 0;
}
int a::aa(void)
{
return 5;
}
int b::aa(void)
{
return 10;
}
/*
用virtual修饰的函数被称为虚函数，虚函数被派生类覆盖后，基类的指针指向派生类对象，调用被覆盖的函数，这时调用的就是派生类覆盖的了，这就被称为多态；
如果基类中的函数不是虚函数，被派生类覆盖后，基类对象指针指向派生类对象，调用的函数仍是基类自己的；
纯虚函数是在基类中没有函数体的函数；
virtual fun()=0;
上面就是一个纯虚函数，含有纯虚函数的类不能被实力化，这种类被称为抽象类；
抽象类中的纯虚函数可以被派生类实现；
*/