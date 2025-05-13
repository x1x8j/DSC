#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    queue<int>q;
    unordered_map<int,int>m;
    int n;
    cin>>n;
    int num;
    int i=1;
    while(cin>>num){
        m[num]=i++;
        q.push(num);
    }
    while(q.size()!=2){
        int n1=q.front();q.pop();
        int n2=q.front();q.pop();
        q.push(max(n1,n2));
    }
    int n1=q.front();q.pop();
    int n2=q.front();q.pop();
    cout<<m[min(n1,n2)];
    return 0;
}
