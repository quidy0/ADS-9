// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* addNode(Node*, T);
    int sTree(Node*, T);
    int dTree(Node*);

 public:
    BST();
    int depth();
    void add(T);
    int search(T);
};

template <typename T>
BST<T>::BST() {
    root = nullptr;
}
template <typename T>
int BST<T>::dTree(Node* root) {
    if (root == nullptr)
        return 0;
    int L = dTree(root->left);
    int R = dTree(root->right);
    if (L > R) {
        return L + 1;
    }else{
        return R + 1;
    }
}
template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
    } else if (root->value > value) {
        root->left = addNode(root->left, value);
    } else if (root->value < value) {
        root->right = addNode(root->right, value);
    } else {
        root->count++;
    }
    return root;
}
template <typename T>
void BST<T>::add(T value) {
    root = addNode(root, value);
}
template <typename T>
int BST<T>::sTree(Node* root, T value) {
    if (root == nullptr) {
        return 0;
    } else if (value < root->value) {
        return sTree(root->left, value);
    } else if (value > root->value) {
        return sTree(root->right, value);
    } else {
        return root->count;
    }
}
template <typename T>
int BST<T>::depth() {
    return dTree(root) - 1;
}
template <typename T>
int BST<T>::search(T value) {
    return sTree(root, value);
}
#endif  // INCLUDE_BST_H_