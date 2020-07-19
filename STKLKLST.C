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
	p=malloc(sizeof(struct node));
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

void display()
{
	struct node *temp;
	if(first==NULL)
	{
		pf("\nDisplay not possible!!\n");
	}
	else if(first->link==NULL)
	{
		pf("%d\n",first->data);
	}
	else
	{
		temp=first;
		pf("\nStack is:\n");
		while(temp!=NULL)
		{
			pf("%d\n",temp->data);
			temp=temp->link;
		}
	}
}

void main()
{
	int ch;
	clrscr();
	while(1)
	{
		pf("\nPress 1 to PUSH!\n");
		pf("Press 2 to POP!\n");
		pf("Press 3 to DISPLAY!\n");
		pf("Press any key to stop\n");
		pf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			       break;

			case 2:pop();
			       break;

			case 3:display();
			       break;

			default:exit(0);
				break;
	}
    }
}