#include <stdio.h>

int main() {
    int n;  // Number of vertices
    int graph[20][20]; // Adjacency matrix for the graph
    int path[20];      // Array to store the Hamiltonian path
    int visited[20];   // Array to mark visited vertices

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (1 if there is an edge, 0 otherwise):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize the path and visited arrays
    for (int i = 0; i < n; i++) {
        path[i] = -1;
        visited[i] = 0;
    }

    // Start the path from vertex 0
    path[0] = 0;
    visited[0] = 1;

    // Backtracking algorithm
    int pos = 1;
    int found = 0;

    while (1) {
        int next_vertex = -1;

        // Try to find the next vertex to visit
        for (int v = 0; v < n; v++) {
            if (graph[path[pos - 1]][v] == 1 && visited[v] == 0) {
                next_vertex = v;
                break;
            }
        }

        if (next_vertex != -1) {
            path[pos] = next_vertex; // Assign the next vertex
            visited[next_vertex] = 1; // Mark it as visited
            pos++;

            // If all vertices are visited, check if there's an edge to the starting vertex
            if (pos == n) {
                if (graph[path[pos - 1]][path[0]] == 1) {
                    found = 1; // Hamiltonian Circuit found
                    break;
                } else {
                    // Backtrack since the last vertex doesn't connect to the first
                    pos--;
                    visited[next_vertex] = 0;
                }
            }
        } else {
            // Backtrack to the previous vertex
            pos--;
            if (pos <= 0) {
                break; // No solution found, exit the loop
            }
            visited[path[pos]] = 0; // Unvisit the current vertex
        }
    }

    // Output the result
    if (found) {
        printf("Hamiltonian Circuit found:\n");
        for (int i = 0; i < n; i++) {
            printf("%d -> ", path[i]);
        }
        printf("%d\n", path[0]); // Return to the starting vertex
    } else {
        printf("No Hamiltonian Circuit found.\n");
    }

    return 0;
}

