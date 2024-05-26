#include<stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int pt[], int n, int solutionVector[n])
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(pt[i - 1] + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // To get the solution vector
    int count = 0, flag, base = K[n][W];

    for(i=n;i>0;i--){
        int j = i-1;
        base = base - count;
        flag=0;
        // Checks if the weight is unique for the given value of i
        for(w = 0; w<=W; w++){
            if(K[j][w] == base){
                solutionVector[i-1] = 0;
                count = 0;
                flag = 1;
                break;
            }
        }
        if(flag == 1) // Not unique (determined from above)
            continue;
        else{
            solutionVector[i-1] = 1;
            count = pt[i-1];
        }
    }

    return K[n][W];
}

// Driver Code
int main()
{
    int i, n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n], W, solutionVector[n];
    printf("Enter the profits and weights:\n");
    for(i=0;i<n;i++){
        printf("Item %d\n", i+1);
        printf("Profit: ");
        scanf("%d", &profit[i]);
        printf("Weight: ");
        scanf("%d", &weight[i]);
        printf("\n");
    }

    printf("Profits and their weights:\n\n");
    for(i=0;i<n;i++){
        printf("p[%d] = %d\tw[%d] = %d\n", i, profit[i], i, weight[i]);
    }

    printf("\nEnter the capacity of the Knapsack: ");
    scanf("%d", &W);
    
    int max_profit = knapSack(W, weight, profit, n, solutionVector);
    printf("Solution Vector: ");
    for(i = 0; i < n; i++) printf("%d ", solutionVector[i]);

    printf("\nMaximum Profit: %d\n", max_profit);
    return 0;
}