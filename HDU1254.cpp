#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct point {
	int x;
	int y;
	int step;
	int manx;
	int many;
};

int n, m;
point target;

bool canreach(vector<vector<int>>&house,int tx,int ty,int manx,int many,int x,int y) {
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	queue<point>q;
	q.push(point{ manx,many });
	while (!q.empty()) { 
		point cur = q.front();
		q.pop();

		if (cur.x == tx && cur.y == ty) {
			return true;
		}
		for (int i = 0; i < 4; i++) {
			int ni=cur.x+dx[i];	
			int nj=cur.y+dy[i];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
				if (house[ni][nj] != 1&&!(ni==x&&nj==y)&&!visited[ni][nj]) {
					visited[ni][nj] = true;
					q.push(point{ ni,nj });
				}
			}
		}
	}
	return false;
}

int visited[10][10][10][10];

void bfs(vector<vector<int>>&house,point now) {
	
	queue<point>q;
	q.push(now);
	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		if (cur.x == target.x && cur.y == target.y) {
			cout << cur.step;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ni=cur.x+dx[i];
			int nj=cur.y+dy[i];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
				if  (house[ni][nj]!=1&&canreach(house, cur.x - dx[i] , cur.y - dy[i],cur.manx,cur.many,cur.x,cur.y)&&!visited[ni][nj][cur.x - dx[i]][cur.y - dy[i]]){
					visited[ni][nj][cur.x - dx[i]][cur.y - dy[i]] = 1;
					q.push(point{ ni,nj,cur.step+1,cur.x - dx[i], cur.y - dy[i] });
				}
			}
		}
	}
	cout << -1;

}

int main() {
	ifstream in("in.txt");
	in >> n >> m;
	int num;
	point now;
	vector<vector<int>>house(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			in >> num;
			house[i][j] = num;
			if (num == 3) {
				target.x = i;
				target.y = j;
			}
			if (num == 2) {
				now.x = i;
				now.y = j;
			}
			if (num == 4) {
				now.manx = i;
				now.many = j;
			}
		}
	}
	now.step = 0;
	bfs(house, now);


	return 0;
}
