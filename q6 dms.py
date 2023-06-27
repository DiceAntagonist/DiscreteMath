def is_complete_graph(adj_matrix):
    # Get the number of vertices in the graph
    num_vertices = len(adj_matrix)

    # Check if each pair of distinct vertices is connected
    for i in range(num_vertices):
        for j in range(i + 1, num_vertices):
            if adj_matrix[i][j] != 1:
                return False

    return True

# Example usage
adjacency_matrix = [
    [0, 1, 1, 1],
    [1, 0, 1, 1],
    [1, 1, 0, 1],
    [1, 1, 1, 0]
]

if is_complete_graph(adjacency_matrix):
    print("The graph is a complete graph.")
else:
    print("The graph is not a complete graph.")
