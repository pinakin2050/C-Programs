#include<stdio.h>
#define pf printf

struct node
{
	int data;
	struct node *link;
};

struct node* create(struct node *first)
{
	struct node *p;
	int ch=0;
	do
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->link=NULL;
		pf("\nEnter Element:");
		scanf("%d",&p->data);
		if(first==NULL)
		{
			first=p;
		}
		else
		{
			p->link=first;
			first=p;
		}
		pf("\nPress 1 to add new node and 0 to stop:");
		scanf("%d",&ch);
	}while(ch==1);
	return first;
}

void display(struct node *first)
{
	struct node *temp;
	if(first==NULL)
	{
		pf("\nLinked list doesn't exist.");
	}
	else if(first->link==NULL)
	{
		pf("%d\n",first->data);
	}
	else
	{
		temp=first;
		while(temp!=NULL)
		{
			pf("%d\t",temp->data);
			temp=temp->link;
		}
	}
}
struct node* reverse(struct node *first)
{
	struct node *x,*y,*z;
	x=first;
	y=first->link;
	z=first->link->link;
	while(z!=NULL)
	{
		y->link=x;
		x=y;
		y=z;
		z=z->link;
	}
	y->link=x;
	first->link=NULL;
	first=y;
	return first;
}

void main()
{
	struct node *first=NULL;
	clrscr();
	pf("Enter linked list:\n");
	first=create(first);
	pf("The linked list:\n");
	display(first);
	first=reverse(first);
	pf("\nThe linked list after reversal:\n");
	display(first);
	getch();
}