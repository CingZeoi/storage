/*
时间：2017年7月3日星期一
14点24分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <iostream>
#include <fstream>
using namespace std;
int main(void)
{
ofstream ofs;
ofs.open("a.txt");
ofs << "abcdefg" << endl;
ofs.close();
ifstream	 ifs;
ifs.open("a.txt");
char data [10];
ifs >> data;
cout << data;
ifs.close();
return 0;
}