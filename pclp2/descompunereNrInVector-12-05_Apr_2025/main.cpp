
```c
#include <iostream>
#include <unistd.h>
using namespace std;

void generateContentArray(int num, int *&contentLength, int *&content)
{
  contentLength = new int;
  *contentLength = 0;
  int numCopy = num, k = 1;
  while (num > 0)
  {
    num /= 10;
    *contentLength = *contentLength + 1;
  }
  // cout << *contentLength << endl;
  num = numCopy;
  content = new int[*contentLength];
  while (num)
  {
    content[*contentLength - k] = num % 10;
    k++;
    num /= 10;
  }
  // for (int i = 0; i < *contentLength; i++)
  // {
  //   cout << content[i] << endl;
  //   usleep(2000);
  // }
}

void showNumber(int num)
{
  int i, *length = nullptr, *content = nullptr;
  generateContentArray(num, length, content);
  for (i = 0; i < *length - *length % 2; i = i + 2)
  {
    cout << content[i] << content[i + 1] << endl;
  }
  if (i == *length - 1)
  {
    cout << content[i] << endl;
  }
}

void testPointer(int num, int *&numCopy)
{
  numCopy = new int;
  *numCopy = num;
}

int main()
{
  showNumber(2345499);

  // int nr = 8, *num = nullptr;
  // testPointer(nr, num);
  // cout << *num << endl;
  // delete num;
  return 0;
}
```