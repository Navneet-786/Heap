#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
  int total_size = 0;
  int size = 0;
  vector<int> vec;

  Heap(int s) : total_size(s) {};

  // heapyfy
  void heapyfy(int index)
  {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && vec[left] > vec[index])
    {
      largest = left;
    }
    if (right < size && vec[right] > vec[index])
    {
      largest = right;
    }

    if (index != largest)
    {
      swap(vec[largest], vec[index]);
      index = largest;
      heapyfy(index);
    }
  }
  // delete Node (Log(n))
  // node is deleted from top
  void deleteNode()
  {
    if (size == 0)
    {
      cout << "deletion not possible || underflow" << endl;
      return;
    }

    vec[0] = vec[size - 1];
    size--;

    heapyfy(0);
  }

  // insert
  void insert(int ele)
  {
    if (size >= total_size)
    {
      cout << "Size overflow\n";
      return;
    }

    vec.push_back(ele);
    size++;
    int index = vec.size() - 1;
    // give the correct positon to ele
    while (index > 0 && vec[(index - 1) / 2] < vec[index])
    {
      swap(vec[index], vec[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }

  void print()
  {
    for (int i = 0; i < size; i++)
    {
      cout << vec[i] << " ";
    }
  }
};

int main()
{
  Heap h1(6);
  h1.insert(30);
  h1.insert(35);
  h1.insert(45);
  h1.insert(65);
  h1.insert(75);
  h1.insert(175);
  h1.print();

  cout << endl
       << "after deleteion" << endl;
  h1.deleteNode();
  h1.print();
}