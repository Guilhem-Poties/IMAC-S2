#include "sorts.hpp"

/* BUBBLE SORT */

void bubble_sort(std::vector<int> & vec) {
    for (unsigned int i = 0; i < vec.size()-1; i++) {
        for (unsigned int j = 0; j < vec.size()-i-1; j++) {   
            if (vec[j] > vec[j+1]) {
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
}

/* QUICK SORT */

// l'idée de cette fonction est de prendre le vecteur sur lequel on va travailler en paramètre et de prendre deux index (left et right) qui indiquent la partie du tableau pour laquelle on va répartir les valeurs (inférieur au pivot à gauche supérieur à droite du pivot réciproquement à droite) et la valeur du pivot

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right) {
    // On choisit le pivot comme étant le dernier élément de la partition
    int const pivot_value { vec[right] };
    
    // On garde l'index du premier élément plus grand que le pivot
    size_t first_bigger_element_index { left };
    // On parcourt les éléments de la partition pour les répartir
    for (size_t i {left}; i < right ;i++) {
        // Si l'élément actuel est plus petit que le pivot, on l'échange avec le dernier élément plus petit que le pivot
        if (vec[i] < pivot_value) {
            std::swap(vec[i], vec[first_bigger_element_index]);
            // on incrémente l'index du premier élément plus grand que le pivot (car on vient de le déplacer et placer un élément plus petit que le pivot à sa place)
            first_bigger_element_index += 1;
        }
    }

    // on échange le pivot (qui est positionné à la fin) pour qu'il soit positionné ente les deux sous partitions (des éléments plus petits et plus grand que le pivot)
    std::swap(vec[right], vec[first_bigger_element_index-1]);

    // on retourne l'index du pivot
    return first_bigger_element_index-1;
}

// Surcharge de la fonction qui permet d'appeler la fonction en passant seulement le vecteur et définir les index left et right pour cibler la totalité du tableau à trier automatiquement
void quick_sort(std::vector<int> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}

void quick_sort(std::vector<int> & vec, size_t const left, size_t const right) {
    if (left >= right) {
        return ;
    }
    size_t pivot = quick_sort_partition(vec, left, right);    

    quick_sort(vec, pivot, right);

    // 1. On partitionne le vecteur et on récupère l'index du pivot grâce à la fonction quick_sort_partition
    // 2. appels récursifs sur les deux sous parties gauche et droite du pivot
    // Attention à la condition d'arrêt de la récursivité
}


/* MERGE SORT */

// void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right) {
//     // On crée deux vecteurs temporaires pour stocker les copies des deux sous-parties à fusionner
//     size_t const left_size { middle - left + 1 };
//     size_t const right_size { right - middle };
//     std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
//     std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

//     // Deux index pour parcourir les deux sous-parties et remplir le vecteur original
//     size_t left_index {0};
//     size_t right_index {0};

//     size_t index {left};

//     // Tant que nous avons pas parcouru tout les éléments d'au moins une des deux sous-parties
//     while (left_index < left_size && /* TODO */) {
//         // On compare les éléments des deux sous-parties et on place le plus petit dans le vecteur original
//         // on met à jour les index pour parcourir les sous-parties en conséquence
//         if (/* TODO */) {
//             /* TODO */
//         } else {
//             /* TODO */
//         }
//         /* TODO */
//     }

//     // S'il reste des éléments dans une des deux sous-parties, on les place dans le vecteur original
//     while (/* TODO */) {
//         /* TODO */
//     }
//     while (/* TODO */) {
//         /* TODO */
//     }
// }

// // Même mécanisme que pour le tri rapide
// void merge_sort(std::vector<float> & vec) {
//     merge_sort(vec, 0, vec.size() - 1);
// }

// void merge_sort(std::vector<float> & vec, size_t const left, size_t const right) {
//     if (left >= right) {
//         return;
//     }
//     // 1. Choix de l'index au milieu de la partition
//     // 2. Appels récursifs sur les deux sous-parties
//     // 3. Fusion des deux sous-parties
// }