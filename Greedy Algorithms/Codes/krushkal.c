#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Edge {
    int u, v, weight;
} Edge;

int parent[MAX];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y)
        parent[y] = x;
}

int cmp(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal(Edge edges[], int n, int m) {
    int i, count = 0;
    qsort(edges, m, sizeof(Edge), cmp);
    for (i = 0; i < n; i++)
        parent[i] = i;
    for (i = 0; i < m && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            union_set(u, v);
            printf("%d - %d\n", u, v);
            count++;
        }
    }
}

int main() {
    int n, m, i;
    Edge edges[MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges (u, v, weight):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    printf("Minimum Spanning Tree:\n");
    kruskal(edges, n, m);
    return 0;
}
