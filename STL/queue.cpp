#include <iostream>
#include <queue>

using namespace std;

// queue -> line
// first in - first out concept!

int main() {
    queue<string> q;
    
    q.push("Harman");
    q.push("Bagrah");
    q.push("It's me");

    cout << "First element: " << q.front() << endl;
    q.pop();
    cout << "First element: " << q.front() << endl;

    // size, back, empty all these are valid!
}