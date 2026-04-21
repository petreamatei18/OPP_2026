#ifndef TREE_H
#define TREE_H

#include <cstdio>

template <typename T>
class Tree {
public:
    struct Node {
        T value;
        Node** children;
        int children_count;
        int capacity;

        Node(const T& val) : value(val), children_count(0), capacity(10) {
            children = new Node*[capacity];
        }

        ~Node() {
            for (int i = 0; i < children_count; i++) {
                delete children[i];
            }
            delete[] children;
        }

        void add_child(Node* child) {
            if (children_count == capacity) {
                capacity *= 2;
                Node** new_children = new Node*[capacity];
                for (int i = 0; i < children_count; i++) new_children[i] = children[i];
                delete[] children;
                children = new_children;
            }
            children[children_count++] = child;
        }

        void insert_child(Node* child, int index) {
            if (index < 0 || index > children_count) return;
            // Ne asigurăm că avem loc în array
            if (children_count == capacity) add_child(nullptr);
            else children_count++;

            for (int i = children_count - 1; i > index; i--) {
                children[i] = children[i - 1];
            }
            children[index] = child;
        }
    };

private:
    Node* root;

public:
    Tree() : root(nullptr) {}
    ~Tree() { delete root; }

    Node* add_node(Node* parent, const T& value) {
        Node* newNode = new Node(value);
        if (parent == nullptr) {
            if (root == nullptr) root = newNode;
            else { delete newNode; return root; }
        } else {
            parent->add_child(newNode);
        }
        return newNode;
    }

    Node* get_node(Node* parent) {
        return (parent == nullptr) ? root : parent;
    }

    void delete_node(Node* node) {
        if (node == nullptr) return;
        if (node == root) {
            delete root;
            root = nullptr;
        } else {
            // Notă: O implementare completă ar căuta nodul în lista părintelui
            delete node;
        }
    }

    void insert(Node* parent, int index, const T& value) {
        if (parent == nullptr) return;
        Node* newNode = new Node(value);
        parent->insert_child(newNode, index);
    }

    Node* find(Node* startNode, bool (*compare)(const T&, const T&), const T& value) {
        if (startNode == nullptr) startNode = root;
        if (startNode == nullptr) return nullptr;

        if (compare(startNode->value, value)) return startNode;

        for (int i = 0; i < startNode->children_count; i++) {
            Node* res = find(startNode->children[i], compare, value);
            if (res) return res;
        }
        return nullptr;
    }

    void sort(Node* node, bool (*callback)(const T&, const T&) = nullptr) {
        if (node == nullptr) return;
        for (int i = 0; i < node->children_count - 1; i++) {
            for (int j = i + 1; j < node->children_count; j++) {
                bool swap_needed = false;
                if (callback) swap_needed = callback(node->children[i]->value, node->children[j]->value);
                else swap_needed = node->children[j]->value < node->children[i]->value;

                if (swap_needed) {
                    Node* temp = node->children[i];
                    node->children[i] = node->children[j];
                    node->children[j] = temp;
                }
            }
        }
    }

    int count(Node* node) {
        if (node == nullptr) node = root;
        if (node == nullptr) return 0;

        int total = node->children_count;
        for (int i = 0; i < node->children_count; i++) {
            total += count(node->children[i]);
        }
        return total;
    }
};

#endif