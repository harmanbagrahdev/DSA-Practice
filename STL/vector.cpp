#include <iostream>
#include <vector>

using namespace std;

// vector is dynamic means it can change its size to hold elements according to the need!!
// whenever it gets full it doubles its size.
// the older vector is copied to a newer vector of double size and older verctor is deleted!

int main() {
    vector<int> v;
    cout << "Capacity: " << v.capacity() << endl; // capacity -> how much memory allocated

    v.push_back(1);
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(3);
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl; // size -> no. of elements present

    cout << "Elements at index 2: " << v.at(2) << endl;
    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;

    cout << "Before pop" << endl;
    for(int i:v) {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();

    cout << "after pop" << endl;
    for(int i:v) {
        cout << i << " ";
    }cout << endl;

    cout << "before clear size: " << v.size() << endl;
    v.clear(); // clears elements not capacity
    cout << "after clear size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    vector<int> a(5,1); // size = 5 and every element is initialized to 1!
    cout << "a: " << endl;
    for(int i:a) {
        cout << i << " ";
    } cout << endl;

    // vector a copied to another vector
    vector<int> copy_of_a(a);
    cout << "copy_of_a: " << endl;
    for(int i:copy_of_a) {
        cout << i << " ";
    } cout << endl;


}