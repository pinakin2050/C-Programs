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
	int ch;
	do
	{
		p=(struct node*)malloc(sizeof(struct node));
		p->link=NULL;
		pf("\nEnter element:");
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
		pf("\nPress 1 to add node and 0 to stop:");
		scanf("%d",&ch);
	}while(ch==1);
	return first;
}

void display(struct node *first)
{
	struct node *temp;
	if(first==NULL)
	{
		pf("\nDisplay not possible\n");
	}
	else if(first->link==NULL)
	{
		pf("%d\t",first->data);
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
int lnkcnt(struct node *first)
{
	int cnt=0;
	struct node *temp;
	temp=first;
	while(temp!=NULL)
	{
		++cnt;
		temp=temp->link;
	}
	return cnt;
}
void main()
{
	int cnt=0;
	struct node *first=NULL;
	clrscr();
	pf("Enter the linked list:\n");
	first=create(first);
	pf("\nThe linked list is\n");
	display(first);
	cnt=lnkcnt(first);
	pf("\nTotal Nodes are:%d",cnt);
	getch();
}