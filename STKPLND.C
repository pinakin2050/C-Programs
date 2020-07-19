#include<stdio.h>
#include<string.h>
#define pf printf

void push(char *stack,int *top,char item)
{
	stack[++(*top)]=item;
}

char pop(char *stack,int *top)
{
	return stack[(*top)--];
}

char *reverse(char *stack,char *str,char *rev,int *top)
{
	int i=0;
	while(str[i]!='\0')
	{
		push(stack,top,str[i]);
		i++;
	}

	i=0;
	while(*top!=-1)
	{
		rev[i]=pop(stack,top);
		i++;
	}
	return rev;
}

int main()
{
	int top=-1,i;
	char *stack,*str,*rev;
	clrscr();
	pf("Enter a string:");
	scanf("%s",str); //to reverse a string
	//gets(str);  to reverse a sentence
	rev=reverse(stack,str,rev,&top);
	if(strcmp(str,rev)==0)
		pf("Palindrome.");
	else
		pf("Not a Palindrome.");
	getch();
	return 0;
}