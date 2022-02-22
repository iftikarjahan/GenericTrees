#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Node

{

public:

  int data = 0;

  vector<Node *> children;



  Node(int data)

  {

    this->data = data;

  }

};

Node *constructor01(vector<int> &arr)

{

  if (arr.size() == 0)

    return NULL;



  vector<Node *> stack;

  stack.push_back(new Node(arr[0]));



  Node *root = stack[0];



  for (int i = 1; i < arr.size(); i++)

  {

    if (arr[i] != -1)

    {

      Node *node = stack.back();

      Node *nnode = new Node(arr[i]);



      node->children.push_back(nnode);

      stack.push_back(nnode);

    }

    else

      stack.pop_back();

  }

  return root;

}
void levelOderZigZag(Node *node)

{
    //Edge Case
  if(node==NULL || node->children.size()==0)return;

    /*
    here we are using two stacks mainStack and childStack. The use of main stack is to perform the algorithm of 
    rpac and the use of child stack is to store the child nodes in a specific order. 
    In order to decide that specific order, we maintain another variable that is called level and if the level
    is odd, we add the children from left to right abd if the level is even, we add the children from right to left.
    */
  stack<Node*>ms;
  ms.push(node);
  stack<Node*>cs;
  int level=1;

  while(ms.size()>0){
    Node*catcher=ms.top();
    ms.pop();
    cout<<catcher->data<<" ";

    
    if(level%2==1){
      for(int i=0;i<catcher->children.size();i++){
        cs.push(catcher->children[i]);
      }
    }
    else{
      for(int i=catcher->children.size()-1;i>=0;i--){
        cs.push(catcher->children[i]);
      }
    }

    /*
    After some iteration of the outer for loop, the main stack might become empty....and in that case we have to
    swap the two stacks and increment the level
    */ 
    if(ms.size()==0){
      swap(ms,cs);
      level++;
      cout<<endl;
    }



  }

}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node * root=constructor01(arr);
    levelOderZigZag(root);
}

int main()
{
    solve();
    return 0;
}