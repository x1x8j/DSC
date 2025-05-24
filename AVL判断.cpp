#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<fstream>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
	node(){}
	node(int data):data(data),left(NULL),right(NULL){}
};

int height(node* root) {
	if (root == NULL) {
		return 0;
	}
	return max(height(root->left), height(root->right)) + 1;
}

int main() {
	string s;
	node* root = NULL;
	node* cur = NULL;
	queue<node*>q;
	bool flag = true;

	ifstream in("in.txt");
	ofstream out("out.txt");

	while (in>>s){

		if (s == "null") {
			cur = NULL;
		}
		else {
			cur = new node(stoi(s));
		}

		if (root == NULL) {
			root = cur;
			if (root == NULL) {
				out << "True" << endl;
				return 0;
			}
			q.push(root);
			continue;
		}

		if (!q.empty()&&flag == true) {
			q.front()->left = cur;
			if  (cur != NULL) {
				q.push(cur);
			}
			flag = false;
		}
		else if (!q.empty() && flag == false){
			q.front()->right = cur;
			if (cur != NULL) {
				q.push(cur);
			}
			q.pop();
			flag = true;
		}
	}

	
	queue<node*>qq;
	qq.push(root);

	while (!qq.empty()) {
		node* cur = qq.front();
		qq.pop();
		int diff=height(cur->left)-height(cur->right);
		if (abs(diff) > 1) {
			out << "False" << endl;
			return 0;
		}
		if (cur->left != NULL) {
			qq.push(cur->left);
		}
		if (cur->right != NULL) {
			qq.push(cur->right);
		}

	}
	out << "True" << endl;

	return 0;
}
