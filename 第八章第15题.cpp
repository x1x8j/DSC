#include<iostream>
using namespace std;

int graph[101][101];
int dist[101];
int path[101];
int ss[101];

int main() {
	int n, m;
	cin >> n >> m;
	int w;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w;
			if (i == j) {
				w = 0xffffff;
			}
			if (w == 0) {
				w = 0xffffff;
			}
			graph[i][j] = w;
		}
	}
	int s, t;
	cin >> s >> t;

	//初始化
	for (int i = 1; i <= n; i++) {
		ss[i] = 0;
		dist[i] = graph[s][i];
		if (graph[s][i] !=0xffffff) {
			path[i] = s;
		}
		else {
			path[i] = -1;
		}
	}
	ss[s] = 1;


	for (int i = 1; i <= n - 1; i++) {
		int min = 0xffffff;
		int index = 0;
		for (int j = 1; j <= n; j++) {
			if (ss[j] == 0 && dist[j] < min) {
				min = dist[j];
				index = j;
			}
		}

		ss[index] = 1;
		if (index == t) {
			cout << dist[t] << endl;
			return 0;
		}
		for (int j = 1; j <= n; j++) {
			if (ss[j] == 0 && graph[index][j] != 0xffffff && dist[j] > dist[index] + graph[index][j]) {
				dist[j]=dist[index] + graph[index][j];
				path[j] = index;
			}
		}
	}


	cout << -1;

	return 0;
}
