/*
时间：2017年6月11日星期日
10点21分
编译器：Visual c++ 6.0
*/
#include <stdio.h>
#include <malloc.h>
#define NULL 0
typedef struct node
{
int data;
struct node *next;
}NODE;
void print(NODE *);
void Free(NODE *);
int main(void)
{
NODE *head = (NODE *)malloc(sizeof(NODE));
NODE *a = (NODE *)malloc(sizeof(NODE));
NODE *b = (NODE *)malloc(sizeof(NODE));
NODE *c = (NODE *)malloc(sizeof(NODE));
NODE *d = (NODE *)malloc(sizeof(NODE));
NODE *e = (NODE *)malloc(sizeof(NODE));
NODE *f = (NODE *)malloc(sizeof(NODE));
NODE *g = (NODE *)malloc(sizeof(NODE));
head->next = a;
a->next = b;
b->next = c;
c->next = d;
d->next = e;
e->next = f;
f->next = g;
g->next = head;
head->data = 0;
a->data = 100;
b->data = 200;
c->data = 300;
d->data = 400;
e->data = 500;
f->data = 600;
g->data = 700;
print(d);
printf("\n\n\n\n");
print(b);
Free(f);
return 0;
}
void print(NODE *pNode)
{
NODE *p = pNode;
printf("%d\n",p->data);
while(p->next != pNode)
{
p = p->next;	
printf("%d\n",p->data);
}
return ;
}
void Free(NODE *pNode)
{
NODE *p = pNode,*q;
while(p->next != pNode)
{
q = p->next;
p->next = q->next;
free(q);
}
return ;
}