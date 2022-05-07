/*
时间：2017年6月1日星期四
10点1分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
#include <malloc.h>
int *LoadInt(int);
int main(void)
{
int x = 0;
int *p;
p = LoadInt(20);
while(x < 20)
{
	printf("%d\n",p[x]);
	x++;
}
free(p);
x = 0;
while(x < 20)
{
printf("%d\n",p[x]);
x++;
}
return 0;
}
int *LoadInt(int length)
{
int x = 0;
int *p;
p = (int *)malloc(sizeof(int)*length);
while(x < length)
{
p [x] = (x+1)*100;
x++;
}
return p;
}
/*
malloc函数声明在malloc.h头文件中，malloc返回一个创建好的内存的地址，参数是创建内存的大小，单位是字节；
malloc会在堆中创建一块内存，这块内存在程序结束时不会自动释放，平时使用的变量都是在栈中创建的，函数返回时或程序结束时会自动释放，
动态创建的内存需手动释放，使用free函数，这个函数也被声明在malloc.h头文件中，参数是内存地址；
在本例中，通过LoadInt函数动态创建了一个含有二十个元素的一围整型数组，
LoadInt创建内存后，并给内存付值，返回内存地址，LoadInt结束；
然后main函数还可以继续查看分配好的内存中的值，当然也可以进行改写，这说明动态创建的内存不会被自动释放，
main函数输出了每个元素的值，然后释放了这块内存，并再次使用该内存的指针输出了每个元素的值，这时输出的结果都是绝对值很大的附数，
这说明释放一块堆内存后，操作系统会随机改写该内存的值，所以释放一块堆内存后，应立即把指针付值为NULL，这是良好的编程习惯。
*/