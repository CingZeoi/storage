#include <stdio.h>
int main(void)
{
	const int i = 5;

	int *p = &i;
*p = 10;
	printf("%d\n",*p);
	return 0;
}