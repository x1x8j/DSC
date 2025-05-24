#include<iostream>
#include<string>
#include<cmath>
using namespace std;


struct node {
	char data;
	node* left;
	node* right;
	int height;
	node(){}
	node(char c) :data(c), left(NULL), right(NULL),height(1){}
};

int getheight(node* root) {
	return root == NULL ? 0 : root->height;
}

void postorder(node* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data;
}

void updateheight(node* root) {
	if (root == NULL) {
		return;
	}
	root->height=  max(getheight(root->left), getheight(root->right)) + 1;
}

node* rightrotate(node* root) {
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateheight(root);
	updateheight(temp);
	return temp;
}

node* leftrotate(node* root) {
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateheight(root);
	updateheight(temp);
	return temp;
}

int getbalance(node* root) {
	if (root == NULL) return 0;
	return getheight(root->left) - getheight(root->right);
}

node* insert(node* root, char data) {
	if (root == NULL) {
		root = new node(data);
		return root;
	}
	else if (data < root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}

	updateheight(root);
	int balance=getbalance(root);

	//LL
	if (balance > 1 && data < root->left->data) {
		return rightrotate(root);
	}
	//RR
	if (balance < -1 && data > root->right->data) {
		return leftrotate(root);
	}
	//LR
	if (balance > 1 && data > root->left->data) {
		root->left = leftrotate(root->left);
		return rightrotate(root);

	}
	//RL
	if (balance < -1 && data < root->right->data) {
		root->right = rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
}

node* findmin(node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

node* del(node* root, char data) {
	if (root == NULL) {
		return root;
	}
	else if (data < root->data) {
		root->left = del(root->left, data);
	}
	else if (data > root->data) {
		root->right = del(root->right, data);
	}
	else {
		//0child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//1child
		else if (root->left == NULL) {
			node* temp = root;
			root=root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			node* temp = root;
			root=root->left;
			delete temp;
		}
		else {
			node* temp = findmin(root->right);
			root->data = temp->data;
			root->right = del(root->right, temp->data);
		}
	}

	updateheight(root);
	int balance = getbalance(root);

	//LL
	if (balance > 1 && getbalance(root->left) >= 0) {
		return rightrotate(root);
	}
	//RR
	if (balance < -1 && getbalance(root->right) <= 0) {
		return leftrotate(root);
	}
	//LR
	if (balance > 1 && getbalance(root->left) <= 0) {
		root->left = leftrotate(root->left);
		return rightrotate(root);
	}
	//RL
	if (balance < -1 && getbalance(root->right) >= 0) {
		root->right = rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
	
}


int main() {

	cin >> n1;
	char c;
	node* root = NULL;
	for (int i = 0; i < n1; i++) {
		cin >> c;
		root=insert(root,c);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> c;
		root=del(root,c);
	}

	postorder(root);

	return 0;
}
