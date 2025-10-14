#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
  T content;
  Node<T> *next;
  Node(T value) : content(value), next(nullptr) {}
};
template <typename T>
class ListaInlantuita
{
private:
  Node<T> *head;
  Node<T> *tail;

public:
  ListaInlantuita() : head(nullptr), tail(nullptr) {}
  int isEmpty()
  {
    if (head == nullptr)
    {
      return 1;
    }
    return 0;
  }

  void addFront(T data)
  {
    Node<T> *newNode = new Node<T>(data);
    if (head == nullptr)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
  }  
   void addTail(T data){
    Node<T> *newNode= new Node<T>(data);
    if(head==nullptr){
      head = newNode;
      tail= newNode;
    }else{
      tail->next = newNode;
      tail = newNode;
    }
   }

  T getHead(){
    if(head==nullptr){
      return T{};
    }
    return head->content;
  }

  T getBack(){
    if(head==nullptr){
      return T{};
    }else{
      return tail->content;
    }
  }
  
};

int main()
{
  ListaInlantuita<int> vector;
  // vector.addFront(1);
  int num = vector.getHead();
  cout<< num<<endl;
  return 0;
}