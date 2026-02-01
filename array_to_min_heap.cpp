#include <bits/stdc++.h>
using namespace std;

// print
void print(vector<int> &vec)
{
  for (auto it : vec)
  {
    cout << it << " ";
  }
  cout << endl;
}

// heapyfy
void heapyfy(int index, vector<int> &vec)
{
  int size = vec.size();
  int smallest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < size && vec[left] < vec[smallest])
  {
    smallest = left;
  }
  if (right < size && vec[right] < vec[smallest])
  {
    smallest = right;
  }
  if (smallest != index)
  {
    swap(vec[smallest], vec[index]);
    index = smallest;
  }
}
// build min heap
void buildMinHeap(vector<int> &vec)
{
  int size = vec.size();
  // we are using step down approach O(n)
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapyfy(i, vec);
  }
}

// main
int main()
{
  vector<int> vec;
  cout << "Enter the number of element" << endl;
  int n;
  cin >> n;
  cout << "Enter the numbers" << endl;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  cout << "original Array" << endl;
  print(vec);

  // build min heap
  buildMinHeap(vec);
  cout << "after min heap" << endl;
  print(vec);
}