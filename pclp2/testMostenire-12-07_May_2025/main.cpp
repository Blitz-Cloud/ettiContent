#include <iostream>

using namespace std;

class D1
{
private:
  int latD1 = 1;

public:
  void afisD1()
  {
  }
};

class D2 : public D1
{
private:
  int latD2 = 2;

public:
  void adfisD2()
  {
    afisD1();
  }
};

int main()
{
}