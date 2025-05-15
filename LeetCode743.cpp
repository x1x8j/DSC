#include<iostream>
#include<fstream>
using namespace std;

int graph[101][101];
int s[101];
int dist[101];
int path[101];
const int INF = 0xfffffff;

int main() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			graph[i][j] = INF;
		}
	}
	ifstream in("in.txt");
	int n, k;
	in >> n >> k;
	int u, v, w;
	while (in >> u >> v >> w) {
		graph[u][v] = w;
	}

	//初始化
	for (int i = 1; i <= n; i++) {
		dist[i] = graph[k][i];
		s[i] = 0;
		if (graph[k][i] != INF) {
			path[i] = k;
		}
		else {
			path[i] = -1;
		}
	}
	s[k] = 1;



	for (int c = 1; c <= n - 1; c++) {
		int min = INF;
		int index = -1;
		for (int i = 1; i <= n; i++) {
			if (s[i] == 0 && dist[i] < min) {
				min = dist[i];
				index = i;
			}
		}

		if (index == -1) {
			cout << -1 << endl;
			return 0;
		}

		s[index] = 1;

		for (int i = 1; i <= n; i++) {
			if (s[i] == 0 && graph[index][i]!=INF && dist[i] > dist[index] + graph[index][i]) {
				dist[i] = dist[index] + graph[index][i];
				path[i] = index;
			}
		}
	}


	int max = -1;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > max&&dist[i]!=INF) {
			max = dist[i];
		}
	}
	cout << max << endl;


	return 0;
}
