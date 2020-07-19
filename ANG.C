#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define P printf
void main()
{
  char *s1,*s2;
  int i,j,cnt=0;
  clrscr();
  P("Enter First string:");
  scanf("%[^\n]s",&s1);
  P("\nEnter Second string:");
  scanf("%[^\n]s",&s2);

  if(strlen(s1)==strlen(s2))
  {
    for(i=0;i<strlen(s1);i++)
    {
       for(j=0;j<strlen(s2);j++)
       {
	  if(s1[i]==s2[j])
	  {
	    cnt++;
	    break;
	  }
       }
    }

    if(cnt==strlen(s1))
     P("\nStrings are anagram");
    else
    P("\nStrings are not!");
  }
  else
    P("\nStrings are not anagram!");
  getch();

}