#include<stdio.h>
 
void main()
{
    int burstime[20];
    int p[20];
    int waitingtime[20];
    int turnaroundtime[20];
    int i,j,n;
    int total=0;
    int pos,temp;
    float avg_wt;
    float avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&burstime[i]);
        p[i]=i+1;           
    }
 
    
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burstime[j]<burstime[pos])
                pos=j;
        }
 
        temp=burstime[i];
        burstime[i]=burstime[pos];
        burstime[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    waitingtime[0]=0;           
 
   
    for(i=1;i<n;i++)
    {
        waitingtime[i]=0;
        for(j=0;j<i;j++)
            waitingtime[i]+=burstime[j];
 
        total+=waitingtime[i];
    }
 
    avg_wt=(float)total/n;      
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turnaroundtime[i]=burstime[i]+waitingtime[i];     
        total+=turnaroundtime[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],burstime[i],waitingtime[i],turnaroundtime[i]);
    }
 
    avg_tat=(float)total/n;     
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}