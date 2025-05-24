#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n, m;

struct node {
	int data;
	node* next;
	node(){}
	node(int data):data(data),next(NULL){}
};

struct headnode {
	int data;
	node* linkhead;
	headnode(){}
	headnode(int data):data(data),linkhead(NULL){}
};

vector<int>ru(n + 1);

int main() {
	cin >> n >> m;
	vector<headnode*>head(n+1);
	for (int i = 1; i <= n; i++) {
		head[i] = new headnode(i);
	}
	int begin, end;
	for (int i = 0; i < m; i++) {
		cin >> begin >> end;
		node* temp = new node(end);
		temp->next = head[begin]->linkhead;
		head[begin]->linkhead = temp;
	}




	for (int i = 1; i <= n; i++) {
		node* cur = head[i]->linkhead;
		while (cur != NULL) {
			ru[cur->data]++;
			cur = cur->next;
		}
	}

	stack<int>st;
	for (int i = 1; i <= n; i++) {
		if (ru[i] == 0) {
			st.push(i);
		}
	}
	while (!st.empty()) {
		int cur = st.top();
		st.pop();
		node*temp = head[cur]->linkhead;
		while (temp != NULL) {
			ru[temp->data]--;
			if (ru[temp->data] == 0) {
				st.push(temp->data);
			}
			temp = temp->next;
		}

	}

	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (ru[i] > 0) {
			flag = true;
		}
	}

	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
