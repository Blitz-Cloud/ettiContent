#include <iostream>
#include <math.h>

using namespace std;

class Cerc
{
  int raza;

public:
  void setarea_razei(int x)
  {
    raza = x;
  }
  float lungimea(void)
  {
    return 2 * M_PI * raza;
  }
  float aria(void)
  {
    return M_PI * raza * raza;
  }
};

main()
{
  cout << "Programul nr 2. clasa pentru cerc" << endl;
  Cerc cerc;
  cout << "Raza=";
  int raza;
  cin >> raza;
  cerc.setarea_razei(raza);
  cout << "Lungimea cercului " << cerc.lungimea() << endl
       << "Aria cercului " << cerc.aria() << endl;
  return 0;
}
`