//Operating System Project By Amit Kumar Ranjan
//Section : K1603
//Registration NO. : 11607646

#include<stdio.h>
#include<stdbool.h>
//average time

void AvgTime(int process[], int n, int brust[],int quant,char name)
{
    int i,wt[n], temp[n], total_wt = 0, total_time= 0;
    int avg_wait , avg_turnaround ;
    WaitingTime(process, n,brust, wt, quant);
    TurnAroundTime(process, n, brust, wt, temp);
    printf("Processes :  ArivalTime:   BrustTime :  WaitingTime :   TurnAroundTime : \n");
    int count=0;
    for (i=1; i<=n; i++)
    {
        total_wt = total_wt + wt[i];
        total_time = total_time + temp[i];
	count+=brust[i];
	if(count>60)
	{
		break;
	}
        printf("%d \t\t  %d \t\t  %d \t \t %d \t\t\t%d\n",i,process[i],brust[i],wt[i],temp[i]);
    }

    // average query time and average waiting time
    avg_wait=total_wt/(i-1);
    avg_turnaround=total_time/(i-1);
    if(name=='s')
    {
	printf("\n Time he spend on handling of students query is : %d",avg_turnaround);
        printf("\n Average query time is : %d",avg_wait);
    }
    else
    {
	printf("\n Time he spend on handling of faculty query is : %d",avg_turnaround);
        printf("\n Average query time is : %d",avg_wait);
    }
}

//waiting time frome here

void WaitingTime(int process[], int n,int brust[], int wt[], int quan)
{
    int i,t,rem[n];
    t=0;
    for (i = 0 ; i < n ; i++)
        {
            rem[i] =  brust[i];
        }
    while (1)
    {
        bool flag= true;
        for (i = 0 ; i < n; i++)
        {
            if (rem[i] > 0)
            {
                flag = false; 
 
                if (rem[i] > quan)
                {
                    t += quan;
                    rem[i] -= quan;
                }
                else
                {
                    t = t + rem[i];
                    wt[i] = t - brust[i];
                    rem[i] = 0;
                }
            }
        }
        if (flag == true)
          break;
    }
}

//turn around time from here

void TurnAroundTime(int process[], int n,int brust[], int wt[], int temp[])
{
    int i;
    for (i = 0; i < n ; i++)
        temp[i] = brust[i] + wt[i];
}



int main()
{
    int process[] = { 1, 2, 3};
    int n = sizeof process / sizeof process[0];
    int burst_time[] = {10, 5, 8};
    int quantum = 2;
    AvgTime(process, n, burst_time, quantum);
    return 0;
}
