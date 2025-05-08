#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
#define maxV 100

struct MGraph{
	int numV=0;
	int numE;
	char list[maxV];
	int edge[maxV][maxV];
};

vector<char>ans;

int find(char c,MGraph G) {
	for (int i = 0; i < G.numV; i++) {
		if (G.list[i] == c) {
			return i;
		}
	}

}

struct record {
	int in = 0;
	int out = 0;
};

void findk(MGraph G) {
	vector<record>r(G.numV);
	for (int i = 0; i < G.numV; i++) {
		for (int j = 0; j < G.numV; j++) {
			if (G.edge[i][j] == 1) {
				r[i].out++;
				r[j].in++;
			}
		}
	}
	for (int i = 0; i < G.numV; i++) {
		if (r[i].in < r[i].out) {
			ans.push_back(G.list[i]);
		}
	}

}

int main() {
	MGraph G;
	string input;
	getline(cin, input);
	input = input.substr(1, input.length() - 2);
	stringstream ss(input);
	string str;
	int num = 0;
	while (getline(ss, str, ',')) {
		G.list[num++] = str[0];
		G.numV++;
	}
	getline(cin, input);
	for (int i = 0;i<input.size();i++) {
		if (input[i] == '(') {
			int indexI=find(input[i + 1], G);
			int indexJ=find(input[i + 3], G);
			G.edge[indexI][indexJ] = 1;
			i = i + 4;
		}	
	}

	findk(G);
	cout << "K vertices: ";
	for (char c : ans) {
		cout << c << " ";
	}
	cout << endl;
	cout<<"Number of K vertices: "<<ans.size();


	return 0;
}
