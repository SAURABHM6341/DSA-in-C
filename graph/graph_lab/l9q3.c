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
struct Queue {
 int front, rear, size;
 unsigned capacity;
 int* array;
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
struct Queue* createQueue(unsigned capacity) {
 struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
 if (queue == NULL) {
 printf("Memory allocation failed\n");
 exit(1);
 }
 queue->capacity = capacity;
 queue->front = queue->size = 0;
 queue->rear = capacity - 1;
 queue->array = (int*)malloc(queue->capacity * sizeof(int));
 if (queue->array == NULL) {
 printf("Memory allocation failed\n");
 exit(1);
 }
 return queue;
}
int isEmpty(struct Queue* queue) {
 return (queue->size == 0);
}
int isFull(struct Queue* queue) {
 return (queue->size == queue->capacity);
}
void enqueue(struct Queue* queue, int item) {
 if (isFull(queue))
 return;
 queue->rear = (queue->rear + 1) % queue->capacity;
 queue->array[queue->rear] = item;
 queue->size++;
}
int dequeue(struct Queue* queue) {
 if (isEmpty(queue))
 return -1;
 int item = queue->array[queue->front];
 queue->front = (queue->front + 1) % queue->capacity;
 queue->size--;
 return item;
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
void BFS(struct Graph* graph, int start) {
 struct Queue* queue = createQueue(graph->numNodes);
 enqueue(queue, start);
 graph->visited[start] = 1;
 printf("BFS Traversal Sequence: ");
 while (!isEmpty(queue)) {
 int current = dequeue(queue);
 printf("%d ", current);
 struct Node* temp = graph->adjacencyList[current];
 while (temp != NULL) {
 if (!graph->visited[temp->data]) {
 enqueue(queue, temp->data);
 graph->visited[temp->data] = 1;
 }
 temp = temp->next;
 }
 }
 printf("\n");
}
int main() {
 struct Graph* graph = createGraph(7);
 
 addEdge(graph, 0, 1);
 addEdge(graph, 0, 2);
 addEdge(graph, 1, 3);
 addEdge(graph, 1, 4);
 addEdge(graph, 2, 5);
 addEdge(graph, 2, 6);
 BFS(graph, 0);
 return 0;
}