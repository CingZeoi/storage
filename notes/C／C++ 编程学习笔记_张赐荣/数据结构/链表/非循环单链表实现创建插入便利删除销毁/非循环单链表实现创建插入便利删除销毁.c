/*
ʱ�䣺2017��6��10��������
19��11��
��������Visual c++ 6.0
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
if(!p->next) //�ڵ㲻����
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
���β�ڵ���ͷ�ڵ�������ӣ�����ʾβ�ڵ��ָ����ָ��ͷ�ڵ㣬����������Ϊѭ������
ѭ�����������ͨ������һ���ڵ㣬�ҵ��������еĽڵ㣻
һ���ڵ���԰�������ָ����ָ����һ���ڵ��ָ���ָ����һ���ڵ��ָ�룬�������������˫����
������������֣���ѭ����������ѭ��˫����ѭ���������ѭ��˫����
����ʵ���˷�ѭ��������Ĵ��������룬������ɾ�������٣�ֻ��һ�������㷨��������һЩϸ�����⡣
*/