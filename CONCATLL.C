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
		p->data=NULL;
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
		pf("\nPress 1 to insert next node and 0 to stop:");
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

struct node* concat(struct node *first1,struct node *first2)
{
	struct node *temp;
	temp=first1;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=first2;
	return first1;
}
void main()
{
	struct node *first1=NULL;
	struct node *first2=NULL;
	clrscr();
	pf("Enter first linked list:\n");
	first1=create(first1);

	pf("Enter second linked list:\n");
	first2=create(first2);

	pf("\nFirst linked list is:\n");
	display(first1);

	pf("\nSecond linked list is:\n");
	display(first2);

	first1=concat(first1,first2);
	pf("\nConcated linked list is\n");
	display(first1);
	getch();
}
