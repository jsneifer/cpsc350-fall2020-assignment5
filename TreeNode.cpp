#include "TreeNode.h"

template <class T>
TreeNode<T>::TreeNode() {
}

template <class T>
TreeNode<T>::TreeNode(T k) {
  *key = k;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode() {
  delete left;
  delete right;
}
