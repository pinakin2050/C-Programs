#include<stdio.h>
#define pf printf

void push(char *stack,char item,int *top)
{
	stack[++(*top)]=item;
}

char pop(char *stack,int *top)
{
	return stack[(*top)--];
}

void strpal(char *stack,char *str,int *top)
{
	char *rev;
	int i=0;
	while(str[i]!='\0')
	{
		push(stack,str[i],top);
		i++;
	}

	i=0;
	while(*top!=-1)
	{
		rev[i]=pop(stack,top);
		i++;
	}

	if(strcmp(str,rev)==0)
		pf("Palindrome.");
	else
		pf("Not a palindrome.");
}

void main()
{
	char *stack,*str;
	int top=-1;
	clrscr();
	pf("Enter a string:");
	scanf("%s",str);
	strpal(stack,str,&top);
	getch();
}