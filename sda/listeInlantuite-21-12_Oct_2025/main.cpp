#include <iostream>

using namespace std;

template <typename T>
class Node
{

public:
  Node<T> *next;
  T content;
  Node(T data) : next(nullptr), content(data) {}
};

template <typename T>
class LinkedList
{
private:
  static int length;
  static Node<T> *current = nullptr;
  Node<T> *head = nullptr, *tail = nullptr;

public:
  LinkedList() : head(nullptr), tail(nullptr) {}
  // pozitionare
  void goToHead();
  void goToTail();

  void goToNextNode();
  void goToPreviousNode();

  void goTillNode(Node<T> &node);
  void walkTillIndex(int index);

  // adaugare de elemente
  void pushFront(T data);
  void pushBack(T data);
  void addNodeAtIndex(T data);

  // citire
  T getFront();
  T getBack();
  T getIndex();
  T getNext();
  T getPrevious();

  // stergere
  void popFront();
  void popBack();
  void popIndex();
  void clear();

  ~LinkedList()
  {
    clear()
  }
};

int main()
{
}