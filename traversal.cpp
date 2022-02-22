/*
This question is very very imporatant and needs a great detail of visualisation.
So it cannot be explained in words and needs to be done using euler trees to visualise each and every steps in the recursion
*/ 
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    vector<Node*>children;
};

Node *newNode(int key){
	Node *temp=new Node;
	temp->data=key;
	return temp;

}

Node *construct(int arr[],int n ){
    Node *root=NULL;
    stack<Node*>st;
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }else{
            Node *t=newNode(arr[i]);
            if(st.size()>0){
                st.top()->children.push_back(t);
            }else{
                root=t;
            }
            st.push(t);
        }
    }
    return root;
}

void traversals(Node *node)
{
  cout<<"Node Pre "+to_string(node->data)<<endl;

  for(int i=0;i<node->children.size();i++){
      cout<<"Edge Pre "+to_string(node->data)+"--"+to_string(node->children[i]->data)<<endl;
      traversals(node->children[i]);
      cout<<"Edge Post "+to_string(node->data)+"--"+to_string(node->children[i]->data)<<endl;
  }
  cout<<"Node Post "+to_string(node->data)<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *root=construct(arr,n);
    traversals(root);
}