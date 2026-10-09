#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Brute Force Approach
// T = O(n), S = O(n) (Explicit heap memory usage via queue)
class BruteForceStack
{
public:
  void reverseStack(stack<int> &st)
  {
    if (st.empty())
      return;

    queue<int> q;

    // Step 1: Pop everything from stack and push into queue
    while (!st.empty())
    {
      q.push(st.top());
      st.pop();
    }

    // Step 2: Push everything back from queue to stack
    while (!q.empty())
    {
      st.push(q.front());
      q.pop();
    }
  }
};

// Optimal Approach
// T = O(n²), S = O(n) (Implicit recursion call stack memory only)
class OptimalStack
{
private:
  void insertAtBottom(stack<int> &st, int element)
  {
    if (st.empty())
    {
      st.push(element);
      return;
    }

    int topElement = st.top();
    st.pop();

    insertAtBottom(st, element);

    st.push(topElement);
  }

public:
  void reverseStack(stack<int> &st)
  {
    if (st.empty())
      return;

    int topElement = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, topElement);
  }
};

// Helper utility to print stack items from top to bottom
void printStack(stack<int> st)
{
  if (st.empty())
  {
    cout << "[ Empty Stack ]\n";
    return;
  }
  cout << "Top -> ";
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
  cout << "\n";
}

int main()
{
  // // Optimize standard input/output streams
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int size;
  cout << "Enter the number of elements to push into the stack: ";
  if (!(cin >> size) || size <= 0)
  {
    cout << "Invalid stack size.\n";
    return 0;
  }

  stack<int> originalStack;
  cout << "Enter " << size << " elements (first entered will be at the bottom):\n";
  for (int i = 0; i < size; ++i)
  {
    int val;
    cin >> val;
    originalStack.push(val);
  }

  // Make copies to test both approaches independently
  stack<int> bruteStack = originalStack;
  stack<int> optimalStack = originalStack;

  cout << "\n--- Initial State ---\n";
  printStack(originalStack);

  // 1. Execute Brute Force Reverse
  BruteForceStack bfs;
  bfs.reverseStack(bruteStack);
  cout << "\n--- After Brute Force Reversal (Queue-based) ---\n";
  printStack(bruteStack);

  // 2. Execute Optimal Reverse
  OptimalStack os;
  os.reverseStack(optimalStack);
  cout << "\n--- After Optimal Reversal (In-Place Recursion) ---\n";
  printStack(optimalStack);

  return 0;
}