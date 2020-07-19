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

char *revsentence(char *stack,char *s,int *top)
{
	char *rev;
	int i=0,j=0;

	while(s[i]!='\0')
	{
		while(s[i]!=' ' && s[i]!='\0')
		{
			push(stack,s[i],top);
			i++;
		}
		i++;

		while((*top)!=-1)
		{
			rev[j]=pop(stack,top);
			j++;
		}
		rev[j++]=' ';
	}
		rev[j]='\0';

	return rev;
}

void main()
{
	char *s,*stack,*revsen;
	int top=-1;
	clrscr();
	pf("Enter a sentence:");
	gets(s);
	revsen=revsentence(stack,s,&top);
	pf("%s",revsen);
	getch();
}