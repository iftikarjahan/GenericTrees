/*
Must revise templates and pointers before starting this
*/ 
using namespace std;
#include<vector>
template<typename T>

/*
Each node of the tree would have a data to store and some memory locations that would be pointing towards the 
address of other nodes

In order to store the address of other nodes in a specific node, we would need a vector of type TreeNode* in which
each index of the vector would be storing the memory location of the other nodes of tree
*/
class TreeNode{
    public: 

    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data=data;
    }
};