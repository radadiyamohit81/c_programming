#include <stdlib.h>
#include<stdio.h>
typedef struct {
    int first;
    int second;
} edge;
static int cyclic_recursive(const edge *edges,int n,int *visited,int order,int vertex,int predecessor)
{
    int i;
    int cycle_found = 0;
    visited[vertex] = 1;
    for (i = 0; i < n && !cycle_found; i++) {
        if (edges[i].first == vertex || edges[i].second == vertex) {
            int neighbour = edges[i].first == vertex ? edges[i].second : edges[i].first;
            if (visited[neighbour] == 0)
            {
                cycle_found = cyclic_recursive(edges, n, visited, order, neighbour, vertex);
            }
            else if (neighbour != predecessor)
            {
                cycle_found = 1;
            }
        }
    }
    return cycle_found;
}
int cyclic(const edge *edges,  int n,  int order)
{
    int *visited = calloc(order, sizeof( int));
    int cycle_found;
    if (visited == NULL) {
        return 0;
    }
    cycle_found  = cyclic_recursive(edges, n, visited, order, 0, 0);
    free(visited);
    return cycle_found;
}
int main(void)
{
    const int order = 6;
    const int n = 6;
    edge *edges;
    int c;

    edges = malloc(n * sizeof(edge));
    if (edges == NULL) {
        return 1;
    }

    edges[0].first = 0;
    edges[0].second = 1;
    edges[1].first = 1;
    edges[1].second = 2;
    edges[2].first = 2;
    edges[2].second = 3;
    edges[3].first = 3;
    edges[3].second = 0;
    edges[4].first = 3;
    edges[4].second = 4;
    edges[5].first = 3;
    edges[5].second = 5;

    c = cyclic(edges, n, order);
    printf("Graph is %s.\n", c ? "cyclic" : "acyclic");
    free(edges);

    return 0;
}
