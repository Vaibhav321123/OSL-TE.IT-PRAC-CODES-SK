#include<stdio.h>
int n,nf;
int in[100];
int p[50];
int hit=0;
int i,j,k;
int pgfaultcnt=0;

void getData()
{
    printf("\nEnter length of page reference sequence:");
    scanf("%d",&n);
    printf("\nEnter the page reference sequence:");
    for(i=0; i<n; i++)
        scanf("%d",&in[i]);
    printf("\nEnter no of frames:");
    scanf("%d",&nf);
}

void initialize() //This function initializes the page fault counter (pgfaultcnt) to 0 
{
    pgfaultcnt=0;
    for(i=0; i<nf; i++)
        p[i]=9999; //This indicates that all pages are initially empty.
}

int isHit(int data) //checks if given data is present in table
{
    hit=0;
    for(j=0; j<nf; j++)
    {
        if(p[j]==data)
        {
            hit=1;
            break;
        }

    }

    return hit;
}

int getHitIndex(int data) //returns the index of  given page in table
{
    int hitind;
    for(k=0; k<nf; k++)
    {
        if(p[k]==data)
        {
            hitind=k;
            break;
        }
    }
    return hitind;
}

void dispPages() // displays contents of pages
{
    for (k=0; k<nf; k++)
    {
        if(p[k]!=9999)
            printf(" %d",p[k]);
    }

}

void dispPgFaultCnt() //This function displays the total number of page faults.
{
    printf("\nTotal no of page faults:%d",pgfaultcnt);
}
void lru()
{
    initialize();

    int least[50]; //used to store most recently used pages
    for(i=0; i<n; i++)
    {

        printf("\nFor %d :",in[i]);

        if(isHit(in[i])==0)
        {

            for(j=0; j<nf; j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i-1; k>=0; k--)
                {                    //same as optimal just k=i-1 because we are looking pages in past i.e backwards
                    if(pg==in[k])    //baki sagla same optimal sarkha
                    {
                        least[j]=k; //the oage is stored in least
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    least[j]=-9999;
            }
            int min=9999;
            int repindex;
            for(j=0; j<nf; j++)
            {
                if(least[j]<min)
                {
                    min=least[j];
                    repindex=j;
                }
            }
            p[repindex]=in[i];
            pgfaultcnt++;

            dispPages();
        }
        else
            printf("No page fault!");
    }
    dispPgFaultCnt();
}
int main()
{
    getData();
    lru();
    return 0;
}