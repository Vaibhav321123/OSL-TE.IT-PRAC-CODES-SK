#include<stdio.h>
#include<pthread.h>
#include<unistd.h> //library for the sleep function
#include<stdlib.h>
pthread_mutex_t wr,mutex;
int a=10, readcount=0;

void * reader(void *arg)
{
    long int num;
    num=(long int) arg;
    pthread_mutex_lock(&mutex);
    readcount++;
    pthread_mutex_unlock(&mutex);

    if(readcount==1)
        pthread_mutex_lock(&wr);
    printf("\n Reader %ld is in critical section",num);
    printf("\nReader %ld is reading data %d",num,a);
    sleep(1);
        pthread_mutex_lock(&mutex);
    readcount--;
        pthread_mutex_unlock(&mutex);
    if(readcount==0)
       pthread_mutex_unlock(&wr);
    printf("\n Reader %ld left critical section",num);
}

void * writer(void *arg)
{
    long int num;
    num=(long int)arg;
    pthread_mutex_lock(&wr);
    printf("\n Writer %ld is in critical section",num);
    printf("\n Writer %ld have written data as %d",num,++a);
    sleep(1);
    pthread_mutex_unlock(&wr);
    printf("\n Writer %ld left critical section",num);
}

int main()
{
    pthread_t r[10],w[10];
    long int i,j;
    int nor,now;

    pthread_mutex_init(&wr,NULL);
    pthread_mutex_init(&mutex,NULL);
    printf("\nEnter number of readers and writers");
    scanf("%d %d",&nor,&now);
    for(i=0;i<nor;i++)
        pthread_create(&r[i],NULL,reader,(void *)i);
    for(j=0;j<now;j++)
        pthread_create(&w[j],NULL,writer,(void *)j);
    for(i=0;i<nor;i++)
        pthread_join(r[i],NULL);
    for(j=0;j<now;j++)
        pthread_join(w[j],NULL);
    return 0;   
}