#include <bits/stdc++.h>
using namespace std;

// print
void print(priority_queue<int, vector<int>, greater<int>> pq)
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
  priority_queue<int, vector<int>, greater<int>> pq;

  // insert
  pq.push(10);
  pq.push(20);
  pq.push(5);
  pq.push(25);

  print(pq);

  pq.pop();
  print(pq);
}