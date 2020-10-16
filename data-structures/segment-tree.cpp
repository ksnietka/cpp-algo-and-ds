#include <iostream>

using namespace std;

struct node {
    int low;
    int high;
    int sum;
    node* left;
    node* right;
};

class segment_tree {
    private:
        node* root;
        int* original;
        int size;

    int calculate_mid_point(int l, int r) {
        if(l + 1 == r) return l;
        return l + ((r - l) / 2);
    }

    int calculate_sum(int l, int r) {
        int sum = 0;
        for(int i = l; i <= r; i++) {
            sum += original[i];
        }
        return sum;
    }

    bool is_in_range(node *n, int l, int h) {
        if ((n-> low <= l && n->high >= l) || (n->low <= h && n->high >= h)) return true;
        return false;
    }

    int get_sum(node *n, int l, int h) {
        if(n->low == l && n->high == h) {
            return n->sum;
        } else {
            int sum = 0;
            if(is_in_range(n->left, l, h)) sum += get_sum(n->left, l, (h > n->left->high) ? n->left->high : h);
            if(is_in_range(n->right, l, h)) sum += get_sum(n->right, (l < n->right->low) ? n->right->low : l, h);
            return sum;
        }
    }

    void create_node_in_range(node *n, int low, int high) {
        int mid = calculate_mid_point(low, high);
        n->sum = calculate_sum(low, high);
        n->low = low;
        n->high = high;

        if(low == high) return;
        n->left = new node();
        n->right = new node();
    
        create_node_in_range(n->left, low, mid);
        create_node_in_range(n->right, mid+1, high); 
    }

    void show_node(node* n) {
        cout << "[" << n->low << ":" << n->high << "] = " << n->sum << endl;
        if(n->left) show_node(n->left);
        if(n->right) show_node(n->right);
    }

    public:
        segment_tree(int arr[], int size) {
            original = arr;
            size = size;
            root = new node();
            create_node_in_range(root, 0, size -1);
        };
    void display() {
        show_node(root);
    }

    int get_sum(int low, int high) {
        return get_sum(root, low, high);
    }

};

int main () {
    int arr [] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    segment_tree st(arr, sizeof(arr)/ sizeof(arr[0]));
    cout << st.get_sum(0,8) << endl;
    // st.display();
}