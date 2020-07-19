#include<stdio.h>
#define pf printf

void push(int s[],int *top,int item)
{
	s[++(*top)]=item;
}

int pop(int s[],int *top)
{
	return s[(*top)--];
}

void display(int s[],int *top)
{
	int i;
	for(i=*top;i>=0;i--)
		pf("%d\n",s[i]);
}

void main()
{
	int *s,ch,size,top=-1,item;
	clrscr();
	pf("Enter size of Stack:");
	scanf("%d",&size);
	s=(int *)malloc(sizeof(size));
	while(1)
	{
		pf("\nPress 1 to push.\n");
		pf("Press 2 to pop.\n");
		pf("Press 3 to display.\n");
		pf("Press 4 to stop.\n");
		pf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(top==size-1)
					pf("\nPush not possible!!\n");
				else
				{
					pf("\nEnter element to be pushed:");
					scanf("%d",&item);
					push(s,&top,item);
				}
				break;

			case 2: if(top==-1)
					pf("\nPop not possible!!!\n");
				else
					pf("\nElement poped is %d\n",pop(s,&top));
				break;

			case 3: if(top==-1)
					pf("\nStack is empty!!!\n");
				else
				{
					pf("\nStack content:\n");
					display(s,&top);
				}
				break;

			case 4: exit(0);

			default: pf("\nInvalid choice!!! Please try again.\n");

		}
	}
}