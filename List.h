#ifndef LIST_H
#define LIST_H

#include <string.h>
#include "Array.h"
#include "Node.h"
#include "Event.h"
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class List
{
  public:
    //constructor for List object
    List() {
      head = NULL;
    }
    //desctructor for List
    ~List() {
      Node<T>* next = head;
      while (next != NULL) {
        Node<T> * holder = next;
        next = next->next;
        delete holder;
      }
    }
    //add function is used for adding a new event to the list
    void add(T evn) {
      cout << "added event to calendar" << endl;
      Node<T> * node = new Node<T>(evn);
     //add element into sorted linked-list

      if (head == NULL || evn < head->event) {
        node->next = head;
        head = node;
      } else {
        Node<T> * temp = head;
        while (temp->next != NULL && temp->next->event < evn) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
      }
    }
    // prints events to the screen
    void format(string& outStr) {
      stringstream ss;
	    Node<T> * temp = head;
      while (temp)
      {
        string str;
        temp->event->format(str);
        ss << str;
        ss <<endl;
        temp = temp->next;
      }
      outStr = ss.str();
    }
    // this function traverse the linkedlist and create shallow copy to parameter array
    void copy(Array& arr) {
      Node<T> *current = head;
      while (current != NULL) {
        arr.add(current->event);
        current = current->next;
      }
    }

  private:
    Node<T> * head;
};

// handle pointer situation. For pointers, add function behaves differently
template <class T> class List<T *>
{
  public:
    //constructor for List object
    List() {
      head = NULL;
    }
    //desctructor for List
    ~List() {
      Node<T *>* next = head;
      while (next != NULL) {
        Node<T *> * holder = next;
        next = next->next;
        delete holder;
      }
    }
    //add function is used for adding a new event to the list
    void add(T* evn) {
      cout << "added event to calendar" << endl;
      Node<T *> * node = new Node<T *>(evn);
     //add element into sorted linked-list

      if (head == NULL || (*evn) < (*(head->event))) {
        node->next = head;
        head = node;
      } else {
        Node<T *> * temp = head;
        while (temp->next != NULL && (*(temp->next->event)) < (*evn)) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
      }
    }
    // prints events to the screen
    void format(string& outStr) {
      stringstream ss;
	    Node<T *> * temp = head;
      while (temp)
      {
        string str;
        temp->event->format(str);
        ss << str;
        ss <<endl;
        temp = temp->next;
      }
      outStr = ss.str();
    }
    // this function traverse the linkedlist and create shallow copy to parameter array
    void copy(Array& arr) {
      Node<T *> *current = head;
      while (current != NULL) {
        arr.add(current->event);
        current = current->next;
      }
    }

  private:
    Node<T *> * head;
};



#endif