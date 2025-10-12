#include <iostream>
#include <vector>
using namespace std;

////////////////////////////////////////////////////////////////

class Stack {

  private:
    int maxSize; //size of stack vector

  vector < double > stackVect; //stack vector

  int top; //top of stack
  public:
    //--------------------------------------------------------------
    Stack(int s): maxSize(s), top(-1) //constructor
  {

    stackVect.reserve(maxSize); //size the vector

  }
  //--------------------------------------------------------------
  void push(double j) //put item on top
  {
    stackVect[++top] = j; //increment top,
  } //insert item
  //--------------------------------------------------------------
  double pop() //take item from top
  {
    return stackVect[top--]; //access item,
  } //decrement top
  //--------------------------------------------------------------
  double peek() //peek at top of stack
  {
    return stackVect[top];
  }
  //--------------------------------------------------------------
  bool isEmpty() //true if stack is empty
  {
    return (top == -1);
  }
  //--------------------------------------------------------------
  bool isFull() //true if stack is full
  {
    return (top == maxSize - 1);
  }
  void print()
  {
    for (int i=0; i<=top; i++)
      cout << stackVect[i]<<" ";
    cout << endl;
  }
  string to_print()
  {
    int n;
    string output="";
    for (int i=0; i<=top; i++)
    {
      n = static_cast<int>(stackVect[i]);
      output += to_string(n);
      output +=" ";
    }
    return output;
  }  //--------------------------------------------------------------
}; //end class Stack

