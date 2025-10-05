
```c
#include <iostream>

using namespace std;

int main()
{
  int cod_abonat;
  char opt;
  cout << "Programul 1" << endl;
  do
  {
    do
    {
      cout << "Indroduceti codul pentru abonat, optiunile valide sunt 1,2,3 sau 4:" << endl;
      cin >> cod_abonat;
      if (cod_abonat == 1)
      {
        cout << "Abonat obisnuit" << endl;
      }
      else if (cod_abonat == 2)
      {
        cout << "Rezerva" << endl;
      }
      else
      {
        switch (cod_abonat)
        {
        case 3:
          cout << "Abonat transferat" << endl;

          break;
        case 4:
          cout << "Abonat absent" << endl;
          break;
        default:
          cout << "Acesta nu este un cod de abonat valid,introduceti un cod de abonat valid" << endl;
          break;
        }
      }
    } while (cod_abonat < 1 || cod_abonat > 4);
    cout << "Doriti sa mai introduceti un cod, tastati d pentru da si n pentru nu" << endl;
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
```