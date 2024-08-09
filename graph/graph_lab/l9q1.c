#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
struct Node {
 int data;
 struct Node* next;
};
struct Graph {
 int numNodes;
 struct Node* adjacencyList[MAX_NODES];
 int visited[MAX_NODES];
};
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 if (newNode == NULL) {
 printf("Memory allocation failed\n");
 exit(1);
 }
 newNode->data = data;
 newNode->next = NULL;
 return newNode;
}
struct Graph* createGraph(int n) {
 struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
 if (graph == NULL) {
 printf("Memory allocation failed\n");
 exit(1);
 }
 graph->numNodes = n;
 for (int i = 0; i < n; i++) {
 graph->adjacencyList[i] = NULL;
 graph->visited[i] = 0;
 }
 return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
 struct Node* newNode = createNode(dest);
 newNode->next = graph->adjacencyList[src];
 graph->adjacencyList[src] = newNode;
}
void DFS(struct Graph* graph, int start) {
 int stack[MAX_NODES];
 int top = -1;
 
 stack[++top] = start;
 while (top != -1) {
 int current = stack[top--];
 
 if (graph->visited[current])
 continue;
 graph->visited[current] = 1;
 printf("%d ", current);
 struct Node* temp = graph->adjacencyList[current];
 while (temp != NULL) {
 if (!graph->visited[temp->data])
 stack[++top] = temp->data;
 temp = temp->next;
 }
 }
}
int main() {
 struct Graph* graph = createGraph(7);
 
 addEdge(graph, 0, 1);
 addEdge(graph, 0, 2);
 addEdge(graph, 1, 3);
 addEdge(graph, 1, 4);
 addEdge(graph, 2, 5);
 addEdge(graph, 2, 6);
 printf("DFS traversal sequence starting from node 0: ");
 DFS(graph, 0);
 return 0;
}