/*
时间：2017年11月18日星期六
11点29分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
int main(void)
{
	int i = 1094795585; //该值占四个字节，每个字节都是十进制的六十五
	char *p = (char *)&i;
printf("%d\n%d\n%d\n%d\n",p[0],p[1],p[2],p[3]);
return 0;
}
/*
基本数据类型的意义在于所控内存的大小，要灵活应用。
如果有整数型和字符型两个变量，虽然说是整数型，字符型，其实这两个变量中放的全是0和1，只是变量的大小不一样而已，说白了就是整数型字符型这么叫起来好听，要是按本质的意义取名，那直接可以叫单字节类型，双字节类型，四字节八字节类型。
*/