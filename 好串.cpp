#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool test(string s) {

	for (int i = 1; i < s.length(); i++) {
		if (!(s[i]==s[i-1]||s[i]==s[i-1]+1))
			return false;
	}
	return true;
}

bool hao(string s) {
	if (test(s))
		return true;
	for (int i = 1; i < s.length(); i++) {
		string s1 = s.substr(0, i);
		string s2 = s.substr(i);
		if (test(s1) && test(s2)) {
			return true;
		}
	}
	return false;
}

int main() {
	string s;
	getline(cin, s);
	int ans=0;
	int len = s.length();
	for (int i = 1; i <= len;i++) {
		for (int j = 0; j <= len - i; j++) {
			string temp = s.substr(j, i);
			if (hao(temp)) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
