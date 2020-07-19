#include<stdio.h>
#include<conio.h>
#define pf printf

void insert(int q[],int *rear,int item)
{
	q[++(*rear)]=item;
}

int delet(int q[],int *front)
{
	return q[(*front)++];
}


void display(int q[],int *front,int *rear)
{
	int i;
	for(i = *front;i <= *rear;i++)
	{
		pf("%d\t",q[i]);
	}
}

int main()
{
	int *q,ch,item,front=0,rear=-1,size;
	pf("Enter size of Queue:");
	scanf("%d",&size);
	q=(int *)malloc(sizeof(size));

	while(1)
	{
		pf("\nPress 1 to insert.\n");
		pf("Press 2 to delete.\n");
		pf("Press 3 to display.\n");
		pf("Press 4 to stop.\n");
		pf("Enter your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: if(rear==size-1)
					pf("\nInsertion failure!! Stack is full.\n");
				else
				{
					pf("\nEnter element to be inserted:");
					scanf("%d",&item);
					insert(q,&rear,item);
				}
				break;

			case 2: if(front>rear)
					pf("\nDeletion failure!! Stack is empty.\n");
				else
					pf("\nElement deleted is:%d\n",delet(q,&front));
				break;

			case 3: if(front>rear)
					pf("\nStack is empty!!!\n");
				else
				{
					pf("\nQueue Content:\n");
					display(q,&front,&rear);
				}
				break;

			case 4: exit(0);

			default: pf("\nInvalid choice!!! Please try again\n");
		}
	}
	getch();
	return 0;
}