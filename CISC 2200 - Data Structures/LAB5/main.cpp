/*
Implement a priority queue using a DoublyLinkedList where the node with the highest priority (key) is the right-most node.

The remove (de-queue) operation returns the node with the highest priority (key).
If displayForward() displays List (first-->last) : 10 30 40 55
remove() would return the node with key 55.

Modify DoublyLinkedList.h to add the two functions:
void priorityInsert(int key)
void priorityRemove() 

The first number of the input is the count of numbers to be added to the priorityList.

*/


#include <iostream>
#include "doublyLinked.h"

int main() 
{
    DoublyLinkedList list;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int key;
        cin >> key;
        list.priorityInsert(key);
    }
    list.displayForward();
    list.priorityRemove();
    list.displayForward();
}
