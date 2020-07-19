#include<stdio.h>
#define P printf
void swap(int *,int *);
void main()
{
	int a,b;
	clrscr();
	P("Enter two numbers:");
	scanf("%d %d",&a,&b);
	P("Values before swapping\n");
	P("a=%d\tb=%d",a,b);
	swap(&a,&b);
	P("\nValues after swapping\n");
	P("a=%d\tb=%d",a,b);
	getch();
}
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}