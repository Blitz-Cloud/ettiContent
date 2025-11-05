#include <iostream>

using namespace std;

int main()
{
  system("clear");
  char opt;
  int i, nr_negative = 0, nr_pozitive = 0, media = 0, suma = 0, v[5];
  cout << "Determinarea mediei aritmetice si nr de numere pozitive si negative a 5 numere introduse de la tastatura" << endl;
  do
  {
    nr_negative = 0, nr_pozitive = 0, media = 0, suma = 0;
    for (i = 0; i < 5; i++)
    {
      cout << "Sa se introduca nr " << i + 1 << endl;
      cin >> v[i];
      suma += v[i];
      if (v[i] < 0)
      {
        nr_negative++;
      }
      else if (v[i] > 0)
      {
        nr_pozitive++;
      }
    }
    cout << "Numarul de numere pozitive " << nr_pozitive << endl;
    cout << "Numarul de numere negative " << nr_negative << endl;
    cout << "Media aritmetica a numerelor este " << suma / 5.0 << endl;

    cout << "Pentru inca o interogare introduceti d, pentru a opri programul introduceti n" << endl;
    cin.ignore();
    cin >> opt;
    while (opt != 'd' && opt != 'n')
    {
      cout << "Aceasta este o optiune invalida, te rog introdu d sau n" << endl;
      cin.ignore();
      cin >> opt;
    }

    system("clear");
  } while (opt != 'n');

  return 0;
}