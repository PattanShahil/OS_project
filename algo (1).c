#include<stdio.h>
main()
{
int n;
printf("Enter the number  of processes: ");
scanf("%d",&n);

int bursttime[n], waitingtime[n],turnaroundtime[n], p[n], c, i, temp;
for(c=0;c<n;c++)
{
printf("Enter process %d burst time: ",c+1);
scanf("%d",&bursttime[c]);
printf("Enter process %d priority: ",c+1);
scanf("%d",&p[c]);
}
for(c=0;c<n;c++)
{
for(i=c+1;i<n;i++)
{
if(p[c]>p[i])
{
temp=p[c];
p[c]=p[i];
p[i]=temp;

temp=bursttime[c];
bursttime[c]=bursttime[i];
bursttime[i]=temp;

}
}
waitingtime[c]=0;
}
for(c=0;c<n;c++)
{
for(i=0;i<c;i++)
{
waitingtime[c]=waitingtime[c]+bursttime[i];
}
turnaroundtime[c]=waitingtime[c]+bursttime[c];
}
float averagewt=0,averagetat=0;
printf("Process\tP\tbursttime\tWTime\tTATime\n");
for(c=0;c<n;c++)
{
printf("%d\t%d\t%d\t%d\n",p[c],bursttime[c],waitingtime[c],turnaroundtime[c]);
averagewt=averagewt+waitingtime[c];
averagetat=averagetat+turnaroundtime[c];
if(c==(n-1))
{
	int t=waitingtime[c]+turnaroundtime[c];
	printf("%d\t%d\t%d\t%d\t%d\n",0,0,0,t,t+5);
}
}

averagewt=averagewt/n;
averagetat=averagetat/n;
printf("Average Waiting Time: %f\n",averagewt);
printf("\nAverage Turnaround Time: %f",averagetat);
}

