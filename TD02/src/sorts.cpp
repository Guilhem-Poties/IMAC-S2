#include "sorts.hpp"

/* BUBBLE SORT */

void bubble_sort(std::vector<int> & vec) {
    for (unsigned int i = 0; i < vec.size()-1; i++) {
        for (unsigned int j = 0; j < vec.size()-i-1; j++) {   
            if (vec[j] > vec[j+1]) {
                int temp{vec[j]};
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }    
}

/* QUICK SORT */

// l'idée de cette fonction est de prendre le vecteur sur lequel on va travailler en paramètre et de prendre deux index (left et right) qui indiquent la partie du tableau pour laquelle on va répartir les valeurs (inférieur au pivot à gauche supérieur à droite du pivot réciproquement à droite) et la valeur du pivot
// template<typename T>
// size_t quick_sort_partition(std::vector<T> & vec, size_t left, size_t right) {
//     // On choisit le pivot comme étant le dernier élément de la partition
//     float const pivot_value {};
    
//     // On garde l'index du premier élément plus grand que le pivot
//     size_t first_bigger_element_index { left };
//     // On parcourt les éléments de la partition pour les répartir
//     for (size_t i {left}; i < right ;i++) {
//         // Si l'élément actuel est plus petit que le pivot, on l'échange avec le dernier élément plus petit que le pivot
//         if (/* TODO */) {
//             std::swap(/* TODO */, /* TODO */);
//             // on incrémente l'index du premier élément plus grand que le pivot (car on vient de le déplacer et placer un élément plus petit que le pivot à sa place)
//             first_bigger_element_index += 1;
//         }
//     }

//     // on échange le pivot (qui est positionné à la fin) pour qu'il soit positionné ente les deux sous partitions (des éléments plus petits et plus grand que le pivot)
//     std::swap(/* TODO */, /* TODO */);

//     // on retourne l'index du pivot
//     return /* TODO */;
// }
 
// // Surcharge de la fonction qui permet d'appeler la fonction en passant seulement le vecteur et définir les index left et right pour cibler la totalité du tableau à trier automatiquement
// void quick_sort(std::vector<float> & vec) {
//     quick_sort(vec, 0, vec.size() - 1);
// }

// void quick_sort(std::vector<float> & vec, size_t const left, size_t const right) {
//     if (left >= right) {
//         return;
//     }

//     // 1. On partitionne le vecteur et on récupère l'index du pivot grâce à la fonction quick_sort_partition
//     // 2. appels récursifs sur les deux sous parties gauche et droite du pivot
//     // Attention à la condition d'arrêt de la récursivité
// }