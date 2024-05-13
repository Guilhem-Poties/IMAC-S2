#include "graphe.hpp"


void Graph::WeightedGraph::add_vertex(int const id) {
    if (adjacency_list.find(id) == adjacency_list.end()) adjacency_list.insert({id, {}});
}

void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float const weight) {
    add_vertex(to);
    add_vertex(from);
    adjacency_list.at(from).push_back({to, weight});
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight) {
    add_vertex(to);
    add_vertex(from);
    adjacency_list.at(from).push_back({to, weight});
    adjacency_list.at(to).push_back({from, weight});
}


Graph::WeightedGraph Graph::build_from_adjacency_matrix(std::vector<std::vector<int>> const& adjacency_matrix) {
    Graph::WeightedGraph graph;

    for (int i {0}; i < (int)adjacency_matrix.size(); i++) {
        for(auto &j : adjacency_matrix[i]) {
        std::cout << i << " " << j << " ; ";
            graph.add_directed_edge(i,j);
        }
    }

    return graph;
}