#include <iostream>
#include <string>
using namespace std;



class Link {

  public:
    int iData; //data item

  Link * pNext; //next link in list
  Link * pPrevious; //previous link in list
  public:

    Link(int dd): //constructor
    iData(dd), pNext(NULL), pPrevious(NULL) {}

  void displayLink() //display this link
  {
    cout << iData << " ";
  }

}; //end class Link

class DoublyLinkedList {
    private:
        Link * pFirst; //pointer to first item
        Link * pLast; //pointer to last item
    public:

        DoublyLinkedList(): //constructor
        pFirst(NULL), pLast(NULL) {}

        ~DoublyLinkedList() //destructor (deletes links)
  {
    Link * pCurrent = pFirst; //start at beginning of list
    while (pCurrent != NULL) //until end of list,
    {
      Link * pOldCur = pCurrent; //save current link
      pCurrent = pCurrent -> pNext; //move to next link
      delete pOldCur; //delete old current
    }
  }

  bool isEmpty() //true if no links
  {
    return pFirst == NULL;
  }

  void insertFirst(int dd) //insert at front of list
  {
    Link * pNewLink = new Link(dd); //make new link
    if (isEmpty()) //if empty list,
      pLast = pNewLink; //newLink <-- last
    else
      pFirst -> pPrevious = pNewLink; //newLink <-- old first
    pNewLink -> pNext = pFirst; //newLink --> old first
    pFirst = pNewLink; //first --> newLink
  }

  void insertLast(int dd) //insert at end of list
  {

    Link * pNewLink = new Link(dd); //make new link

    if (isEmpty()) //if empty list,
      pFirst = pNewLink; //first --> newLink
    else {

      pLast -> pNext = pNewLink; //old last --> newLink

      pNewLink -> pPrevious = pLast; //old last <-- newLink

    }
    pLast = pNewLink; //newLink <-- last

  }

  void removeFirst() //remove first link
  { //(assumes non-empty list)

    Link * pTemp = pFirst;

    if (pFirst -> pNext == NULL) //if only one item
      pLast = NULL; //null <-- last
    else
      pFirst -> pNext -> pPrevious = NULL; //null <-- old next
    pFirst = pFirst -> pNext; //first --> old next

    delete pTemp; //delete old first

  }

  Link * removeLast() //remove last link
  { //(assumes non-empty list)

    Link * pTemp = pLast;

    if (pFirst -> pNext == NULL) //if only one item
      pFirst = NULL; //first --> null
    else
      pLast -> pPrevious -> pNext = NULL; //old previous --> null
    pLast = pLast -> pPrevious; //old previous <-- last

    return pTemp;
    delete pTemp; //delete old last

  }

  //insert dd just after key
  bool insertAfter(int key, int dd) { //(assumes non-empty list)

    Link * pCurrent = pFirst; //start at beginning

    while (pCurrent -> iData != key) //until match is found,
    {

      pCurrent = pCurrent -> pNext; //move to next link

      if (pCurrent == NULL)
        return false; //didn’t find it
    }
    Link * pNewLink = new Link(dd); //make new link
    if (pCurrent == pLast) //if last link,
    {
      pNewLink -> pNext = NULL; //newLink --> null
      pLast = pNewLink; //newLink <-- last
    } else //not last link,
    { //newLink --> old next
      pNewLink -> pNext = pCurrent -> pNext;
      //newLink <-- old next
      pCurrent -> pNext -> pPrevious = pNewLink;
    }
    pNewLink -> pPrevious = pCurrent; //old current <-- newLink
    pCurrent -> pNext = pNewLink; //old current --> newLink
    return true; //found it, did insertion
  }

  void priorityInsert(int key){
    if (isEmpty()) {
        insertLast(key);
        return;
    }
    Link * pCurrent = pFirst;
    while (pCurrent != NULL && pCurrent->iData <= key){
        pCurrent = pCurrent->pNext;
    }
    if (pCurrent == NULL){
        insertLast(key);
    } else if ( pCurrent == pFirst){
        insertFirst(key);
    } else {
        Link * pNew = new Link(key);
        pNew->pNext = pCurrent;
        pNew->pPrevious = pCurrent->pPrevious;
        pCurrent->pPrevious->pNext = pNew;
        pCurrent->pPrevious = pNew;
    }
  } 

  void priorityRemove(){ 
    if(isEmpty()){
        return;
    }
    Link * pRemoved = removeLast();
    delete pRemoved;

  }

  bool removeKey(int key) //remove item w/ given key
  { //(assumes non-empty list)
    Link * pCurrent = pFirst; //start at beginning
    while (pCurrent -> iData != key) //until match is found,
    {
      pCurrent = pCurrent -> pNext; //move to next link
      if (pCurrent == NULL)
        return false; //didn’t find it
    }
    if (pCurrent == pFirst) //found it; first item?
      pFirst = pCurrent -> pNext; //first --> old next
    else //not first
      //old previous --> old next
      pCurrent -> pPrevious -> pNext = pCurrent -> pNext;
    if (pCurrent == pLast) //last item?
      pLast = pCurrent -> pPrevious; //old previous <-- last
    else //not last
      //old previous <-- old next
      pCurrent -> pNext -> pPrevious = pCurrent -> pPrevious;
    delete pCurrent; //delete item
    return true; //successful deletion
  }

  void displayForward() {
    cout << "List (first-->last): ";
    Link * pCurrent = pFirst; //start at beginning
    while (pCurrent != NULL) //until end of list,
    {
      pCurrent -> displayLink(); //display data
      pCurrent = pCurrent -> pNext; //move to next link
    }
    cout << endl;
  }

  void displayBackward() {
    cout << "List (last-->first): ";
    Link * pCurrent = pLast; //start at end
    while (pCurrent != NULL) //until start of list,
    {
      pCurrent -> displayLink(); //display data
      pCurrent = pCurrent -> pPrevious; //go to previous link
    }
    cout << endl;
  }
  string toString() 
    {
        string outString="";
        int key;
        Link * pCurrent = pFirst; //start at beginning
        while (pCurrent != NULL) //until end of list,
        {
            key = pCurrent ->iData;
            outString += to_string(key);
            pCurrent = pCurrent -> pNext; //move to next link
        }
        return outString;
    }
};