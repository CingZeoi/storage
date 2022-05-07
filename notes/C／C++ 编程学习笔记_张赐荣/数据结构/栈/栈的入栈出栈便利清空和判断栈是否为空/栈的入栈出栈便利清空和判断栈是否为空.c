/*
 ʱ�䣺2017��6��11��������
13��30��
��������Visual c++ 6.0
*/
#include <stdio.h>
#include <malloc.h>
#define NULL 0
#define TRUE 1
#define FALSE 0
typedef int BOOL;
//����ڵ�
typedef struct node
{
int data;
struct node *next;
}NODE;
//����ջ�ṹ��
typedef struct stack
{
NODE *top;
NODE *bottom;
}STACK;
void push(STACK *); //��ջ
void pop(STACK *); //��ջ
void print(STACK *); //ջ�ı���						
BOOL isEmpty(STACK *); //�ж�ջ�Ƿ�Ϊ��
void clear(STACK *); //ջ�����
int main(void)
{
STACK s;
s.top = (NODE *)malloc(sizeof(NODE));
s.top->next = NULL;
s.top->data = 0;
s.bottom = s.top;
push(&s,100);
push(&s,200);
push(&s,300);
push(&s,400);
push(&s,500);
push(&s,600);
print(&s);
pop(&s);
print(&s);
pop(&s);
print(&s);
isEmpty(&s) ? printf("true\n") : printf("false\n");
clear(&s);
isEmpty(&s) ? printf("true\n") : printf("false\n");
free(s.top);
return 0;
}
void push(STACK *pStack,int i)
{
NODE *p = (NODE *)malloc(sizeof(NODE));
p->data = i;
p->next = pStack->top;
pStack->top = p;
return ;
}
void pop(STACK *pStack)
{
NODE *p = pStack->top;
if(isEmpty(pStack))
return ;
pStack->top = p->next;
free(p);
return ;
}
void print(STACK *pStack)
{
NODE *p = pStack->top;
if(isEmpty(pStack))
return ;
printf("%d\n",p->data);
while(p != pStack->bottom)
{
p = p->next;
printf("%d\n",p->data);
}
return ;
}
BOOL isEmpty(STACK *pStack)
{
return pStack->top == pStack->bottom ? TRUE : FALSE;
}
void clear(STACK *pStack)
{
	NODE *p = pStack->top,*q;
if(isEmpty(pStack))
return ;
while(p != pStack->bottom)
{
	q = p;
	p = q->next;
	free(q);
}
pStack->top = pStack->bottom;
return ;
}