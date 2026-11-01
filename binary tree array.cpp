#include<iostream>
using namespace std;

const int size = 100;
const int empty = -1;

int tree[size];

void initialize(){
    for(int i = 0; i < size; i++){
        tree[i] = empty;
    }
}

void insertNode(int val){
    if(tree[0] == empty){
        tree[0] = val;
        return;
    }

    for(int i = 1; i < size; i++){
        if(tree[i] == empty){
            tree[i] = val;
            return;
        }
    }

    cout << "Tree is full!" << endl;
}

void search(int val){
    if(tree[0] == empty){
        cout << "Empty Array" << endl;
        return;
    }
    else{
        for(int i = 0; i < size; i++){
            if(tree[i] == val){
                cout << "Value: " << tree[i]
                     << " Found at index: " << i << endl;
                return;
            }
        }

        cout << "Value not found" << endl;
    }
}

void preorder(int index){
    if(index >= size || tree[index] == empty){
        return;
    }

    cout << tree[index] << " ";
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

void inorder(int index){
    if(index >= size || tree[index] == empty){
        return;
    }

    inorder(2 * index + 1);
    cout << tree[index] << " ";
    inorder(2 * index + 2);
}

void postorder(int index){
    if(index >= size || tree[index] == empty){
        return;
    }

    postorder(2 * index + 1);
    postorder(2 * index + 2);
    cout << tree[index] << " ";
}

int main(){
    initialize();

    insertNode(10);
    insertNode(25);
    insertNode(5);
    insertNode(3);
    insertNode(12);
    insertNode(24);
    insertNode(30);

    cout << "Preorder Traversal: ";
    preorder(0);

    cout << "\nInorder Traversal: ";
    inorder(0);

    cout << "\nPostorder Traversal: ";
    postorder(0);

    cout << "\n\nSearching for 12: ";
    search(12);

    cout << "Searching for 50: ";
    search(50);

    return 0;
}
