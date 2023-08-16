#include<stdio.h>
#include<stdlib.h>

int main() {
    /*Output:
    Enter the no of requests:
    7 
    Enter the request sequence
    82 170 43 140 24 16 190
    Enter the initial head position
    50
    Enter the total disk size
    200
    Enter the head movement direction for high 1 and for low 0
    1
    Sequence of request access:
    82 140 170 190 43 24 16 
    Total head movement is 332
    */
    int rq[100],i,j,n,total=0,initial,size,move;
    printf("Enter the no of requests:\n");
    scanf("%d",&n);
    printf("Enter the request sequence\n");
    for ( i = 0; i<n; i++){
        scanf("%d",&rq[i]);
    }
    printf("Enter the initial head position\n");
    scanf("%d",&initial);
    printf("Enter the total disk size\n");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d",&move);

    for ( i = 0; i < n; i++) {
       for ( j = 0;j < n-i-1; j++) {
            if(rq[j]>rq[j+1]) {
                int temp =rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
       }
    }
    int index;
    for ( i = 0; i < n; i++) {
        if(initial<rq[i]) {
            index=i;
            break;
        }
    }
    if(move==1) {
        printf("Sequence of request access:\n");
        for ( i = index; i < n; i++){
            printf("%d ",rq[i]);
            total=total+abs(rq[i]-initial);
            initial=rq[i];
        }
        total=total+abs(size-rq[i-1]-1);
        initial=size-1;
        for ( i = index-1; i >=0; i--){
            printf("%d ",rq[i]);
            total=total+abs(rq[i]-initial);
            initial=rq[i];
        }
    } else {
        printf("Sequence of request access:\n");
        for ( i = index-1; i >=0; i--) {
            printf("%d ",rq[i]);
            total=total+abs(rq[i]-initial);
            initial=rq[i];
        }
        total=total+abs(size-rq[i-1]-1);
        initial=0;
        for ( i = index; i >=0; i--) {
            printf("%d ",rq[i]);
            total=total+abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    printf("\nTotal head movement is %d\n",total);
    return 0;
}