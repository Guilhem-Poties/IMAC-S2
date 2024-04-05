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

size_t quick_sort_partition(std::vector<int> & vec, size_t const& left, size_t const& right) {
    int const pivot_value { vec[right] };

    size_t first_bigger_element_index { left };

    for (size_t i {left}; i < right ;i++) {
        if (vec[i] < pivot_value) {
            std::swap(vec[first_bigger_element_index], vec[i]);

            first_bigger_element_index++;
        }
    }

    // on échange le pivot (qui est positionné à la fin) pour qu'il soit positionné ente les deux sous partitions (des éléments plus petits et plus grand que le pivot)
    std::swap(vec[first_bigger_element_index], vec[right]);

    // on retourne l'index du pivot
    return first_bigger_element_index;
}

// Surcharge de la fonction qui permet d'appeler la fonction en passant seulement le vecteur et définir les index left et right pour cibler la totalité du tableau à trier automatiquement
void quick_sort(std::vector<int> & vec) {
    quick_sort(vec, 0, vec.size()-1);
}

void quick_sort(std::vector<int> & vec, size_t const& left, size_t const& right) {
    if (left < right) {
        size_t pivot = quick_sort_partition(vec, left, right);
        
        size_t newRight = pivot-1;
        quick_sort(vec, left, newRight);

        size_t newLeft = pivot+1;
        quick_sort(vec, newLeft, right);
    }
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