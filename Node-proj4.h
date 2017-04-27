/**
* file: ContainerIfc-proj4.h
* author: Grant Gasser
* course: CSI 1440
* assignment:  project 3
* due date:  4/19/2017
*
* date modified:  4/16/2017
*      - file created
*
* An abstract class providing the structure necessary for a Linked-List class
*/

#ifndef PROJECT4_NODE_PROJ4_H
#define PROJECT4_NODE_PROJ4_H

#include <cstdlib>

template <class T>
class Node {
public:
    T data;
    Node<T> *next;
    Node(T e) {
        data = e;
        next = NULL;
    }
};

#endif //PROJECT4_NODE_PROJ4_H
