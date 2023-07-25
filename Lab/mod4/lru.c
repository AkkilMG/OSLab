#include<stdio.h>
#include<limits.h>

int checkhit(int incomingPage, int queue[], int occupied){
    for(int i=0;i<occupied;i++){
        if(incomingPage==queue[i])
        return 1;
    }
    return 0;
}

void printFrame(int queue[],int occupied){
    for(int i=0;i<occupied;i++)
    printf("%d\t",queue[i]);
}

void main(){
    /*output:
    Page    Frame1  Frame2  Frame3
    1:      1
    2:      1       2
    3:      1       2       3
    2:      1       2       3
    1:      1       2       3
    5:      1       2       5
    2:      1       2       5
    1:      1       2       5
    6:      1       2       6
    2:      1       2       6
    5:      5       2       6
    6:      5       2       6
    3:      5       3       6
    1:      1       3       6
    3:      1       3       6
    Page Fault: 8
    */
    int incomingStream[]={1,2,3,2,1,5,2,1,6,2,5,6,3,1,3};
    int n=sizeof(incomingStream)/sizeof(incomingStream[0]);
    int frames=3,queue[n],distance[n],occupied=0,pagefault=0;
    printf("Page\tFrame1\tFrame2\tFrame3\n");
    for(int i=0;i<n;i++){
        printf("%d:\t",incomingStream[i]);
        if(checkhit(incomingStream[i],queue,occupied)) {
            printFrame(queue,occupied);
        } else if (occupied<frames){
            queue[occupied]=incomingStream[i];
            pagefault++;
            occupied++;
            printFrame(queue, occupied);
        } else {
            int max=INT_MIN,index;
            for(int j=0;j<frames;j++){
                distance[j]=0;
                for(int k=i-1;k>=0;k--){
                    ++distance[j];
                    if(queue[j]==incomingStream[k])
                    break;
                }
                if(distance[j]>max){
                    max=distance[j];
                    index=j;
                }
            }
            queue[index]=incomingStream[i];
            printFrame(queue,occupied);
            pagefault++;
        }
        printf("\n");
    }
    printf("Page Fault: %d\n",pagefault);
}