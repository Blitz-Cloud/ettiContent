#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  cout << "Afisarea puterilor consecutive ale unui nr citit" << endl;
  int nr, nr_initial;
  int pin, i = 1;
  cout << "Sa se introduca un numar de la tastura" << endl;
  cin >> nr;
  while (cin.fail())
  {
    cin.clear();
    cin.ignore();
    cin.get();
    cout << "Tocmai ai introdus litere, te rog sa intoduci numai cifre" << endl;
    cin >> nr;
  }
  nr_initial = nr;

  do
  {
    pin = 0;
    cout << nr_initial << "^" << i << "=" << nr << endl
         << endl;
    nr *= nr_initial;
    i++;
    cin.ignore();
    cout << "Sa se introduca pinul pentru a continua afisarea puterilor numarul " << nr_initial << endl;
    cout << "Pin:";
    cin >> pin;
    while (cin.fail())
    {
      cin.clear();
      cin.ignore();
      cout << "\nPinul nu poate sa contina litere.\nTe rog sa introduci din nou pinul" << endl;
      cout << "Pin:";
      cin >> pin;
    }
    cout << endl;
  } while (pin == 1234);
  cout << "Pinul este gresit" << endl;
  return 0;
}