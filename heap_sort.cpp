#include <bits/stdc++.h>
using namespace std;

// heapyfy
void heapyfy(int index, vector<int> &vec, int size)
{
  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < size && vec[left] > vec[largest])
  {
    largest = left;
  }
  if (right < size && vec[right] > vec[largest])
  {
    largest = right;
  }

  if (index != largest)
  {
    swap(vec[index], vec[largest]);
    heapyfy(largest, vec, size);
  }
}

void heapyfyHeapSort(vector<int> &vec, int size)
{
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapyfy(i, vec, size);
  }
}
void heapSort(vector<int> &vec)
{
  // please ensure that array must me a max heap
  int size = vec.size();
  while (size > 0)
  {
    swap(vec[0], vec[size - 1]);
    size--;
    heapyfyHeapSort(vec, size);
  }
}

// print
void print(vector<int> &vec)
{
  for (auto it : vec)
  {
    cout << it << " ";
  }
  cout << endl;
}
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

  // convert it into maxheap
  int size = vec.size();
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapyfy(i, vec, size);
  }
  cout << "after Heapyfy" << endl;
  print(vec);

  // sort it in acending order in-place
  cout << "afte  sorting" << endl;
  heapSort(vec);
  print(vec);
}