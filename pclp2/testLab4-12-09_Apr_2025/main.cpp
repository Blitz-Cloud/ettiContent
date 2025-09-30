#include <iostream>
#include <cmath>

using namespace std;

class Romb
{
private:
  int diagonala_1, diagonala_2;

public:
  void set_dimensiuni(int a, int b)
  {
    diagonala_1 = a;
    diagonala_2 = b;
  }
  float perimetru()
  {
    int mini_diag_1 = diagonala_1 / 2;
    int mini_diag_2 = diagonala_2 / 2;
    int lat = sqrt(pow(mini_diag_1, 2) + pow(mini_diag_2, 2));
    return 4 * lat;
  }
  float aria();
};

float Romb::aria()
{
  return (diagonala_1 * diagonala_2) / 2;
}

main()
{
  cout << "Determinarea ariei si perimetrului unui romb in functie de dimensiunile diagonalei" << endl;
  char opt;
  Romb forma;
  do
  {
    int a, b;
    cout << "Introduceti diagonala 1 a rombului" << endl;
    cin >> a;
    cout << "Introduceti diagonala 2 a rombului" << endl;
    cin >> b;
    forma.set_dimensiuni(a, b);
    cout << "Perimetru:" << forma.perimetru() << endl;

    cout << "Aria:" << forma.aria() << endl;
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
`