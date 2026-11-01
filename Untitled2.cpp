#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class bst {
private:
    node* root;

    node* insert(node* node, int val) {
        if (node == NULL) {
            return new class node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        }

        if (val > node->data) {
            node->right = insert(node->right, val);
        }

        return node;
    }

    node* search(node* temp, int val) {
        if (temp == NULL || temp->data == val) {
            return temp;
        }
        else if (val < temp->data) {
            return search(temp->left, val);
        }
        else {
            return search(temp->right, val);
        }
    }

    node* deleten(node* temp, int val) {
        if (temp == NULL) {
            return NULL;
        }
        else if (temp->data > val) {
            temp->left = deleten(temp->left, val);
            return temp;
        }
        else if (temp->data < val) {
            temp->right = deleten(temp->right, val);
            return temp;
        }
        else {
            if (temp->left == NULL && temp->right == NULL) {
                delete temp;
                return NULL;
            }
            else if (temp->right == NULL) {
                node* t = temp->left;
                delete temp;
                return t;
            }
            else if (temp->left == NULL) {
                node* t = temp->right;
                delete temp;
                return t;
            }
            else {
                node* child = temp->left;
                node* parent = temp;

                while (child->right != NULL) {
                    parent = child;
                    child = child->right;
                }

                if (parent != temp) {
                    parent->right = child->left;
                    child->right = temp->right;
                    child->left = temp->left;
                    delete temp;
                    return child;
                }
                else {
                    child->right = temp->right;
                    delete temp;
                    return child;
                }
            }
        }
    }

    void inorder(node* temp) {
        if (temp == NULL) {
            return;
        }

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

public:
    bst() {
        root = NULL;
    }

    void inset(int val) {
        root = insert(root, val);
    }

    void deletion(int val) {
        root = deleten(root, val);
    }

    void search(int val) {
        node* result = search(root, val);

        if (result == NULL) {
            cout << "Value not found" << endl;
        }
        else {
            cout << "Value found: " << result->data << endl;
        }
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    // BFS / Level Order Traversal
    void bfs() {
        if (root == NULL) {
            return;
        }

        node* queue[100];
        int front = 0;
        int rear = 0;

        queue[rear] = root;
        rear++;

        while (front < rear) {
            node* temp = queue[front];
            front++;

            cout << temp->data << " ";

            if (temp->left != NULL) {
                queue[rear] = temp->left;
                rear++;
            }

            if (temp->right != NULL) {
                queue[rear] = temp->right;
                rear++;
            }
        }

        cout << endl;
    }
};

int main() {
    bst tree;

    tree.inset(50);
    tree.inset(30);
    tree.inset(70);
    tree.inset(20);
    tree.inset(40);
    tree.inset(60);
    tree.inset(80);
    tree.inset(25);
    tree.inset(35);

    cout << "BST before deletion: ";
    tree.display();

    cout << "BFS before deletion: ";
    tree.bfs();

    tree.search(40);
    tree.search(90);

    tree.deletion(30);

    cout << "BST after deleting 30: ";
    tree.display();

    cout << "BFS after deletion: ";
    tree.bfs();

    return 0;
}
