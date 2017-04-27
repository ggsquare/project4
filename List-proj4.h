/**
* file: List-proj4.cpp
* author: Grant Gasser
* course: CSI 1440
* assignment:  project 4
* due date:  4/19/2017
*
* date modified:  4/18/2017
*      - file created
*
* Defining and implementing the necessary functions for Linked List
*/

#ifndef PROJECT4_LIST_H
#define PROJECT4_LIST_H

#include "ContainerIfc-proj4.h"
#include "Node-proj4.h"

#include <iostream>

using namespace std;

template <class T>
class List : public ContainerIfc <T> {
public:
    List();
    ~List();
    List(const List&);
    List <T>& operator =(List&);
    List <T>& pushFront(T);
    List <T>& pushBack(T);
    List <T>& popFront(T&);
    List <T>& popBack(T&);
    int getSize();
    bool isEmpty();
    T front();
    T back();
    T& operator [](int);
private:
    Node<T> *head;
};

template <class T>
List<T>::List(){
    this->head = NULL;
}

template <class T>
List<T>::~List(){
    Node<T> *temp;
    while(this->head != NULL){
        temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    delete this->head;
}

template <class T>
List<T>::List(const List& that){
    this->head = NULL;

    if(that.head != NULL){
        this->head = new Node<T>(that.head->data);

        Node<T> *thatTemp = that.head;
        Node<T> *thisTemp = this->head;

        while(thatTemp->next != NULL){
            thisTemp->next = new Node<T>(thatTemp->next->data);

            thisTemp = thisTemp->next;
            thatTemp = thatTemp->next;
        }
    }
}

template <class T>
List <T>& List<T>::operator=(List& that){
    if(this != &that){
        //similar code to destructor, deleting what exists in 'this'
        Node<T> *temp;
        if(this->head != NULL){
            temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        delete this->head;

        //from copy constructor
        this->head = NULL;

        if(that.head != NULL){
            this->head = new Node<T>(that.head->data);

            Node<T> *thatTemp = that.head;
            Node<T> *thisTemp = this->head;

            while(thatTemp->next != NULL){
                thisTemp->next = new Node<T>(thatTemp->next->data);

                thisTemp = thisTemp->next;
                thatTemp = thatTemp->next;
            }
        }
    }
    return *this;
}

template <class T>
List <T>& List<T>::pushFront(T e){
    if(isEmpty()){
        this->head = new Node<T>(e);
    } else {
        Node<T> *temp = this->head;
        this->head = new Node<T>(e);

        this->head->next = temp;

        temp = NULL; //DONT FORGET THIS
        delete temp;
    }
    return *this;
}

template <class T>
List <T>& List<T>::pushBack(T e){
    if(isEmpty()){
        this->head = new Node<T>(e);
    } else {
        Node<T> *temp = this->head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        //now add the new value
        temp->next = new Node<T>(e);
    }

    return *this;
}

template <class T>
List <T>& List<T>::popFront(T &e){
    if(isEmpty()){
        throw BADINDEX();
    } else {
        e = this->head->data;

        Node<T> *temp = this->head;

        this->head = this->head->next;
        temp->next = NULL; //don't forget
        delete temp;
    }
    return *this;
}

template <class T>
List <T>& List<T>::popBack(T &e){
    //if empty
    if(isEmpty()){
        throw BADINDEX();
    }

    //if not empty
    if(!isEmpty()){
        //if only one node
        if(this->head->next == NULL){
            e = this->head->data;
            delete this->head;
            this->head = NULL; //don't forget!
        } else {
            Node<T> *temp = this->head;
            Node<T> *prev = temp;

            //get to the end
            while(temp->next != NULL){
                //increment
                prev = temp;
                temp = temp->next;
            }
            e = temp->data;

            //so no temp->next == NULL
            prev->next = NULL;
            delete temp;
        }
    }
    return *this;
}

template <class T>
int List<T>::getSize(){
    int size = 0;
    Node<T> *temp = this->head;

    while(temp != NULL){
        temp = temp->next;
        size++;
    }

    return size;
}

template <class T>
bool List<T>::isEmpty(){
    return this->head == NULL;
}

template <class T>
T List<T>::front(){
    if(isEmpty()){
        throw BADINDEX();
    }
    return this->head->data;
}

template <class T>
T List<T>::back(){
    if(isEmpty()){
        throw BADINDEX();
    }

    Node<T> *temp = this->head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    return temp->data;
}

template <class T>
T& List<T>::operator[](int val){
    if(isEmpty()){
        throw BADINDEX();
    } else if(val < 0 || val > getSize()){
        throw BADINDEX();
    }

    Node<T> *temp = this->head;
    int counter = 0;

    while(counter < val){
        temp = temp->next;
        counter++;

        if(temp == NULL){
            throw BADINDEX();
        }
    }

    return temp->data;
}

#endif //PROJECT4_LIST_H
