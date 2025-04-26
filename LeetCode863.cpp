//#include<iostream>
//#include<string>
//#include<fstream>
//#include<sstream>
//#include<queue>
//#include<stack>
//#include<vector>
//using namespace std;
//
//int target, k;
//
//
//struct Node {
//	int data;
//	int flag;
//	Node* left;
//	Node* right;
//	Node(){}
//	Node(int data):data(data),flag(0),left(NULL),right(NULL){}
//};
//
//queue<Node*>q;
//vector<Node*>st;//Ä£ÄâÕ»
//vector<Node*>res;
//Node* root = NULL;
//
//int main() {
//	ifstream in("in.txt");
//	string s;
//	getline(in, s);
//	in >> target >> k;
//	s = s.substr(1, s.length() - 2);
//	stringstream ss(s);
//	string t;
//	while (getline(ss, t, ',')) {
//		if (root == NULL) {
//			root = new Node(stoi(t));
//			q.push(root);
//		}
//		else {
//			Node* cur = q.front();
//			if (cur->flag == 0) {
//				if (t != "#") {
//					cur->left = new Node(stoi(t));
//					q.push(cur->left);
//				}
//				cur->flag++;
//			}
//			else {
//				if (t != "#") {
//					cur->right = new Node(stoi(t));
//					q.push(cur->right);
//				}
//				q.pop();
//			}
//		}
//	}
//	
//
//	Node* temp = root;
//	bool flag;
//	int distance;
//	bool flag2 = false;
//	Node* per;
//	
//	do {
//		while (temp != NULL) {
//			st.push_back(temp);
//			temp = temp->left;
//		}
//		flag = true;
//		per = NULL;
//		while (flag && !st.empty()) {
//			temp = st.back();
//			if (temp->right == per) {
//				if (st.size() > k) {
//					if (st[st.size() - k - 1] ->data== target) {
//						res.push_back(temp);
//					}
//				}
//				if (flag2) {
//					if (st.size()-1 == distance) {
//						res.push_back(temp);
//					}
//				}
//				if (temp->data == target) {
//					flag2 = true;//Ä¿±ê½áµãÒª³öÕ»
//					int now=st.size()-1;
//					if (now >= k) {
//						distance = now - k;
//					}
//					else {
//						distance = k - now;
//					}
//					
//				}
//			
//				st.pop_back();
//				per = temp;
//			}
//			else {
//				temp = temp->right;
//				flag = false;
//			}
//		}
//	} while (!st.empty());
//
//	cout << "[";
//	for (int i = 0; i < res.size(); i++) {
//		if (i == res.size() - 1) {
//			cout << res[i]->data;
//		}
//		else {
//			cout << res[i]->data << ",";
//		}
//	}
//	cout << "]" << endl;
//
//
//	return 0;
//}

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;




struct Node {
	int data;
	int flag;
	Node* left;
	Node* right;
	Node() {}
	Node(int data) :data(data), flag(0), left(NULL), right(NULL) {}
};

int target, k;
unordered_map<int, Node*>parent;

queue<Node*>q;
vector<Node*>res;
Node* root = NULL;

void createParent(Node* cur) {
	if (cur->left != NULL) {
		parent[cur->left->data] = cur;
		createParent(cur->left);
	}
	if (cur->right != NULL) {
		parent[cur->right->data] = cur;
		createParent(cur->right);
	}
}

void find(Node* cur, Node* from,int depth, int k) {
	if (cur == NULL)
		return;
	if (depth == k) {
		res.push_back(cur);
		return;
	}
	if (cur->left != from) {
		find(cur->left, cur, depth + 1, k);
	}
	if ( cur->right != from) {
		find(cur->right, cur, depth + 1, k);
	}
	if (parent[cur->data] != from) {
		find(parent[cur->data], cur, depth + 1, k);
	}

}

int main() {
	ifstream in("in.txt");
	string s;
	getline(in, s);
	in >> target >> k;
	s = s.substr(1, s.length() - 2);
	stringstream ss(s);
	string t;
	Node* tt=NULL;
	while (getline(ss, t, ',')) {
		if (root == NULL) {
			root = new Node(stoi(t));
			if(root->data==target)
				tt=root;
			q.push(root);
		}
		else {
			Node* cur = q.front();
			if (cur->flag == 0) {
				if (t != "#") {
					cur->left = new Node(stoi(t));
					if(cur->left->data==target)
						tt=cur->left;
					q.push(cur->left);
				}
				cur->flag++;
			}
			else {
				if (t != "#") {
					cur->right = new Node(stoi(t));
					if (cur->right->data == target)
						tt = cur->right;
					q.push(cur->right);
				}
				q.pop();
			}
		}
	}

	createParent(root);

	find(tt,root,0, k);

	

	cout << "[";
	for (int i = 0; i < res.size(); i++) {
		if (i == res.size() - 1) {
			cout << res[i]->data;
		}
		else {
			cout << res[i]->data << ",";
		}
	}
	cout << "]" << endl;


	return 0;
}
