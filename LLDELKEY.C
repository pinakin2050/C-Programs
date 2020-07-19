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

struct node* delkey(struct node *first,int key)
{
	struct node *temp,*prev;
	int cnt=0;
	if(first==NULL)
	{
		pf("Deletion not possible!!\n");
	}
	else if(first->data==key)
	{
		temp=first;
		first=first->link;
		free(temp);
		temp=NULL;
	}
	else
	{
		prev=NULL;
		temp=first;
		while(temp!=NULL)
		{
			if(temp->data==key)
			{
				prev->link=temp->link;
				free(temp);
				temp=prev->link;
				++cnt;
			}
			else
			{
				prev=temp;
				temp=temp->link;
			}
		}
	}

	if(cnt==0)
	  pf("Key value not found!!\n");
	else
	  pf("Key value deleted %d times",cnt);

	return first;
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
	delkey(first,key);
	pf("\nLinked list after deletion of key:\n");
	display(first);
	getch();
}