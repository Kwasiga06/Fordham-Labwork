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

    cout << "recGetLength():" << endl;
    cout << list.recGetLength() << endl;
    cout << endl;

    cout << "recReversePrint():" << endl;
    list.recReversePrint();
    cout << endl;

    int searchNum = 45;
    Link* found = list.recSearchFor(searchNum);
    if (found != NULL){
        found->displayLink();
        cout << "was found" << endl;}
        else cout << searchNum <<" was not found" << endl;
    cout << endl;
    list.recReversePrint();

    int removeNum = 44;
    Link* foundAfter = list.recSearchFor(removeNum);
    if (foundAfter != NULL) {
        foundAfter->displayLink();
        cout << "was found" << endl;
    } else {
        cout << removeNum << " was not found" << endl;
    }
    list.recRemoveFirst(removeNum);
    list.recPrint();

    Link* foundAfter2 = list.recSearchFor(removeNum);
    if (foundAfter2 != NULL) {
        foundAfter2->displayLink();
        cout << "was found" << endl;
    } else {
        cout << removeNum << " was not found" << endl;
    }
    list.recRemoveAll(removeNum);
    list.recPrint();

    return 0;
}