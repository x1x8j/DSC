#include<iostream>
#include<string>
#include<stack>
#include<cctype>
#include<queue>
#include<algorithm>
using namespace std;

struct Node {
	char data;
	Node* left;
	Node* right;
	Node(){}
	Node(char data):data(data),left(NULL),right(NULL){}
};

int evaluate(Node* root) {
	if (root == NULL) {
		return 0;
	}
	if(isdigit(root->data)) {
		return root->data - '0';
	}
	if(isalpha(root->data)) {
		return root->data;
	}

	int left = evaluate(root->left);
	int right = evaluate(root->right);
	switch(root->data) {
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		return left / right;
	}

	
}

string levelOrder(Node* root) {
	string s = "";
	queue<Node*>q;
	q.push(root);
	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();
		s += temp->data;
		if (temp->left != NULL) {
			q.push(temp->left);
		}
		if (temp->right != NULL) {
			q.push(temp->right);
		}
	}
	return s;
}

int calculate(string s) {
	queue<int>q;
	int a, b;
	for (char c : s) {
		switch (c) {
		case '+':
			a  = q.front();q.pop();
			b  = q.front();q.pop();
			q.push(b+a);
			break;
		case '-':
			a  = q.front();q.pop();
			b  = q.front();q.pop();
			q.push(b-a);
			break;
		case '*':
			a  = q.front();q.pop();
			b  = q.front();q.pop();
			q.push(b*a);
			break;
		case '/':
			a  = q.front();q.pop();
			b  = q.front();q.pop();
			q.push(b/a);
			break;
		default:
			if  (isdigit(c)) {
				q.push(c-'0');
			}
			 else {
				q.push(c);
			}
		}
	}
	return q.front();
}

int main() {
	stack<char>op;
	stack<Node*>exp;
	string s;
	getline(cin, s);
	for (char c : s) {
		if (c == '(') {
			op.push(c);
		}
		else if (c == ')') {
			while (op.top() != '(') {
				Node* exp1 = exp.top(); exp.pop();
				Node* exp2 = exp.top(); exp.pop();
				char op1 = op.top(); op.pop();
				Node* temp = new Node(op1);
				temp->left = exp2;
				temp->right = exp1;
				exp.push(temp);
			}
			op.pop();
		}
		else if (c == '+' || c == '-') {
			while (!op.empty() && op.top() != '(') {
				Node* exp1 = exp.top(); exp.pop();
				Node* exp2 = exp.top(); exp.pop();
				char op1 = op.top(); op.pop();
				Node* temp = new Node(op1);
				temp->left = exp2;
				temp->right = exp1;
				exp.push(temp);
			}
			op.push(c);
		}
		else if (c == '*' || c == '/') {
			while (!op.empty() && op.top() != '(' && op.top()!= '+' && op.top() != '-') {
				Node* exp1 = exp.top(); exp.pop();
				Node* exp2 = exp.top(); exp.pop();
				char op1 = op.top(); op.pop();
				Node* temp = new Node(op1);
				temp->left = exp2;
				temp->right = exp1;
				exp.push(temp);
			}
			op.push(c);
		}
		else {
			exp.push(new Node(c));
		}
	}
	while (!op.empty()) {
		Node* exp1 = exp.top(); exp.pop();
		Node* exp2 = exp.top(); exp.pop();
		char op1 = op.top(); op.pop();
		Node* temp = new Node(op1);
		temp->left = exp2;
		temp->right = exp1;
		exp.push(temp);
	}
	Node* root = exp.top();

	int res=evaluate(root);
	cout << res << endl;

	string level = levelOrder(root);
	reverse(level.begin(), level.end());
	cout << level << endl;

	int res2 = calculate(level);
	cout << res2 << endl;

	return 0;
}
