#include <iostream>
using namespace std;

class CDreptunghi
{
  int x, y;

public:
  void set_valori(int a, int b)
  {

    x = a;
    y = b;
  }
  int aria(void);
};

int CDreptunghi::aria(void)
{
  return (x * y);
}

int main()
{
  cout << "Programul nr 1" << endl;
  CDreptunghi drept;
  int x, y;
  cout << "Sa se introduca de la tastura dimensiunile dreptunghiului" << endl;
  cout << "X= ";
  cin >> x;
  cout << "y= ";
  cin >> y;

  drept.set_valori(x, y);
  cout << "aria: " << drept.aria() << endl;
  return 0;
}

`