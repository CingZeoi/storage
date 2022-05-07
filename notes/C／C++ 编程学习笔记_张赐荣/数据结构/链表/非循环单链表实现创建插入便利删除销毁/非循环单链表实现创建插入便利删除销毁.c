/*
时间：2017年6月10日星期六
19点11分
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
NODE *create(void);
void insert(NODE *,NODE *,int);
void delete(NODE *,int);
void print(NODE*);
void Free(NODE *);
int main(void)
{
NODE *head = create();
NODE *a = (NODE *)malloc(sizeof(NODE));
NODE *b = (NODE *)malloc(sizeof(NODE));
NODE *c = (NODE *)malloc(sizeof(NODE));
NODE *d = (NODE *)malloc(sizeof(NODE));
NODE *e = (NODE *)malloc(sizeof(NODE));
a->next = NULL;
b->next = NULL;
c->next = NULL;
d->next = NULL;
e->next = NULL;
a->data = 100;
b->data = 200;
c->data = 300;
d->data = 400;
e->data = 500;
insert(head,a,1);
insert(head,b,2);
insert(head,c,3);
insert(head,d,4);
insert(head,e,1);
delete(head,3);
print(head);
Free(head);
return 0;
}
NODE *create(void)
{
NODE *head = (NODE *)malloc(sizeof(NODE));
NODE *p = (NODE *)malloc(sizeof(NODE));
head->next = p;
head->data = 0;
p->next = NULL;
p->data = 0;
return head;
}
void insert(NODE *head,NODE *pNode,int i)
{
NODE *p = head;
int j = 0;
while(j<i-1&&p)
{
p = p->next;
j++;
}
pNode->next = p->next;
p->next = pNode;
return ;
}
void print(NODE *head)
{
NODE *p = head;
while(p->next)
{
printf("%d\n",p->next->data);
p = p->next;
}
return ;
}
void delete(NODE *head,int i)
{
	NODE *p = head,*q;
int j = 0;
while(j<i-1&&p->next!=NULL)
{
p = p->next;
j++;
}
if(!p->next) //节点不存在
return ;
q = p->next;
if(q->next)
{
p->next = q->next;
free(q);
}
else
{
	free(q);
	p->next = NULL;
}
return ;
}
void Free(NODE *head)
{
NODE *p,*q;
p = head;
while(p->next)
{
q = p->next;
p->next = q->next;
free(q);
}
free(head);
return ;
}
/*
如果尾节点与头节点进行连接，及表示尾节点的指针域指向头节点，这种链表被称为循环链表；
循环单链表可以通过任意一个节点，找到链表所有的节点；
一个节点可以包含两个指针域，指向上一个节点的指针和指向下一个节点的指针，这样的链表叫做双链表；
所以链表分四种，非循环单链表，非循环双链表，循环单链表和循环双链表；
本例实现了非循环单链表的创建，插入，便利，删除，销毁，只是一个基本算法，还存在一些细节问题。
*/