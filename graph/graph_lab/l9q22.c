//Using adjacency linked list
 #include <stdio.h>
 #include <stdlib.h>
 struct Node {
 int data;
 struct Node* next;
 };
 struct GraphList {
 int numNodes;
 struct Node* adjacencyListArray[];
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
 struct GraphList* createGraphList(int n) {
 struct GraphList* graph = (struct GraphList*)malloc(sizeof(struct GraphList) +
n * sizeof(struct Node*));
 if (graph == NULL) {
 printf("Memory allocation failed\n");
 exit(1);
 }
 graph->numNodes = n;
 for (int i = 0; i < n; i++) {
 graph->adjacencyListArray[i] = NULL;
 }
 return graph;
 }
 void addEdgeList(struct GraphList* graph, int src, int dest) {
 struct Node* newNode = createNode(dest);
 newNode->next = graph->adjacencyListArray[src];
 graph->adjacencyListArray[src] = newNode;
 }
 void printGraphList(struct GraphList* graph) {
 printf("Adjacency List Representation:\n");
 for (int i = 0; i < graph->numNodes; i++) {
 struct Node* temp = graph->adjacencyListArray[i];
 printf("Node %d: ", i);
 while (temp != NULL) {
 printf("%d -> ", temp->data);
 temp = temp->next;
 }
 printf("NULL\n");
 }
 }
 int main() {
 struct GraphList* graphList = createGraphList(5);
 addEdgeList(graphList, 0, 1);
 addEdgeList(graphList, 0, 2);
 addEdgeList(graphList, 1, 3);
 addEdgeList(graphList, 1, 4);
 addEdgeList(graphList, 2, 4);
 printGraphList(graphList);
 return 0;
 }