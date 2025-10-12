/* 
To the LinkList class in LinkList.h
1- Add function void removeLast(int n): it deletes the last occurrence of an item from a linked list.
So if the item to remove is 7 and the list is 1 3 7 4 7 3 7 2
the resulting list is 1 3 7 4 7 3 2

In main() read an int n representing the number of elements in the list.
You then repeat n times: read number and call insertFirst(number) .
Lastly another int remove is read to indicate which number to remove.
*/

#include <iostream>
#include "linkList.h"


int main() {
    LinkList list;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int numInsert;
        cin >> numInsert;
        list.insertFirst(numInsert);
    }

 list.displayList();

    int numRemove;
    if (cin >> numRemove){
        cout << "theList.removeLast(" << numRemove << ")" << endl;
        list.removeLast(numRemove);
        list.displayList();

        cout << "theList.removeAll(" << numRemove << ")" << endl;
        list.removeAll(numRemove);
        list.displayList();
    }

    return 0;
}