#pragma once
#include <assert.h> // for assert

//------------------------------------------------------------------------------
// Node
//
//   T is the type parameter, it is the type that will be stored in the Node.
//
//   This is stored in the same file as List because List directly accesses its
//   private attributes. It could be rewritten using public functions to access
//   private data, using a nested class, or by making Node a "friend" of List.
//
//   This is fine for this implementation though!
//
//------------------------------------------------------------------------------

template <class T>
class Node
{
public:
    Node(const T& item); // Node constructor
    T item;              // the data item in the node
    Node<T>* next;       // pointer to the next node (initialised to nullptr)
};

// Node implementation
// -------------------
template <class T>
Node<T>::Node(const T& item) : item(item), next(nullptr)
{
}
//-----------------------------------------------------------------------------
// List
//
//   T is the type parameter, it is the type that will be managed by the List.
//
//-----------------------------------------------------------------------------

template <class T>
class List
{
public:
    List();                                  // default constructor
    List(const List<T>&);                    // copy constructor
    List(const T&);                          // constructor to make a list from an item
    ~List();                                 // destructor
    List<T>& operator = (const List<T>&);    // copy assignment operator
    bool operator == (const List<T>&) const; // compare with content of another list
    const T& operator [] (int pos) const;    // overload [] operator to access a list node
    bool isEmpty() const;                    // check if list is empty
    const T first() const;                   // return first item (MUST be non-empty)
    const T last() const;                    // return last item (MUST be non-empty)
    const List<T> tail() const;              // return tail (MUST be non-empty)
    void addInFront(const T&);               // insert an item in front
    void addAtEnd(const T&);                 // insert an item at end
    void deleteFirst();                      // delete first item (MUST be non-empty)
    void deleteOne(const T&);                // delete first occurrence of item
    int length() const;                      // return length
    bool contains(const T&) const;           // check if an item is in list
private:
    Node<T>* head;                           // point onto first item (nullptr if empty)
    Node<T>* end() const;                    // return address of last item (nullptr if empty)
    void destroy();                          // delete all items in list
    void copy(const List<T>&);               // make a deep copy of the list
};

#include "ListT.h"

template <class T>
List<T>::List() : head(nullptr)
{
}

template <class T>
List<T>::List(const T& item) : head(new Node<T>(item))
{
    assert(head != nullptr);
}

template <class T>
List<T>::List(const List<T>& other) : head(nullptr)
{
    copy(other);
}

template <class T>
List<T>::~List()
{
    destroy();
}

// public operations
// -----------------
template <class T>
List<T>& List<T>::operator = (const List<T>& rhs)
{
    if (&rhs != this)
    {
        List<T> temp = rhs;
        Node<T>* pn = head;
        head = temp.head;
        temp.head = pn;
    }

    return *this;
}

template <class T>
bool List<T>::operator == (const List<T>& rhs) const
{
    if (isEmpty() && rhs.isEmpty())
    {
        return true;
    }
    else
    {
        if (!isEmpty() && !rhs.isEmpty() && first() == rhs.first() && tail() == rhs.tail())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

template<class T>
const T& List<T>::operator[](int pos) const
{
    int size = 0;

    for (Node<T>* pn = head; pn != nullptr; pn = pn->next)
    {
        if (size == pos) {
            return pn->item;
        }
        size++;
    }
}

template <class T>
bool List<T>::isEmpty() const
{
    return head == nullptr;
}

template <class T>
const T List<T>::first() const
{
    assert(head != nullptr);
    return head->item;
}

template <class T>
const T List<T>::last() const
{
    assert(head != nullptr);
    return end()->item;
}

template <class T>
const List<T> List<T>::tail() const
{
    assert(head != nullptr);
    List<T> tailList = *this;
    tailList.deleteFirst();
    return tailList;
}

template <class T>
void List<T>::addInFront(const T& val)
{
    Node<T>* pn = new Node<T>(val);
    assert(pn != nullptr);

    pn->next = head;
    head = pn;
}

template <class T>
void List<T>::addAtEnd(const T& val)
{
    Node<T>* pn = new Node<T>(val);
    assert(pn != nullptr);

    if (head == nullptr)
    {
        head = pn;
    }
    else
    {
        end()->next = pn;
    }
}

template <class T>
void List<T>::deleteFirst()
{
    assert(head != nullptr);
    Node<T>* pn = head;
    head = head->next;
    delete pn;
}

template <class T>
void List<T>::deleteOne(const T& item)
{
    if (isEmpty()) return;

    if (first() == item)
    {
        deleteFirst();
    }
    else
    {
        List<T> temp = tail();
        temp.deleteOne(item);
        temp.addInFront(first());
        *this = temp;
    }
}

template <class T>
int List<T>::length() const
{
    int size = 0;

    for (Node<T>* pn = head; pn != nullptr; pn = pn->next)
    {
        size++;
    }

    return size;
}

template <class T>
bool List<T>::contains(const T& item) const
{
    for (Node<T>* pn = head; pn != nullptr; pn = pn->next)
    {
        if (pn->item == item)
        {
            return true;
        }
    }

    return false;
}

// private support operations
// --------------------------
template <class T>
Node<T>* List<T>::end() const
{
    Node<T>* plast = head;

    while (plast->next != nullptr)
    {
        plast = plast->next;
    }

    return plast;
}

template <class T>
void List<T>::destroy()
{
    while (head != nullptr)
    {
        deleteFirst();
    }
}

template <class T>
void List<T>::copy(const List<T>& other)
{
    assert(head == nullptr);

    if (other.head == nullptr) return;

    head = new Node<T>(other.head->item);
    assert(head != nullptr);

    Node<T>* pnew = head;
    for (Node<T>* porig = other.head->next; porig != nullptr; porig = porig->next)
    {
        pnew->next = new Node<T>(porig->item);
        assert(pnew->next != nullptr);
        pnew = pnew->next;
    }
}