#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define pf printf

char stack[100],expression[100],*revexpr,evaluation_stack[100];
int top=-1,top_e=-1;

void push(char stack[],int top,char item)
{
	stack[++(top)]=item;
}

char *pop(char stack[],int top)
{
	return stack[(top)--];
}

char *reverse(char stack[],char *revexpr,int top)
{       int j=0;
	while((top)!=-1)
	{
		revexpr[j]=*pop(stack,top);
		j++;
	}
	return revexpr;
}

int main()
{
	int item,ch,i,res=0;
	clrscr();
	pf("Enter a prefix expression:");
	scanf("%s",expression);

	i=0;
	while(expression[i]!='\0')
	{
		push(stack,top,expression[i]);
		i++;
	}

	revexpr=reverse(stack,revexpr,top);
	pf("%s\n",revexpr);

	i=0;
	while(revexpr[i]!='\0')
	{
		if(revexpr[i]!='+' && revexpr[i]!='*')
			push(evaluation_stack,top_e,revexpr[i]);
		i++;
	}
	// printing evaluated stack
	i=0;
	while(top_e!=-1)
	{
		pf("%c",pop(evaluation_stack,top_e));
		i++;
	}

	/*
	i=0;
	while(revexpr[i]!='\0')
	{
		switch(revexpr[i])
		{
			case '+': res=res+atoi(pop(evaluation_stack,&top_e))+atoi(pop(evaluation_stack,(&top_e)-1));
				  break;
		}
		i++;
	}
	pf("\n%d",res);
	*/
	getch();
	return 0;
}