/*
ʱ�䣺2017��11��19��������
0��27��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
*/
#include <stdio.h>
namespace name1
{
int plus(int a,int b)
{
return a+b;
}
};
namespace name2
{
int max(int a,int b)
{
return a>b?a:b;
}
};
int main(void)
{
	printf("%d\n",name1::plus(5,5));
printf("%d\n",name2::max(10,100));
return 0;
}
/*
c++�����ƿռ���Ϊ�˱����ʶ����ͻ������ʹ��using��䣬ʹ���ƿռ��µĵ�����ʶ�������б�ʶ����ȫ�ֵ���ʽ���֡�
using name1::plus;
���������ǰѽ�name1�����ƿռ��µ�plus��ʶ��ȫ�ֳ��֣�����ʱ�����ڼ����ƿռ�����
23�еĴ���Ϳ�д��
printf("%d\n",plus(5,5));
using namespace name1;
using namespace name2;
���������ǰ�name1�µ����б�ʶ����name2�����б�ʶ��ȫ�ֳ��֣�
*/