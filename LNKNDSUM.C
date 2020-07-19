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
		p=malloc(sizeof(struct node));
		p->link=NULL;
		pf("\nEnter the element:");
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
		pf("Press 1 to add node and 0 to stop:");
		scanf("%d",&ch);
	}while(ch==1);
}

void display(struct node *first)
{
	struct node *temp;
	if(first==NULL)
	{
		pf("Display not possible!");
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

int lnksum(struct node *first)
{
	int sum=0;
	struct node *temp;
	while(temp!=NULL)
	{
		sum=sum+temp->data;
		temp=temp->link;
	}
	return sum;
}
void main()
{
	struct node *first=NULL;
	int sum;
	clrscr();
	pf("Enter the linked list:");
	first=create(first);
	pf("\nThe linked list is\n");
	display(first);
	sum=lnksum(first);
	pf("\nThe sum of nodes is:%d",sum);
	getch();
}