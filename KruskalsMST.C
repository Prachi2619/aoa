//Kruskal's MST
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function prototypes
int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
void Kruskal(struct Edge edges[], int V, int E);
void sortEdges(struct Edge edges[], int E);

int main() {
    int V = 4; // Number of vertices in the graph
    int E = 5; // Number of edges in the graph

    // Array of edges with their source, destination, and weight
    struct Edge edges[MAX_EDGES] = {
    {0, 1, 10},
    {0, 2, 6},
    {0, 3, 5},
    {1, 3, 15},
    {2, 3, 4}
    };

    Kruskal(edges, V, E);

    return 0;
}

// Function to find the set of an element i
int find(struct Subset subsets[], int i) {
    while (subsets[i].parent != i)
    i = subsets[i].parent;
    return i;
}

// Function that does union of two sets of x and y
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
    subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
    subsets[yroot].parent = xroot;
    else {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
    }
}

// Function to construct MST using Kruskal's algorithm
void Kruskal(struct Edge edges[], int V, int E) {
    struct Edge result[MAX_VERTICES];
    int e = 0;
    int i = 0;
    int v;
    struct Subset subsets[MAX_VERTICES];
    sortEdges(edges, E);

    // Allocate memory for creating V subset

    // Initialize subsets with single elements
    for (v = 0; v < V; ++v) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
    }

    // Number of edges to be taken is V-1
    while (e < V - 1 && i < E) {
    struct Edge next_edge = edges[i++];
    int x = find(subsets, next_edge.src);
    int y = find(subsets, next_edge.dest);

    // If including this edge does not cause cycle, include it
    if (x != y) {
        result[e++] = next_edge;
        Union(subsets, x, y);
    }
    }

    // Print the constructed MST
    printf("Edges of the MST:\n");
    for (i = 0; i < e; ++i)
    printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
}

// Bubble sort function to sort the edges
void sortEdges(struct Edge edges[], int E) {
    int i;
    int j;
    for (i = 0; i < E - 1; i++) {
    for (j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}
