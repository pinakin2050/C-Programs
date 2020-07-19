#include<stdio.h>
#include<conio.h>
#include<process.h>

struct node
{
	int emp_number;
	char *emp_name;
	double emp_salary;
	struct node *link;
}*head=NULL;

void add_employee(int *number)
{
	struct node *p,*temp;
	char *name;
	double salary;

	p=(struct node *)malloc(sizeof(struct node));

	printf("\nEnter Name of the employee:");
	gets(name);
	p->emp_name=malloc(strlen(name)+1);
	strcpy(p->emp_name,name);

	printf("Enter salary of the employee:");
	scanf("%lf",&salary);
	p->emp_salary=salary;
	p->emp_number=(*number)++;
	p->link=NULL;

       if(head==NULL) //checking whether linked list exists or not
		head=p; //if doesn't exist then make p the head node
       else
       {
		temp=head;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=p;
       }
}

struct node* remove_employee()
{       int num;
	struct node *temp,*remover,*x;
	if(head==NULL)
	{
		printf("\nLinked list doesn't exist! Please create first.\n");
		return head;
	}
	else
	{
		printf("\nEnter Employee Number:");
		scanf("%d",&num);

		if(head->emp_number==num)
		{
			printf("\nSuccessfully deleted the record of employee whose number is %d\n",num);
			temp=head;
			head=head->link;
			free(temp);
			temp=NULL;
			return head;
		}
		else
		{
			temp=head;
			while(temp->link->emp_number!=num)
			{
				if(temp->link->link!=NULL)
					temp=temp->link;
				else
				{
					printf("\nError!!Employee with the inputed number doesn't exist!\n");
					return head;
				}
			}
			remover=temp->link;
			x=temp->link->link;
			temp->link=x;
			free(remover);
			remover=NULL;
			printf("\nSuccessfully deleted the record of employee whose number is %d\n",num);
			return head;
		}
	}
}

void display_employee()
{
	struct node *temp;
	if(head==NULL)
		printf("\nNo record found!!!\n");
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("\nEmployee's Number:%d\n",temp->emp_number);
			printf("Employee's Name:%s",temp->emp_name);
			printf("\nEmployee's Salary:%.0lf\n\n",temp->emp_salary);
			temp=temp->link;
		}
	}
}



void main()
{
	int choice;
	char *dummy;
	int number=1; //starting id with one.It will be incremented by 1 for every new employee.;
	clrscr();
	while(1)
	{
		printf("\nPress 1 to add an employee.\n");
		printf("Press 2 to remove an employee.\n");
		printf("Press 3 to display the detail of an employee.\n");
		printf("Press 4 to exit.\n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		gets(dummy); //to catch enter

		switch(choice)
		{
			case 1: add_employee(&number);
				break;

			case 2: remove_employee();
				break;

			case 3: display_employee();
				break;

			default: exit(0);
		}
	}
}