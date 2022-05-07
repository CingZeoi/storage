/*
ʱ�䣺2017��6��26������һ
19��39��
����:�Ŵ���
����:www.prc.cx
�������� VS2008
*/
#include <stdio.h>
#define SIZE 10
typedef struct queue
{
int array[SIZE];
int front;
int rear;
}QUEUE;
void push(QUEUE *,int);
void pop(QUEUE *);
void print(QUEUE *);
int main(void)
{
QUEUE q;
int i = 0;
q.front = q.rear = 0;
for(i=0;i<=SIZE-2;i++)
push(&q,i);
print(&q);
pop(&q);
print(&q);
pop(&q);
print(&q);
return 0;
}
void push(QUEUE *p,int data)
{
if(!((p->rear+1)%SIZE == p->front))
{
p->array [p->rear] = data;
p->rear = (p->rear+1)%SIZE;
}
}
void print(QUEUE *p)
{
QUEUE q = *p;
while(q.front%SIZE != q.rear)
{
printf("%d\n",q.array [q.front]);
q.front = (q.front+1)%SIZE;
}
}
void pop(QUEUE *p)
{
if(!(p->front == p->rear))
p->front = (p->front+1)%SIZE;
}
/*
�����ڶ�������ʱҪ��������ĳ��ȣ��������ʵ�ֵĶ��еĳ����ǹ̶��ģ�
������ʱrear��1������ʱfront��1����ôfrontǰ���Ԫ�ؾͲ����ٴ�ʹ���ˣ�
����rear��front�ӵ���βʱ���ڼ�1��ʱ���Ӧ�ð�rear��front�Ƶ���ͷ��Ҳ����ѭ�����У���������ʵ�ֵĶ��б�����ѭ�����С�
������ʵ����ѭ�����е���ӱ����ͳ��ӡ�
*/