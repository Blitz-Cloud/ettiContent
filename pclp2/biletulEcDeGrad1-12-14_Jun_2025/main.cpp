#include <iostream>

using namespace std;

class Ec1
{
private:
  int b, c;

public:
  Ec1(int x = 0, int y = 0)
  {
    b = x;
    c = y;
  }

  Ec1 operator+(Ec1 &);
};

class Ec2 : public Ec1
{
private:
  int a, b, c;

public:
  Ec2(int x = 0, int y = 0, int z = 0)
  {
    a = x;
    b = y;
    c = z;
  };

  Ec2 operator+(Ec2 &);
};

int main()
{
  cout << "Hello World" << endl;
  return 0;
}