/*
时间：2017年7月2日星期日
15点58分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
class a
{
public:
int GetX(void);
void SetX(int);
private:
int x;
};
int main(void)
{
a a1;
a1.SetX(100);
printf("%d\n",a1.GetX());
return 0;
}
int a::GetX(void)
{
return this->x;
}
void a::SetX(int a)
{
this->x = a;

}
/*
同类的对象之间可能成员变量的值不同，但成员函数都一样，因此，无论创建多少个同类对象，在内存中永远只有一份代码。
每个非静态成员函数内部都有一个隐藏的this指针，哪个对象调用的这个函数，这个this指针就指向哪个对象，
所以成员函数才知道要进行处理的是哪个对象。
因此在非静态成员函数中，this->i = 0，等价于i = 0。
this的实际意义在于，当非静态成员函数的局部变量或形参与类的成员变量发生冲突时，用this指针访问类成员变量；
若函数的局部变量或形参鱼类成员变量同名，不使用this指针表示函数局部变量或形参，加上this表示类成员变量；
*/