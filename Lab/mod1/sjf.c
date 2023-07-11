#include<stdio.h>
void printer(int processes[],int n,int burst_time[],int arrival_time[]) {
    int WT[n],TAT[n],total_WT=0,total_TAT=0,completion_time[n],idle=0,RT[n];
    for (int i = 0; i < n; i++) {
        if(i==0) {
            WT[0]=0;
            completion_time[0]=burst_time[0]+arrival_time[0];
            TAT[0]=completion_time[0]-arrival_time[0];
            total_TAT=TAT[0];
            RT[0]=0;
            if(arrival_time[0]!=0) {
                idle=arrival_time[0];
            }
            continue;
        }
        if(completion_time[i-1]<arrival_time[i]) {
            completion_time[i]=arrival_time[i]+burst_time[i];
            idle+=(arrival_time[i]-completion_time[i-1]);
            RT[i]=0;
        } else {
            completion_time[i]=completion_time[i-1]+burst_time[i];
            RT[i]=completion_time[i-1]-arrival_time[i];
        }
        TAT[i]=completion_time[i]-arrival_time[i];
        total_TAT+=TAT[i];
        WT[i]=TAT[i]-burst_time[i];
        total_WT+=WT[i];
    }
    printf("Processes\tAT\tBT\tWT\tTAT\tCT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",processes[i],arrival_time[i],burst_time[i],WT[i],TAT[i],completion_time[i],RT[i]);
    }
    printf("AVG waiting time: %2f\n",(float)total_WT/n);
    printf("AVG turnaround time: %2f\n",(float)total_TAT/n);
    printf("Total Idle time: %d\n\n",idle);
}
void Sorter(int n,int processes[],int burst_time[],int arrival_time[])
{
    for (int i = 0; i < n; i++)//sorting in priority
    {
        int first=i;
        for (int j = i+1; j < n; j++) {
            if (burst_time[j]<burst_time[first]) {
                first=j;
            }
        }
        int temp=processes[i];
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
void sjf(int processes[],int n,int burst_time[],int arrival_time[]) {
    Sorter(n,processes,burst_time,arrival_time);
    printf("SJF algorithm\n");
    printer(processes,n,burst_time,arrival_time);
}
void main() {
    /*ouput
    Enter the number of processes: 4
    Enter the arrival time for process 1:2
    Enter the Burst time for processes 1:1
    Enter the arrival time for process 2:1
    Enter the Burst time for processes 2:5
    Enter the arrival time for process 3:4
    Enter the Burst time for processes 3:1
    Enter the arrival time for process 4:0
    Enter the Burst time for processes 4:6
    SJF agorithm
    Processes       AT      BT      WT      TAT     CT      RT
    1               2       1       0       1       3       0
    3               4       1       0       1       5       0
    2               1       5       4       9       10      4
    4               0       6       10      16      16      10
    AVG waiting time: 3.500000
    AVG turnaround time: 6.750000
    Total Idle time: 3
    */
    int n=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int processes[n],burst_time[n],arrival_time[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time for process %d:",i+1);
        scanf("%d",&arrival_time[i]);
        printf("Enter the Burst time for processes %d:",i+1);
        scanf("%d",&burst_time[i]);
        processes[i]=i+1;
    }
    sjf(processes,n,burst_time,arrival_time);
}