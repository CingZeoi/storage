/*
时间：2017年6月10日星期六
14点8分
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
int main(void)
{
NODE *head,*p,*q,*r;
head = (NODE *)malloc(sizeof(NODE));
p = (NODE *)malloc(sizeof(NODE));
q = (NODE *)malloc(sizeof(NODE));
head->data = 0;
r = (NODE *)malloc(sizeof(NODE));
p->data = 5;
q->data = 10;
r->data = 20;
head->next = p;
p->next = q;
q->next = r;
r->next = NULL;
printf("%d\n%d\n%d\n",p->data,p->next->data,p->next->next->data);
free(head);
head = NULL;
free(p);
p = NULL;
free(q);
q = NULL;
free(r);
r = NULL;
return 0;
}
/*
先来熟悉几个术语，节点，首节点，尾节点，头节点，头指针；
可以把节点理解成数组中的元素，节点就是链表中的元素。
可以用结构体描述一个存放数据的节点，这个节点至少要包含两个部分，数据部分，称为数据域，指向下一个节点的指针，称为指针域；
数据域可以是任意类型，指针域的类型必须是指向结构体本身的指针类型，一个节点的指针域存放指向下一个节点的内存地址，下一个节点的指针域存放在下一个节点的内存地址，由此可将每个节点串联起来，称为链表；
首节点就是链表中存放有效数据的第一个节点，尾节点就是存放有效数据的最后一个节点，尾节点的指针域指向NULL；
头节点就是首节点前面的节点，因为首节点是存放有效数据的第一个节点，所以头节点不存放有效数据，头节点的指针域指向首节点；
头指针就是头节点的指针；
*/