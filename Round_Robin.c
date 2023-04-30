#include<stdio.h>  
#include<conio.h>  
  
int main()  
{  
    int i, n, sum=0,count=0, y, qt, at[10], bt[10], rt[10];  
    float avg_wt,avg_tat,sum_wt = 0,sum_tat = 0;  
    printf("Enter total number of process:\n");  
    scanf("%d", &n);  
    y = n;  
  
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

    printf("Enter the Quantum time:\n");  
    scanf("%d", &qt);  

    printf("\nProcess\t Xi\tAi\tCi\tWi\tTi\n");  
    for(sum=0, i = 0; y!=0; )  
    {  
    if(rt[i] <= qt && rt[i] > 0) 
    {  
        sum = sum + rt[i];  
        rt[i] = 0;  
        count=1;  
        }     
        else if(rt[i] > 0)  
        {  
            rt[i] = rt[i] - qt;  
            sum = sum + qt;    
        }  
        if(rt[i]==0 && count==1)  
        {  
            y--; 
            printf("\nP[%d]\t %d\t%d\t%d\t%d\t%d", i+1, bt[i],at[i],sum,sum-at[i]-bt[i],sum-at[i]);  
            sum_wt = sum_wt+sum-at[i]-bt[i];  
            sum_tat = sum_tat+sum-at[i];  
            count =0;     
        }  
        if(i==n-1)  
        {  
            i=0;  
        }  
        else if(at[i+1]<=sum)  
        {  
            i++;  
        }  
        else  
        {  
            i=0;  
        }  
    }  

    avg_wt = sum_wt/n;  
    avg_tat = sum_tat/n;  
    printf("\n\nAverage Turn Around Time: %.2f\n", avg_wt);  
    printf("Average Waiting Time: %.2f", avg_tat);  
    return 0;
}  