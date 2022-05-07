/*
时间：2017年5月31日星期三
7点53分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
struct Student
{
char name;
int age;
};
int main(void)
{
struct Student a,*p;
p = &a;
p->name = 'a';
p->age = 12;
printf("%c\n%d\n",a.name,a.age);
printf("%c\n%d\n",p->name,p->age);
return 0;
}