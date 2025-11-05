#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  cout << "Rezolvarea ecuatiei de gradul 2" << endl;
  char opt;
  float x, x1, x2, a, b, c, d;

  do
  {
    system("clear");
    cout << "Acest program este destinat sa rezolve ecuatia de gradul al doilea.\nAceasta are forma ax^2+bx+c=0" << endl;
    cout << "Sa se introduca valorile pentru a,b si c in oridinea in care sunt cerute" << endl;
    cout << "a=";
    cin >> a;
    cout << "b=";
    cin >> b;
    cout << "c=";
    cin >> c;

    d = b * b - 4 * a * c;
    if (d > 0)
    {
      x1 = (-1 * b + sqrt(d)) / 2 * a;
      x2 = (-1 * b - sqrt(d)) / 2 * a;
      cout << "x1=" << x1 << endl;
      cout << "x2=" << x2 << endl;
    }
    else if (d < 0)
    {
      x1 = -b / 2 * a;
      x2 = sqrt(-1 * d) / 2 * a;
      cout << "x1=" << x1 << "+ i*" << x2 << endl;
      x1 = -b / 2 * a;
      x2 = sqrt(-1 * d) / 2 * a;
      cout << "x2=" << x1 << "- i*" << x2 << endl;
    }
    else
    {
      x = -b / 2 * a;
    }
    cout << "Daca se mai dorescte o interogare sa se introduca d pentru a opri programul tasteaza n" << endl;
    cin >> opt;
    while (opt != 'd' && opt != 'n')
    {
      cin.ignore();
      cout << "Optiune invalida, sa se introduca d sau n" << endl;
      cin >> opt;
    }
  } while (opt != 'n');
  return 0;
}