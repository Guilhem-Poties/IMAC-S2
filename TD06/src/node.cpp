#include "node.hpp"


bool Node::is_leaf() const {
    return this->left == nullptr && this->right == nullptr;
}

void Node::insert(int value) {
    value < this->value ? this->left = create_node(value) : this->right = create_node(value);
}

int Node::height() const {
    if(this->is_leaf()) return 1;
    
    int leftHeight {1};
    int rightHeight {1};

    if(this->left) leftHeight += this->left->height();

    if(this->right) rightHeight += this->right->height();

    return std::max(leftHeight, rightHeight);
}

void Node::delete_childs() {
    if (this->left) this->left->delete_childs();
    this->left = nullptr;

    if (this->right) this->right->delete_childs();
    this->right = nullptr;
}

void Node::display_infixe() const {
    if (this->left) this->left->display_infixe();

    std::cout << this->value << " "; 

    if (this->right) this->right->display_infixe();
}

std::vector<Node const*> Node::prefixe() const {
    std::vector<Node const*> nodes;

    if (this->left){
        auto left_nodes {this->left->prefixe()};
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }

    if (this->right){
        auto right_nodes {this->right->prefixe()};
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }

    nodes.push_back(this);

    return nodes;
}

int Node::min() const {
    int min {this->value};

    if(this->left) min = std::min(this->left->min(), min);

    if(this->right) min = std::min(this->right->min(), min);

    return min;
}

int Node::max() const {
    int max {this->value};

    if(this->left) max = std::max(this->left->max(), max);

    if(this->right) max = std::max(this->right->max(), max);

    return max;
}


// std::vector<Node const*> Node::postfixe() const {
//     std::vector<Node const*> nodes {};
//     std::stack<Node const*> to_process {};
//     Node* previous {nullptr};
//     to_process.push(this);

//     while (!to_process.empty()) {
//         Node const* current { to_process.top() };

//         // Si on est en train de descendre dans l'arbre
//         if (previous == nullptr || (previous->left == current || previous->right == current)) {
//             if() {
//                 to_process.push(current->left);
//             }
//             else if(/* ? */) {
//                 to_process.push(current->right);
//             } else {
//                 nodes.push_back(current);
//                 // on traite le nœud (ajouter au vecteur) et on le retire de la pile
//                 // todo
//             }

//         // Si l'on remonte dans l'arbre en venant de la gauche
//         }else if (previous == current->left) {
//             if(/* ? */) {
//                 // todo
//             } else {
//                 // todo
//             }

//         // Si l'on remonte dans l'arbre en venant de la droite
//         } else if (previous == current->right) {
//             // todo
//         }

//         previous = current;

//     }
//     return nodes;
// }



void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}



Node* create_node(int value) {
    Node* root {new Node {value, nullptr, nullptr}};
    return root;
}

Node*& most_left(Node*& node) {
    if (node->is_leaf()) return node;
    else if (node->left) return most_left(node->left);
    else return most_left(node->right);
}

bool remove(Node*& node, int value) {
    if (value == node->value) {
        if (node->is_leaf()) {
            delete node;
            node = nullptr;
            return true;
        }
        else if (node->left && !node->right) {
            delete node;
            node = node->left;
            return true;
        }
        else if (node->right && !node->left) {
            delete node;
            node = node->right;
            return true;
        }
        else {
            node->value = most_left(node)->value;
            remove(most_left(node), most_left(node)->value);
            return true;
        }
    }
    else {
        if (node->left && node->right) return remove(node->left, value) || remove(node->right, value);
        else if (node->left) return remove(node->left, value);
        else if (node->right) return remove(node->right, value);

        return false;
    }
}

void delete_tree(Node* node) {
    if (node->left) delete_tree(node->left);

    if (node->right) delete_tree(node->right);

    delete node;
}