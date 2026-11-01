#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;

		node(int val){
			data=val;
			left=NULL;
			right=NULL;
		}
};

class binarytree{
	public:
		node* root;

		binarytree(){
			root=NULL;
		}

		void insert(int val){
			node* newnode=new node(val);

			if(root==NULL){
				root=newnode;
				return;
			}

			node* queue[100];
			int rear=0;
			int front=0;

			queue[rear]=root;
			rear++;

			while(front < rear){
				node* temp=queue[front];
				front++;

				if(temp->left==NULL){
					temp->left=newnode;
					return;
				}
				else{
					queue[rear]=temp->left;
					rear++;
				}

				if(temp->right==NULL){
					temp->right=newnode;
					return;
				}
				else{
					queue[rear]=temp->right;
					rear++;
				}
			}
		}

		void preorder(node* temp){
			if(temp==NULL){
				return;
			}

			cout<<temp->data<<" ";
			preorder(temp->left);
			preorder(temp->right);
		}

		void inorder(node* temp){
			if(temp==NULL){
				return;
			}

			inorder(temp->left);
			cout<<temp->data<<" ";
			inorder(temp->right);
		}

		void postorder(node* temp){
			if(temp==NULL){
				return;
			}

			postorder(temp->left);
			postorder(temp->right);
			cout<<temp->data<<" ";
		}

		void levelorder(){
			if(root==NULL){
				return;
			}

			node* queue[100];
			int front=0;
			int rear=0;

			queue[rear]=root;
			rear++;

			while(front<rear){
				node* temp=queue[front];
				front++;

				cout<<temp->data<<" ";

				if(temp->left!=NULL){
					queue[rear]=temp->left;
					rear++;
				}

				if(temp->right!=NULL){
					queue[rear]=temp->right;
					rear++;
				}
			}
		}
};

int main(){

	binarytree t;

	t.insert(20);
	t.insert(30);
	t.insert(40);
	t.insert(60);
	t.insert(80);
	t.insert(90);
	t.insert(100);

	cout<<"Preorder: ";
	t.preorder(t.root);
	cout<<endl;

	cout<<"Inorder: ";
	t.inorder(t.root);
	cout<<endl;

	cout<<"Postorder: ";
	t.postorder(t.root);
	cout<<endl;

	cout<<"Level Order: ";
	t.levelorder();
	cout<<endl;

	return 0;
}
