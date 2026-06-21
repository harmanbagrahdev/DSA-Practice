#include <iostream>
#include <list>
using namespace std;

// direct access through index is not possible!
// doubly linked list

int main() {
    list<int> l;
    l.push_back(1);
    l.push_front(2);

    for(int i:l) {
        cout << i << " ";
    } cout << endl;

    l.erase(l.begin());

    cout << "After erase: " << endl;
    for(int i:l) {
        cout << i << " ";
    } cout << endl;

    cout << "Size: " << l.size() << endl;
    // pop_front/back and all these can be used!!

    list<int> n(5,100);
    cout << "copy of l(list): " << endl;
    for(int i:n) {
        cout << i << " ";
    } cout << endl;
}