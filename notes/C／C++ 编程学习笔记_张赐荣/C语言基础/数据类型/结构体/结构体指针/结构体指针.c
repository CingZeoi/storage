/*
ʱ�䣺2017��5��31��������
7��53��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
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