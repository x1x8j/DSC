#include<iostream>
#include<string>

using namespace std;

void post(string in,string pre){
    int n=in.length();
    if(n==0)
        return;
    int k=in.find(pre[0]);
    post(in.substr(0,k),pre.substr(1,k));
    post(in.substr(k+1),pre.substr(k+1));
    cout<<pre[0];
    
}

int main(){
    string in,pre;
    cin>>in>>pre;

    post(in,pre);
    return 0;

}
