#include "node.hpp"
#include "utils.hpp"

int main() {
    /************ Exercice 1 ************/
    /* 1 */
    Node* root {create_node(1)};

    /* 2 */
    checkCondition(root->is_leaf());

    /* 3 */
    root->insert(3);
    root->insert(0);
    root->right->insert(2);
    root->right->insert(4);
    root->right->left->insert(5);

    pretty_print_left_right(*root, "", false);
    endLine();

    /* 4 */
    std::cout << "root height : " << root->height() << std::endl;

    /* 5 */
    root->delete_childs();
    std::cout << "root height : " << root->height() << std::endl;

    /* 6 */
    root->insert(3);
    root->insert(0);
    root->right->insert(2);
    root->right->insert(4);
    root->right->left->insert(5);
    
    root->display_infixe();
    endLine();

    /* 7 */
    for (auto & node : root->prefixe()) {
        std::cout << node->value << " ";
    }
    endLine();

    /* 9 */
    std::cout << "Most left value : " << most_left(root)->value;
    endLine();
    pretty_print_left_right(*root, "", false);

    /* 10 */
    checkCondition(remove(root, 3));
    endLine();
    pretty_print_left_right(*root, "", false);
    endLine();

    /* 12 */
    std:: cout << "Min value of the tree : " << root->min() << std::endl;
    std:: cout << "Max value of the tree : " << root->max() << std::endl;

    /* 11 */
    delete_tree(root);

    return 0;
}