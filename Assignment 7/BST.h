// template class for BST

#include "TreeNode.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

/* *********************************************************************************
 * Template Base Class - BST
 * ---------------------------------------------------------------------------------
 * @param: none
 * **********************************************************************************/
template <typename E>
class BST{

public:
  BST();
  ~BST();
  bool contains(int k);
  E find(int k);
  TreeNode<E>* getNode(int k);
  void insert(TreeNode<E>* node);
  bool remove(int k);
  TreeNode<E>* getSuccessor(TreeNode<E>* d);
  TreeNode<E>* getMin();
  TreeNode<E>* getMax();
  string orderedString;
  void inOrder(TreeNode<E>* node);
  std::list<E> nodeList;
  std::string inOrderString(TreeNode<E>* node);
  std::string printTreeString();
  std::list<E> getNodeList();
  std::string printOrderedString();
  std::string getOrderedString(TreeNode<E>* node);

  void printTree();
  TreeNode<E>* getRoot();
  int length();
  bool isEmpty();

private:
    TreeNode<E>* root; // root of tree
    int size; // number of elements in tree
};

/*
Constructor, sets root and size values.
*/
template <typename E>
BST<E>::BST(){
  root= nullptr;
  size=0;
}

/*
Destructor
*/
template <typename E>
BST<E>::~BST(){

}

/*
Checks if tree contains node with key k.
@param int k: key to find.
@return: True or False
*/
template <typename E>
bool BST<E>::contains(int k){
  if(root ==nullptr){
    return false;
  }
  TreeNode<E>* curr=root;
  while (curr->key != k){
    if(k<curr->key){
      curr=curr->left;
    } else {
      curr=curr->right;
    }
    if(curr==nullptr){
      return false;
    }
  }
  return true;
}

/*
Find - Checks if tree contains node with key k.
@param int k: key to find.
@return: True or False
*/
template <typename E>
E BST<E>::find(int k){
  if(root ==nullptr){
    return E();
  }
  TreeNode<E>* curr=root;
  while (curr->key != k){
    if(k < curr->key){
      curr=curr->left;
    } else {
      curr=curr->right;
    }
    if(curr==nullptr){
      return E();
    }
  }
  return curr->value;
}


/*
getNode - Checks if tree contains node with key k.
@param int k: key to find.
@return: nullPrt or curr
*/
template <typename E>
TreeNode<E>* BST<E>::getNode(int k){
  if(root ==nullptr){
    return nullptr;
  }
  TreeNode<E>* curr = root;
  while (curr->key != k){
    if(k < curr->key){
      curr=curr->left;
    } else {
      curr=curr->right;
    }
    if(curr==nullptr){
      return nullptr;
    }
  }
  return curr;
}

/*
insert
Inserts node in tree.
@param node: tree node to insert.
*/
template <typename E>
void BST<E>::insert(TreeNode<E>* node){
  if(root == nullptr){
    root = node;
  }
  else{
    TreeNode<E>* curr = root;
    TreeNode<E>* parent;
    while(true){
      parent = curr;
      if(node->key < curr->key){
        curr= curr->left;
        if(curr == nullptr){
          parent->left = node;
          break;
        }
      } else {
        curr= curr -> right;
        if (curr == nullptr){
          parent->right = node;
          break;
        }
      }
    }
  }
  size++;
}


/*
delete
Delete a node from tree.
@param k: key to find and delete.
@return T/F whether delete was successful.
for this function, you will first need to find the node you want to delete
the rule is, you always replace a child with the left most node of it's right child
*/
template <typename E>
bool BST<E>::remove(int k){
  if(root == nullptr){
    return false;
  }
  TreeNode<E>* curr = root;
  TreeNode<E>* parent = root;
  bool isLeft = true;

  // locate the node to Delete
  while(curr->key!= k){
    parent=curr;
    if(k<curr->key){
      isLeft=true;
      curr=curr->left;
    }
    else{
      isLeft=false;
      curr=curr->right;
    }
    if(curr == nullptr){
      return false;
    }
  }
  // at this point we have found the node to remove.
  // case 1: no children
  if(curr->left == nullptr && curr->right == nullptr){
    if(curr == root)
        root = nullptr;
     else if(isLeft)
        parent->left=nullptr;
     else
        parent->right=nullptr;
  }
  // case 2: node has one child on the left
  else if(curr->right==nullptr){
    if(curr == root)
      root = curr->left;
    else if(isLeft)
      parent->left=curr->left;
    else
      parent->right=curr->left;
  }

  // case 3: node has one child on the right
  else if(curr->left==nullptr){
    if(curr == root)
      root = curr->right;
    else if(isLeft)
      parent->left=curr->right;
    else
      parent->right=curr->right;
  }
// case 4: 2 children
else{
  TreeNode<E>* successor = getSuccessor(curr);
  // come back here
  if (curr==root)
    root = successor;
  else if(isLeft)
    parent->left = successor;
  else
    parent->right = successor;
  successor->left = curr->left;
}
size--;
delete curr;
return true;
}



/*
getSuccessor
Find a node's left most child of its right child
@param d: Node to find successor for.
@return: successor node.
*/
template <typename E>
TreeNode<E>* BST<E>::getSuccessor(TreeNode<E>* d){
  TreeNode<E>* sp = d;
  TreeNode<E>* successor = d;
  TreeNode<E>* curr = d->right;
  while(curr != nullptr){
    sp = successor;
    successor=curr;
    curr = curr->left;
  }
  if(successor!=d->right){
    sp->left = successor->right;
    successor->right=d->right;
  }
  return successor;
}

/*
getMin
Find a tree's smallest key node.
@return: curr, the smallest key node
*/
template <typename E>
TreeNode<E>* BST<E>::getMin(){
  TreeNode<E>* curr=root;
  if(root==nullptr)
    return new TreeNode<E>();
  while(curr->left!=nullptr)
    curr=curr->left;
  return curr;
}


/*
getMax
Find a tree's largest key node.
@return: curr, largest key node
*/
template <typename E>
TreeNode<E>* BST<E>::getMax(){
  TreeNode<E>* curr=root;
  if(root==nullptr)
    return new TreeNode<E>();
  while(curr->right!=nullptr)
    curr=curr->right;
  return curr;
}

/*
inOrder
Inorder traversal starting at some node.
@param node: node to begin traversal
*/
template <typename E>
void BST<E>::inOrder(TreeNode<E>* node){
  if(node == nullptr)
    return;
  inOrder(node->left);
  orderedString+=std::to_string(node->key)+"-";
  inOrder(node->right);
}

/*
getOrderedString - Checks if tree contains node with key k.
@param: TreeNode<E>* node, passing in root of the tree
@return: orderedString
*/
template <typename E>
std::string BST<E>::getOrderedString(TreeNode<E>* node){
  orderedString="";
  if(node == nullptr)
    return orderedString;
  inOrder(node->left);
  orderedString+=std::to_string(node->key)+"-";
  inOrder(node->right);
  std::cout  << '\n';
  return orderedString;
}


/*
printTree - prints tree starting at the root
@param node:none
@return: none
 */
template <typename E>
void BST<E>::printTree(){
  inOrder(root);
  std::cout << '\n';
}



/*
printTreeString - prints tree starting at the root
@param node:none
@return: root node in order of string
 */
template <typename E>
std::string BST<E>::printTreeString(){
  return(inOrderString(root));
}


/*
getRoot - gets the root of the tree
@param : none
@return root: root
*/
template <typename E>
TreeNode<E>* BST<E>::getRoot(){
  return root;
}

/*
length - gets the size of the tree
@param: none
@return: size
*/
template <typename E>
int BST<E>::length(){
  return size;
}

/*
isEmpty - check to see if empty
@param: none
@return: true or false
*/
template <typename E>
bool BST<E>::isEmpty(){
  return (size==0);
}
