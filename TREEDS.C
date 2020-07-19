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

void pre_order(struct node *root)
{       if(root!=NULL)
	{
		pf("%d\t",root->data);
		pre_order(root->llink);
		pre_order(root->rlink);
	}
}

void in_order(struct node *root)
{
	if(root!=NULL)
	{
		in_order(root->llink);
		pf("%d\t",root->data);
		in_order(root->rlink);
	}
}

void post_order(struct node *root)
{
	if(root!=NULL)
	{
		post_order(root->llink);
		post_order(root->rlink);
		pf("%d\t",root->data);
	}
}

void main()
{
	struct node *root=NULL;
	int ch=0;
	clrscr();
	while(1)
	{
		pf("\nPress 1 to create tree\n");
		pf("Press 2 for Pre-order traversal\n");
		pf("Press 3 for In-order traversal\n");
		pf("Press 4 for Post-order traversal\n");
		pf("Press 5 to stop\n");
		pf("Enter your choice:");
		sf("%d",&ch);

		switch(ch)
		{
			case 1:root=create(root);
			       break;

			case 2:pre_order(root);
			       break;

			case 3:in_order(root);
			       break;

			case 4:post_order(root);
			       break;

			default:exit(0);
		}
	}
}