#include <iostream>
#include <deque>

using namespace std;

// deque -> doubly ended queue (inserion and deletion can be done at both ends of array)
// data not in contigous memory locations 
// multiple static arrays involved but deque id dynamic!!!

int main() {
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_front(3); // 3,2,1

    for(int i:d) {
        cout << i << " ";
    } cout << endl;

    d.pop_back(); // deletes from back
    for(int i:d) {
        cout << i << " ";
    } cout << endl;

    d.pop_front(); // deletes at front
    for(int i:d) {
        cout << i << " ";
    } cout << endl;

    d.push_back(4);
    for(int i:d) {
        cout << i << " ";
    } cout << endl;
    cout << "Element at 1st index: " << d.at(1) << endl;

    cout << "First element: " << d.front() << endl;
    cout << "Last element: " << d.back() << endl;
    cout << "Empty or not: " << d.empty() << endl;

    cout << "before erase: " << d.size() << endl;
    d.erase(d.begin() + 1, d.begin() + 2); // d.begin -> iterator
    cout << "After erase: " << d.size() << endl;

    for(int i:d) {
        cout << i << " ";
    } cout << endl;

    
}