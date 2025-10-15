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
  int length;
  Node<T> *current;
  Node<T> *head = nullptr, *tail = nullptr;

public:
  LinkedList() : head(nullptr), tail(nullptr)
  {
    length = 0;
  }
  // pozitionare
  void goToHead()
  {
    current = head;
  }

  void goToTail()
  {
    current = tail;
  }

  void goToNextNode()
  {
    if (!isEmpty() && current != tail)
    {
      current = current->next;
    }
  }
  void goToPreviousNode()
  {

    if (!isEmpty() && current != head)
    {
      goTillNode(*current);
    }
  }

  void goTillNode(Node<T> &node)
  {
    goToHead();
    while (current->next != &node)
    {
      goToNextNode();
    }
  }

  void goTillIndex(int index)
  {

    goToHead();
    for (int i = 0; i < index - 1; i++)
    {
      goToNextNode();
    }
  }

  void goToIndex(int index)
  {
    if (index == 0)
    {
      goToHead();
    }
    else
    {

      goTillIndex(index);
      goToNextNode();
    }
  }

  // adaugare de elemente
  void pushFront(T data)
  {
    Node<T> *newNode = new Node<T>(data);
    current = newNode;
    if (isEmpty())
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
    length++;
  }
  void pushBack(T data)
  {
    Node<T> *newNode = new Node<T>(data);
    current = newNode;
    if (isEmpty())
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
    length++;
  }
  void pushAtIndex(int index, T data)
  {

    goTillIndex(index);
    Node<T> *newNode = new Node<T>(data);
    Node<T> *softTail = current->next;
    newNode->next = softTail;
    current->next = newNode;
    length++;
  }

  // citire
  T getCurrentNode()
  {
    return current->content;
  }
  T getHead()
  {
    return head->content;
  }
  T getTail()
  {
    return tail->content;
  }
  T getNextNode()
  {
    if (current == tail)
    {
      return tail->content;
    }
    return current->next->content;
  }

  T getIndex(int index)
  {
    goToIndex(index);
    return current->content;
  }

  T getPrevious()
  {
    if (current == head)
    {
      return head->content;
    }
    goTillNode(*current);

    return current->content;
  }

  // stergere
  void popFront()
  {
    Node<T> *temp = head;
    head = head->next;
    length--;
    delete temp;
  }

  void popBack()
  {
    Node<T> *temp = tail;
    goTillNode(*tail);
    tail = current;
    length--;
    delete temp;
  }

  void popIndex(int index)
  {
    goTillIndex(index);
    Node<T> *temp = current->next;
    current->next = current->next->next;
    length--;
    delete temp;
  }
  void clear()
  {
    while (length != 0)
    {
      popFront();
    }
  }

  // misc
  int getLength()
  {
    return length;
  }
  int isEmpty()
  {
    return length == 0 ? 1 : 0;
  }
  void display()
  {
    cout << "Lista are urmatoarele elemente: " << endl;
    for (int i = 0; i < length; i++)
    {
      cout << getIndex(i) << " ";
    }
    cout << endl;
  }

  ~LinkedList()
  {
    clear();
  }
};
template <typename T>
class Stack : private LinkedList<T>
{
public:
  Stack() : LinkedList<T>::LinkedList()
  {
  }
  void pushNode(T data)
  {
    LinkedList<T>::pushFront(data);
  }
  void popNode()
  {
    LinkedList<T>::popFront();
  }

  // misc
  void getLength()
  {
    LinkedList<T>::getLength();
  }
  void isEmpty()
  {
    LinkedList<T>::isEmpty();
  }
  void display()
  {
    LinkedList<T>::display();
  }
};

template <typename T>
class Queue : private LinkedList<T>
{
public:
  Queue() : LinkedList<T>::LinkedList() {}

  void pushNode(T data)
  {
    LinkedList<T>::pushFront(data);
  }
  void popNode()
  {
    LinkedList<T>::popBack();
  }
  // misc
  void getLength()
  {
    LinkedList<T>::getLength();
  }
  void isEmpty()
  {
    LinkedList<T>::isEmpty();
  }
  void display()
  {
    LinkedList<T>::display();
  }
};

int main()
{
  LinkedList<int> l1;

  l1.pushBack(1);
  l1.pushBack(2);
  l1.pushBack(3);
  l1.pushBack(4);
  l1.pushBack(5);

  l1.display();

  l1.goToHead();
  cout << "Deplasare pointer la cap...\nElementul din cap " << l1.getCurrentNode() << endl;
  l1.goToTail();
  cout << "Deplasare pointer la coada...\nElementul din coada " << l1.getCurrentNode() << endl;

  l1.goToHead();
  l1.goToNextNode();
  cout << "Elementul curent este " << l1.getCurrentNode() << endl;
  l1.goToPreviousNode();
  cout << "Elementul curent este " << l1.getCurrentNode() << endl;
  l1.goToHead();
  l1.goTillIndex(3);
  cout << "Elementul de pe pozitia " << 2 << " este " << l1.getCurrentNode() << endl;
  l1.goToIndex(3);
  cout << "Elementul de pe pozitia " << 3 << " este " << l1.getCurrentNode() << endl;

  cout << "Se adauga nr 10 la inceputul listei\nSe adauga nr 11 la sfarsitul listei\nSe adauga nr 13 pe pozitia 0" << endl;
  l1.pushFront(10);
  l1.pushBack(11);
  l1.pushAtIndex(0, 13);
  l1.display();
  cout << endl;
  cout << "Se reseteaza lista" << endl;
  l1.clear();
  l1.pushBack(1);
  l1.pushBack(2);
  l1.pushBack(3);
  l1.pushBack(4);
  l1.pushBack(5);
  l1.display();
  cout << "Pe prima pozitie se afla " << l1.getHead() << "\nPe ultima pozitie se afla " << l1.getTail() << endl;
  l1.goToHead();
  cout << "Al doilea element este " << l1.getNextNode() << endl;

  cout << "Elementul de pe pozitia 2 este " << l1.getIndex(2) << endl;
  l1.goToIndex(4);
  cout << "Elementul de pe index 3 este " << l1.getPrevious() << endl;

  cout << endl
       << endl
       << "Se elimina primul,ultimul element si cel de pe pozitia a 3-a " << endl;

  l1.popFront();
  l1.popBack();
  l1.popIndex(2);
  cout << "Lungime " << l1.getLength() << endl;
  l1.display();

  cout << endl;
  cout << "Se elimina toate elementele din lista" << endl;
  l1.clear();
  l1.display();

  cout << "Exemplu de folosire si functionare pentru stiva" << endl;
  Stack<int> stiva;
  stiva.pushNode(1);
  stiva.pushNode(2);
  stiva.pushNode(3);
  stiva.display();
  stiva.popNode();
  stiva.display();

  cout << "Exemplu de folosire si functionare pentru coada" << endl;
  Queue<int> coada;
  coada.pushNode(1);
  coada.pushNode(2);
  coada.pushNode(3);
  coada.display();
  coada.popNode();
  coada.display();
}
