
#define MARKER -1
#include <stdio.h>

/* *********************************************************************************
 *  Template Base Class - TreeNode
 * ---------------------------------------------------------------------------------
 *  TreeNode
 * **********************************************************************************/

template <typename E>
class TreeNode{
public:
  E value; //data value
  int key; // key for the tree
  TreeNode* left; // left child pointer
  TreeNode* right; // right child pointer

  TreeNode(){
    key = 0;
    value = E();
    left = nullptr;
    right = nullptr;
  }
  TreeNode(int k, E v){
    key = k;
    value = v;
    left = nullptr;
    right = nullptr;
  }


  //Destructor
  virtual ~TreeNode(){
      left = nullptr;
      right = nullptr;
  }


/* ************************************************************************************************
 * Implementation of a member function - serialization
 * ------------------------------------------------------------------------------------------------
 * This function turns information into text file
 * ------------------------------------------------------------------------------------------------
 * Function has 2 @param: pointer to root, pointer left and right node
 * returns: none
 * ************************************************************************************************/
void serialize(TreeNode *root, FILE *fp)
    {
    // If current node is NULL, store marker
    if (root == nullptr)
    {
        return;
    }
    // Else, store current node and recur for its children
    fprintf(fp, "%d ", root->key);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

/* ************************************************************************************************
 * Implementation of a member function - deserialization
 * ------------------------------------------------------------------------------------------------
 * This function turns
 * ------------------------------------------------------------------------------------------------
 * Function has 2 @param: pointer to root, pointer left and right node
 * returns: none
 * ************************************************************************************************/
void deSerialize(TreeNode *&root, FILE *fp)
{
    // Read next item from file. If there are no more items or next
    // item is marker, then return
    int val;
    if ( !fscanf(fp, "%d ", &val) || val == MARKER)
       return;
    // Else create node with this item and recur for children
    root = new TreeNode<int>(val,val);
    deSerialize(root->left, fp);
    deSerialize(root->right, fp);
  }
};
