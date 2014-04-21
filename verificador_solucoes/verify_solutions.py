import sys

def floyd_warshall(graph):
    distance = []
    numbers_nodes = len(graph)
    for i in xrange(numbers_nodes):
        distance.append([float('inf')] * numbers_nodes)
        for j in xrange(numbers_nodes):
            adj_i = graph.get(i, {})
            weight = adj_i.get(j, float('inf'))
            distance[i][j] = weight
    for k in xrange(numbers_nodes):
        for i in xrange(numbers_nodes):
            for j in xrange(numbers_nodes):
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])
    return distance

def read_graph(name_file, edge_removed):
    graph = {}
    f = open(name_file, 'r')
    min_node = float('inf')
    max_node = -1
    arcs = []
    for arc in f.readlines():
        arc = arc.split()
        source = int(arc[0])
        dest = int(arc[1])
        if source < min_node:
            min_node = source
        if dest < min_node:
            min_node = dest
        if source > max_node:
            max_node = source
        if dest > max_node:
            max_node = dest
        arcs.append((source, dest))
        arcs.append((dest, source))
    for arc in arcs:
        source = arc[0] - min_node
        dest = arc[1] - min_node
        if (source, dest) not in edge_removed:
            adj_source = graph.get(source, {})
            adj_source.update({dest:1})
            graph[source] = adj_source
            adj_dest = graph.get(dest, {})
            adj_dest.update({source:1})
            graph[dest] = adj_dest
    f.close()
    return graph, min_node

def read_solution(name_file_result):
    f = open(name_file_result, 'r')
    edge_removed = []
    communities = {}
    for line in f.readlines():
        if line.startswith('Aresta Removida:'):
            line = line.replace('Aresta Removida:', '')
            line = line.split(',')
            source = int(line[0])
            dest = int(line[1])
            edge_removed.append((source, dest))
        else:
            line = line.split(' ')
            node = int(line[0])
            community_id = int(line[1])
            communities[community_id] = communities.get(community_id, [])
            communities[community_id].append(node)
    f.close()
    return edge_removed, communities

def verify_solution(distance, communities, min_node, numbers_communities):
    solution_is_correct = True
    if numbers_communities != len(communities):
        solution_is_correct = False
        return solution_is_correct
    for community_id, nodes in communities.iteritems():
        for source in nodes:
            for dest in nodes:
                if distance[source - min_node][dest - min_node] == float('inf'):
                    solution_is_correct = False
                    return solution_is_correct
    return solution_is_correct

def main(name_file, name_file_result, numbers_communities):
    edge_removed, communities = read_solution(name_file_result)
    graph, min_node = read_graph(name_file, edge_removed)
    distance = floyd_warshall(graph)
    print verify_solution(distance, communities, min_node, numbers_communities), name_file_result

if __name__ == '__main__':
    name_file = sys.argv[1]
    numbers_communities = int(sys.argv[2])
    name_file_result = sys.argv[3]
    main(name_file, name_file_result, numbers_communities)