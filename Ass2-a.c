#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void bass(int arr[30],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\n Ascending Order \n");
    for(i=0;i<n;i++)
        printf("\t%d",arr[i]);
    printf("\n\n\n");
}

int main()
{
    int arr[25], n, i, exitStatus, childPid;
    pid_t pid;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    pid = fork();
    if(pid == 0)
    {
        // sleep(50); //Here sleep is used to make sure that the parent process is completed first and thus a Orphan process is created
        printf("Child Process\n");
        printf("Process Id of Child: %d", getpid());
        bass(arr, n); //Array sorted using bubble sort.
        printf("Elements sorted\n");
        for(i=0;i<n;i++)
                printf("%d,",arr[i]);
        printf("\b");
        printf("\nparent process id=%d\n",getppid());
        // system("ps -e -o pid,stat"); //run this in terminal
    }
    else
    {
        sleep(5); //if we give sleep then the process would be in zombie state
        wait(NULL); //if we give wait then the process would not be in zombie state
        printf("\nparent process\n");
        printf("\nparent process id=%d\n",getpid());
        bass(arr,n);          
        printf("Elements Sorted Using Bubble Sort");
        printf("\n");
        for(i=0;i<n;i++)
            printf("%d,",arr[i]);
        printf("\n\n\n");
    }
}



/*
OUTPUT:
Enter the number of elements in the array: 5
Enter the array elements: 8 1 3 9 4
Child Process
Process Id of Child: 99094
 Ascending Order 
	1	3	4	8	9


Elements sorted
1,3,4,8,9,
parent process id=99091

parent process

parent process id=99091

 Ascending Order 
	1	3	4	8	9


Elements Sorted Using Bubble Sort
1,3,4,8,9,

99405 S   
96692 Ss  
96696 S   
99091 S+  
99094 Z+  
98992 Ss  
98995 S   
99096 R+
*/