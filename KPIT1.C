#include<stdio.h>
#include<conio.h>
#define pf printf
char* check(int num)
{
	int i,cnt=0;
	char *result;
	if(num<0)
	{
	 result="Not a positive num";
	 return result;
	}
	else if(num==0)
	{
	  result="Zero";
	  return result;
	}
	else
	{
		for(i=2;i<=num/2;i++)
		{
			if(num%i==0)
			{
				if(i*i==num)
				{
					cnt++;
				}
			}
		}
	}
	if(cnt==1)
	{
		result="A square number";
		return result;
	 }
	else
	{
		result="not square number";
		return result;
	}
}

int main()
{       int num;
	char *res;
	clrscr();
	pf("Enter num:");
	scanf("%d",&num);
	res=check(num);
	pf(res);
	getch();
	return 0;
}