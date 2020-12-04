#include "BST.h"

template <class T>
BST<T>::BST(){
  root = NULL;
  //prev = new BST<T>();
}
template <class T>
BST<T>::~BST(){
  delete root;
  //delete prev;
}

template <class T>
T BST<T>::Find(int id){
  if(checkNode(id)){
    TreeNode<T> *curr = root;
    while(curr->key != id){
      if(id < curr->key){
        curr = curr->left;
      }
      else if(id > curr->key){
        curr = curr->right;
      }
      if(curr == NULL){
        TreeNode<T> *blank = NULL;
        return blank;
      }
    }
    return curr;
  } else {
    TreeNode<T> *blank = NULL;
    return blank;
  }
}

template <class T>
bool BST<T>::checkNode(int id){
    if(isEmpty()){
      return false;
    } else {
      //tree is not empty
      TreeNode<T> *curr = root;
      while(curr->key != id){
        if(id < curr->key){
          curr = curr->left;
        }
        else if(id > curr->key){
          curr = curr->right;
        }
        if(curr == NULL){
          return false;
        }
      }
      return true;
    }
}

template <class T>
void BST<T>::insert(T v) {
  TreeNode<T>* newNode = new TreeNode<T>(v);

  if(isEmpty()) {
    root = newNode;
  } else {
    TreeNode<T>* curr = root;
    TreeNode<T>* parent = root;
    while(curr != NULL) {
      parent = curr;
      //If the node should go to the left (ID is less than)
      if(newNode->key < curr->key) {
        curr = curr->left;
        //We found an empty spot to the left
        if(curr == NULL) {
          parent->left = newNode;
          break;
        }
      //If node should go to the right
      } else {
        curr = curr->right;
        //We found an empty spot to the right
        if(curr == NULL) {
          parent->right = newNode;
          break;
        }
      }
    }
  }
}


template <class T>
bool BST<T>::Remove(T k) {
  if(!searchNode(k))
   return false;

   //tree is not empty and value exist
 TreeNode<T> *curr = root;
 TreeNode<T> *parent = root;
 bool isLeft;

 while(curr->key != k) {
   parent = curr;
   if(k < curr->key) {
     isLeft = true;
     curr = curr->left;
   } else if(k > curr->key) {
     isLeft = false;
     curr = curr->right;
   }

   if(curr == NULL) {
     return false;
   }
 }
 //node found, let's delete
 if(curr->left == NULL && curr->right == NULL) {//no children
   if(curr == root) {
     root = NULL;
   } else if(isLeft) {
     parent->left = NULL;
   } else if(!isLeft) {
     parent->right = NULL;
   }
 } else if(curr->left == NULL) {
   if(curr == root){
     root = curr->right;
   } else if(isLeft) {
     parent->left = curr->right;
   } else if(!isLeft) {
     parent->right = curr->right;
   }
 } else if(curr->right == NULL) {
   if(curr == root) {
     root = curr->left;
   } else if(isLeft) {
     parent->left = curr->left;
   } else if(!isLeft) {
     parent->right = curr->left;
   }
 } else {
   //the node has 2 Children
   TreeNode<T> *succ = getSuccessor(curr);
   if(curr == root) {
     root = succ;
   } else if(isLeft) {
     parent->left = succ;
   } else if(!isLeft) {
     parent->right = succ;
   }
   succ->left = curr->left;

   return true;
 }
}


template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
  TreeNode<T> *curr = d->right;
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;

  while (curr != NULL){
    sp = successor;
    successor = curr;
    curr = curr->left;
  }
  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

template <class T>
int BST<T>::numNodes(TreeNode<T> *node) {
  if(node->right != NULL && node->left != NULL){
    return numNodes(node->left) + numNodes(node->right) + 1;
  }
  else if(node->right == NULL && node->left == NULL){
    return 1;
  }
  else if(node->right == NULL){
    return 1 + numNodes(node->left);
  }
  else if(node->left == NULL){
    return 1 + numNodes(node->right);
  }
}//counts the number of nodes in the tree

template <class T>
int BST<T>::numNodes() {
  return numNodes(root);
}

template <class T>
bool BST<T>::isEmpty() {
 return (root == NULL);
}

template <class T>
TreeNode<T>* BST<T>::getMax(){
 TreeNode<T>* curr = root;
 while(curr->right != NULL){
   curr = curr->right;
 }
 return curr;
}

template <class T>
TreeNode<T>* BST<T>::getMin(){
  TreeNode<T> *curr = root;
  if(root == NULL){
    return NULL;//tree is empty
  }
  while(curr->left != NULL){
    curr = curr->left;
  }
  return curr;
}

template <class T>
void BST<T>::printAscending() {
  printAscending(root);
}

template <class T>
void BST<T>::printAscending(TreeNode<T> *node) {
  if(node == NULL) {
    return;
  }

  printAscending(node->left);
  cout << node->key;
  printAscending(node->right);
}
