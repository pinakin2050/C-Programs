#include<stdio.h>
#define pf printf
#define sf scanf

struct node
{
	struct node *llink;
	int data;
	struct node *rlink;
};

struct node* create(struct node *root)
{
	struct node *temp1,*temp2,*p;
	p=(struct node*)malloc(sizeof(struct node));
	p->llink=NULL;
	p->rlink=NULL;
	pf("\nEnter element:");
	sf("%d",&p->data);

	if(root==NULL)
		root=p;
	else
	{
		temp1=NULL;
		temp2=root;
		while(temp2!=NULL)
		{
			if(p->data<temp2->data)
			{
				temp1=temp2;
				temp2=temp2->llink;
			}
			else
			{
				temp1=temp2;
				temp2=temp2->rlink;
			}
		}
		if(p->data<temp1->data)
			temp1->llink=p;
		else
			temp1->rlink=p;
	}
	return root;
}

void min(struct node *root)
{
	struct node *temp1,*temp2;
	if(root==NULL)
		pf("\nTree doesn't exist!!!!!");
	else
	{
		temp1=NULL;
		temp2=root;
		while(temp2!=NULL)
		{
			temp1=temp2;
			temp2=temp2->llink;
		}
		pf("Minimum element is %d.\n",temp1->data);
	}
}

void max(struct node *root)
{
	struct node *temp1,*temp2;
	if(root==NULL)
		pf("\nTree doesn't exist!!!!!");
	else
	{
		temp1=NULL;
		temp2=root;
		while(temp2!=NULL)
		{
			temp1=temp2;
			temp2=temp2->rlink;
		}
		pf("Maximum element is %d.\n",temp1->data);
	}
}

void main()
{
	struct node *root=NULL;
	int ch=0;
	clrscr();
	while(1)
	{
		pf("\nPress 1 to create tree.\n");
		pf("Press 2 to find Min element in the tree\n");
		pf("Press 3 to find Max element in the tree\n");
		pf("Press 4 to Stop!\n");
		pf("Enter your choice:");
		sf("%d",&ch);

		switch(ch)
		{
			case 1: root=create(root);
				break;

			case 2: min(root);
				break;

			case 3: max(root);
				break;

			default:exit(0);
		}
	}
}