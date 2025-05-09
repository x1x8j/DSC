#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {
	ifstream in("in.txt");
	ofstream out("abc.out");
	int i, j, n,num,ii,jj;
	in >> i >> j >> n;
	vector<vector<int>>M(i, vector<int>(j));
	vector<vector<int>>T(j, vector<int>(i));
	for (int k = 0; k < n; k++) {
		in >> ii >> jj >> num;
		M[ii][jj] = num;
		T[jj][ii] = num;
	}
	out << j<<" " << i<<" " << n << endl;
	for (int m = 0; m < j; m++) {
		for (int k = 0; k < i; k++) {
			if (T[m][k] != 0) {
				out << m << " " << k << " " << T[m][k] << endl;
			}
				
		}
	}

	return 0;
}
