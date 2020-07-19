#include<stdio.h>
#define pf printf
#define sf scanf

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
		p=(struct node*)malloc(sizeof(struct node));
		p->link=NULL;
		pf("\nEnter element:");
		sf("%d",&p->data);
		if(first==NULL)
			first=p;
		else
		{
			p->link=first;
			first=p;
		}
		pf("\nPress 1 to create new node.Press 0 to stop!!!!:");
		sf("%d",&ch);
	}while(ch==1);
	return first;
}

void display(struct node *first)
{
	struct node *temp;
	if(first==NULL)
		pf("\nLinked list doesn't exists!!");
	else if(first->link==NULL)
		pf("%d\n",first->data);
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

void oddeven(struct node *first)
{
	struct node *temp;
	int odd=0,even=0;
	temp=first;
	while(temp!=NULL)
	{
		if(temp->data%2==0)
			++even;
		else
			++odd;
		temp=temp->link;
	}
	pf("\n\nTotal odd elements are %d",odd);
	pf("\nTotal even elements are %d",even);
}
void main()
{
	struct node *first=NULL;
	clrscr();
	pf("Enter the linked list:\n");
	first=create(first);
	pf("\nThe linked list is:\n");
	display(first);
	oddeven(first);
	getch();
}
