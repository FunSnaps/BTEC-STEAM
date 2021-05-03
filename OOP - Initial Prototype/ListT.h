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
