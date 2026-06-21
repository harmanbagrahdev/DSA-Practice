#include <iostream>
#include <map>

using namespace std;

// data is stored in key-value pairs and every key is unique
// ordered_map -> sorted fetching --> O( log(n) )
// unordered_map --> O(1)

int main() {
    map<int, string> m;

    m[1] = "Harman";
    m[30] = "me";
    m[2] = "Bagrah";

    for(auto i: m) {
        cout << i.first << endl;
    }

    cout << endl;

    m.insert( {5, "Bheem"});

    for(auto i:m) {
        cout << i.first << " " << i.second << endl;
    }

    cout << "Finding 30 -> " << m.count(30) << endl;
    cout << "Finding -30 -> " << m.count(-30) << endl;

    cout << "Before erase" << endl;
    for(auto i:m) {
        cout << i.first << " " << i.second << endl;
    }
    m.erase(30);
    cout << "After erase" << endl;
    for(auto i:m) {
        cout << i.first << " " << i.second << endl;
    }

    cout << endl;
    
    m.insert( {54, "new"});
    auto it = m.find(5);

    for(auto i = it; i != m.end(); ++i) {
        cout << (*i).first << endl;
    }
}