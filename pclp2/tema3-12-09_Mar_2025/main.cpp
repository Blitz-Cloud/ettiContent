#include <iostream>

using namespace std;

int main()
{
  int suma = 1, i, n, x, x_copy;
  char opt;
  cout << "Programul 3" << endl;
  do
  {
    cout << "Introduceti valoare pentru n:" << endl;
    cin >> n;
    cout << "Sa se introduca valoarea pentru x" << endl;
    cin >> x;
    x_copy = x;
    for (i = 1; i <= n; i++)
    {
      x *= x_copy;
      suma += x;
    }
    cout << suma << endl;
    cout << "Mai doresti o interograre. Optiuni valide sunt d si n" << endl;
    cin.get();
    cin.get(opt);
    while (opt != 'd' && opt != 'n')
    {
      cout << "Optiune invalida, te rog sa introduci d sau n" << endl;
      cin.get();
      cin.get(opt);
    }

  } while (opt != 'n');
  return 0;
}