#include <iostream>

using namespace std;

int main()
{
  cout << "Programul 2" << endl;
  int luna, anul;
  char opt;
  do
  {
    cout << "Te rog sa introduci luna anului, optiuni valide sunt numere de la 1 la 12" << endl;
    cin >> luna;
    while (luna < 0 || luna > 12)
    {
      cout << "Aceasta este optiune invalida, in calendar sunt doar 12 luni si nici una nu este negativa" << endl;
      cin >> luna;
    }

    if (luna == 2)
    {
      cout << "Pentru luna februarie te rog sa introduci si anul";
      cin >> anul;
      if (anul % 4 == 0)
      {
        cout << 29 << endl;
      }
      else
      {
        cout << 28 << endl;
      }
    }
    else if (luna % 2 == 1)
    {
      cout << 31 << endl;
    }
    else if (luna % 2 == 0)
    {
      cout << 30 << endl;
    }
    cout << "Mai doriti inca o interogare.Optiuni valide d pentru da si n prentu nu" << endl;
    // bucla de repetitie
    cin.get();
    cin.get(opt);
    while (opt != 'd' && opt != 'n')
    {
      cout << "Optiune invalida" << endl;
      cin.get();
      cin.get(opt);
    }
  } while (opt != 'n');
  return 0;
}
`