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

void lincmp(struct node *first1,struct node *first2)
{
	struct node *temp1,*temp2;
	if(first1==NULL && first2==NULL)
		pf("\nLinked lists are equal.");
	else if(first1->link==NULL && first2->link==NULL)
	{
		if(first1->data==first2->data)
			pf("\nLinked lists are equal.");
		else
			pf("\nLinked lists are unequal.");
	}
	else
	{
		temp1=first1;
		temp2=first2;
		while(temp1!=NULL && temp2!=NULL)
		{
			if(temp1->data!=temp2->data)
				pf("\nLinked lists are unequal.");
			else
			{
				temp1=temp1->link;
				temp2=temp2->link;
			}
		}
		if((temp1==NULL && temp2!=NULL)||(temp1!=NULL && temp2==NULL))
			pf("\nLinked lists are unequal.");
		else
			pf("\nLinked lists are equal.");
	}
}
void main()
{
	struct node *first1=NULL,*first2=NULL;
	clrscr();
	pf("Enter first linked list:\n");
	first1=create(first1);
	pf("\n");
	pf("Enter second linked list:\n");
	first2=create(first2);
	pf("The linked list are:\n");
	display(first1);
	pf("\n");
	display(first2);
	lincmp(first1,first2);
	getch();
}