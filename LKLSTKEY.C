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
		pf("\nPress 1 to add new node and 0 to stop!:");
		scanf("%d",&ch);
	}while(ch==1);
	return first;
}

void display(struct node *first)
{
	struct node *temp;
	if(first==NULL)
	{
		pf("\nDisplay not possible!!!!");
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

void search(struct node *first,int key)
{
	struct node *temp;
	int cnt=0;
	if(first==NULL)
	{
		pf("\nSearch not possible!!!");
	}
	else
	{
		temp=first;
		while(temp!=NULL)
		{
			if(temp->data==key)
			{
				++cnt;
				temp=temp->link;
			}
			else
			{
				temp=temp->link;
			}
		}
	}
	if(cnt==0)
	{
		pf("\nKey not found!!!");
	}
	else
	{
		pf("\nKey found %d times",cnt);
	}
}
void main()
{
	struct node *first=NULL;
	int key;
	clrscr();
	pf("Enter linked list:\n");
	first=create(first);
	pf("The linked list is:\n");
	display(first);
	pf("\nEnter the key value:");
	scanf("%d",&key);
	search(first,key);
	getch();
}