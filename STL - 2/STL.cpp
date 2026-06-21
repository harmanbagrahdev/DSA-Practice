#include<bits/stdc++.h>
using namespace std;

// Pair
void pairDemo() {
    pair<int, int> p1 = {1,3};

    cout << "p1: ";
    cout << p1.first << " " << p1.second << endl;

    pair<int, pair<int, int> > p2 = {1, {2,3}};

    cout << "p2: ";
    cout << p2.first << " " << p2.second.second << " " << p2.second.first << endl;

    pair<int, int> arr[] = {{1,2}, {3,4}, {5,6}, {7,8}};

    cout << "arr(1,2) : ";
    cout << arr[1].second << endl; // 4
}

// vector
void vectorDemo() {
    vector<int> v;

    v.push_back(10);
    v.emplace_back(20);  // emplace is faster than push back

    vector< pair<int, int> > vp;
    vp.push_back({1,2});
    vp.emplace_back(3,4); // inverted brackets not needed

    vector<int> v1(5, 100); // 5 instances of 100
    
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(12);
    v2.push_back(23);
    
    vector<int> v3(v1); // copy of v1

    vector<int>::iterator it = v.begin(); // points before the starting element

    it++; // 2
    cout << "v[0] : " << *(it) << "\n";  // * -> dereferencing

    auto it1 = v1.begin();
    it1 += 2; // 5
    cout << "v1[1] : " << *(it1) << "\n";

/*
    vector<int>::iterator it2 = v2.end(); // points to after end

    auto it = v1.rend(); // points to reverse end

    auto it = v1.rbegin(); // points to the end element and traversal is done in reverse order but with normal forward index syntax!

    cout << "v[0]: " << v1[0] << " " << v.at(0) << endl;

    cout << "v.back: " << v1.back() << "\n";
*/

    cout << "v1: ";
    for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << *it << ", ";
    } cout << endl;

    cout << "v: ";
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << ", ";
    } cout << endl;

    cout << "v: ";
    for(auto &x: v) {
        cout << x << ", ";
    } cout << endl;

    // {10,20,12,23}
    v2.erase(v2.begin() + 1);

    // {10,20,12,23}
    v2.erase(v2.begin() + 2, v2.begin() + 3); // [start, end)

    // Insert fn
    vector<int> v4(2,100); // {100, 100}

    v4.insert(v4.begin(), 300); // {300, 100, 100}
    v4.insert(v4.begin()+1, 2, 10); // {300, 10, 10 100, 100}
    
    vector<int> copy(2,50); // {50,50}

    v4.insert(v4.begin(), copy.begin(), copy.end() ); // {{50, 50, 300, 10, 10, 100, 100}}
    // insert -> copy from begin to end at beginning of v

    // v = {10, 20}
    cout << "size of v: " << v.size() << endl; // 2

    v.pop_back(); // {10}

    v1.swap(v2); // swap

    cout << "v1: "; 
    for(auto x: v1) {
        cout << x << ", ";
    } cout << endl;
    
    cout<< "v2: ";
    for(auto x: v2) {
        cout << x << ", ";
    } cout << endl;
}

// list
void listDemo() {
    list<int> ls;

    ls.push_back(2); // { 2}
    ls.emplace_back(4); // {2, 4}

    ls.push_front(5); // {5,2,4}

    ls.emplace_front();

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap

    // insert in a vector is costlier than that in list!
}

// deueue
void dequeDemo() {
    deque<int> dq;
    
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1,2}
    dq.push_front(4); // {4,1,2}
    dq.emplace_front(3); // {3,4,1,2}

    dq.pop_back(); // {3,4,1}
    dq.pop_front(); // {4,1}

    dq.back(); // reference to last element
    dq.front(); // reference to first element

    // rest fn's same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

// stack
void stackDemo() {
    // LIFO
    stack<int> st;

    st.push(1); // {1}
    st.push(2); // {2,1}
    st.push(3); // {3,2,1}
    st.push(3); // {3,3,2,1}
    st.emplace(5); // {5,3,3,2,1}

    cout << st.top() << endl; // prints 5

    st.pop(); // deletes 5

    cout << st.top() << endl; // prints 3

    cout << st.size() << endl; // 4

    cout << st.empty() << endl;

    stack<int> st1, st2;
    st1.swap(st2);

    // All are O(1)
}

// queue
void queueDemo() {
    // a line 
    // FIFO
    queue<int> q;

    q.push(1); // {1}
    q.push(2); // {1,2}
    q.push(4); // {1,2,4}

    q.back() += 5; // {1,2,3,9}

    cout << q.back() << endl; // prints 9
    
    cout << q.front() << endl; // prints 1

    q.pop(); // {2,9}

    cout << q.front() << endl; // prints 2

    // size, swap, empty same as stack
}

// priority queue and minimum heap
void PQ_demo() {
    // A queue that stores elements in sorted manner
    // greatest element at top
    priority_queue<int> pq;

    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.emplace(10); // {10,8,5,2}

    cout << pq.top() << endl; // 10

    pq.pop(); // {8,5,2}

    cout << pq.top() << endl; // 8

    // size, swap, empty, fn's same as others

    // Minimum Heap
    cout << "Minimum heap\n";

    priority_queue<int, vector<int>, greater<int> > mpq;
    mpq.push(5); // {5}
    mpq.push(2); // {2,5}
    mpq.push(8); // {2,5,8}
    mpq.emplace(10); // {2,5,8,10}

    cout << mpq.top() << endl; // 2
}

// set
void setDemo() {
    // unique elements, sorted manner (ascending)
    set<int> st;

    st.insert(1); // {1}
    st.emplace(2); // {1,2}
    st.insert(2); // {1, 2}
    st.insert(4); // {1, 2, 4}
    st.insert(3); // {1,2,3,4}

    // functionality of insert In Vector can be used to increase efficiency

    // begin(), rbegin(), end(), rend(), size(), empty(), and swap() are same as those of above

    auto it1 = st.find(3);
    auto it2 = st.find(6); // finds element

    // takes logarithmic time
    st.erase(5); // erases 5

    int cnt = st.count(1); // counts freq. of element which is one if element exists in the set and zeo if doesn't exist

    auto it3 = st.find(3);

    st.erase(3);

    // {1,2,3,4,5}
    auto it4 = st.find(2);
    auto it5 = st.find(4);
    st.erase(it4, it5); // After erase --> {1,4,5}     [start, end)

    // lower_bound() and upper_bound() fn works in the same way as in vector it does!

    // lower_bound(x) → iterator to the first element ≥ x
    // upper_bound(x) → iterator to the first element > x

    // Example:  set = {1,3,5,7} ->
    // lower_bound(4) → 5
    // upper_bound(5) → 7

    // syntax
    // {1,4,5}
    auto it6 = st.lower_bound(2); // 4

    auto it7 = st.upper_bound(4); // 5

    // everything in logarithmic time
}

// multi set -> no unique elements
void multiSet_Demo() {
    // everything same as set
    // only it can store duplicate elements also

    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}
    
    int cnt = ms.count(1); // freq. of count = 3
    
    ms.erase(ms.find(1)); // now only first occurrence of 1 is deleted!
    
    auto it = ms.find(1);
    ms.erase(it, next(it, 2)); // [start, end)
    
    ms.erase(1); // all 1's erased
    
    // rest all fn's same as set
}

// unordered set -> no ordered elements
void unorderedSetDemo() {
    unordered_set<int> ust;

    // also stores unique elements
    // lower_bound amd upper_bound fn's don't work rest all fn's are same as above
    // it does not store elements in a sorted fashion and has better complexity than set in most cases, except some when collision occurs!
}

// map -> elements are indexed by keys and keys are unique; like dictionary in python!
void mapDemo() {
    // key value pairs
    // stores elements in sorted order of keys!!

    map<int, int> mp;

    map<int, pair<int, int> > mpp1;

    map< pair<int, int>, int> mpp2;

    mp[1] = 2;
    
    mp.emplace(3, 1);

    mp.insert({2, 4});

    mpp2[{2, 3}] = 10;

    /*
    mp -->
    {
        {1,2},
        {2,4},
        {3,1}
    }
    */

    for(auto it : mp) {
        cout << it.first << " " << it.second << endl;
    } cout << endl;

    cout << mp[1] << endl; // 2
    cout << mp[5] << endl; // 0

    auto it1 = mp.find(3);
    cout << it1->second << endl;

    auto it2 = mp.find(5); // 0 --> no element
    cout << it2->second << endl;

    auto it3 = mp.lower_bound(2); // 4
    cout << it3->second << endl;
    auto it4 = mp.upper_bound(3); // 0
    cout << it4->second << endl;

    // erase, swap, size, empty, are same as above
}

// multimap -> multiple keys
void multiMap_Demo() {
    // everything same as map, only it can store multiple keys
    // only mp[key] cannot be used here as there are multple keys!
}

// unorderedMap --> elements are not ordered by keys
void unorderedMap_Demo() {
    // same difference as set and and unordered_Set
}

// comparator is bool fn.
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second < p2.second) {
        return true;
    }
    else if(p1.second == p2.second) {
        if(p1.first > p2.second) return true;
    }
    return false;
}

// Algorithms
void some_Important_Algorithms() {
    pair<int, int> a[] = { {1,2}, {2,1}, {4,1} };

    // sort it according to second element
    // if second element is same then sort it according to descending order of first element

    sort(a, a + 4);
    sort(0, 4);

    sort(a + 2, a + 4);

    sort(a, a + 4, greater< pair<int, int> >() /* a built in comparator */ ); // descending order

    sort(a, a + 4, comp);

    // { {4,1}, {2,1}, {1,2} }

    int num1 = 7;
    int cnt = __builtin_popcount(num1); // binary of 7 = 111
    // this will return no. of bits taken on the memory (out of 32 or 64 bit system)!
    // e.g; 000000000.........111 = __builtin_popcount(7) = 3

    long long num2 = 165786578687;
    int cnt = __builtin_popcountll(num2); // for long long it becomes " ll " at last of __builtin_popcount

    // printing different combination of a string!
    string s = "123";

    // to make sur string is sorted and all of the permutations gets printed!!!!
    sort(s.begin(), s.end());
    
    /*
    123
    132
    213
    231
    312
    321
    */

    do {
        cout << s << endl;
    }  while (next_permutation(s.begin(), s.end() ) );
    

}

int main() {
    mapDemo();
}