
```c
/*<#include <iostream>

using namespace std;

class Cerc
{
private:
  int r;

public:
  Cerc()
  {
    cout << "Fara" << endl;
    cin >> r;
  }
  Cerc(int x)
  {
    cout << "Cu" << endl;
    r = x;
  }
  Cerc(Cerc &c)
  {
    cout << "Copiere" << endl;
    r = c.r;
  }
  void mutare(int x)
  {
    r = r + x;
  }
  int getx()
  {
    return r;
  }
  ~Cerc()
  {
    cout << "Destr" << endl;
  }
};

int main()
{
  Cerc c1;
  Cerc c2(2);
  Cerc c3(c2);
  int a, b, c;
  a = c1.getx();
  b = c2.getx();
  c3.mutare(2);
  c = c3.getx();
  cout << a << " " << b << " " << c << endl;

  return 0;
}
*/
#include <iostream>

using namespace std;

class Dreptunghi
{
  int lungime, latime;

public:
  friend class Cerc;
  Dreptunghi()
  {
    cout << "Apel constructor fara parametrii" << endl;
    int x, y;
    cout << "lungime dreptunghi= ";
    cin >> x;
    cout << endl;
    cout << "latime dreptunghi= ";
    lungime = x;
    cin >> y;
    latime = y;
    cout << endl;
  }
  Dreptunghi(int x, int y)
  {
    cout << "Apel constructor cu parametrii" << endl;
    lungime = x;
    latime = y;
  }
  Dreptunghi(Dreptunghi &x)
  {
    lungime = x.lungime;
    latime = x.latime;
  }
  ~Dreptunghi()
  {
    cout << "Apel destructor" << endl;
  }
  int aria();
  friend class Cerc;
};

class Cerc
{
  int raza;

public:
  void transforma_d_in_c(Dreptunghi &d);
  int aria();
};
int Dreptunghi::aria()
{
  return (lungime * latime);
}
int Cerc::aria()
{
  return (3.14 * raza * raza);
}
void Cerc::transforma_d_in_c(Dreptunghi &d)
{
  raza = d.lungime * d.latime / 2;
}
int main()
{
  int x, y;
  cout << "Program pentru Dreptunghi si Cerc" << endl;
  Dreptunghi d1;
  cout << endl;
  cout << "Introduceti Lungimea dreptunghiului 2" << endl;
  cin >> x;
  cout << "introduceti latimea dreptunghiului 2" << endl;
  cin >> y;
  Dreptunghi d2(x, y);
  cout << endl;
  Dreptunghi d3(d2);
  Cerc c1;
  c1.transforma_d_in_c(d1);
  Cerc c2;
  c2.transforma_d_in_c(d2);
  Cerc c3;
  c3.transforma_d_in_c(d3);
  cout << "Ariile d1,d2,d3,c1,c2,c3 sunt: " << d1.aria() << "," << d2.aria() << "," << d3.aria() << "," << c1.aria() << "," << c2.aria() << "," << c3.aria() << endl;
}
```