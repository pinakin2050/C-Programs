#include<stdio.h>
#define P printf
char str[10];
int i;
void toLower();
void toUpper();
void main()
{
	int ch;
	clrscr();
	while(1)
	{
		P("Press 1 to convert uppercase string into lowercase.\n");
		P("Press 2 to convert lowercase string into uppercase.\n");
		P("Press 0 to exit!!\n");
		P("Please enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: toLower();
				break;

			case 2: toUpper();
				break;

			default: exit(0);
		}
	}
}

void toLower()
{
	P("Enter a string in Uppercase:");
	scanf("%s",str);
	i=0;
	while(str[i]!='\0')
	{
		str[i]=str[i]+32;
		i++;
	}
	P("%s\n\n",str);
}

void toUpper()
{
	P("Enter a string in Lowercase:");
	scanf("%s",str);
	i=0;
	while(str[i]!='\0')
	{
		str[i]=str[i]-32;
		i++;
	}
	P("%s\n\n",str);
}
