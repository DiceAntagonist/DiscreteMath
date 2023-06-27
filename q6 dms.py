def is_complete_graph(adj_matrix):
    
    num_vertices = len(adj_matrix)

    
    for i in range(num_vertices):
        for j in range(i + 1, num_vertices):
            if adj_matrix[i][j] != 1:
                return False

    return True


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
