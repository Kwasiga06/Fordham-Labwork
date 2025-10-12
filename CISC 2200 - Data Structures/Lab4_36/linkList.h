
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////

class Link {

  public:
  int iData; //data item
  Link * pNext; //ptr to next link in list

  Link(int id): //constructor
    iData(id), pNext(NULL) {}

  void displayLink() //display ourself {22, 2.99}
  {
    cout << iData << " ";
  }


}; //end class Link
////////////////////////////////////////////////////////////////
class LinkList {
  private:
    Link * pFirst; //ptr to first link on list
  public:

  LinkList(): pFirst(NULL) //constructor
  {} //(no links on list yet)

  bool isEmpty() //true if list is empty
  {
    return pFirst == NULL;
  }

  //insert at start of list
  void insertFirst(int id) { //make new link
    Link * pNewLink = new Link(id);
    pNewLink -> pNext = pFirst; //newLink-->old first
    pFirst = pNewLink; //first-->newLink
  }

  Link * getFirst() //return first link
  {
    return pFirst;
  }

  void removeFirst() //delete first link
  { //(assumes list not empty)
    Link * pTemp = pFirst; //save first
    pFirst = pFirst -> pNext; //unlink it: first-->old next
    delete pTemp; //delete old first
  }

  void removeLast(int n){
    Link * prevNode = NULL;
    Link * currNode = pFirst;
    Link * lastNode = NULL;
    Link * lastPrevNode = NULL;
    
    while (currNode != NULL){
        if (currNode->iData == n) {
            lastNode = currNode;
            lastPrevNode = prevNode;
        }
        prevNode = currNode;
        currNode = currNode->pNext;
    }

    if(lastNode == NULL) return;
    if (lastPrevNode == NULL) {
      pFirst = pFirst->pNext;
      delete lastNode;
    } else {
      lastPrevNode->pNext = lastNode->pNext;
      delete lastNode;
    }
  }

  void removeAll(int n) {
    while (pFirst != NULL && pFirst->iData == n) {
      Link* toDelete = pFirst;
      pFirst = pFirst->pNext;
      delete toDelete;
    }

    Link* prev = pFirst;
    if (prev == NULL) return;
    Link* curr = prev->pNext;
    while (curr != NULL) {
      if (curr->iData == n) {
        prev->pNext = curr->pNext;
        delete curr;
        curr = prev->pNext;
      } else {
        prev = curr;
        curr = curr->pNext;
      }
    }
  }
  
  void displayList() {
    cout << "List (first-->last): ";
    Link * pCurrent = pFirst; //start at beginning of list
    while (pCurrent != NULL) //until end of list,
    {
      pCurrent -> displayLink(); //print data
      pCurrent = pCurrent -> pNext; //move to next link
    }
    cout << endl;
  }

}; //end class LinkList