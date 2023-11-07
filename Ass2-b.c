MAIN:
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void bubbleSort(char arr[],int n)
{
    printf("\n Sorting Started \n");
     
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);

    printf("\nSorting Completed! \n");   
}

int main()
{
    int n = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    char arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf(" %c", &arr[i]);

    bubbleSort(arr, n);

    pid_t cpid = fork();
    

    if(cpid > 0)
    {
        printf("\n\n Parent is Running:\n ParentID: %d \n It's ID: %d \n",getppid(),getpid());
 
        printf("\n Parent is waiting for child to Complete! \n\n");
         
        wait(NULL);
  
        printf("\n\n Parent is Exiting!!\n"); 
    }
    else if(cpid == 0)
    {
        printf("\n\n Child is running:\n ParentID: %d \n It's ID: %d \n",getppid(),getpid());
        printf("\n\n Child Calling EXECV System Call:\n");

        char program[] = "./part2child";
        char *arguments[n + 2]; // +2 for the program name and NULL

        arguments[0] = program;
        for (int i = 0; i < n; i++)
        {
            arguments[i + 1] = (char *)malloc(2);
            sprintf(arguments[i + 1], "%c", arr[i]);
        }
        arguments[n + 1] = NULL;

        execv(program, arguments);
        perror("execv"); // Print error if execvp fails
        // exit(1);

        printf("\n\n Child EXECV Call Complete\n"); //Ideally this should not be printed
        printf("\n\n Child Execution Complete \n");
    }
    return 0;
}


CHILD:
#include <stdio.h>
#include<stdlib.h>
 
int main(int argc, char *argv[])
{ 
    /* argv[0] is the program name */
    if (argc <= 2) {
        printf("Usage: %s [number1] [number2] ... [numberN]\n", argv[0]);
        return 1;
    }
 
    // Printing Element in Reverse
    printf("\n Printing Element in Reverse:");
    for(int i = argc-1; i>0;i--)
    {
        printf("%c ", argv[i]);
    }
     
    printf("\n\n EXCEV task Completed \n");
    return 0;
}

/*
OUTPUT:

./Assignment2part2
Enter the size of the array: 5
Enter the elements of the array: 8 9 1 4 2

 Sorting Started 
1 2 4 8 9 
Sorting Completed! 


 Parent is Running:
 ParentID: 96696 
 It's ID: 97662 

 Parent is waiting for child to Complete! 



 Child is running:
 ParentID: 97662 
 It's ID: 97665 


 Child Calling EXECV System Call:

 Printing Element in Reverse:9 8 4 2 1 

 EXCEV task Completed 


 Parent is Exiting!!
*/
