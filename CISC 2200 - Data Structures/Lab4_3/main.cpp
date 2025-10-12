#include <iostream>
#include "queue.h"
#include "stack.h"

using namespace std;


void reorder(Queue& theQ){
    int n = theQ.size();
    Stack theS(n); 
    for (int i = 0; i < n; i++){
        int x = theQ.remove();
        if (x < 0) theQ.insert(x);
        else theS.push(x);
    }
    
    while (!theS.isEmpty()) {
        theQ.insert(theS.pop());
    }
}


void printQueue(Queue& theQ) {
    int n = theQ.size();
    for (int i = 0; i < n; i++) {
        int x = theQ.remove();
        if (i) cout << " ";
        cout << x;
        theQ.insert(x);
    }
    cout << "\n";
}


int main() 
{
    int size = 100;
    Queue theQ(size);
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        theQ.insert(v);
    }

    printQueue(theQ);
    cout << "After reorder\n";
    reorder(theQ);
    printQueue(theQ);

    return 0;
}