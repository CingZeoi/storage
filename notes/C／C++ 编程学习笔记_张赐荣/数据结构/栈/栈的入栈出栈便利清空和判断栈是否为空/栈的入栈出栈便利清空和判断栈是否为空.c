/*
 时间：2017年6月11日星期日
13点30分
编译器：Visual c++ 6.0
*/
#include <stdio.h>
#include <malloc.h>
#define NULL 0
#define TRUE 1
#define FALSE 0
typedef int BOOL;
//定义节点
typedef struct node
{
int data;
struct node *next;
}NODE;
//定义栈结构体
typedef struct stack
{
NODE *top;
NODE *bottom;
}STACK;
void push(STACK *); //入栈
void pop(STACK *); //出栈
void print(STACK *); //栈的便利						
BOOL isEmpty(STACK *); //判断栈是否为空
void clear(STACK *); //栈的清空
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