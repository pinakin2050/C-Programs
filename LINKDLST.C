#include<stdio.h>
#define P printf

struct node
{
	int data;
	struct node *link;
};
struct node *first=NULL;

void insert_front()
{
	int element;
	struct node *p;
	p=malloc(sizeof(struct node));
	P("\nEnter Element:");
	scanf("%d",&element);
	p->data=element;
	p->link=NULL;
	if(first==NULL)
	{
		first=p;
	}
	else
	{
		p->link = first;
		first=p;
	}
}
void insert_rear()
{
	int element;
	struct node *p,*temp;
	p=malloc(sizeof(struct node));
	P("\nEnter Element:");
	scanf("%d",&element);
	p->data=element;
	p->link=NULL;
	if(first==NULL)
	{
		first=p;
	}
	else
	{
		temp=first;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=p;
	}
}
void del_front()
{
	struct node *x;
	if(first==NULL)
	{
		P("\nDeletion not possible!!\n");
	}
	else if(first->link==NULL)
	{
		P("\nDeleted element is %d\n",first->data);
		free(first);
		first=NULL;
	}
	else
	{
		x=first;
		P("\nDeleted element is %d\n",first->data);
		first=first->link;
		free(x);
	}
}
void del_rear()
{
	struct node *temp;
	if(first==NULL)
	{
		P("\nDeletion not possible!!\n");
	}
	else if(first->link==NULL)
	{
		P("\nDeleted element is %d\n",first->data);
		free(first);
		first=NULL;
	}
	else
	{
		temp=first;
		while(temp->link->link!=NULL)
		{
			temp=temp->link;
		}
		P("Deleted element is %d\n",temp->link->data);
		free(temp->link);
		temp->link=NULL;
	}
}
void display()
{
	struct node *temp;
	if(first==NULL)
	{
		P("\nDisplay not possible!!\n");
	}
	else if(first->link==NULL)
	{
		P("%d\t",first->data);
	}
	else
	{
		temp=first;
		while(temp!=NULL)
		{
			P("%d\t",temp->data);
			temp=temp->link;
		}P("\n");
	}
}

void main()
{
	int ch;
	clrscr();

   for( ; ; )
   {
	P("\nPress 1 to insert at front.");
	P("\nPress 2 to insert at rear.");
	P("\nPress 3 to delete at front.");
	P("\nPress 4 to delete at rear.");
	P("\nPress 5 to display.");
	P("\nPress 6 to stop.");
	P("\nEnter your choice:");
	scanf("%d",&ch);
	P("\n");

	switch(ch)
	{
		case 1:insert_front();
			 break;

		case 2:insert_rear();
			 break;

		case 3:del_front();
			 break;

		case 4:del_rear();
			 break;

		case 5:display();
			 break;

		default:exit(0);
	}
   }
}