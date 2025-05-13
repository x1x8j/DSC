#include<iostream>
#include<string>

using namespace std;

int main(){
    string pre,post;
    int res=1;
    cin>>pre>>post;
    for(int i=0;i<pre.length();i++){
        for(int j=0;j<post.length();j++){
            if(pre[i]==post[j]){
                if(i+1<pre.length()&&j-1>=0&&pre[i+1]==post[j-1]){
                    res*=2;
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
