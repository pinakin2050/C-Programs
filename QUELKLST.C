#include<stdio.h>
#define pf printf

struct node
{
	int data;
	struct node *link;
};
struct node *first=NULL;

void push()
{
	struct node *p;
	pf("\nEnter element:");
	scanf("%d",&p->data);
	p->link=NULL;
	if(first==NULL)
	{
		first=p;
	}
	else
	{
		p->link=first;
		first=p;
	}
}

void pop()
{
	struct node *x;
	if(first==NULL)
	{
		pf("\nPop not possible!\n");
	}
	else if(first->link==NULL)
	{
		pf("\nelement poped is %d\n",first->data);
		free(first);
		first=NULL;
	}
	else
	{
		pf("\nelement poped is %d\n",first->data);
		x=first;
		first=first->link;
		free(x);
		x=NULL;
	}
}