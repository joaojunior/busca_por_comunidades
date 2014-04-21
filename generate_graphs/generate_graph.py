import sys

def generate_graph_complete(numbers_nodes):
    for i in xrange(numbers_nodes):
        for j in xrange(numbers_nodes):
            if i != j:
                print i, ' ', j

def generate_graph_path(numbers_nodes):
    for i in xrange(numbers_nodes-1):
        print i, ' ', i + 1

if __name__ == '__main__':
    method = sys.argv[1]
    numbers_nodes = int(sys.argv[2])
    if method == 'complete':
        generate_graph_complete(numbers_nodes)
    elif method == 'path':
        generate_graph_path(numbers_nodes)
