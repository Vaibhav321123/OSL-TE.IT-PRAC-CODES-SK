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
void optimal()
{
    initialize();
    int near[50]; //will be used to store index of next refernces
    for(i=0; i<n; i++)
    {

        printf("\nFor %d :",in[i]);

        if(isHit(in[i])==0) //checks if present in table
        {

            for(j=0; j<nf; j++) //searches for next reference to page from ref.string
            {
                int pg=p[j];
                int found=0;
                for(k=i; k<n; k++)
                {
                    if(pg==in[k])
                    {
                        near[j]=k; //stores in near array if found
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    near[j]=9999;
            }
            int max=-9999; //max used to store the index of next reference page that will be used the furthest away in the future
            int repindex; //used to store index of page to be replaced
            for(j=0; j<nf; j++)
            {                   //this loop is used to iterate over near so the farthest used page can be replaced
                if(near[j]>max)
                {
                    max=near[j];
                    repindex=j; //index of page to be replaced
                }
            }
            p[repindex]=in[i]; //page is replaced
            pgfaultcnt++;

            dispPages();
        }
        else
            printf("No page fault");
    }
    dispPgFaultCnt();
}
int main()
{
    getData();
    optimal();
    return 0;
}