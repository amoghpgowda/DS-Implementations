#include<stdio.h>
#include<stdlib.h>
struct Process
{
    int pid;
    int bt;
    int priority;
};

typedef struct Process proc;
proc pro[30],temp;
int n=0;

void insert()
{
    int i=0,j;
    printf("\nEnter the process id, burst time and priority of the queue: ");
    scanf("%d %d %d", &temp.pid,&temp.bt,&temp.priority);

    while(temp.priority > pro[i].priority)
        i++;

    for(j=n-1; j>=i; j--)
        pro[j+1] = pro[j];

    pro[i] = temp;
    n = n+1;
}

void del()
{
    int i,j,pid;
    printf("Enter the process ID of element to be deleted: ");
    scanf("%d",&pid);

    for ( j = 0; j < n; j++)
    {
        if (pro[j].pid == pid)
            break;
    }

    printf("Deleted element is pid =%d\tburst time=%d\tpriority=%d\n", pro[j].pid,pro[j].bt,pro[j].priority);

    for(i=j; i<n-1; i++)
        pro[i]=pro[i+1];

    n = n-1;
}

void findWaitingTime(int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n ; i++ )
        wt[i] = pro[i-1].bt + wt[i-1] ;
}

void findTurnAroundTime(int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = pro[i].bt + wt[i];
}

void display()
{
    if(n==0)
    {
        printf("Priority Queue is empty\n");
        return;
    }
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime( wt);
    findTurnAroundTime(wt, tat);

    printf("\nProcess ID\tBurst time\tWaiting time\tTurnaround time\n");
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\n",pro[i].pid,pro[i].bt,wt[i],tat[i]);
    }
    printf("\n Average waiting time=%f\n Average turnaround time=%f", (float)total_wt/(float)n,(float)total_tat / (float)n);
}

void main()
{
    int ch;

    for (int i = 0; i < 10; i++)
    {
        pro[i].priority=100;
    }

    for(;;)
    {
        printf("\n--------Menu-----------\n");
        printf("1.Insert\n2.Display\n3.Delete\n4.Exit\n");
        printf("-----------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insert();
                break;
            case 2: display();
                break;
            case 3: del();
                break;
            case 4: exit(0);
                break;
            default: printf("\nInvalid choice:\n");
                break;
        }
    }
}
