#include <iostream>
using namespace std;
#include "ListNode.cpp"

template <class T>
class DoublyLinkedList {
  private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;

  public:
    DoublyLinkedList<T>();
    ~DoublyLinkedList<T>();
    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    T getFront();
    T Find(T value); //AKA search()
    void deletePos(int pos);
    int removeNode(T key); //finds the value and deletes
    T* returnAtPos(int x); //Returns

    void printList();
    bool isEmpty();
    int getSize();
};
