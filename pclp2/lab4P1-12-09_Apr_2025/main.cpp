#include <iostream>
#include <cmath>
using namespace std;
class CCerc
{
private:
  int raza;

public:
  CCerc();
  CCerc(float a);
  CCerc(CCerc &cerc);
  ~CCerc();
  float perimetru();
  float aria();
};

CCerc::CCerc()
{
  cout << "constructor fara parametrii" << endl;
  cout << "Introduceti raza cercului" << endl;
  cin >> raza;
}

CCerc::CCerc(float a)
{
  cout << "constructor cu parametrii" << endl;
  raza = a;
}

CCerc::CCerc(CCerc &cerc)
{
  cout << "contructor de copiere" << endl;
  raza = cerc.raza;
}

CCerc::~CCerc()
{
  cout << "destructor" << endl;
}

float CCerc::perimetru()
{
  return 2 * M_PI * raza;
}

float CCerc::aria()
{
  return M_PI * raza * raza;
}

int main()
{
  CCerc cerc1;
  float raza;
  cout << "Introduceti raza cercului 2" << endl;
  cin >> raza;
  CCerc cerc2(raza);
  CCerc cerc3(cerc2);

  cout << "Aria 1 " << cerc1.aria() << endl;
  cout << "Aria 2 " << cerc2.aria() << endl;
  cout << "Aria 3 " << cerc3.aria() << endl;

  return 0;
}