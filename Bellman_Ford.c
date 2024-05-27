#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
int n;
void Initialize_Single_Source(int g[][n+1], int d[], int p[], int s)
{
    for(int i=1;i<=n;i++)
    {
        d[i] = INT_MAX;
        p[i] = -1;
    }//for
    d[s] = 0;
}//Initialize_Single_Source()
void Relax(int g[][n+1], int d[], int p[], int u, int v)
{
    if(d[v]>d[u]+g[u][v])
    {
        d[v] = d[u] + g[u][v];
        p[v] = u;
    }//if
}//Relax()
bool BellmanFord(int g[][n+1], int d[], int p[], int s)
{
    int i, j, k;
    Initialize_Single_Source(g, d, p, s);
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                if(g[j][k]!=0)
                Relax(g, d, p, j, k);
            }//k loop
        }//j loop
    }//i loop
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        if(g[i][j]!=0 && d[j]>d[i]+g[i][j])
        return false;
    }//for
    return true;
}//BellmanFord()
void PrintPath(int p[], int u, int v)
{
    if(v==u)
    printf("%d ", u);
    else if(p[v]==-1)
    printf("No path from %d to %d\n", u, v);
    else
    {
        PrintPath(p, u, p[v]);
        printf("%d ", v);
    }//else
}//PrintPath()
int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int g[n+1][n+1];
    int d[n+1], p[n+1];
    int i, j;
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d", &g[i][j]);
    int s;
    printf("Enter start vertex: ");
    scanf("%d", &s);
    bool res = BellmanFord(g, d, p, s);
    if(res)
    {   
        printf("Shortest distance estimate of each vertex:\n");
        for(i=1;i<=n;i++)
        printf("Vertex %d: %d\n", i, d[i]);
        printf("Predecessor of each vertex:\n");
        for(i=1;i<=n;i++)
        if(p[i]==-1)
        printf("Vertex %d: NIL\n", i);
        else
        printf("Vertex %d: %d\n", i, p[i]);
        for(i=1;i<=n;i++)
        {
            printf("Shortest path from %d to %d: ", s, i);
            PrintPath(p, 1, i);
            printf("\n");
        }//for
    }
    else printf("Negative weight cycle detected. No path exists. \n");
    return 0;
}//main()