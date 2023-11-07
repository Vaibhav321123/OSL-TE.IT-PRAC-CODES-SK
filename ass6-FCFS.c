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
void fcfs()
{
    initialize();
    for(i=0; i<n; i++)
    {
        printf("\nFor %d :",in[i]); // for iterating over reference string

        if(isHit(in[i])==0) //isHit() function returns 1 if the page is present else 0.
        {
                                 //as page is not presnt in table it enter in this condition
            for(k=0; k<nf-1; k++)
                p[k]=p[k+1]; //copies the contents of the next page frame into the current page frame.

            p[k]=in[i]; //copies page from reference string at last page frame
            pgfaultcnt++; // fault count incremented
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
    fcfs();
    return 0;
}