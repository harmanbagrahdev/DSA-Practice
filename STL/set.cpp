#include <iostream>
#include <set>

using namespace std;

// unique elements, data is returned in sorted manner, not modifiable
// unordered_set -> set is slower than unordered_set, elements are not sorted

int main() {
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0); // insert, find, erase, count -> complexity = O( log(n) )

    for(auto i:s) {
        cout << i << endl;
    }

    cout << endl;

    set<int>::iterator it = s.begin();
    it++; // 1

    s.erase(it); // deletes 1
    for(auto &i:s) {
        cout << i << endl;
    }

    cout << endl;
    cout << "Count: " << s.count(5) << endl; // count checks 5

    set<int>::iterator itr = s.find(5);

    cout << "value present at itr : " << *itr << endl;

    cout << "We get reference for what we are finding(here 5) and then here we printed every element after 5 " << endl;
    for(auto it = itr; it != s.end(); ++it) {
        cout << *it << " ";
    } cout << endl;
}