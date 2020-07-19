#include<stdio.h>
#include<conio.h>
#define pf printf

struct result
{
  int nums[100];
};

int cnt=0;

struct result getEvenOddNumber(int ip1,int ip2)
{       int i,j=0;
	struct result s;
	if(ip1<=0 || ip2<=0)
	{
	     if(ip1>ip2)
	     {
		s.nums[0]=ip2;
		s.nums[1]=ip1;
		cnt+=2;
	     }
	     else
	     {
		s.nums[0]=ip1;
		s.nums[1]=ip2;
		cnt+=2;
	     }

	}
	else if(ip1>ip2)
	{
		for(i=ip2;i<ip1;i++)
		{
		  if(i%2==0)
		  {
		    s.nums[j]=i;
		    j++;
		    cnt++;
		  }
		}
	}
	else if(ip2>ip1)
	{
		for(i=ip1;i<ip2;i++)
		{
		  if(i%2!=0)
		  {
		     s.nums[j]=i;
		     j++;
		     cnt++;
		  }
		}
	}
	else  //returning the given number if both numbers are same
	{
		s.nums[j]=ip1;
		     j++;
		     cnt++;

	}
	return s;
}

int main()
{       int n1,n2,i;
	struct result res;
	clrscr();
	pf("Enter num1:");
	scanf("%d",&n1);
	pf("Enter num2:");
	scanf("%d",&n2);
	res=getEvenOddNumber(n1,n2);
	for(i=0;i<cnt;i++)
	{
		pf("%d ",res.nums[i]);
	}
	getch();
	return 0;
}