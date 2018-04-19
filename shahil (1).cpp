#include<stdio.h>
#include<conio.h>
int value(int val)
{
	if(val<0)
	{
		val= -1*val;
	}
	return val;
}
int main()
{
	int d=0;
	int i;
	printf("Enter cylinder where it is currently serving\n");
	int c;
	scanf("%d",&c);
	printf("Enter number of cylinders waiting\n");
	int n;
	scanf("%d",&n);
	int q[n+1];
	q[0]=c;
	printf("Enter waiting cylinders   \n");
	for(i=1;i<sizeof(q)/4;i++)
	{
		scanf("%d",&q[i]);
	}
	for(i= 0;i<(sizeof(q)/4)-1; i++)
	{
		d=d+value(q[i]-q[i+1]);
	}
	printf("\nThe first come first served (FCFS) schedule is :\n");
	for(i =0;i<sizeof(q)/4;i++)
	{
		printf("%d \n",q[i]);
	}
	printf("\nThe total seek distance(in cylinders) is: %d\n",d);
	
}
