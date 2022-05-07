/*
时间：2017年11月19日星期日
0点27分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
namespace name1
{
int plus(int a,int b)
{
return a+b;
}
};
namespace name2
{
int max(int a,int b)
{
return a>b?a:b;
}
};
int main(void)
{
	printf("%d\n",name1::plus(5,5));
printf("%d\n",name2::max(10,100));
return 0;
}
/*
c++的名称空间是为了避免标识符冲突，可以使用using语句，使名称空间下的单个标识符或所有标识符已全局的形式呈现。
using name1::plus;
上面的语句是把叫name1的名称空间下的plus标识符全局呈现，引用时无需在加名称空间名；
23行的代码就可写成
printf("%d\n",plus(5,5));
using namespace name1;
using namespace name2;
上面两句是把name1下的所有标识符与name2下所有标识符全局呈现；
*/