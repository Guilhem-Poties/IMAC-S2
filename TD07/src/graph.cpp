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

std::unordered_map<int, std::pair<float, int>> dijkstra(Graph::WeightedGraph const& graph, int const& start, int const end) {
    // On crée un tableau associatif pour stocker les distances les plus courtes connues pour aller du sommet de départ à chaque sommet visité
    // La clé est l'identifiant du sommet et la valeur est un pair (distance, sommet précédent)
    std::unordered_map<int, std::pair<float, int>> distances {};

    // On crée une file de priorité pour stocker les sommets à visiter
    // la pair contient la distance pour aller jusqu'au sommet et l'identifiant du sommet

    // Ce type compliqué permet d'indiquer que l'on souhaite trier les éléments par ordre croissant (std::greater) et donc les éléments les plus petits seront au début de la file (top) (Min heap)
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> to_visit {};

    // 1. On ajoute le sommet de départ à la liste des sommets à visiter avec une distance de 0 (on est déjà sur le sommet de départ)
    to_visit.push({0, start});
    
    // Tant qu'il reste des sommets à visiter
    while (!to_visit.empty()) {
        // 2. On récupère le sommet le plus proche du sommet de départ dans la liste de priorité to_visit
        std::pair<float, int> closest_edge = to_visit.top();

        // 3.Si on atteins le point d'arrivé, on s'arrête
        if (closest_edge.second == end) {
            return distances;
        }
        // 3. On parcoure la liste des voisins (grâce à la liste d'adjacence) du nœud courant
        for (auto & edge : graph.adjacency_list.at(closest_edge.second)) {
            // 4. on regarde si le nœud existe dans le tableau associatif (si oui il a déjà été visité)

            auto find_node {distances.find(end)};
            bool const visited {find_node != distances.end()};

             if (!visited) {
                    // 5. Si le nœud n'a pas été visité, on l'ajoute au tableau associatif en calculant la distance pour aller jusqu'à ce nœud
                    // la distance actuelle + le point de l'arrête)
                distances.at(edge.to) = {distances.at(closest_edge.second).first + closest_edge.first, closest_edge.second};

                    // 6. On ajout également le nœud de destination à la liste des nœud à visité (avec la distance également pour prioriser les nœuds les plus proches)
            } else {
                // 7. Si il a déjà été visité, On test si la distance dans le tableau associatif est plus grande
                // Si c'est le cas on à trouvé un plus court chemin, on met à jour le tableau associatif et on ajoute de nouveau le sommet de destination dans la liste à visité
                if (distances.at(edge.to).first > distances.at(closest_edge.second).first + closest_edge.first) {
                    distances.at(edge.to) = {distances.at(closest_edge.second).first + closest_edge.first, closest_edge.second};                   
                }
            } 
        }
    }

    return distances;
}