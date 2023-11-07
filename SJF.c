#include<stdio.h>
struct proc
{
 char nm[3];
 int at,bt,wt,tat,remain_bt;
 int flag,finish,cntinue,consume;
};


void main()
{
struct proc p[10],temp,tmp[10];
int n,i,j,k,cur;
int avgwt=0,avgtat=0;
int total=0,total_consume=0;

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
	p[i].cntinue=0;
}
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
		else
		if(p[i].at==p[j].at)
		if(p[i].bt>p[j].bt)
		{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
		}
	}
}
cur=0;
p[cur].wt=0;
p[cur].tat=0;
total_consume=0;
while(total_consume<total)
{
	if(p[cur].remain_bt==0)
	{
		for(i=0;i<n;i++)
		{
			if(p[cur].remain_bt==0)
				cur=(cur+1)%n;
		else
			break;
		}
	}
	else
	{
		p[cur].remain_bt--;
		p[cur].consume++;
		total_consume++;
	}

	for(i=0;i<n;i++)
	{
		if(p[i].at<=total_consume && p[i].remain_bt>0)
		{
			if(p[i].remain_bt<p[cur].remain_bt)
			{
				cur=i;
			}
			else if(cur==i)
			{
				p[cur].cntinue=1;
			}

		}
	}

	if(p[cur].cntinue==1)
	{
		p[cur].wt=p[cur].wt;
	}
	else
		p[cur].wt=total_consume-p[cur].consume;
	p[cur].tat=total_consume;
	for(i=0;i<n;i++)
		p[i].cntinue=0;
}

printf("\nProcess\tA.T.\tB.T\tW.T\tT.A.T\n");
printf("----------------------------------------------------------------\n");
for(i=0;i<n;i++)
{
printf("\n");
printf("%s\t%d\t%d\t%d\t%d",p[i].nm,p[i].at,p[i].bt,(p[i].wt-p[i].at),(p[i].tat-p[i].at));
avgwt+=(p[i].wt-p[i].at);
avgtat+=(p[i].tat-p[i].at);
}
printf("\nAverage wait time=%d",(avgwt/n));
printf("\nAverage turn around time=%d",(avgtat/n));

}

/*
arnavi@rockstar:~/scheduling$ gcc final_sjf_pre.c
arnavi@rockstar:~/scheduling$ ./a.out
Enter no. of processes tobe entered:4
Enter process information:
Enter process name:p1
Enter arrival time:0
Enter process burst time:4 

Enter process name:p2
Enter arrival time:1
Enter process burst time:2

Enter process name:p3
Enter arrival time:2
Enter process burst time:3

Enter process name:p4
Enter arrival time:4
Enter process burst time:5

Process	A.T.	B.T	W.T	T.A.T
----------------------------------------------------------------

p1	0	4	5	9
p2	1	2	0	2
p3	2	3	1	4
p4	4	5	5	10
Average wait time=2
Average turn around time=6
*/
