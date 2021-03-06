#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    vector<Node*>children;
};

Node *newNode(int key)
{
	Node *temp=new Node;
	temp->data=key;
	return temp;

}

Node *construct(int arr[],int n )
{
    Node *root=NULL;
    stack<Node*>st;
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }else{
            Node *t=newNode(arr[i]);
            //t->data=arr[i];
            
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

int height(Node *node)
{
    //height will always be positive or 0, so we can consider min height to be -1
    //here height starts from -1 because we are considering the deapth with respect to edges 
    int heightOfTree=-1;

    //So in every iteration of the for loop, we are calculating the height of each child
    for(int i=0;i<node->children.size();i++){
        int heightOfIndividualChild=height(node->children[i]);
        heightOfTree=max(heightOfIndividualChild,heightOfTree);
    }

    return heightOfTree+1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Node *root=construct(arr,n);
    int h=height(root);
    cout << h << endl;
}