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

#ifndef PROJECT4_CONTAINERIFC_PROJ4_H
#define PROJECT4_CONTAINERIFC_PROJ4_H

class BADINDEX {};

template <class T>
class ContainerIfc
{
public:
    virtual ContainerIfc <T>& pushFront(T) = 0;
    virtual ContainerIfc <T>& pushBack(T) = 0;
    virtual ContainerIfc <T>& popFront(T&) = 0; // throws BADINDEX
    virtual ContainerIfc <T>& popBack(T&) = 0; // throws BADINDEX
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual T front() = 0; // throws BADINDEX
    virtual T back() = 0; // throws BADINDEX
    virtual T& operator [](int) = 0; // throws BADINDEX
};


#endif //PROJECT4_CONTAINERIFC_PROJ4_H
