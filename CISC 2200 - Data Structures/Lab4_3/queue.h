#include <iostream>
#include <vector>

using namespace std;
////////////////////////////////////////////////////////////////
class Queue {
  private:
    int maxSize;
  vector < int > queVect;
  int front;
  int rear;
  int nItems;
  public:
    //----------------------------------------------------------------
    //constructor
    Queue(int s): maxSize(s), front(0), rear(-1), nItems(0) {
      queVect.resize(maxSize);
    }
  //--------------------------------------------------------------
  void insert(int j) //put item at rear of queue
  {

    if (rear == maxSize - 1) //deal with wraparound
      rear = -1;
    queVect[++rear] = j; //increment rear and insert

    nItems++; //one more item

  }
  //--------------------------------------------------------------
  int remove() //take item from front of queue
  {

    int temp = queVect[front++]; //get value and incr front

    if (front == maxSize) //deal with wraparound
      front = 0;
    nItems--; //one less item

    return temp;

  }
  //--------------------------------------------------------------
  int peekFront() //peek at front of queue
  {
    return queVect[front];
  }
  //--------------------------------------------------------------
  bool isEmpty() //true if queue is empty
  {
    return (nItems == 0);
  }
  //--------------------------------------------------------------
  bool isFull() //true if queue is full
  {
    return (nItems == maxSize);
  }
  //--------------------------------------------------------------
  int size() //number of items in queue
  {
    return nItems;
  }
  
  void display()
  {
    for (int i=0; i<nItems; i++)
        cout<<queVect[i]<<" ";
    cout<<endl;
  }
  //--------------------------------------------------------------
}; //end class Queue