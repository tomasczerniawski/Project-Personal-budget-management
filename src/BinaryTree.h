#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Expense.h"
#include "Income.h"
#include <iostream>

template <class T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <class T>
class BinaryTree {
private:
    BinaryTreeNode<T>* root;

    BinaryTreeNode<T>* insertRecursive(BinaryTreeNode<T>* currentNode, T entry) {
        if (currentNode == nullptr) {
            return new BinaryTreeNode<T>(entry);
        }

        if (entry.getAmount() < currentNode->data.getAmount()) {
            currentNode->left = insertRecursive(currentNode->left, entry);
        }
        else {
            currentNode->right = insertRecursive(currentNode->right, entry);
        }

        return currentNode;
    }

    void inOrderTraversalRecursive(BinaryTreeNode<T>* currentNode) {
        if (currentNode == nullptr) {
            return;
        }

        inOrderTraversalRecursive(currentNode->left);
        std::cout << currentNode->data.getDescription() << " ";
        inOrderTraversalRecursive(currentNode->right);
    }

    BinaryTreeNode<T>* searchRecursive(BinaryTreeNode<T>* currentNode, const std::string& keyword) {
        if (currentNode == nullptr || currentNode->data.getDescription() == keyword) {
            return currentNode;
        }

        BinaryTreeNode<T>* leftResult = searchRecursive(currentNode->left, keyword);
        if (leftResult != nullptr) {
            return leftResult;
        }

        return searchRecursive(currentNode->right, keyword);
    }

public:
    BinaryTree() : root(nullptr) {}

    void insertNode(T entry) {
        if (root == nullptr) {
            root = new BinaryTreeNode<T>(entry);
        }
        else {
            insertRecursive(root, entry);
        }
    }

    void inOrderTraversal() {
        inOrderTraversalRecursive(root);
        std::cout << std::endl;
    }

    BinaryTreeNode<T>* getRoot() const {
        return root;
    }

    BinaryTreeNode<T>* search(const std::string& keyword) {
        return searchRecursive(root, keyword);
    }
};

#endif // BINARY_TREE_H
