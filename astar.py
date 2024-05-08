def aStarAlgo(start_node, stop_node, graph, heuristic):
    open_set = set([start_node])
    closed_set = set()
    g = {start_node: 0}  # store distance from starting node
    parents = {start_node: start_node}  # parents contain an adjacency map of all nodes
    while open_set:
        n = None  # node with the lowest f() is found
        for v in open_set:
            if n is None or g[v] + heuristic[v] < g[n] + heuristic[n]:
                n = v
        if n == stop_node:
            # Path found, reconstruct path here
            path = []
            while parents[n] != n:
                path.append(n)
                n = parents[n]
            path.append(start_node)
            path.reverse()
            print('Path found: {}'.format(path))
            return path
        else:
            for (m, weight) in get_neighbors(graph, n):
                if m not in open_set and m not in closed_set:
                    open_set.add(m)
                    parents[m] = n
                    g[m] = g[n] + weight
                else:
                    if g[m] > g[n] + weight:  # update g(m)
                        g[m] = g[n] + weight
                        parents[m] = n
                        if m in closed_set:
                            closed_set.remove(m)
                            open_set.add(m)
        open_set.remove(n)
        closed_set.add(n)
    # Check if path doesn't exist
    if n is None:
        print('Path does not exist!')
        return None

        # if the current node is the stop_node
        # then we begin reconstructing the path from it to the start_node
        if n == stop_node:
            path = []
            while parents[n] != n:
                path.append(n)
                n = parents[n]
            path.append(start_node)
            path.reverse()
            print('Path found: {}'.format(path))
            return path
        # remove n from the open_list, and add it to closed_list
        # because all of his neighbors were inspected
        open_set.remove(n)
        closed_set.add(n)
    print('Path does not exist!')
    return None

# Define function to return neighbor and its distance from the passed node
def get_neighbors(graph, node):
    if node in graph:
        return graph[node]
    else:
        return None


# User input for the graph
def input_graph():
    graph = {}
    num_edges = int(input("Enter the number of edges: "))
    for _ in range(num_edges):
        src, dest, weight = input("Enter source, destination, and weight (space-separated): ").split()
        weight = int(weight)
        if src not in graph:
            graph[src] = [(dest, weight)]
        else:
            graph[src].append((dest, weight))
        # Assuming the graph is undirected, add reverse edges
        if dest not in graph:
            graph[dest] = [(src, weight)]
        else:
            graph[dest].append((src, weight))
    return graph

# User input for heuristic values
def input_heuristic(nodes):
    heuristic = {}
    print("Enter heuristic values for each node:")
    for node in nodes:
        heuristic[node] = int(input(f"Enter heuristic value for node {node}: "))
    return heuristic

# User input for start and stop nodes
start_node = input("Enter the start node: ")
stop_node = input("Enter the stop node: ")

# Get the graph from the user
Graph_nodes = input_graph()

# Get the heuristic values from the user
heuristic = input_heuristic(Graph_nodes.keys())

# Call the A* algorithm function with user input
aStarAlgo(start_node, stop_node, Graph_nodes, heuristic)




























# Enter the start node: A
# Enter the stop node: E
# Enter the number of edges: 7
# Enter source, destination, and weight (space-separated): A B 2
# Enter source, destination, and weight (space-separated): A C 1
# Enter source, destination, and weight (space-separated): B D 5
# Enter source, destination, and weight (space-separated): C D 3
# Enter source, destination, and weight (space-separated): C E 8
# Enter source, destination, and weight (space-separated): D E 1
# Enter source, destination, and weight (space-separated): B E 7
# Enter heuristic values for each node:
# Enter heuristic value for node A: 7
# Enter heuristic value for node B: 6
# Enter heuristic value for node C: 2
# Enter heuristic value for node D: 1
# Enter heuristic value for node E: 0







# Path found: ['A', 'B', 'E']

