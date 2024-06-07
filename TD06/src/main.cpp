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
    root->insert(2);
    root->insert(4);
    root->insert(5);
    
    root->display_infixe();
    endLine();

    /* 7 */
    for (auto & root : root->prefixe()) {
        std::cout << root->value << " ";
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

    
    /************ Exercice 2 ************/

    Node* root2 {create_node(1)};
    
    /* 1 */
    root2->value = 5;
    root2->insert(3);
    root2->insert(7);
    root2->insert(2);
    root2->insert(4);
    root2->insert(6);
    root2->insert(8);
    root2->insert(1);
    root2->insert(9);
    root2->insert(0);

    /* 2 */
    root2->display_infixe();
    endLine();

    /* 3 */
    std:: cout << "Min value of the tree : " << root2->min() << std::endl;
    std:: cout << "Max value of the tree : " << root2->max() << std::endl;

    /* 4 */
    int sum {0};
    for (auto & node : root2->postfixe()) {
        sum += node->value;
    }
    std::cout << "Tree's value sum : " << sum << std::endl;

    /* 5 */
    std::cout << "root2 height : " << root2->height() << std::endl;

    return 0;
}