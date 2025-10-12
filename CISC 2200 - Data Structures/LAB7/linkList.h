
#include <iostream>
#include <string>

using namespace std;

////////////////////////////////////////////////////////////////

class Link {
public:
    int iData;      // data item
    Link* pNext;    // ptr to next link in list

    //-------------------------------------------------------------
    Link(int id) : // constructor
        iData(id), pNext(NULL) {}
    //-------------------------------------------------------------

    void displayLink() // display ourself
    {
        cout << iData << " ";
    }

    //-------------------------------------------------------------
}; // end class Link
////////////////////////////////////////////////////////////////

class LinkList {
private:
    Link* pFirst; // ptr to first link on list

public:
    //-------------------------------------------------------------
    LinkList() : pFirst(NULL) {} // constructor (no links on list yet)
    //-------------------------------------------------------------

    bool isEmpty() // true if list is empty
    {
        return pFirst == NULL;
    }

    //-------------------------------------------------------------
    // insert at start of list
    void insertFirst(int id) // make new link
    {
        Link* pNewLink = new Link(id);
        pNewLink->pNext = pFirst; // newLink --> old first
        pFirst = pNewLink;        // first --> newLink
    }

    //-------------------------------------------------------------
    Link* getFirst() // return first link
    {
        return pFirst;
    }

    //-------------------------------------------------------------
    void removeFirst() // delete first link (assumes list not empty)
    {
        Link* pTemp = pFirst;        // save first
        pFirst = pFirst->pNext;      // unlink it: first --> old next
        delete pTemp;                // delete old first
    }

    //-------------------------------------------------------------
    void displayList()
    {
        cout << "List (first-->last): ";
        Link* pCurrent = pFirst; // start at beginning of list
        while (pCurrent != NULL) // until end of list,
        {
            pCurrent->displayLink();         // print data
            pCurrent = pCurrent->pNext;     // move to next link
        }
        cout << endl;
    }

    //-------------------------------------------------------------
    string toString()
    {
        string outString = "";
        int key;
        Link* pCurrent = pFirst; // start at beginning
        while (pCurrent != NULL) // until end of list,
        {
            key = pCurrent->iData;
            outString += to_string(key);
            pCurrent = pCurrent->pNext; // move to next link
        }
        return outString;
    }

    int recGetLength()
    {
        return recGetLength(pFirst);
    }

    int recGetLength(Link* node) {
        if (node == NULL) return 0;
        return 1 + recGetLength(node->pNext);
    }

    void recReversePrint()
    {
        recReversePrint(pFirst);
        cout << endl;
    }

    void recReversePrint(Link* node)
    {
        if (node != NULL){
            recReversePrint(node->pNext);
            cout << node->iData << " ";
        }
    }

    void recRemoveFirst(int value) {
        pFirst = recRemoveFirst(pFirst, value);
    }
    
    Link* recRemoveFirst(Link* node, int value){
        if (node == NULL) return NULL;
            if (node->iData == value) {
                    Link* next = node->pNext;
                    delete node;
                    return next;
            }

        node->pNext = recRemoveFirst(node->pNext, value);
        return node;
    }

    Link * recSearchFor(Link * node, int value){
        if (node == NULL || node->iData == value) return node;
        else return recSearchFor(node->pNext, value);

    }

    Link* recSearchFor(int n)
    {
        return recSearchFor(pFirst, n);
    }

    void recPrint()
    {
        recPrint(pFirst);
        cout << endl;
    }

    void recPrint(Link* node)
    {
        if (node == NULL) return;
        cout << node->iData << " ";
        recPrint(node->pNext);
    }


};