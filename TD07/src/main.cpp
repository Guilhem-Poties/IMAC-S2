#include <graphe.hpp>
#include <utils.hpp>

int main() {
    /************ Exercice 1 ************/
    std::vector<std::vector<int>> const& adjacency_matrix {{1,2}, {2}, {0}};

    Graph::WeightedGraph graph_from_matrix {Graph::build_from_adjacency_matrix(adjacency_matrix)};
    Graph::WeightedGraph graph;

    graph.add_directed_edge(0, 1);
    graph.add_directed_edge(0, 2);
    graph.add_directed_edge(1, 2);
    graph.add_directed_edge(2, 0);

    checkCondition(graph_from_matrix==graph);

    return 0;
}