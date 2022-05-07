/*
时间：2017年6月26日星期一
10点55分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
*/
#include <stdio.h>
#include <malloc.h>
#define NULL 0
typedef struct node
{
int data;
struct node *next;
}NODE;
typedef struct queue
{
NODE *front;
NODE *		rear;
}QUEUE;
void push(QUEUE *,int);
void print(QUEUE *q);
void pop(QUEUE *);
void clear(QUEUE *q);
int main(void)
{
QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));
int i = 0;
q->front = q->rear = (NODE *)malloc(sizeof(NODE));
for(i=0;i<=10;i++)
push(q,i);
print(q);
pop(q);
print(q);
pop(q);
print(q);
clear(q);
free(q);
return 0;
}
void push(QUEUE *q,int data)
{
NODE *pNode = (NODE *)malloc(sizeof(NODE));
pNode->data = data;
pNode->next = NULL;
q->rear->next = pNode;
q->rear = pNode;
}
void print(QUEUE *q)
{
NODE *p = q->front;
if(q->front->next == NULL)
return ;
p = p->next;
while(p->next!=NULL)
{
p = p->next;
printf("%d\n",p->data);
}
}
void pop(QUEUE *q)
{
if(q->front!=q->rear)
{
NODE *p = q->front;
q->front = p->next;
free(p);
}
}
void clear(QUEUE *q)
{
NODE *p;
while(q->front!=q->rear)
{
p = q->front;
q->front = p->next;
free(p);
}
}
/*
队列是先进先出，本例中实现了入队出队便利及清空。
*/