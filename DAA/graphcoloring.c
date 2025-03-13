#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

bool isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c) {
    for (int i = 0; i < v; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int v, int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[]) {
    if (v == MAX_VERTICES) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(v + 1, graph, m, color)) {
                return true;
            }
            color[v] = 0; // backtrack
        }
    }

    return false;
}

void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m) {
    int color[MAX_VERTICES] = {0};

    if (graphColoringUtil(0, graph, m, color)) {
        printf("Graph coloring is possible with %d colors.\n", m);
        printf("The color assignment for each vertex is:\n");
        for (int i = 0; i < MAX_VERTICES; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
    } 
	else 
	{
        printf("Graph coloring is not possible with %d colors.\n", m);
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}
    };

    int numColors = 8;

    graphColoring(graph, numColors);

    return 0;
}
