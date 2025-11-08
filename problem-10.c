#include <stdio.h>
#include <stdbool.h>

#define MAX 7

// Graph adjacency matrix
char nodes[MAX] = {'A','B','C','D','E','F','G'};
int graph[MAX][MAX] = {0};

// Add undirected edge
void addEdge(char u, char v) {
    int i = u - 'A';
    int j = v - 'A';
    graph[i][j] = 1;
    graph[j][i] = 1;
}

// BFS using queue
void BFS(char start) {
    bool visited[MAX] = {false};
    char queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start - 'A'] = true;


    while (front < rear) {
        char current = queue[front++];
        printf("%c ", current);

        for (int i = 0; i < MAX; i++) {
            if (graph[current-'A'][i] && !visited[i]) {
                queue[rear++] = nodes[i];
                visited[i] = true;
            }
        }

        // Show queue state
        printf("\tQueue: ");
        for (int i = front; i < rear; i++)
            printf("%c ", queue[i]);
        printf("\n");
    }
    printf("\n");
}

// DFS using recursion
void DFS(char current, bool visited[]) {
    visited[current - 'A'] = true;
    printf("%c ", current);

    // Show stack state (visited nodes)
    printf("\tVisited so far: ");
    for (int i = 0; i < MAX; i++)
        if (visited[i])
            printf("%c ", nodes[i]);
    printf("\n");

    for (int i = 0; i < MAX; i++) {
        if (graph[current-'A'][i] && !visited[i])
            DFS(nodes[i], visited);
    }
}

int main() {
    // Add edges
    addEdge('A','B');
    addEdge('A','C');
    addEdge('B','D');
    addEdge('C','E');
    addEdge('D','F');
    addEdge('E','G');
    addEdge('F','G');

    printf("BFS traversal: \n");
    BFS('A');

    bool visited[MAX] = {false};
    printf("DFS Traversal: \n");
    DFS('A', visited);
    printf("\n");

    return 0;
}
