#include <iostream> 
using namespace std; 

// A binary Tree node 
struct node 
{ 
	int data; 
	struct node *left, *right; 
}; 

/* Recursive function to print all the nodes at distance k in the 
tree (or subtree) rooted with given root.*/
void printkdistancedown(node *root, int k) 
{ 
	if (root == NULL || k < 0) 
		return; 

	if (k==0) 
	{ 
		cout << root->data << endl; 
		return; 
	} 

	printkdistancedown(root->left, k-1); 
	printkdistancedown(root->right, k-1); 
} 

// Prints all nodes at distance k from a given target node. 
// The k distant nodes may be upward or downward. This function 
// Returns distance of root from target node, it returns -1 if target 
// node is not present in tree rooted with root. 
int printkdistance(node* root, node* target , int k) 
{ 
	if (root == NULL) return -1; 

	if (root == target) 
	{ 
		printkdistancedown(root, k); 
		return 0; 
	} 

	int l = printkdistance(root->left, target, k); 

	if (l != -1) 
	{ 
		if (l + 1 == k) 
			cout << root->data << endl; 

		else
			printkdistancedown(root->right, k-l-2); 

		return 1 + l; 
	} 

	int r = printkdistance(root->right, target, k); 
	if (r != -1) 
	{ 
		if (r + 1 == k) 
			cout << root->data << endl; 
		else
			printkdistancedown(root->left, k-r-2); 
		return 1 + r; 
	} 

	return -1; 
} 

// A utility function to create a new binary tree node 
node *newnode(int data) 
{ 
	node *temp = new node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	node * root = newnode(20); 
	root->left = newnode(8); 
	root->right = newnode(22); 
	root->left->left = newnode(4); 
	root->left->right = newnode(12); 
	root->left->right->left = newnode(10); 
	root->left->right->right = newnode(14); 
	node * target = root->left->right; 
	printkdistance(root, target, 2); 
	return 0; 
}

