#include<stdio.h>
#define pf printf

void push(char *stack,int *top,char item)
{
	stack[++(*top)]=item;
}

char pop(char *stack,int *top)
{
	return stack[(*top)--];
}

void reverse()
{
	int top=-1,i;
	char *stack,*str,*rev;
	pf("Enter a string:");
	scanf("%s",str); //to reverse a string
	//gets(str);  to reverse a sentence

	i=0;
	while(str[i]!='\0')
	{
		push(stack,&top,str[i]);
		i++;
	}

	i=0;
	while(top!=-1)
	{
		rev[i]=pop(stack,&top);
		i++;
	}
	pf("reversed string is %s",rev);

}
int main()
{
	clrscr();
	reverse();
	getch();
	return 0;
}