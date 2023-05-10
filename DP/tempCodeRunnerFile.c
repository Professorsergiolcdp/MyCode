#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<math.h>
// Number of vertices in the graph
#define V 51
 struct server1{
    int n;
    int pos_x;
    int pos_y;
} loc[50];
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed distance array
void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i
 
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    // print the constructed distance array
    printSolution(dist);
}
 
// driver program to test above function
int main()
{
    /* Let us create the example graph discussed above */
    int grid[301][301];
    for(int i = 0;i < 300;i++){
        for(int j = 0; j < 300; j++){
            grid[i][j] = 0;
        }
    }
     int cost_matrix[51][51];
    // struct server loc[50];
    int prev_i = 0,prev_j = 0;
    int k = 0;
    while(k < 50){
        int i = rand() % 299 + 1;
        int j = rand() % 299 + 1;
        if(abs(i-prev_i) + abs(j-prev_j) > 20){
             if(grid[i][j] != 1){
                grid[i][j] = 1;
                loc[k].n = k;
                loc[k].pos_x = i;
                loc[k].pos_y = j;
                k++;
             }
             prev_i = i, prev_j = j;
        }
    }
    for(int i = 0;i < 51;i++){
        for(int j = 0; j < 51; j++){
            cost_matrix[i][j] = 1000;
        }
    }
    for(int i = 0;i < 50; i++){
        for(int j = 0; j < 50; j++){
            if(abs(loc[i].pos_x - loc[j].pos_x) +abs(loc[i].pos_y - loc[j].pos_y) <= 80){
                 cost_matrix[i][j] = abs(loc[i].pos_x - loc[j].pos_x) +abs(loc[i].pos_y - loc[j].pos_y);
                }
        }
    }
    dijkstra(cost_matrix, 0);
 
    return 0;
}