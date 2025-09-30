#include <iostream>

using namespace std;

class Multiplu
{
private:
  int a, b;

public:
  Multiplu()
  {

    cout << "Constructor fara parametri" << endl;
    cout << "Sa se introduca primul numar" << endl;
    cin >> a;
    cout << "Sa se introduca al doilea numar" << endl;
    cin >> b;
  };
  Multiplu(int x, int y)
  {
    cout << "Constructor cu parametrii" << endl;
    a = x;
    b = y;
  };
  Multiplu(Multiplu &temp)
  {
    cout << "Constructor de copiere" << endl;
    a = temp.a;
    b = temp.b;
  }
  ~Multiplu()
  {
    cout << "Destructor" << endl;
  }
  void multiplu()
  {
    int x = a, y = b, z = 0, r = 0;
    while (y != 0)
    {
      r = x % y;
      x = y;
      y = r;
    }
    z = a * b / x;
    cout << "numerele " << a << " si " << b << " au cmmmc " << z << endl;
  }
};

int main()
{
  char opt;

  do
  {

    cout << "Afisarea cmmmc pentru 2 numere introduse de la tastatura" << endl;
    Multiplu p1;
    int a, b;
    cout << "Sa se introduca de la tastatura un numar" << endl;
    cin >> a;
    cin.ignore();
    cout << "Sa se introduca de la tastura un al numar" << endl;
    cin >> b;
    cin.ignore();
    Multiplu p2(a, b);
    Multiplu p3(p1);
    p1.multiplu();
    p2.multiplu();
    p3.multiplu();
    cout << "Daca se mai doreste o interogare sa se introduca d, daca se doreste oprirea programului sa se introduca n" << endl;
    cin >> opt;
    while (opt != 'd' && opt != 'n')
    {
      cout << "Optiune invalida" << endl
           << "\tVa rog introduce d pentru inca o interogare si n pentru a iesi din program" << endl;
      cin.ignore();
      cin >> opt;
    }
    system("clear");
  } while (opt != 'n');
  return 0;
}
`