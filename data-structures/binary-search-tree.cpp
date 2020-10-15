#include <iostream>

using namespace std;

struct node {
    int value;
    int count;
    node *left;
    node *right;
};

class binary_search_tree {
    private:
        node *root;
    public:
        binary_search_tree() {
            root = new node();
        }
    void add(int num) {
        add_to_node(root, num);
    };

    void static add_to_node(node * n, int value) {
        if(n == NULL) {

        }
        if (!n->value || n->value == value) {
            n->value = value;
            n->count++;
            return;
        }
        if(n->value > value) {
            if(!n->left) n->left = new node(); 
            add_to_node(n->left, value);
        }
        if(n->value < value) {
            if(!n->right) n->right = new node();
            return add_to_node(n->right, value);
        }
    };

    int find(int num) {
        return find_in_node(root, num);
    }

    int find_in_node(node *n, int number) {
        if(!n) return -1;
        if(n->value == number) return number;
        if(n->value > number) return find_in_node(n->left, number);
        if(n->value < number) return find_in_node(n->right, number);
    }
};


int main() {
    binary_search_tree bst;

    bst.add(1);
    bst.add(4);
    bst.add(7);
    bst.add(13);
    bst.add(23);
    bst.add(4);
    bst.add(6);

    cout << bst.find(13) << endl;
    cout << bst.find(20) << endl;
    cout << bst.find(1) << endl;

}