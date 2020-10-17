#include <iostream>
#include <chrono>

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

int sum_in_range(int arr[], int l, int h) {
    int sum = 0;
    for(int i = l; i <= h; i++) {
        sum += arr[i];  
    }
    return sum;
}

int main () {
    int low = 10;
    int high = 999;
    int *arr = new int[10000000];
    for (int i = 0; i < 10000000; i++) {
        arr[i] = (rand()%100)+1;
    }
    auto start = chrono::high_resolution_clock::now();
    cout << sum_in_range(arr, low, high) << endl;
    auto end = chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    
    cout << elapsed.count() << endl;
    segment_tree st(arr, sizeof(arr)/ sizeof(arr[0]));
    start = chrono::high_resolution_clock::now();
    cout << st.get_sum(low,high) << endl;

    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    
    cout << elapsed.count() << endl;
    // st.display();
}