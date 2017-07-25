#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *left;
	Node *right;
};

// TODO: add travasal methods
class BineryTree{
public:
	BineryTree();
	~BineryTree();

	void insert(int value);
	Node *search(int value);
	void destroy();

private:
	void insert(int value, Node *pnode);
	Node *search(int value, Node *pnode);
	void destroy(Node *pnode);

	Node *root;
};


BineryTree::BineryTree() {
	root = NULL;
}

void BineryTree::insert(int value, Node *pnode) {
	if(value < pnode->value) {
		if(pnode->left != NULL) {
			insert(value, pnode->left);
		} else {
			pnode->left = new Node;
			
			pnode->left->value = value;
			pnode->left->left = NULL;
			pnode->left->right = NULL;
		}
	} else if(value >= pnode->value) {
		if(pnode->right != NULL) {
			insert(value, pnode->right);
		} else {
			pnode->right = new Node;

			pnode->right->value = value;
			pnode->right->left = NULL;
			pnode->right->right = NULL;
		}
	}
}

void BineryTree::insert(int value){
	if(root != NULL) {
		insert(value, root);
	} else {
		root = new Node;

		root->value = value;
		root->left = NULL;
		root->right = NULL;
	}
}

Node *BineryTree::search(int value, Node *pnode) {
	if(pnode != NULL) {
		if(value == pnode->value) return pnode;
		if(value < pnode->value) return search(value, pnode->left);
		return search(value, pnode->right);
	} else {
		return NULL;
	}
}

Node *BineryTree::search(int value) {
	return search(value, root);
}

void BineryTree::destroy(Node *pnode) {
	if(pnode != NULL) {
		destroy(pnode->left);
		destroy(pnode->right);
		
		delete pnode;
	}
}

void BineryTree::destroy() {
	destroy(root);
}

int main() {
	BineryTree* bTree = new BineryTree;
	bTree->insert(3);
	bTree->insert(4);
	bTree->insert(2);

	cout << bTree->search(3)->value << endl;
	cout << bTree->search(4)->value << endl;
	cout << bTree->search(2)->value << endl;
}

