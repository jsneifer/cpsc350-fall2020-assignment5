#include <iostream>
using namespace std;

#include "TreeNode.cpp"

template <class T>
class BST {
  public:
    BST<T>();
    ~BST<T>();

    T Find(int id); //Finds the treenode with the given ID, returns NULL if it does not exist
    bool checkNode(int id); //Checks if the Node exists
    void insert(T v); // Inserts a new node
    bool isEmpty(); //Checks if tree is empty
    void printAscending();// prints from root
    void printAscending(TreeNode<T> *node); // prints from passed node

    bool Remove(T k); //Removes specified node
    TreeNode<T>* getSuccessor(TreeNode<T> *d);

    int numNodes(TreeNode<T> *node); //returns number of tree nodes
    int numNodes(); //number of nodes from root
    TreeNode<T>* getMax();
    TreeNode<T>* getMin();

  private:
    TreeNode<T> *root;
    //BST<T> *prev; //Stores the previous BST for rollback
};
