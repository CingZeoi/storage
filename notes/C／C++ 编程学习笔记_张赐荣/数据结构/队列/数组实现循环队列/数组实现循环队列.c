/*
时间：2017年6月26日星期一
19点39分
作者:张赐荣
博客:www.prc.cx
编译器： VS2008
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
由于在定义数组时要定义数组的长度，因此数组实现的队列的长度是固定的，
如果入队时rear加1，出队时front加1，那么front前面的元素就不能再次使用了，
所以rear和front加到队尾时，在加1的时候就应该把rear和front移到队头，也就是循环队列，所以数组实现的队列必须是循环队列。
本例中实现了循环队列的入队便利和出队。
*/