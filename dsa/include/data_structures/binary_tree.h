#pragma once
#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    void insert(Node*& node, int key) {
        if (node == nullptr) {
            node = new Node(key);
        } else {
            if (key < node->key) {
                insert(node->left, key);
            } else {
                insert(node->right, key);
            }
        }
    }

    bool search(Node* node, int key) {
        if (node == nullptr) {
            return false;
        }

        if (key == node->key) {
            return true;
        } else if (key < node->key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    void destroy_tree(Node*& node) {
        if (node != nullptr) {
            destroy_tree(node->left);
            destroy_tree(node->right);
            delete node;
            node = nullptr;
        }
    }

    void inorder_print(Node* node) {
        if (node != nullptr) {
            inorder_print(node->left);
            std::cout << node->key << " ";
            inorder_print(node->right);
        }
    }

    void postorder_print(Node* node) {
        if (node != nullptr) {
            postorder_print(node->left);
            postorder_print(node->right);
            std::cout << node->key << " ";
        }
    }

    void preorder_print(Node* node) {
        if (node != nullptr) {
            std::cout << node->key << " ";
            preorder_print(node->left);
            preorder_print(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        destroy_tree();
    }

    void insert(int key) {
        insert(root, key);
    }

    bool search(int key) {
        return search(root, key);
    }

    void destroy_tree() {
        destroy_tree(root);
    }

    void inorder_print() {
        inorder_print(root);
        std::cout << '\n';
    }

    void postorder_print() {
        postorder_print(root);
        std::cout << '\n';
    }

    void preorder_print()
	{
        preorder_print(root);
        std::cout << '\n';
    }
};
