#include <iostream>

using namespace std;

struct node {
    int value;
    node *next;
};

class linked_list {
    private:
        node *tail, *head;
        int length;
    public:
    linked_list() {
  
        tail = NULL;
        head = NULL;
    };
    void add_node(int i) {
        node *tmp = new node;
        tmp->value = i;
        tmp->next = NULL;
        if(tail == NULL) {
            tail = tmp;
            head = tmp;
        } else {
            tail->next = tmp;
            tail = tail->next;
        }
        length++;
    };

    int get(int index) {
        if(index > length -1) return -1;
        node *current = head;
        for(int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }
    int find(int value) {
        node *current = head;
        int index = 0;
        do {
            if (current->value == value) return index;
            current = current->next;
            index++;
        } while(current != NULL);
        return -1;
    }

    void del(int index) {
        node *before_delete = head;
        node *to_delete = NULL;
        node *after_delete = NULL;
        for(int i = 0; i < index - 1; i++) {
            before_delete = before_delete->next;
        }
        to_delete = before_delete->next;
        after_delete = to_delete->next;
        before_delete->next = after_delete;

        delete to_delete;
    }

    void show() {
        node *current = head;
        do {
            cout << current->value << endl;
            current = current->next;
        } while(current != NULL);
    }
};


int main () {
    linked_list list;
    list.add_node(1);
    list.add_node(2);
    list.add_node(3);
    list.add_node(10);
    list.add_node(100);
    

    list.del(3);
    list.show();

    return 0;
}