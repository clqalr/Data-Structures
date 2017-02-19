#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <class T>
class List
{
private:
    template <class U>
    class Node
    {
    public:
        Node();
        U data;
        Node<U> *pNext;
    };
public:
   List();
   ~List();
   List(const List<T> &origList);
   void pushFront(const T &data);
   int getSize() const;
   void display();
   bool empty() const;
   const List<T> &operator=(const List<T> &rhs);
private:
    void deleteList();
    Node<T> *pHead;
    int size;
};

template <class T>
List<T>::List()
{
    size = 0;
    pHead = NULL;
}

template <class T>
List<T>::~List()
{
    this->deleteList();
}

template <class T>
List<T>::List(const List<T> &origList)
{
    this->size = origList.size;
    Node<T> *ptrOrig = origList.pHead;

    Node<T> *pNode = new Node<T>;
    pNode->data = ptrOrig->data;
    pHead = pNode;
    Node<T> *ptr = pHead;
    // increment original's ptr just before iteration.
    ptrOrig = ptrOrig->pNext;

    while (ptrOrig != NULL)
    {
        Node<T> *pNode = new Node<T>;
        pNode->data = ptrOrig->data;
        ptr->pNext = pNode;
        ptr = ptr->pNext; // go forward
        ptrOrig = ptrOrig->pNext; // go forward
    }
}

template <class T>
template <class U>
List<T>::Node<U>::Node()
{
    pNext = NULL;
}

template <class T>
void List<T>::pushFront(const T &data)
{
    if (this->size == 0)
    {
        pHead = new Node<T>;
        pHead->data = data;
        size++;
    }
    else
    {
        Node<T> *pNew = new Node<T>;
        pNew->data = data;
        pNew->pNext = pHead;
        this->pHead = pNew;
        size++;
    }
}

template <class T>
int List<T>::getSize() const
{
    return this->size;
}

template <class T>
void List<T>::display()
{
    Node<T> *ptr = pHead;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->pNext;
    }
}

template <class T>
bool List<T>::empty() const
{
    return (pHead == NULL);
}

template <class T>
const List<T> & List<T>::operator=(const List<T> &rhs)
{
    // check for self-assignment
    if (this != &rhs)
    {
        // since this is pointer-based linked-list
        // always destroy the current list on lhs
        this->deleteList();
        Node<T> *ptrRhs = rhs.pHead;
        Node<T> *pNode = new Node<T>;
        pNode->data = ptrRhs->data;
        pHead = pNode;
        ptrRhs = ptrRhs->pNext;
        Node<T> *ptr = pHead;
        while (ptrRhs != NULL)
        {
            Node<T> *pNode = new Node<T>;
            pNode->data = ptrRhs->data;
            ptr->pNext = pNode;
            ptr = ptr->pNext;
            ptrRhs = ptrRhs->pNext;
        }
        this->size = rhs.size;
    }
}

template <class T>
void List<T>::deleteList()
{
    if (!empty())
    {
        Node<T> *ptr = this->pHead;
        while (ptr != NULL)
        {
            Node<T> *pNext = ptr->pNext;
            delete ptr;
            ptr = pNext;
        }
        this->size = 0;
        pHead = NULL;
    }
}

#endif // LIST_H
