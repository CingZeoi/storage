/*
时间：2017年6月1日星期四
9点18分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
union U1
{
unsigned char c [3];unsigned
 int i;
};
union U2
{
char c[15];
int i;
};
int main(void)
{
union U1 u1;
union U2 u2;
printf("%d\n",sizeof(u1));
printf("%d\n",sizeof(u2));
u1.i = 4294967295; //这是无符号整型能表示的最大值
printf("%u\n%u\n%u\n%u\n",u1.c[0],u1.c[1],u1.c[2],u1.c[3]);
printf("%u\n",u1.i);
return 0;
}
/*
定义联合体的格式是：
union 联合体类型名
{
联合体成员1;
联合体成员2;
联合体成员n;
}联合体变量;
联合体与结构体不同，结构体的长度是其成员所占字节大小的和，而联合体的长度是联合体成员中所占字节大小最宽的成员的长度，
在本例中，联合体U1包含一个含有三个成员的字符数组和一个整型量，
含有三个元素的字符数组占三个字节，整型量占四个字节，所以联合体U1就占四个字节；
但不完全是这样，刚说的只是其中一点，评判联合体所占字节大小还有很重要的一点
联合体U2中包含一个含有十五个元素的字符数组，这个成员占十五个字节，还包含一个整型量，占四个字节，这个联合体的长度是十六个字节；
字符数组是这个联合体中所占字节最宽的一个成员，但十五不完整，或者说，这个联合体中所有的基本类型量所占字节大小不能被十五整除，
联合体U2中包含一个字符型和一个整型，所占字节大小分别是1和4，十五不能完全整除这两个数，所以加宽到16。
联合体的意义有很多，它可以更直观的查看一块内存，随着对指针，内存的理解的加深，会慢慢体会到它的妙处，
本例中掩饰了它的基本用法，并通过程序说明了该联合体在内存中的布局，请务必把这些都搞明白，这里不做解释。
*/	