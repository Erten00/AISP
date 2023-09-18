#include <stdio.h>
#include <stdlib.h>

// Definirajte maksimalan broj vrhova u grafu
#define N 6

// Data structure to store graph
struct Graph {
	// Niz pokazivača na čvor za predstavljanje popisa susjedstva
	struct Node* head[N];
};

// Struktura podataka za pohranjivanje čvorova popisa susjedstva grafa
struct Node {
	int dest;
	struct Node* next;
};

// Struktura podataka za čuvanje ivica grafa
struct Edge {
	int src, dest;
};

// Funkcija za kreiranje liste susednosti od navedenih krajeva
struct Graph* createGraph(struct Edge edges[], int n)
{
	unsigned i;

	// alociranje memorije za strukturu podataka grafa
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

	// initialize head pointer for all vertices
	for (i = 0; i < N; i++)
		graph->head[i] = NULL;

	// add edges to the directed graph one by one
	for (i = 0; i < n; i++)
	{
		int src = edges[i].src;
		int dest = edges[i].dest;

		// 1. allocate new node of Adjacency List from src to dest

		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->dest = dest;
		newNode->next = graph->head[src];
		graph->head[src] = newNode;

		// 2. allocate new node of Adjacency List from dest to src

		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->dest = src;
		newNode->next = graph->head[dest];
		graph->head[dest] = newNode;
		
	}

	return graph;
}

// Function to print adjacency list representation of graph
void printGraph(struct Graph* graph)
{
	int i;
	for (i = 0; i < N; i++)
	{
		// print current vertex and all ts neighbors
		struct Node* ptr = graph->head[i];
		while (ptr != NULL)
		{
			printf("(%d -> %d)\t", i, ptr->dest);
			ptr = ptr->next;
		}

		printf("\n");
	}
}

// Undirected Graph Implementation in C
int main(void)
{
	// input array containing edges of the graph (as per above diagram)
	// (x, y) pair in the array represents an edge from x to y
	struct Edge edges[] =
	{
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	// calculate number of edges
	int n = sizeof(edges)/sizeof(edges[0]);

	// construct graph from given edges
	struct Graph *graph = createGraph(edges, n);

	// print adjacency list representation of graph
	printGraph(graph);

	return 0;
}
