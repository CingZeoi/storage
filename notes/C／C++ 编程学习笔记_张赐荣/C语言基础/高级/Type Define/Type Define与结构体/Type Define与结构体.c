/*
ʱ�䣺2017��5��30�����ڶ�
12��32��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
*/
#include <stdio.h>
typedef struct student
{
char *name;
int age;
}stu,*s;
int main(void)
{
stu a;
s b;
a.name = "sam";
a.age = 15;
b = &a;
printf("%s\n%d\n",b->name,b->age);
return 0;
}
/*
���Կ�������ʹ��student�ı�������ṹ�������ṹ��ָ�����ʱ����û��ʹ��struct�ؼ��֣�������typedef���εĽṹ�壬�ڶ������ʱ���Բ�ʹ��struct�ؼ��֣�
typedef�ڸ�������������ȡ����ʱ������˵��������������͵ı��������Ǳ�������ôͬ������student�ṹ��������student���͵ı�����һ��ָ��student��ָ�����͵ı��������ǽṹ������ͽṹ��ָ�������
*/