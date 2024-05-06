#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;

    int height() const;
    int min() const;
    int max() const;

    void insert(int value);
    void delete_childs();

    void display_infixe() const;
    std::vector<Node const*> prefixe() const;
    std::vector<Node const*> postfixe() const;
};


void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);


Node* create_node(int value);

Node*& most_left(Node*& node);

bool remove(Node*& node, int value);

void delete_tree(Node* node);