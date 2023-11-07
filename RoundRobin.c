#include<stdio.h>

struct proc
{
 char nm[3];
 int at,bt,wt,tat,remain_bt;
 int flag,finish,consume;
};

void main()
{
struct proc p[10],temp,tmp[10];
int n,i,j,avgwt=0,avgtat=0,quantum=1;
int total_consume=0,total=0,cur,max,prev;

printf("Enter no. of processes to be entered:");
scanf("%d",&n);
printf("Enter process information:");
for(i=0;i<n;i++)
{
	printf("\nEnter process name:");
	scanf("%s",p[i].nm);
	printf("Enter arrival time:");
	scanf("%d",&p[i].at);
	printf("Enter process burst time:");
	scanf("%d",&p[i].bt);
	p[i].remain_bt=p[i].bt;
	p[i].consume=0;
	total+=p[i].bt;
	p[i].finish=0;
}
printf("\nEnter time quantum:");
scanf("%d",&quantum);

for(i=0;i<n;i++)
{
	for(j=i+1;j<n;j++)
	{
		if(p[i].at>p[j].at)
		{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
		}
	}
}

prev=0;
while(total_consume<total)
{
for(i=0;i<n;i++)
{
	if(p[i].remain_bt==0)
		p[i].finish=1;
	else
	{
		if(prev==i)
		{
			p[i].wt=p[i].wt;
		}
		else
		{
			p[i].wt=total_consume-p[i].consume;
		}
		prev=i;
		if(p[i].remain_bt>quantum)
		{
			p[i].remain_bt-=quantum;
			p[i].consume+=quantum;
			total_consume+=quantum;
		}
		else
		{
			p[i].consume+=p[i].remain_bt;
			total_consume+=p[i].remain_bt;
			p[i].remain_bt=0;
		}
		p[i].tat=total_consume;
	}
}
}
printf("\nProcess\tA.T.\tB.T\tW.T\tT.A.T\n");
printf("----------------------------------------------------------------\n");

for(i=0;i<n;i++)
{
	printf("\n%s\t%d\t%d\t%d\t%d",p[i].nm,p[i].at,p[i].bt,(p[i].wt-p[i].at),(p[i].tat-p[i].at));
	avgwt+=(p[i].wt-p[i].at);
	avgtat+=(p[i].tat-p[i].at);
}

printf("\nAverage wait time=%d",(avgwt/n));
printf("\nAverage turn around time=%d",(avgtat/n));

}

