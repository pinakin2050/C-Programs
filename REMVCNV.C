#include<stdio.h>
#define P printf

void main()
{
	char str[20];
	int i=0,ch=0;
	clrscr();
	P("Enter your string:");
	scanf("%[^\n]s",str);
	P("Press 1 to remove vowels\n");
	P("Press 2 to remove conconents\n");
	P("Press 3 to remove special symbols\n");
	P("Enter your choice:\n");
	scanf("%d",&ch);

	P("String after removing vowels:%s\n",str);
	getch();
}

void removeVowels()
{
	int i=0;
	while(str[i]!='\0')
	{
		if((str[i]>='A'&& str[i]<='Z')||(str[i]>='a'&& str[i]<='z'))
		{
			if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
			{
				str[i]=' ';
			}
		}
		++i;
	}
}
void removeConsonents()
{
	int i=0;
	while(str[i]!='\0')
	{
		if((str[i]>='A'&& str[i]<='Z')||(str[i]>='a'&& str[i]<='z'))
		{
			if(str[i]!='A'||str[i]!='E'||str[i]!='I'||str[i]!='O'||str[i]!='U'||str[i]!='a'||str[i]!='e'||str[i]!='i'||str[i]!='o'||str[i]!='u')
			{
				str[i]=' ';
			}
		}
		++i;
	}
}

void removeVowels()
{
	int i=0;
	while(str[i]!='\0')
	{
		if(!(str[i]>='A'&& str[i]<='Z')||(str[i]>='a'&& str[i]<='z'))
		{
			str[i]=' ';
		}
		++i;
	}
}