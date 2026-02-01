#include <bits/stdc++.h>
using namespace std;

void print(priority_queue<int> pq)
{
  cout << "Priority queue is like: " << endl;
  while (!pq.empty())
  {
    cout << pq.top() << " ";
    pq.pop();
  }

  cout << endl;
}

int main()
{
  priority_queue<int> pq; // by default max-heap

  // insert
  pq.push(10);
  pq.push(20);
  pq.push(5);
  pq.push(25);

  print(pq);

  // delete
  pq.pop();
  print(pq);

  // check empty
  if (pq.empty())
  {
    cout << "queue is empty" << endl;
  }

  // size
  cout << "size: " << pq.size() << endl;

  cout << "Top element: " << pq.top() << endl;
}