#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

template <class T> class Node
{
    public:
        Node(T evn) {
            event = evn;
            next = NULL;
        }
        T event;
        Node<T>* next;
};

// handles pointer situations
template <class T> class Node<T *>
{
    public:
        Node(T* evn) {
            event = evn;
            next = NULL;
        }
        ~Node() {
            delete event;
        }
        T* event;
        Node<T *> * next;
};

#endif