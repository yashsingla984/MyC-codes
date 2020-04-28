#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Node
{
    public:
    	int key;
    	Node *left;
    	Node *right;
    	int height;


};

int max(int a, int b)  
{  
	if(a>b)
    return a;
    else 
    	return b;
}  

int height(Node *node)
{
	int h=0;
	if(node==NULL)
	{
		h=0;
	}
	else
	{
		h=node->height;
	}
	return h;
}

Node *rightRotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 
	x->height = max(height(x->left), 
					height(x->right)) + 1; 

	// Return new root 
	return x; 
} 

// A utility function to left 
// rotate subtree rooted with x 
// See the diagram given above. 
Node *leftRotate(Node *x) 
{ 
	Node *y = x->right; 
	Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left),	 
					height(x->right)) + 1; 
	y->height = max(height(y->left), 
					height(y->right)) + 1; 

	// Return new root 
	return y; 
}

/*Node *leftrotate(Node *x)
{
	Node *y=x->right;
	Node *T2=y->left;

     
    x->right=T2;
    
	y->left=x;

 //update height

	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;

	return y;


}


Node *rightrotate(Node *x)
{
	Node *y=x->left;
	Node *T2=y->right;

     
    x->left=T2;
    
	y->right=x;

 //update height

	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;

	return y;


}*/

/*int Balance(Node *node1,Node *node2)
{
	int h1=node1->height;
	int h2=node2->height;

	return h1-h2;

}*/

int getBalance(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
}

Node* newNode(int key)
{
	Node* node=new Node();
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->height=1;

	return node;


}

Node* insert(Node* node, int key) 
{ 
	/* 1. Perform the normal BST insertion */
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else // Equal keys are not allowed in BST 
		return node; 

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	/* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
	int balance = getBalance(node); 

	// If this node becomes unbalanced, then 
	// there are 4 cases 

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 

// A utility function to print preorder 
// traversal of the tree. 
// The function also prints height 
// of every node 

/*Node* insert(Node* node,int key)
{
	if(node==NULL)
	{
       return newNode(key);
	}
	else if(key< node->key)
	{
		node->left=insert(node->left,key);
	}
	else if(key> node->key)
	{
		node->right=insert(node->right,key);
	}
	else 
		return node;

	2. Update height of this ancestor node 
	node->height=1+max(height(node->left),height(node->right));

	int balance=Balance(node->left,node->right);
    3. To balance the tree 
    //Left Left Key case
	if(balance >1 && key<node->left->key)
	{
		rightRotate(node->left);
	}
	//left Right case
	if(balance>1 && key>node->left->key)
	{
		node->left=leftRotate(node->left);
		rightRotate(node);
	}
    //right right Key case
	if(balance <-1 && key>node->right->key)
	{
		leftRotate(node->right);
	}
	//right left Key case
	if(balance <-1 && key<node->right->key)
	{
		node->right=rightRotate(node->right);
		leftRotate(node);
	}

	return node;


}*/

void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  
int main(int argc, char const *argv[])
{
	
	Node *root=NULL;

	root = insert(root, 10);  
	cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    root = insert(root, 20);  
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    root = insert(root, 30);  
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preOrder(root);  
      

	return 0;
}