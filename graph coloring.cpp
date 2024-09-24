#include <stdio.h>

int main() {
    int V; // Number of vertices
    int graph[20][20]; // Adjacency matrix to represent the graph
    int colors[20]; // Array to store the color assigned to each vertex
    int num_colors; // Number of colors to be used
    int found_solution = 0; // To indicate if a solution is found

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    // Initialize the color array to -1 (no color assigned)
    for (int i = 0; i < V; i++) {
        colors[i] = -1;
    }

    // Start backtracking
    int vertex = 0;
    while (vertex >= 0) {
        int assigned_color = colors[vertex] + 1;

        // Try assigning colors from 0 to num_colors - 1
        while (assigned_color < num_colors) {
            int is_safe = 1; // Assume the color is safe to assign
            for (int i = 0; i < V; i++) {
                if (graph[vertex][i] == 1 && colors[i] == assigned_color) {
                    is_safe = 0; // Adjacent vertex has the same color, not safe
                    break;
                }
            }

            if (is_safe) {
                break; // Found a safe color to assign
            }
            assigned_color++;
        }

        if (assigned_color < num_colors) {
            colors[vertex] = assigned_color; // Assign the color to the current vertex

            if (vertex == V - 1) { // All vertices have been assigned colors
                found_solution = 1;
                break;
            }

            vertex++; // Move to the next vertex
        } else {
            colors[vertex] = -1; // Backtrack, remove color assignment
            vertex--; // Move back to the previous vertex
        }
    }

    if (found_solution) {
    	printf("R.Babu Eshwar-192211778\n");
        printf("Solution found! The colors assigned to the vertices are:\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d -> Color %d\n", i, colors[i]);
        }
    } else {
        printf("No solution found with %d colors.\n", num_colors);
    }

    return 0;
}

