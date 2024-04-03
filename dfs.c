#include<stdio.h>
#define MAX 100

void addEdge(int u, int v, int adjMatrix[MAX][MAX]){
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void displayMatrix(int nodes, int adjMatrix[MAX][MAX]){
    int i,j;
    printf("Adjacency Matrix:\n");
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            printf("%d ",adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void DFS(int startNode, int nodes, int adjMatrix[MAX][MAX]){
    int visited[MAX] = {0};
    int stack[MAX], top = -1, i;
    
    stack[++top] = startNode;
    visited[startNode] = 1;

    printf("DFS Traversal starting from from node %d: ",startNode+1);

    while(top!=-1){
        int current = stack[top--];
        printf("%d ",current+1);

        for(i=0;i<nodes;i++){
            if(adjMatrix[current][i]==1 && visited[i]==0){
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }
}

int main(){
    int i, nodes, edges, u, v;
    static int adjMatrix[MAX][MAX];

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: from_node to_node):\n");
    for(i=0;i<edges;i++){
        scanf("%d %d",&u, &v);
        addEdge(u-1, v-1, adjMatrix);
    }

    displayMatrix(nodes, adjMatrix);

    printf("Enter the starting node for DFS traversal: ");
    scanf("%d", &u);

    DFS(u-1, nodes, adjMatrix);

    return 0;
}