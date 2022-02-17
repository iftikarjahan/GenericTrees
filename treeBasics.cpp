#include<bits/stdc++.h>
using namespace std;
#include"treeNodeClass.h"

TreeNode<int>* takeInput(){
    //Take input for root data
    int rootData;
    cout<<"Enter the data of "<<rootData<<" ";
    cin>>rootData;
    //Now create a node to store the root data
    TreeNode<int>* root=new TreeNode<int>(rootData);
    

    cout<<"No of children of "<<root->data<<": ";
    int noOfChildren;
    cin>>noOfChildren;

    for(int i=0;i<noOfChildren;i++){
        TreeNode<int>* child= takeInput();
        root->children.push_back(child);
    }

    return root;
}

//Taking Input Level Wise makes it much more easier for us in understanding
TreeNode<int>* takeInputLevelWise(){

    //At first, we create the root node
    int rootData;
    cout<<"Enter the root data: ";
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);

    /*
    Then we create a queue of node pointers in which we will be following an algorithm using following steps
    ->push the root node in the queue
    ->start a loop and follow----catch,pop,addAChildNode,pushThatNode
    */
    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()>0){
        TreeNode<int>*front=pendingNodes.front();      //catch
        pendingNodes.pop();                            //pop

        //Adding Child Nodes
        int n;
        cout<<"Enter no of child of "<<front->data<<": ";
        cin>>n;
        //Adding Child Nodes in Each Iteration
        for(int i=0;i<n;i++){
            cout<<"Enter the "<<i<<"th child of "<<front->data<<": ";
            int childData;
            cin>>childData;
            TreeNode<int>* child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;


}

void printTree(TreeNode<int>* root){
    //Edge Case
    if(root==NULL)return;
    cout<<root->data<<": ";

    //Once we have printed the root data, we have to print the child data with the root data
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;


    //Here base case is not required for the recursive call as its handled by the looping conditions
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

void printTreeLevelWise(TreeNode<int>* root){
    //Creating a queue so that we can push the nodes of the tree
    queue<TreeNode<int>*>pendingNodesToBePrinted;
    pendingNodesToBePrinted.push(root);
    while(pendingNodesToBePrinted.size()>0){
        //follow the "r,p,ac" algorith where r=remove, p=print, ac=addChildren
        //store the root value
        TreeNode<int>* front=pendingNodesToBePrinted.front();

        //remove
        pendingNodesToBePrinted.pop();

        //print
        cout<<front->data<<",";

        //addChildren
        for(int i=0;i<front->children.size();i++){
            pendingNodesToBePrinted.push(front->children[i]);
        }

    }
}

void printLevelWiseZigzag(TreeNode<int>* root) {
        //Creating a queue so that we can push the nodes of the tree
    queue<TreeNode<int>*>pendingNodesToBePrinted;
    pendingNodesToBePrinted.push(root);
    while(pendingNodesToBePrinted.size()>0){
        //follow the "r,p,ac" algorith where r=remove, p=print, ac=addChildren
        //store the root value
        TreeNode<int>* front=pendingNodesToBePrinted.front();

        //remove
        pendingNodesToBePrinted.pop();

        //print
        cout<<front->data<<":";

        //addChildren
        for(int i=(front->children.size()-1);i>=0;i--){
            if(i==0){
                cout<<front->children[i]->data;
                pendingNodesToBePrinted.push(front->children[i]);
            }
            else{
                cout<<front->children[i]->data<<",";
            	pendingNodesToBePrinted.push(front->children[i]);
            }
            
        }
		cout<<endl;
    }
    // Write your code here
}
int main(){
    /*
    TreeNode<int>* root=new TreeNode<int>(10);
    TreeNode<int>*c1=new TreeNode<int>(20);
    TreeNode<int>* c2=new TreeNode<int>(30);

    root->children.push_back(c1);
    root->children.push_back(c2);
    */

    TreeNode<int>* root=takeInputLevelWise();
    printLevelWiseZigzag(root); 
    return 0;
}