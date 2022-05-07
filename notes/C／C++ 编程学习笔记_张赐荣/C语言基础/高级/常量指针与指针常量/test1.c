//error
#include <stdio.h>
int main(void)
{
int i = 5;
const int *p = &i;
printf("%d\n",*p);
*p = 10;
printf("%d\n",*p);
return 0;
}