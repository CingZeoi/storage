/*
时间：2017年6月29日星期四
21点38分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
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