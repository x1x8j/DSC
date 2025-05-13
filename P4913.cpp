// #include<iostream>
// #include<cmath>
// using namespace std;

// struct Node{
// int data;
// Node* left;
// Node* right;
// Node(){}
// Node(int data):data(data),left(NULL),right(NULL){}
// };

// Node*root;

// Node* findi(Node*root,int data){
//     if(root==NULL)
//         return NULL;
//     if(root->data==data){
//         return root;
//     }
//     Node*ll=findi(root->left,data);
//     if(ll!=NULL)
//         return ll;
//     else
//         return findi(root->right,data);
// }

// int depth(Node*root){
//     if(root==NULL)
//         return 0;
//     return 1+max(depth(root->left),depth(root->right));
// }

// int main(){
//     int n;
//     cin>>n;
//     int l,r;
//     Node*temp;
//     for(int i=1;i<=n;i++){
//         cin>>l>>r;
//         if(i==1){
//             root=new Node(i);
//             if(l!=0)
//                 root->left=new Node(l);
//             if(r!=0)
//                 root->right=new Node(r);
//             continue;
//         }
//         temp=findi(root,i);
//         if(l!=0)
//             temp->left=new Node(l);
//         if(r!=0)
//             temp->right=new Node(r);
        
//     }

//     int k=depth(root);
//     cout<<k<<endl;
//     return 0;
// }


#include<iostream>
#include<vector>
using namespace std;

struct Node{
int left;
int right;
};
vector<Node>v(100000);
int max=0;

void dfs(int i,int depth){
    if(i==0){
        if(depth>::max)
            ::max=depth;
        return;
    }
    dfs(v[i].left,depth+1);
    dfs(v[i].right,depth+1);
}

int main(){
    int n;
    cin>>n;

    int left,right;
    for(int i=1;i<=n;i++){
        cin>>left>>right;
        v[i].left=left;
        v[i].right=right;
    }

    dfs(1,0);

    cout<<::max<<endl;
    return 0;
}
