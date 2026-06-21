#include <iostream>
#include <stack>

using namespace std;

// stack --> last in -first out concept

int main() {
    stack<string> s;

    s.push("Harman");
    s.push("Bagrah");
    s.push("it's me");

    cout << "Top element: " << s.top() << endl; // last insertion is on top
    s.pop();
    cout << "Top element: " << s.top() << endl;

    cout << "Size of stack: " << s.size() << endl;
    cout << "Empty or not: " << s.empty() << endl;

    s.pop();
    cout << "Top element: " << s.top() << endl;


}