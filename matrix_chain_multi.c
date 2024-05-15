#include<stdio.h>
#define inf 99999
int n;
int Chain_multi(int P[], int n) // P is the array of dimensions
{
    int m[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;
 
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) 
        {
            j = i + L - 1;
            m[i][j] = inf;
            for (k = i; k <= j - 1; k++) 
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j]
                    + P[i - 1] * P[k] * P[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    return m[1][n - 1];
}

void print_Optimal_parens(int s[n-1][n-1], int i, int j){
    if(i==j)
    printf("A%d", i);
    else{
        printf("(");
        print_Optimal_parens(s, i, s[i][j]);
        print_Optimal_parens(s, s[i][j]+1, j);
        printf(")");
    }
}

int main(){
    int n, i, dim1, dim2;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    int P[n+1];
    printf("Enter dimensions of the matrices\n");
    for(i=0;i<n;i++){
        printf("Matrix A%d: ", i+1);
        scanf("%d %d", &dim1, &dim2);
        
        P[i] = dim1;
        P[i+1] = dim2;
    }

    for(i = 0; i<n+1; i++)printf("%d ", P[i]);
    printf("\n");
    int s[n-1][n-1];
    int m = Chain_multi(P, n+1);
    printf("\nMinimum number of multiplications = %d\n", m);
    // print_Optimal_parens(s, 1, n);
    return 0;
}