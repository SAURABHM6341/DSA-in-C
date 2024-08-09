// Using adjacency matrix
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
struct GraphMatrix {
 int numNodes;
 int matrix[MAX_NODES][MAX_NODES];
};
struct GraphMatrix* createGraphMatrix(int n) {
 struct GraphMatrix* graph = (struct GraphMatrix*)malloc(sizeof(struct 
GraphMatrix));
 if (graph == NULL) {
 printf("Memory allocation failed\n");
 exit(1);
 }
 graph->numNodes = n;
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 graph->matrix[i][j] = 0;
 }
 }
 return graph;
}
void addEdgeMatrix(struct GraphMatrix* graph, int src, int dest) {
 graph->matrix[src][dest] = 1;
 graph->matrix[dest][src] = 1;
}
void printGraphMatrix(struct GraphMatrix* graph) {
 printf("Adjacency Matrix Representation:\n");
 for (int i = 0; i < graph->numNodes; i++) {
 for (int j = 0; j < graph->numNodes; j++) {
 printf("%d ", graph->matrix[i][j]);
 }
 printf("\n");
 }
}
int main() {
 struct GraphMatrix* graphMatrix = createGraphMatrix(5);
 
 addEdgeMatrix(graphMatrix, 0, 1);
 addEdgeMatrix(graphMatrix, 0, 2);
 addEdgeMatrix(graphMatrix, 1, 3);
 addEdgeMatrix(graphMatrix, 1, 4);
 addEdgeMatrix(graphMatrix, 2, 4);
 printGraphMatrix(graphMatrix);
 return 0;}