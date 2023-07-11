#include<stdio.h>
void Sorter(int priority[],int n,int processes[],int burst_time[],int arrival_time[],int key)
{
    for (int i = 0; i < n; i++)//sorting in priority
    {
        int first=i;
        for (int j = i+1; j < n; j++)
        {
            if (priority[j]>priority[first])
            {
                first=j;
            }
        }
        break;
        int temp=priority[i];
        priority[i]=priority[first];
        priority[first]=temp;
        
        temp=processes[i];
        processes[i]=processes[first];
        processes[first]=temp;

        temp=burst_time[i];
        burst_time[i]=burst_time[first];
        burst_time[first]=temp;

        temp=arrival_time[i];
        arrival_time[i]=arrival_time[first];
        arrival_time[first]=temp;
    }
}
void priority(int processes[],int n,int burst_time[],int arrival_time[],int priority[])
{
    int remaining_time[n],WT[n],TAT[n],total_WT=0,total_TAT=0,time=0,RT[n],flag[n],avg_RT=0;
    int completion_time[n];
    int all_processes_completed[n],idle=0;
    Sorter(priority,n,processes,burst_time,arrival_time,3);
    for (int i = 0; i < n; i++)//setting remaining time
    {
        remaining_time[i]=burst_time[i];
        RT[i]=0;
        flag[i]=0;
        completion_time[n]=0;
        all_processes_completed[i]=1;
    }
    while(1)
    {
        int x=time,check=0;
        for (int i = 0; i < n; i++)
        {
            if (remaining_time[i]>0&&arrival_time[i]<=time)//non-preemption process
            {
                if(flag[i]==0){
                    flag[i]=1;
                    RT[i]=time-arrival_time[i];
                    avg_RT+=RT[i];
                }
                time+=remaining_time[i];
                completion_time[i]=time;
                remaining_time[i]=0;
                all_processes_completed[i]=0;
            }
        }
        for (int i = 0; i < n; i++)//checking if all processes have finished executing
        {
            check+=all_processes_completed[i];
        }
        if (time==x&&check!=0)//checking for idle times
        {
            time++;
            idle++;
        }
        if (check==0)break;  
    }
    for (int i = 0; i < n; i++)//calculating times
    {
        TAT[i]=completion_time[i]-arrival_time[i];
        total_TAT+=TAT[i];
        WT[i]=TAT[i]-burst_time[i];
        total_WT+=WT[i];
    }
    printf("\nPriority algorithm\n");
    printf("Processes\tAT\tBT\tPriority\tWT\tTAT\tCT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t%d\t%d\t\t%d\t%d\t%d\t%d\n",processes[i],arrival_time[i],burst_time[i],priority[i],WT[i],TAT[i],completion_time[i],RT[i]);
    }
    printf("AVG waiting time: %2f\n",(float)total_WT/n);
    printf("AVG turnaround time: %2f\n",(float)total_TAT/n);
    printf("AVG Response time: %2f\n",(float)avg_RT/n);
    printf("Total Idle time: %d\n",idle);
    printf("\n");
}
void main() {
    /*
    Enter the number of processes: 3
    Enter the arrival time for process 1:
    12
    Enter the Burst time for processes 1:
    23
    Enter the priority for process 1:3
    Enter the arrival time for process 2:3
    Enter the Burst time for processes 2:3
    Enter the priority for process 2:2
    Enter the arrival time for process 3:2
    Enter the Burst time for processes 3:2
    Enter the priority for process 3:2

    Priority algorithm
    Processes       AT      BT      Priority        WT      TAT     CT      RT
    1               12      23      3               0       23      35      0
    2               3       3       2               1       4       7       1
    3               2       2       2               0       2       4       0
    AVG waiting time: 0.333333
    AVG turnaround time: 9.666667
    AVG Response time: 0.333333
    Total Idle time: 7
    */

    int n;
    int quantum;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int processes[n],burst_time[n],arrival_time[n],prioritylist[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time for process %d:",i+1);
        scanf("%d",&arrival_time[i]);
        printf("Enter the Burst time for processes %d:",i+1);
        scanf("%d",&burst_time[i]);
        printf("Enter the priority for process %d:",i+1);
        scanf("%d",&prioritylist[i]);
        processes[i]=i+1;
    }
    priority(processes,n,burst_time,arrival_time,prioritylist);
}

