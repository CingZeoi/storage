/*
ʱ�䣺2017��7��3������һ
14��24��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
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