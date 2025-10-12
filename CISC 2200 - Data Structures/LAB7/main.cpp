/* 
Based on the article (code in Java) in

https://ics.uci.edu/~pattis/ICS-H22/lectures/llrecursion/

To the LinkList class in linkList.h, add the following recursive functions:
int recGetLength()
void recReversePrint()

Link * recSearchFor(int n)
void recRemoveFirst(int n) // first occurrence of n if exists
void recRemoveAll(int n)
void recPrint()

Note: Since recGetLength() takes no parameters, it needs to call another recursive method that takes a Link first as a parameter.
You can overload method recGetLength() with another one recGetLength(Link lnk). So recGetLength() can call recGetLength(first).


*/

#include "linkList.h"
using namespace std;

int main(){
    LinkList list;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++){
        int n;
        cin >> n;
        list.insertFirst(n);
    }
    
    list.recPrint();
    cout << endl;
    cout << "recGetLength(): " << endl;
    cout << list.recGetLength() << endl;
    cout << endl;
    cout << "recReversePrint(): " << endl;
    list.recReversePrint();
    cout << endl;
    int searchNum;
    cin >> searchNum;
    cout << "recSearchFor(" << searchNum << "): " << endl;
    Link* found = list.recSearchFor(searchNum);
    if (found != NULL){
        found->displayLink();
        cout << "was found" << endl;}
    else cout << searchNum <<" was not found" << endl;
    cout << endl;
    list.recPrint();
    int removeNum;
    cin >> removeNum;
    cout << "recRemoveFirst(" << removeNum << "):" << endl;
    list.recRemoveFirst(removeNum);
    // Try to find the removed value
    Link* foundAfter = list.recSearchFor(removeNum);
    if (foundAfter != NULL) {
        foundAfter->displayLink();
        cout << "was found" << endl;
    } else {
        cout << removeNum << " was not found" << endl;
    }
    list.recReversePrint();
    cout << endl;

    cout << "recRemoveAll(" << removeNum << "):" << endl;
    list.recRemoveAll(removeNum);
    // Try to find the removed value
    Link* foundAllAfter = list.recSearchFor(removeNum);
    if (foundAllAfter != NULL) {
        foundAllAfter->displayLink();
        cout << "was found" << endl;
    } else {
        cout << removeNum << " was not found" << endl;
    }
    cout << endl;
    list.recReversePrint();


    
   





    return 0;
}