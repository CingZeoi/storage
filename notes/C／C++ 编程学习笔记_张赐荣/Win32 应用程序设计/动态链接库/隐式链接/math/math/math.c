/*
ʱ�䣺2017��6��29��������
21��38��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
*/
#include <windows.h>
extern "C" _declspec(dllexport) int plus(int a,int b)
{
return a+b;
}
extern "C" _declspec(dllexport) int minus(int a,int b)
{
return a-b;
}
extern "C" _declspec(dllexport) int multiply(int a,int b)
{
return a*b;
}
extern "C" _declspec(dllexport) int divide(int a,int b)
{
return a/b;
}