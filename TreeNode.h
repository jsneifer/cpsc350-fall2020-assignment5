#include <iostream>
using namespace std;

template <class T>
class TreeNode {
  public:
    TreeNode();
    TreeNode(T k);
    ~TreeNode();

    T *key;
    TreeNode<T> *left;//left node
    TreeNode<T> *right;//right node
};
