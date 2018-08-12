
#include<stdio.h>
 
void main()
{
  while (1){
  int input;
  printf("for fcfs scheduler enter 1 \n");
  printf("for sjf nonpreempative scheduler enter 2 \n");
  printf("for Priority nonpreempative scheduler enter 3 \n");
  printf("for Priority preempative scheduler enter 4 \n");
  printf("round robin scheduler enter 5 \n");
  scanf("%d" ,&input);
  if (input == 2){
    int bt[100],p[100],wt[100],tat[100],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
    printf ("\t gantt chart \n");
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
 }
  if (input == 1){
   int n,bt[100],wt[100],tat[100],avwt=0,avtat=0,i,j;
    printf("Enter total number of processes ");
    scanf("%d",&n);
 
    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
 
    wt[0]=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    printf ("\t gantt chart \n");
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);
 }
  if (input == 3){
   int bt[100],p[100],wt[100],tat[100],pr[100],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;    //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
    printf ("\t gantt chart \n");
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 }
  if (input == 5){
   int k,j,q,i,n,ts,temp;
     int aw;                      float awt;
     int bt[10],wt[10],te[10],rt[10],at[10];j=0; 
     printf("enter number of process :\t");
     scanf("%d",&n);
    printf("\n enter brust time and arriavl time , please consider that process 1 arrival time is 0 :) \n");
    for(i=0;i<n;i++)
      {
          printf("P%d  \nbrust time ",i+1);
          scanf("%d",&bt[i]);
          printf("ariavl time   :  ");
          scanf("%d",&at[i]);
          te[i]=0;     wt[i]=0;
      }
    for(i=0;i<n;i++)
      {
        for(j=i+1;j<n;j++)
         {
             if(at[i]>at[j])
               {
                    temp=at[i];                                          //sorting according to arrival time
                    at[i]=at[j];
                    at[j]=temp;
                    temp=bt[i];
                    bt[i]=bt[j];
                    bt[j]=temp;
              }
         }
     }
    printf("\n enter time slice\t");
    scanf("%d",&ts); q=0;   
    printf("\nprocess      :")  ;
    for(i=0;i<n;i++)
     {
       printf("  %d",i+1);
      }
    printf("\nBrust time   :");
    for(i=0;i<n;i++)
       {
         printf("  %d",bt[i]); rt[i]=bt[i];
        }
    printf("\nArrival time :");
    for(i=0;i<n;i++)
      {
          printf("  %d",at[i]);
      }
    printf("\n Gaint chart \n");
    j=0;

    while(j<=n)
       {
          j++;
          for(i=0;i<n;i++)
            {
              if(rt[i]==0)  continue;
                   if(rt[i]>ts)
                     {
                        printf("\n %d\t P%d",q,i+1);
                        q=q+ts;
                        rt[i]=rt[i]-ts;
                        te[i]=te[i]+1;
                     }
                  else
                    {
                       printf("\n %d\t P%d",q,i+1);
                       wt[i]=q-te[i]*ts;
                       q=q+rt[i]; 
                       rt[i]=rt[i]-rt[i];
                    }
            }
       }                                   //end of while     
    awt=0;
    printf("\n Process   Waitnig time");
    for(i=0;i<n;i++)
       {
                       wt[i]=wt[i]-at[i];
                       printf("\n P%d      :   %d",i+1,wt[i]); awt=awt+wt[i];
        }
    aw=awt;
    printf("\ntotal waiting time %d",aw);
    printf("\n Avg wainting time %f ",awt/n);
 }
  if (input == 4) {
   int n;

printf("Enter the no. of processes: ");

scanf("%d",&n);

int id[n],bt[n],wt[n],tat[n],p[n],i,j,temp;

for(i=0;i<n;i++)

{

printf("Enter process %d id ( just enter %d :D ): ",i+1,i+1);

scanf("%d",&id[i]);

printf("Enter process %d burst time: ",i+1);

scanf("%d",&bt[i]);

printf("Enter process %d priority: ",i+1);

scanf("%d",&p[i]);

}

for(i=0;i<n;i++)

{

for(j=i+1;j<n;j++)

{

if(p[i]>p[j])

{

temp=p[i];

p[i]=p[j];

p[j]=temp;

temp=bt[i];

bt[i]=bt[j];

bt[j]=temp;

temp=id[i];

id[i]=id[j];

id[j]=temp;

}

}

wt[i]=0;

}

for(i=0;i<n;i++)

{

for(j=0;j<i;j++)

{

wt[i]=wt[i]+bt[j];

}

tat[i]=wt[i]+bt[i];

}

float avwt=0,avtat=0;
printf ("\t gantt chart \n");
printf("Process\tP\tBT\tWT\tTAT\n");

for(i=0;i<n;i++)

{

printf("P[%d]\t%d\t%d\t%d\t%d\n",id[i],p[i],bt[i],wt[i],tat[i]);

avwt=avwt+wt[i];

avtat=avtat+tat[i];

}

avwt=avwt/n;

avtat=avtat/n;

printf("Average Waiting Time: %f\n",avwt);

printf("\nAverage Turnaround Time: %f",avtat);
 }
   
}
}

