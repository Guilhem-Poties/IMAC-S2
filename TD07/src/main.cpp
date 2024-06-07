#include <graphe.hpp>
#include <utils.hpp>

int main() {
    /************ Exercice 1 ************/
    std::vector<std::vector<float>> const& adjacency_matrix {{0,5,4}, {0,0,2}, {1,0,0}};

    Graph::WeightedGraph graph_from_matrix {Graph::build_from_adjacency_matrix(adjacency_matrix)};
    Graph::WeightedGraph graph;

    graph.add_directed_edge(0, 1);
    graph.add_directed_edge(0, 2);
    graph.add_directed_edge(1, 2);
    graph.add_directed_edge(2, 0);

    checkCondition(graph_from_matrix==graph);


    /************ Exercice 2 ************/
    graph.print_DFS(0);
    graph.print_BFS(0);

    
    /************ Exercice 3 ************/
    std::unordered_map<int, std::pair<float, int>> distances = Graph::dijkstra(graph, 0, 2);
    
    for (auto && edge : distances) {
        std::cout << edge.first << " : " << edge.second.first << " - " << edge.second.first;
        endLine();
    }
    

    return 0;
}