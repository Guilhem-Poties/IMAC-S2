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

void Graph::WeightedGraph::print_DFS(int const start) const {
    std::stack<int> unvisited_vertex;
    std::vector<int> visited_vertex;

    unvisited_vertex.push(start);

    while (!unvisited_vertex.empty()) {
        int current_vertex = unvisited_vertex.top();
        visited_vertex.push_back(current_vertex);
        unvisited_vertex.pop();

        for (auto & adjacent_vertex : adjacency_list.at(current_vertex)) {
            if (visited_vertex.end() == std::find(visited_vertex.begin(), visited_vertex.end(), adjacent_vertex.to)) {
                unvisited_vertex.push(adjacent_vertex.to);
            }
        }
    }

    for (auto & vertex : visited_vertex) {
        std::cout << vertex << ", ";
    }
    std::cout << std::endl;
}

void Graph::WeightedGraph::print_BFS(int const start) const {
    std::vector<int> unvisited_vertex;
    std::vector<int> visited_vertex;

    unvisited_vertex.push_back(start);

    while (!unvisited_vertex.empty()) {
        int current_vertex = unvisited_vertex[0];
        visited_vertex.push_back(current_vertex);
        unvisited_vertex.erase(unvisited_vertex.begin());

        for (auto & adjacent_vertex : adjacency_list.at(current_vertex)) {
            if (visited_vertex.end() == std::find(visited_vertex.begin(), visited_vertex.end(), adjacent_vertex.to)) {
                unvisited_vertex.push_back(adjacent_vertex.to);
            }
        }
    }

    for (auto & vertex : visited_vertex) {
        std::cout << vertex << ", ";
    }
    std::cout << std::endl;
}

Graph::WeightedGraph Graph::build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix) {
    Graph::WeightedGraph graph;

    for (int i {0}; i < (int)adjacency_matrix.size(); i++) {
        for(int j {0}; j < (int)adjacency_matrix[i].size(); j++) {
            if (adjacency_matrix[i][j] != 0) graph.add_directed_edge(i,j);
        }
    }

    return graph;
}