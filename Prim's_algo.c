#include<stdio.h>
#include<stdbool.h>

#define INF 9999999
#define V 5

//The adjacency matrix
/*int G[V][V] = {
	{0, 9, 75, 0, 0},
	{9, 0, 95, 19, 42},
	{75, 95, 0, 51, 66},
	{0, 19, 51, 0, 31},
	{0, 42, 66, 31, 0}};
*/

void addEdge(int u, int v, int adjMatrix[V][V]){
	int w;
	printf("Enter weight of edge between %d and %d : ", u, v);
	scanf("%d", &w);
	adjMatrix[u][v] = w;
	adjMatrix[v][u] = w;
}

void displayMatrix(int nodes, int adjMatrix[V][V]){
	int i, j;
	printf("Adjacency Matrix :\n");
	for(i=0; i<V; i++){
		for(j=0; j<V; j++)
		printf("%d\t",adjMatrix[i][j]);
		printf("\n");
	}
}
int main(){
	int i, j, u, v;
	int sum = 0;
	static int G[V][V];
	
	int no_edge;// number of edges
	int selected[V];
    
	for(i=0; i<V; i++){
		for(j=0; j<V; j++){
			addEdge(i, j, G);
		}
	}
	
	displayMatrix(V, G);
	
	memset(selected, false, sizeof(selected));
	
	no_edge = 0;
	selected[0] = true;
	
	int x; //row no
	int y; //col no
	
	printf("Edge : Weight\n");
	
	while(no_edge < V-1){
		int min = INF;
		x = 0;
		y = 0;
		
		for(i=0; i<V; i++){
			if(selected[i]){
				for(j=0; j<V;j++){
					if(!selected[j] && G[i][j]){
						if(min > G[i][j]){
							min = G[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		printf("%d - %d : %d\n", x, y, G[x][y]);
		sum += G[x][y];
		selected[y] = true;
		no_edge++;
	}
	printf("\nTotal Weight = %d\n", sum);
	return 0;
}