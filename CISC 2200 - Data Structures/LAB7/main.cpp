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
    list.recGetLength();






    return 0;
}