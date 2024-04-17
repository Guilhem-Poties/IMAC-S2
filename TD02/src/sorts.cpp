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

// size_t quick_sort_partition(std::vector<int> & vec, size_t const& left, size_t const& right) {
//     int pivot_value { vec[right] };

//     size_t first_bigger_element_index { left };

//     for (size_t i {left}; i < right ;i++) {
//         if (vec[i] < pivot_value) {
//             std::swap(vec[first_bigger_element_index], vec[i]);

//             first_bigger_element_index++;
//         }
//     }

//     // on échange le pivot (qui est positionné à la fin) pour qu'il soit positionné ente les deux sous partitions (des éléments plus petits et plus grand que le pivot)
//     std::swap(vec[first_bigger_element_index], vec[right]);

//     // on retourne l'index du pivot
//     return first_bigger_element_index;
// }

// // Surcharge de la fonction qui permet d'appeler la fonction en passant seulement le vecteur et définir les index left et right pour cibler la totalité du tableau à trier automatiquement
// void quick_sort(std::vector<int> & vec) {
//     quick_sort(vec, 0, vec.size()-1);
// }

void quick_sort(std::vector<int> & vec, size_t const& left, size_t const& right) {
    if (left < right) {
        size_t pivot = quick_sort_partition(vec, left, right);
        std::cout << "pivot : " << pivot << std::endl;

        size_t newLeft = pivot+1;
        std::cout << "right : "<< newLeft << ", " << right << std::endl;
        quick_sort(vec, newLeft, right);

        size_t newRight = pivot-1;
        std::cout << "left : "<< left << ", " << newRight << std::endl;
        quick_sort(vec, left, newRight);
    }
}

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right) {
    int pivot_value = vec[right];
    size_t partition_index = left;

    for (size_t i = left; i < right; i++) {
        if (vec[i] < pivot_value) {
            std::swap(vec[i], vec[partition_index]);
            partition_index++;
        }
    }

    std::swap(vec[right], vec[partition_index]);
    return partition_index;
}

void quick_sort(std::vector<int> & vec, size_t left, size_t right) {
    if (left < right) {
        size_t pivot = quick_sort_partition(vec, left, right);
        quick_sort(vec, left, pivot - 1);
        quick_sort(vec, pivot + 1, right);
    }
}

void quick_sort(std::vector<int> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}
