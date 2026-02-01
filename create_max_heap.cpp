#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
  int total_size = 0;
  int size = 0;
  vector<int> vec;

  Heap(int s) : total_size(s) {};

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
    for (auto it : vec)
    {
      cout << it << " ";
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
}