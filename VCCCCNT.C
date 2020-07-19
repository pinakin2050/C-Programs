#include<stdio.h>
#define P printf
void count();
char str[20];
void main()
{
	clrscr();
	P("Enter your string:");
	scanf("%[^\n]s",str);
	count();
	getch();
}
void count()
{
	int i=0,vc=0,cc=0,sc=0;
	while(str[i]!='\0')
	{
		if((str[i]>='A'&& str[i]<='Z')||(str[i]>='a'&& str[i]<='z'))
		{
			if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
			{
				++vc;
			}
			else
			{
				++cc;
			}
		}
		else
		{
			++sc;
		}
		++i;
	}
	P("Total Vowels:%d\n",vc);
	P("Total Consonents:%d\n",cc);
	P("Total Special Symbols:%d\n",sc);

}