#include <iostream>
#include<stdio.h>
#include <sstream>
#include<stdlib.h>
using namespace std; 
struct Node {
	int val;   // Value of the node
  	Node *left;   // Pointer to the left node
  	Node *right;  // Pointer to the right node
  	Node *parent; // Pointer to the parent node
};

class BST {
  	public: 
		enum TraversalOrder { InOrderTrav, PreOrderTrav, PostOrderTrav };

  	public:
    	BST();  // Constructor
   	~BST(); // Destructor
    	void Insert(int toInsert);
    	void Delete(int toDelete);
    	void Print(enum TraversalOrder);

  	private:
    		Node *root;
		Node *Search(int toFind); // Search for a node in the tree
    		void Transplant(Node *u, Node *v); // Replace the subtree rooted at node u with the subtree rooted at node v
    		void InOrder(Node *curr); 
    		void PreOrder(Node *curr); 
    		void PostOrder(Node *curr); 
	};
BST::BST() {
	root = NULL;
}
BST::~BST() {
	while (root != NULL){
		BST::Delete(root->val);
	}
}

void BST::Insert(int toInsert) {
	Node *x = root;
	Node *y = NULL;
	Node *z = new Node;
  	z->val = toInsert;
  	z->left = NULL;
  	z->right = NULL;
  	while (x != NULL){
    		y = x;
    		if (z->val < x->val){
      			x = x->left;
    		} 
		else {
      			x = x->right;
    		}
  	}
  
  	z->parent = y;

  	if (y == NULL){
    		root = z;
  	} 
	else if (z->val < y->val) {
    		y->left = z;
  	} 
	else {
    		y->right = z;
  	}

}

Node *treeMinimum(Node *x){
	while (x->left != NULL)
		x = x->left;
	return x;
}
void BST::Transplant(Node *u, Node *v) {
        if (u->parent == NULL)
                root = v;
        else if (u == u->parent->left)
                u->parent->left = v;
        else
                u->parent->right = v;
        if (v != NULL)
                v->parent = u->parent;
}

Node *search(Node *root, int toFind) {
        if (root == NULL || toFind == root->val)
                return root;
        if (toFind < root->val)
                return search(root->left, toFind);
        else
                return search(root->right, toFind);
}

Node *BST::Search(int toFind) {
        return search(root, toFind);
}


void BST::Delete(int toDelete) {
	Node *z = new Node;
	z = BST::Search(toDelete);

	if (z->left == NULL)
		BST::Transplant(z, z->right);
	else if (z->right == NULL)
		BST::Transplant(z, z->left);
	else
	{
		Node *y = new Node;
		y = treeMinimum(z->right);
		if (y->parent != z){
			BST::Transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		BST::Transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}


void BST::Print(TraversalOrder Order) {
	if(Order==InOrderTrav)
    		InOrder(root);
  	else if(Order==PreOrderTrav)
    		PreOrder(root);
  	else if(Order==PostOrderTrav)
    		PostOrder(root);
}

void BST::PreOrder(Node *x) {
  	if (x == NULL)
    		return;
  	cout << x->val << endl;
  	BST::PreOrder(x->left);
  	BST::PreOrder(x->right);
}

void BST::InOrder(Node *x) {
  	if (x == NULL)
    		return;
  	BST::InOrder(x->left);
  	cout << x->val << endl;
  	BST::InOrder(x->right);
}

void BST::PostOrder(Node *x) {
  	if (x == NULL)
    	return;
  	BST::PostOrder(x->left);
  	BST::PostOrder(x->right);
  	cout << x->val << endl;
}
int main(int argc,char **argv) {
  	// Creates an empty Binary Search Tree
  	BST Tree;
  	char line[100];
  	while ( std::cin.getline(line,100) ){
    		string str(line);
    		if ( str.size()==0 ) continue; 
    		if ( str[0]=='e' ) return 1;

    		if ( str[0]=='o' ){
      			if ( str.substr(0,3)=="oin" ){   
        			Tree.Print(BST::InOrderTrav);
      			}
			else if ( str.substr(0,4)=="opre" ){
        			Tree.Print ( BST::PreOrderTrav );
      			}
			else if (str.substr(0,5) == "opost"){
        			Tree.Print(BST::PostOrderTrav);
      			}
     		}
		else{ 
			int key;
       			stringstream convert_stm(str.substr(1,str.size()-1));
       			if ( !(convert_stm>>key) ) 
				key = -1;

       			if (str.substr(0,1) == "i") Tree.Insert(key);
       			else if (str.substr(0,1) == "d") Tree.Delete(key);
		}
  	}
 	return 1;
}

