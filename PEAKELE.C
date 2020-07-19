#include<stdio.h>
#include<conio.h>
#define P printf

void main()
{
	int a[10],i,j,n,cnt=0;
	clrscr();
	P("Enter total number of elements:");
	scanf("%d",&n);
	P("Enter array elements:\n");
	for(i=0;i<n;i++)
	{
	  scanf(" %d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
	      if(a[cnt]<a[i])
		cnt=i;
	}
	P("Index of Peak Element is %d",cnt+1);
	getch();
}
