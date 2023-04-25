#include<stdio.h>

int main()
{
    int FCFS[100][6];
    int min_val,n,temp;
    printf("Enter the no. of processes:\n");
    scanf("%d",&n);

    printf("Enter the burst time:\n");
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&FCFS[i][1]);
        FCFS[i][0] = i+1;
    }

    printf("Enter the arrival time:\n");
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&FCFS[i][2]);
    }

    for(int i=0; i<n; i++)
    {
        min_val = i;
        for(int j=i+1; j<n; j++)
        {
            if(FCFS[i][2] > FCFS[j][2])
            {
                min_val = j;

                temp = FCFS[i][2];
                FCFS[i][2] = FCFS[min_val][2];
                FCFS[min_val][2] = temp;
                

                temp = FCFS[i][0];
                FCFS[i][0] = FCFS[min_val][0];
                FCFS[min_val][0] = temp;

                temp = FCFS[min_val][1];
                FCFS[min_val][1] = FCFS[i][1];
                FCFS[i][1] = temp;
            }
        }
    }
    
    //calculation of completion time
    FCFS[0][3] = FCFS[0][1];
    for(int i=1; i<n; i++)
    {
        FCFS[i][3] = FCFS[i-1][3] + FCFS[i][1];
        
    }

    // calculation of waiting and turn around time.
    for(int i=0; i<n; i++)
    {
        FCFS[i][4] = FCFS[i][3] - FCFS[i][2] - FCFS[i][1];
        FCFS[i][5] = FCFS[i][3] - FCFS[i][2];
    }

    printf("\nProcess\t Xi\tAi\tCi\tWi\tTi\n");
    for(int i = 0; i<n; i++)
    {
        printf("\n%d\t %d\t%d\t%d\t%d\t%d",FCFS[i][0],FCFS[i][1],FCFS[i][2],FCFS[i][3],FCFS[i][4],FCFS[i][5]);
    }
    float sum_wt = 0, sum_tat = 0;
    for(int i=0; i<n; i++)
    {
        sum_wt += FCFS[i][4];
        sum_tat += FCFS[i][5];
    }

    float avg_wt = (sum_wt / n);
    float avg_tat = (sum_tat / n);

    printf("\n\nAvg. waiting time = %.2f\n",avg_wt);
    printf("Avg. Turn around time = %.2f",avg_tat);

    return 0;
}