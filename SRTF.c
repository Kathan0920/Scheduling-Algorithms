#include<stdio.h>
int main()
{
    int at[10], bt[10], rt[10], ct[10], i, smallest = 0;
    int remain = 0, n, t;
    float sum_wt = 0, sum_tat = 0;
    printf("Enter no of Processes:\n");
    scanf("%d", &n);

    printf("Enter burst time:\n");
    for(i = 0; i < n; i++)
    {       
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter arrival time:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("\n\nProcess\t Xi\tAi\tCi\tTi\tWi\n\n");
    for(t = 0; remain != n; t++)
    {
        smallest = -1;
        for(i = 0; i < n; i++)
        {
            if(at[i] <= t && rt[i] && (smallest == -1 || bt[i] < bt[smallest]))
            {
                smallest = i;
            }
        }
        if(smallest == -1)
        {
            continue;
        }
        rt[smallest]--;
        if(rt[smallest] == 0)
        {
            remain++;
            ct[smallest] = t + 1;
            printf("P[%d]\t %d\t%d\t%d\t%d\t%d\n", smallest + 1,bt[smallest],at[smallest],ct[smallest],ct[smallest] - at[smallest], ct[smallest] - bt[smallest] - at[smallest]);
            sum_wt += ct[smallest] - bt[smallest] - at[smallest];
            sum_tat += ct[smallest] - at[smallest];
        }
    }
    
    printf("\n\nAverage waiting time = %.2f\n", (sum_wt / n));
    printf("Average Turn around time = %.2f\n", (sum_tat / n));
    return 0;
}