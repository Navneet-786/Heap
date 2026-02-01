#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &vec)
{
  cout << endl
       << "array will be" << endl;
  for (auto it : vec)
  {
    cout << it << " ";
  }
  cout << endl;
}

void heapyfy(int index, vector<int> &vec)
{
  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < vec.size() && vec[left] > vec[largest])
  {
    largest = left;
  }

  if (right < vec.size() && vec[right] > vec[largest])
  {
    largest = right;
  }

  if (largest != index)
  {
    // it means we get the largest child
    swap(vec[index], vec[largest]);
    index = largest;
    heapyfy(index, vec);
  }
}

int main()
{
  vector<int> vec;
  cout << "Enter the size of array" << endl;
  int n;
  cin >> n;
  cout << "Enter the elements" << endl;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  print(vec);
  // convert this array to heap
  for (int i = vec.size() / 2; i >= 0; i--)
  {

    heapyfy(i, vec);
  }

  cout << "after Heapyfy" << endl;
  print(vec);
}