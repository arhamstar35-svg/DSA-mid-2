#include <iostream>
using namespace std;

const int MAX = 100;

class BST {
private:
    int data[MAX];
    int leftChild[MAX];
    int rightChild[MAX];
    int root;
    int count;

    int createNode(int value) {
        data[count] = value;
        leftChild[count] = -1;
        rightChild[count] = -1;
        return count++;
    }

    int insertNode(int node, int value) {
        if (node == -1) {
            return createNode(value);
        }

        if (value < data[node]) {
            leftChild[node] = insertNode(leftChild[node], value);
        }
        else if (value > data[node]) {
            rightChild[node] = insertNode(rightChild[node], value);
        }

        return node;
    }

    bool searchNode(int node, int value) {
        if (node == -1) {
            return false;
        }

        if (data[node] == value) {
            return true;
        }

        if (value < data[node]) {
            return searchNode(leftChild[node], value);
        }

        return searchNode(rightChild[node], value);
    }

    void inorder(int node) {
        if (node == -1) {
            return;
        }

        inorder(leftChild[node]);
        cout << data[node] << " ";
        inorder(rightChild[node]);
    }

    int deleteNode(int node, int value) {
        if (node == -1) {
            return -1;
        }

        if (value < data[node]) {
            leftChild[node] = deleteNode(leftChild[node], value);
        }
        else if (value > data[node]) {
            rightChild[node] = deleteNode(rightChild[node], value);
        }
        else {
            // Case 1: No children
            if (leftChild[node] == -1 && rightChild[node] == -1) {
                return -1;
            }

            // Case 2: No left child
            if (leftChild[node] == -1) {
                return rightChild[node];
            }

            // Case 3: No right child
            if (rightChild[node] == -1) {
                return leftChild[node];
            }

            // Case 4: Both children exist
            int child = leftChild[node];
            int parent = node;

            // Find the inorder predecessor
            while (rightChild[child] != -1) {
                parent = child;
                child = rightChild[child];
            }

            // Predecessor is deeper in the left subtree
            if (parent != node) {
                rightChild[parent] = leftChild[child];

                rightChild[child] = rightChild[node];
                leftChild[child] = leftChild[node];

                return child;
            }
            else {
                // Predecessor is the immediate left child
                rightChild[child] = rightChild[node];

                return child;
            }
        }

        return node;
    }

public:
    BST() {
        root = -1;
        count = 0;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    bool search(int value) {
        return searchNode(root, value);
    }

    void sort() {
        inorder(root);
        cout << endl;
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }
};

int main() {
    BST tree;

    tree.insert(16);
    tree.insert(5);
    tree.insert(7);
    tree.insert(20);
    tree.insert(3);
    tree.insert(11);
    tree.insert(4);
    tree.insert(18);
    tree.insert(48);
    tree.insert(56);
    tree.insert(36);

    cout << "BST in sorted order: ";
    tree.sort();

    if (tree.search(11)) {
        cout << "11 found in BST" << endl;
    }
    else {
        cout << "11 not found in BST" << endl;
    }

    tree.insert(13);

    cout << "After inserting 13: ";
    tree.sort();

    tree.remove(20);

    cout << "After deleting 20: ";
    tree.sort();

    return 0;
}
