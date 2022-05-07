//error
#include <stdio.h>
int main(void)
{
	int i = 5,j = 10;
int* const p = &i;
	printf("%d\n",*p);
p = &j;
printf("%d\n",*p);
return 0;
}