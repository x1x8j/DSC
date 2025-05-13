// #include<iostream>
// #include<string>
// #include<queue>
// using namespace std;

// struct Node{
// char data;
// Node*left;
// Node*right;
// Node(){}
// Node(char data):data(data),left(NULL),right(NULL){}
// };
// Node*root=NULL;

// void preorder(Node*root){
//     if(root==NULL)
//         return;
//     cout<<root->data;
//     preorder(root->left);
//     preorder(root->right);
// }

// int main(){
//     int n;
//     cin>>n;
//     char a,b,c;
//     Node*temp;
//     queue<Node*>q;
//     for(int i=0;i<n;i++){
//         cin>>a>>b>>c;
//         if(root==NULL){
//             root=new Node(a);
//             if(b!='*'){
//                 root->left=new Node(b);
//                 q.push(root->left);
//             }
//             if(c!='*'){
//                 root->right=new Node(c);
//                 q.push(root->right);
//             }
        
//             continue;
//         }
//         else{
//             temp=q.front();
//             q.pop();
//             if(b!='*'){
//                 temp->left=new Node(b);
//                 q.push(temp->left);
//             }
//             if(c!='*'){
//                 temp->right=new Node(c);
//                 q.push(temp->right);
//             }
            
//         }
//     }

//     preorder(root);
    
//     return 0;
// }

#include<iostream>
using namespace std;

char c[30][3];
int n;

void preorder(char ch){
    if(ch!='*'){
        cout<<ch;
        for(int i=0;i<n;i++){
            if(ch==c[i][0]){
                preorder(c[i][1]);
                preorder(c[i][2]);
                break;
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c[i][0]>>c[i][1]>>c[i][2];
    }

    preorder(c[0][0]);
}
