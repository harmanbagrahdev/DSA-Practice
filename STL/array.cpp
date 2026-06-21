#include <iostream>
#include <array>

using namespace std;

int main() {
    int basic_array[3] = {1,2,3};

    array<int, 4> a = {1,2,3,4};  // this is a stl array and is static.(not dynamic)
    int size = a.size();
    for(int i = 0; i < size; ++i) {
        cout << a[i] << endl;
    }

    cout << "element at 2nd index: " << a.at(2) << endl; // a[2]
    cout << "empty or not: " << a.empty() << endl;
    cout << "First element: " << a.front() << endl;
    cout << "Last element: " << a.back() << endl;
    // O(1) complexity for all above fn's
}