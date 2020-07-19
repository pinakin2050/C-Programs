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
		p=malloc(sizeof(struct node));
		p->link=NULL;
		pf("\nEnter the element:");
		sf("%d",&p->data);
		if(first==NULL)
			first=p;
		else
		{
			p->link=first;
			first=p;
		}
		pf("\nPress 1 to add new element and 0 to stop!!:");
		sf("%d",&ch);
	}while(ch==1);
	return first;
}

void display(struct node *first)
{
	struct node *temp;
	if(first==NULL)
		pf("\nLinked list doesn't exist!!!");
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

struct node* insert_right(struct node *first,int key)
{       struct node *p,*temp;
	int cnt=0;
	if(first==NULL)
		pf("\nInsertion not possible!!!");
	else if(first->data==key)
	{
		p=malloc(sizeof(struct node));
		pf("\nEnter element:");
		sf("%d",&p->data);
		p->link=first->link;
		first->link=p;
		++cnt;
	}
	else
	{
		temp=first;
		while(temp!=NULL)
		{
			if(temp->data==key)
			{
				p=malloc(sizeof(struct node));
				pf("\nEnter element:");
				sf("%d",&p->data);
				p->link=temp->link;
				temp->link=p;
				temp=temp->link;
				++cnt;
			}
			else
				temp=temp->link;
		}
	}
	if(cnt==0)
		pf("\nKey not found!!!\n");
	return first;
}
void main()
{
	int key;
	struct node *first=NULL;
	clrscr();
	pf("Enter the linked list:\n");
	first=create(first);
	pf("\nThe linked list is:\n");
	display(first);
	pf("\nEnter the key:");
	sf("%d",&key);
	first=insert_right(first,key);
	pf("\nUpdated linked list is:\n");
	display(first);
	getch();
}
