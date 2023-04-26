#include<stdio.h>
#include<stdbool.h>

void sort_bt(int *process, int *bt, int *at, int start, int end)
{
	int index,temp;
    for(int i=start; i<end; i++)
    {
        index = i;
        for(int j=i+1; j<end; j++)
        {
            if((bt[i]) > (bt[j]))
            {
                index = j;
                temp = bt[index];
                bt[index] = bt[i];
                bt[i] = temp;

                temp = at[index];
                at[index] = at[i];
                at[i] = temp;

                temp = process[index];
                process[index] = process[i];
                process[i] = temp;
            }
        }        
    }
	
}
void sort_at(int *process, int *bt, int *at, int start, int end)
{
	int index,temp;
    for(int i=start; i<end; i++)
    {
        index = i;
        for(int j=i+1; j<end; j++)
        {
            if((at[i]) > (at[j]))
            {
                index = j;
                temp = bt[index];
                bt[index] = bt[i];
                bt[i] = temp;

                temp = at[index];
                at[index] = at[i];
                at[i] = temp;

                temp = process[index];
                process[index] = process[i];
                process[i] = temp;
                
            }
        }        
    }

	
}

int main()
{   
    int n,b = 0,temp = 0,min = 0,k = 1;
    bool at_zero = false;
    printf("Enter the no. of processes:\n");
    scanf("%d",&n);
    int process[n],bt[n],at[n],tat[n],wt[n],ct[n];

    printf("Enter the burst time:\n");
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&bt[i]);
        process[i] = i+1;
    }

    printf("Enter the arrival time:\n");
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&at[i]);
    }

    // Sort by arrival time
    sort_at(process,bt,at,0,n);
    
    // Sort by burst time for arrival time is zero
    for(int i = 0; i<n; i++)
    {
        at_zero = false;
        if(at[i] == 0)
            at_zero = true;
    }
    if(at_zero)
    {
        sort_bt(process,bt,at,0,n);
    }

    // Sort by burst time for arrival time is not zero.
    for(int j = 0; j<n-1; j++)
    {
        b = b + bt[j];

        for(int i = k; i<n; i++)
        {
            min = bt[k];
            if(b > at[i])
            {
                if(bt[i] < min)
                {
                    temp = at[k];
                    at[k] = at[i];
                    at[i] = temp;

                    temp = bt[k];
                    bt[k] = bt[i];
                    bt[i] = temp;

                    temp = process[k];
                    process[k] = process[i];
                    process[i] = temp;
                }
            }
        }
        k++;
    }
    
    // Calculation of completion time
    ct[0] = bt[0];
    for(int i=1; i<n; i++)
    {
        ct[i] = ct[i-1] + bt[i];        
    }

    // Calculation of waiting time and turn around time
    for(int i=0; i<n; i++)
    {
        wt[i] = ct[i] - at[i] - bt[i];
        tat[i] = ct[i] - at[i];
    }
    
    // Calculation of avg. waiting time and avg. turn around time
    printf("\nProcess\t Xi\tAi\tCi\tWi\tTi\n");
    for(int i = 0; i<n; i++)
    {
        printf("\n%d\t %d\t%d\t%d\t%d\t%d",process[i],bt[i],at[i],ct[i],wt[i],tat[i]);
    }
    float sum_wt = 0, sum_tat = 0;
    for(int i=0; i<n; i++)
    {
        sum_wt += wt[i];
        sum_tat += tat[i];
    }

    float avg_wt = sum_wt / n;
    float avg_tat = sum_tat / n;

    printf("\n\nAvg. waiting time = %.2f\n",avg_wt);
    printf("Avg. Turn around time = %.2f\n",avg_tat);

    return 0;
}