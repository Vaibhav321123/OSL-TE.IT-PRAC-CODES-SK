#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int track,no_req,head,head1,distance;
int disc_req[100],finish[100];

void input()
{
    int i;
    printf("Enter Total number of tracks");
    scanf("%d",&track);
    printf("Enter total number of disc requests");
    scanf("%d",&no_req);
    printf("\n Enter disc requests in FCFS order");
    for(i=0;i<no_req;i++)
    {
        scanf("%d",&disc_req[i]);
        
    }
    printf("\n Enter current head position");
    scanf("%d",&head1);
}

void sstf()
{
    int min,diff;
    int pending=no_req;
    int i,distance=0,index;
    head=head1;
  
    for(i=0;i<no_req;i++)
    {
        finish[i]=0;
    }

    printf("\n%d=>",head);
    
    while(pending>0)
    {   min=9999;
    
        for(i=0;i<no_req;i++)
        {
            diff=abs(head-disc_req[i]);
            if(finish[i]==0 && diff<min)
            {
                min=diff;
                index=i;
            }
        }
        finish[index]=1;
        distance+=abs(head-disc_req[index]);
        head=disc_req[index];
        pending--;
        printf("%d=>",head);
    }
    printf("End");
    printf("\n\n Total Distance Traversed=%d",distance);
}

int main()
{
    input();
    sstf();
    return 0;
}