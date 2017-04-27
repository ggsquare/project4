/**
* file: Driver-proj4.cpp
* author: Grant Gasser
* course: CSI 1440
* assignment:  project 4
* due date:  4/19/2017
*
* date modified:  4/16/2017
*      - file created
*
* Testing all the lovely Linked-List functions written in List-proj4.h
*/

#include <iostream>
#include "List-proj4.h"

using namespace std;

int main() {
    List<int> intList;
    List<int> intList3;
    List<char> charList;
    List<char> charList3;

    //arbitrary
    int removeVal = 3;
    char removeChar = 'a';

    //Testing getSize when empty
    cout << "Initial size: " << intList.getSize() << endl;

    //Making sure popFront and popBack both throw exceptions w/ empty list
    try {
        intList.popBack(removeVal);
    } catch(BADINDEX){
        cout << "Error. Can't remove from an empty list." << endl;
    }

    try {
        intList.popFront(removeVal);
    } catch(BADINDEX){
        cout << "Error. Can't remove from an empty list." << endl;
    }

    //add numbers to intList

    cout << "Adding 1-10" << endl;
    for(int i = 1; i <= 10; i++){
        //test pushFront when list is empty
        if(i == 1){
            intList.pushFront(i);
        } else {
            intList.pushBack(i);
        }
    }

    //print to check
    for(int i = 0; i < intList.getSize(); i++){
        cout << intList[i] << " ";
    }

    //test pushFront
    cout << endl;
    cout << "Pushing 0 to the front..." << endl;
    intList.pushFront(0);

    //print to check
    for(int i = 0; i < intList.getSize(); i++){
        cout << intList[i] << " ";
    }


    //Test popFront
    cout << endl;
    cout << "Removing front value..." << endl;
    intList.popFront(removeVal);


    //print to check
    for(int i = 0; i < intList.getSize(); i++){
        try{
            cout << intList[i] << " ";
        } catch(BADINDEX){
            cout << endl;
            cout << "Can't print element " << i << ". Out of bounds." << endl;
        }
    }
    cout << endl << "Value removed: " << removeVal << endl;



    //Test popBack
    cout << "Removing value from back..." << endl;
    intList.popBack(removeVal);

    //print to check
    for(int i = 0; i < intList.getSize(); i++){
        try{
            cout << intList[i] << " ";
        } catch(BADINDEX){
            cout << endl;
            cout << "Can't print element " << i << ". Out of bounds." << endl;
        }
    }
    cout << endl;
    cout << "Value removed: " << removeVal << endl;



    //Test copy constructor
    List<int> intList2 = intList;

    //print
    cout << "After copy constructor..." << endl;
    for(int i = 0; i < intList2.getSize(); i++){
        try{
            cout << intList2[i] << " ";
        } catch(BADINDEX){
            cout << endl;
            cout << "Can't print element " << i << ". Out of bounds." << endl;
        }
    }

    //Test overloaded =
    intList3 = intList2;


    //print
    cout << endl;
    cout << "After overloaded assignment operator..." << endl;
    for(int i = 0; i < intList3.getSize(); i++){
        try{
            cout << intList3[i] << " ";
        } catch(BADINDEX){
            cout << endl;
            cout << "Can't print element " << i << ". Out of bounds." << endl;
        }
    }

    cout << endl;
    cout << "Front: " << intList3.front() << endl;
    cout << "Back: " << intList3.back() << endl;

    for(int i = 0; i < 9; i++){
        intList3.popBack(removeVal);
        cout << "Remove val: " << removeVal << endl;
        cout << "Size: " << intList3.getSize() << endl;
    }

    cout << endl;
    cout << "After popping all the values off..." << endl;
    cout << "Size: " << intList3.getSize() << endl;
    for(int i = 0; i < 1; i++){
        try{
            cout << intList3[i] << " ";
        } catch(BADINDEX){
            cout << endl;
            cout << "Can't print element " << i << ". Out of bounds." << endl;
        }
    }

    cout << endl;
    cout << "Adding 1-10 with pushFront" << endl;
    for(int i = 1; i <= 10; i++){
        intList3.pushFront(i);
    }

    cout << endl;
    cout << "Printing after adding 1-10." << endl;
    for(int i = 0; i < intList3.getSize(); i++){
        try{
            cout << intList3[i] << " ";
        } catch(BADINDEX){
            cout << endl;
            cout << "Can't print element " << i << ". Out of bounds." << endl;
        }
    }

    /*

    //NOW TESTING WITH CHARS
    cout << endl << endl << endl;
    cout << "Now testing with chars..." << endl << endl;

    //Testing getSize when empty
    cout << "Initial size: " << charList.getSize() << endl;

    //Making sure popFront and popBack both throw exceptions w/ empty list
    try {
        charList.popBack(removeChar);
    } catch(BADINDEX){
        cout << "Error. Can't remove from an empty list." << endl;
    }

    try {
        charList.popFront(removeChar);
    } catch(BADINDEX){
        cout << "Error. Can't remove from an empty list." << endl;
    }

    //add numbers to intList
    cout << "Adding b-k" << endl;
    for(int i = 1; i <= 10; i++){
        //test pushFront when list is empty
        if(i == 1){
            charList.pushFront('b');
        } else {
            charList.pushBack('a' + i);
        }
    }

    //print to check
    for(int i = 0; i < charList.getSize(); i++){
        cout << charList[i] << " ";
    }

    //test pushFront
    cout << endl;
    cout << "Pushing a to the front..." << endl;
    charList.pushFront('a');

    //print to check
    for(int i = 0; i < charList.getSize(); i++){
        cout << charList[i] << " ";
    }

    //Test popFront
    cout << endl;
    cout << "Removing front char..." << endl;
    charList.popFront(removeChar);

    //print to check
    for(int i = 0; i < charList.getSize(); i++){
        try{
            cout << charList[i] << " ";
        } catch(BADINDEX){
            cout << endl;
            cout << "Can't print element " << i << ". Out of bounds." << endl;
        }
    }
    cout << endl << "Char removed: " << removeChar << endl;

    //Test popBack
    cout << "Removing char from back..." << endl;
    charList.popBack(removeChar);

    //print to check
    for(int i = 0; i < charList.getSize(); i++){
        try{
            cout << charList[i] << " ";
        } catch(BADINDEX){
            cout << endl;
            cout << "Can't print element " << i << ". Out of bounds." << endl;
        }
    }
    cout << endl;
    cout << "Char removed: " << removeChar << endl;

    //Test copy constructor
    List<char> charList2 = charList;

    //print
    cout << "After copy constructor..." << endl;
    for(int i = 0; i < charList2.getSize(); i++){
        try{
            cout << charList2[i] << " ";
        } catch(BADINDEX){
            cout << endl;
            cout << "Can't print element " << i << ". Out of bounds." << endl;
        }
    }

    //Test overloaded =
    charList3 = charList2;

    //print
    cout << endl;
    cout << "After overloaded assignment operator..." << endl;
    for(int i = 0; i < charList3.getSize(); i++){
        try{
            cout << charList3[i] << " ";
        } catch(BADINDEX){
            cout << endl;
            cout << "Can't print element " << i << ". Out of bounds." << endl;
        }
    }

    cout << endl;
    cout << "Front: " << charList3.front() << endl;
    cout << "Back: " << charList3.back() << endl;

*/
    return 0;
}
