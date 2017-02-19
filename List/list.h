#ifndef LIST_H
#define LIST_H

using namespace std;

template <class T>
class List
{
public:
    List();
    List(const List &list);
    ~List();
    int length();
    int cap();
    void display();
    void insert(const int &pos, const T &value);
    void erase(const int &pos);
    void truncate();
    bool empty() const;
    const List<T> &operator=(const List<T> &rhs);
private:
    int capacity;
    int size;
    T *list;
};

template <class T>
List<T>::List()
{
    this->capacity = 1024;
    this->size = 0;
    this->list = new (nothrow) T[this->capacity];
    if (this->list == NULL)
    {
        cout << "ERROR! Inadequate system memory\n";
        return;
    }
}

template <class T>
List<T>::List(const List &origList)
{
    this->capacity = origList.capacity;
    this->size = origList.size;
    this->list = new T[this->capacity];
    // deep copy
    for (int i = 0; i < size; i++)
    {
        this->list[i] = origList.list[i];
    }
}

template <class T>
const List<T> &List<T>::operator=(const List<T> &rhs)
{
    // is it self-assignment?
    if (this != &rhs) // this contains address of the current object
    {
        if (this->capacity != rhs.capacity)
        {
            delete [] this->list;
            this->capacity = rhs.capacity;
            this->list = new (nothrow) T[rhs.capacity];
            if (this->list == NULL)
            {
                cout << "ERROR! Inadequate system memory\n";
            }
        }
        this->size = rhs.size;
        for (int i = 0; i < rhs.capacity; i++)
        {
            list[i] = rhs.list[i];
        }
    }
    return *this; // a constant reference (address) to this list (object). Simply put, A reference to the object.
}

template <class T>
List<T>::~List()
{
    delete [] this->list;
    list = NULL;
}

template <class T>
int List<T>::length()
{
    return size;
}

template <class T>
int List<T>::cap()
{
    return capacity;
}

template <class T>
void List<T>::display()
{
    if (size > 0) {
        for (int i = 0; i < size; i++)
        {
            cout << list[i] << endl;
        }
    }
    else {
        cout << "List is empty.\n";
    }
}

/*************************************************
* erase
*
* erases item at position pos in a list by
* shifting array elements to the left, closing the
* gap
*
* erasing at i = 0
*
* [1][2][3][4][5][6][7]...[n - 1]
*    /  /  /  /  /  /
* [2][3][4][5][6][7]...[n - 1]
**************************************************/
template <class T>
void List<T>::erase(const int &pos)
{
    // list is empty
    if (this->empty())
    {
        cout << "List is empty\n";
        return;
    }
    // position validity
    if (pos < 0 || pos > size)
    {
        cout << "Invalid position\n";
        return;
    }
    else
    {
        for (int i = pos; i <= size - 2; i++)
        {
            list[i] = list[i + 1];
        }
        size--;
    }
}

template <class T>
bool List<T>::empty() const
{
    return (size == 0);
}

/*************************************************
* insert
*
* inserts item at position pos in a list by
* shifting array elements to the right, making
* room at position pos.
*
* inserting at i = 0
*
* [1][2][3][4][5][6][7]...[n - 1]
*   \  \  \  \  \  \  \
* [1][1][2][3][4][5][6][7]...[n - 1]
**************************************************/
template <class T>
void List<T>::insert(const int &pos, const T &value)
{
    // list is full
    if (size == capacity)
    {
        cout << "List is full\n";
        return;
    }
    // position's validity
    if (pos < 0 || pos > size)
    {
        cout << "Invalid position\n";
        return;
    }
    else
    {
        for (int i = size; i >= pos + 1; i--)
        {
            list[i] = list[i - 1];
        }
        list[pos] = value;
        size++;
    }
}

template <class T>
void List<T>::truncate()
{
    if (this->empty())
    {
        cout << "List is empty\n";
        return;
    }
    this->size = 0;
}

#endif
