#include <iostream>
#include <vector>

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

    void in_order(node* n, vector<int> &vect) {
        if(n->left) in_order(n->left, vect);
        for(int i = 0; i < n->count; i++) {
            vect.push_back(n->value);
        }
        if(n->right) in_order(n->right, vect);
    }

    void pre_order(node* n, vector<int> &vect) {
        for(int i = 0; i < n->count; i++) {
            vect.push_back(n->value);
        }
        if(n->left) pre_order(n->left, vect);
        if(n->right) pre_order(n->right, vect);
    }

    void post_order(node* n, vector<int> &vect) {
        if(n->left) post_order(n->left, vect);
        if(n->right) post_order(n->right, vect);
        for(int i = 0; i < n->count; i++) {
            vect.push_back(n->value);
        }
    }

    int min_for_node(node* n) {
        node *current = n;
        while(current->left != NULL) {
            current = current->left;
        };
        return current->value;
    }

    int max_for_node(node* n) {
        node *current = root;
        while(current->right != NULL) {
            current = current->right;
        };
        return current->value;
    }
    
    void add_to_node(node * n, int value) {
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

    int find_in_node(node *n, int number) {
        if(!n) return -1;
        if(n->value == number) return number;
        if(n->value > number) return find_in_node(n->left, number);
        if(n->value < number) return find_in_node(n->right, number);
    }

    public:
        binary_search_tree() {
            root = new node();
        }
    void add(int num) {
        add_to_node(root, num);
    };

    int find(int num) {
        return find_in_node(root, num);
    }

    int min() {
        return min_for_node(root); 
    }

    int max() {
        return max_for_node(root);
    }

    vector<int> get_in_order() {
        vector<int> vect;
        in_order(root, vect);
        return vect;
    }
    vector<int> get_pre_order() {
        vector<int> vect;
        pre_order(root, vect);
        return vect;
    }

    vector<int> get_post_order() {
        vector<int> vect;
        post_order(root, vect);
        return vect;
    }
};


int main() {
    binary_search_tree bst;

    bst.add(5);
    bst.add(3);
    bst.add(4);
    bst.add(1);
    bst.add(6);
    
    vector<int> v = bst.get_in_order();
    vector<int> v1 = bst.get_pre_order();
    vector<int> v2 = bst.get_post_order();

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    cout << endl;

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << endl;
    }

    cout << endl;
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << endl;
    }

}