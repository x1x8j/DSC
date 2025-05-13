#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct Node {
	char data;
	Node* left;
	Node* right;
	Node(){}
	Node(char data):data(data),left(NULL),right(NULL){}
};


Node* create(string s, int& i) {
	if (i >= s.size() || s[i] == '#') {
		i++;
		return NULL;
	}
	Node* root = new Node(s[i]);
	i++;
	root->left=create(s, i);
	root->right=create(s, i);
	return root;
}



void preOrder(Node* root) {
	if (root != NULL) {
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);

	}
}


int main() {
	string s;
	getline(cin, s);
	int i = 0;
	Node* root = create(s, i);
	preOrder(root);

	return 0;
}
