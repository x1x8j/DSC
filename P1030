#include<string>
#include<iostream>
using namespace std;

struct Node{
    char data;
    Node*left;
    Node*right;
Node(){}
Node(char data):data(data),left(NULL),right(NULL){}
};

// Node* create(string post,int i,string in,int j,int n){
//     if(n<=0){
//         return NULL;
//     }
//     char r=post[i+n-1];
//     Node*root=new Node(r);
//     int k=j;
//     while(in[k]!=r){
//         k++;
//     }
//     int l=k-j;
//     root->left=create(post,i,in,j,l);
//     root->right=create(post,i+l,in,j+1,n-l-1);
//     return root;
// }

// void preorder(Node*root){
//     if(root!=NULL){
//         cout<<root->data;
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

void pre(string in,string post){
    int n=post.length();
    if(n<=0)
        return;
    cout<<post[n-1];
    int k=0;
    while(in[k]!=post[n-1]){
        k++;
    }
    int l=k;
    int r=n-k-1;
    pre(in.substr(0,k),post.substr(0,k));
    pre(in.substr(k+1,r),post.substr(k,r));
}

int main(){
    string in,post;
    getline(cin,in);
    getline(cin,post);
    // int n=in.length();
    // Node*root=create(post,0,in,0,n);

    // preorder(root);
    pre(in,post);
    
    return 0;
}
