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
        size++;
        if (size == pos) {
            return pn->item;
        }
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