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

void display(Node *node)
{
  string s = "";
  s += to_string(node->data) + " -> ";
  for (Node *child : node->children)
  {
    s += to_string(child->data) + ", ";
  }

  cout << s << "." << endl;

  for (Node *child : node->children)
  {
    display(child);
  }
}

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

Node *linearize(Node *node)
{
  queue<Node*>pendingNodesToBePrinted;
  pendingNodesToBePrinted.push(node);
  
  //In every iteration of the outer for loop, the size of the queue is figured out
  //And thats why, although the size becomes 0 after each iteration, the loop still runs because the size is figured out again

  while(pendingNodesToBePrinted.size()>0){

    int s=pendingNodesToBePrinted.size();
    while(s>0){
      //catch
      Node*front=pendingNodesToBePrinted.front();

      //remove
      pendingNodesToBePrinted.pop();

      //print
      cout<<front->data<<" ";

      //add child
      for(int i=0;i<front->children.size();i++){
        pendingNodesToBePrinted.push(front->children[i]);
      }
      s--;
    }
    cout<<endl;
    

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
    
  linearize(root);
  
    
}

int main()
{
    solve();
    return 0;
}