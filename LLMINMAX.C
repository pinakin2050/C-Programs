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

int max_ele(struct node *first,int max)
{
	struct node *temp;
	max=first->data;
	if(first==NULL)
		pf("\nLinked list doesn't exist!!!");
	else if(first->link==NULL)
	{
		max=first->data;
		return max;
	}
	else
	{
		temp=first;
		while(temp!=NULL)
		{
			if(temp->data>max)
			{
				max=temp->data;
				temp=temp->link;
			}
			else
				temp=temp->link;
		}
	}
	return max;
}

int min_ele(struct node *first,int min)
{
	struct node *temp;
	min=first->data;
	if(first==NULL)
		pf("\nLinked list doesn't exist!!!");
	else if(first->link==NULL)
	{
		min=first->data;
		return min;
	}
	else
	{
		temp=first;
		while(temp!=NULL)
		{
			if(temp->data<min)
			{
				min=temp->data;
				temp=temp->link;
			}
			else
				temp=temp->link;
		}
	}
	return min;
}
void main()
{
	int min,max;
	struct node *first=NULL;
	clrscr();
	pf("Enter the linked list:\n");
	first=create(first);
	pf("\nThe linked list is:\n");
	display(first);
	max=max_ele(first,max);
	min=min_ele(first,min);
	pf("\n\nThe max element is:%d",max);
	pf("\nThe min element is:%d",min);
	getch();
}