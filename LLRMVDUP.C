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

struct node* remove_dup(struct node *first)
{
	struct node *temp1,*temp2,*temp3;
	if(first==NULL)
		pf("Linked list doesn't exist!!\n");
	else if(first->link==NULL)
		return first;
	else
	{
		temp1=first;
		while(temp1!=NULL)
		{
			temp2=temp1;
			temp3=temp1->link;
			while(temp3!=NULL)
			{
				if(temp1->data==temp3->data)
				{
					temp2->link=temp3->link;
					free(temp3);
					temp3=temp2->link;
				}
				else
				{
					temp2=temp3;
					temp3=temp3->link;
				}
			}
			temp1=temp1->link;
		}
	}
	return first;
}
void main()
{
	struct node *first=NULL;
	clrscr();
	pf("Enter linked list:\n");
	first=create(first);
	pf("The linked list is:\n");
	display(first);
	first=remove_dup(first);
	pf("\nLinked list after removing duplicates:\n");
	display(first);
	getch();
}