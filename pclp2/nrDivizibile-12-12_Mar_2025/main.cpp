#include <iostream>

using namespace std;

int main()
{
  cout << "Verifica daca 2 numere sunt divizibile.";
  int a, b;
  char opt;
  do
  {
    cout << "Sa se introduca 2 numere de la tastura.\nPrimul trebuie sa fie mai mare, al doilea mai mic" << endl;
    cin >> a >> b;
    if (a % b == 0)
    {
      cout << a << " se divide la " << b << endl;
    }
    else
    {

      cout << a << " se nu se divide la " << b << endl;
    }
    cout << "Daca se mai doreste inca o interogare sa se introduca d daca nu n" << endl;
    cin.ignore();
    cin >> opt;
    while (opt != 'd' && opt != 'n')
    {
      cout << "Optiune invalida sa se introduca d sau n" << endl;
      cin.ignore();
      cin >> opt;
    }
  } while (opt != 'n');
  return 0;
}