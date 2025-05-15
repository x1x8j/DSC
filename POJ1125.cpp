#include<iostream>
#include<fstream>
using namespace std;

int a[101][101];
int path[101][101];

int main() {
	ifstream in("in.txt");
	int n, m, w;
	in >> n;
	for (int i = 1; i <= n; i++) {
		in >> m;
		for (int k = 1; k <= m; k++) {
			int j;
			in >> j >> w;
			a[i][j] = w;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 0) {
				if  (i != j)
					a[i][j] = 0xffffff;
				path[i][j] = -1;
			}
			else {
				path[i][j] = i;
			}
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] > a[i][k] + a[k][j]) {
					a[i][j] = a[i][k] + a[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}

	//选出股票经纪人起点
	int min = 0xffffff;
	int min_i = 0;
	for (int i = 1; i <= n; i++) {
		int max=0;
		for (int j = 1; j <= n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		if (max < min) {
			min = max;
			min_i = i;
		}
	}

	if (min_i == 0) {
		cout << "disjoint" << endl;
	}
	else {
		cout << min_i << " " << min << endl;
	}

	return 0;
}
