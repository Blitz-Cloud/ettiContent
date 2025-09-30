#include <iostream>
#include <cmath>

using namespace std;

class Cerc;

class Drepthunghi
{
private:
  float lungime, latime;

public:
  friend class Cerc;
  friend void aria(Drepthunghi &);
  Drepthunghi()
  {
    cout << "Construnctor fara parametri" << endl;
    cout << "Sa se introduca lungimea drepthunghiului" << endl;
    cin >> lungime;
    cout << "Sa se introduca latimea drepthunghiului" << endl;
    cin >> latime;
  }
  Drepthunghi(float lung, float lat)
  {
    cout << "Constructor cu parametri" << endl;
    lungime = lung;
    latime = lat;
  }
  Drepthunghi(Drepthunghi &temp)
  {
    lungime = temp.lungime;
    latime = temp.latime;
  }
  ~Drepthunghi() {}
};

void aria(Drepthunghi &temp)
{
  cout << "Aria drepthunghiului este:" << temp.latime * temp.lungime << endl;
}

class Cerc
{
private:
  float raza;

public:
  friend void aria(Cerc &);
  void transforma(Drepthunghi &temp)
  {
    raza = (temp.latime + temp.lungime) / 2.0;
  }
};

void aria(Cerc &temp)
{
  cout << "Aria cercului este:" << M_PI * temp.raza * temp.raza << endl;
}

int main()
{
  char opt;
  do
  {
    float a, b, c, d;
    cout << "Sa se introduca lungimea pentru primul drepthunghi" << endl;

    cin >> a;
    cout << "Sa se introduca latimea pentru primul drepthunghi" << endl;
    cin >> b;
    cout << "Sa se introduca lungimea pentru al doilea drepthunghi" << endl;
    cin >> c;
    cout << "Sa se introduca latimea pentru al doilea drepthunghi" << endl;
    cin >> d;
    Drepthunghi d1(a, b), d2(c, d);
    Drepthunghi d3(d1);
    aria(d1);
    aria(d2);
    aria(d3);
    Cerc c1;
    c1.transforma(d1);
    aria(c1);
    c1.transforma(d2);
    aria(c1);
    c1.transforma(d3);
    aria(c1);
    cout
        << "Daca se mai doreste o interogare sa se introduca d, pentru a opri programul sa se introduca n" << endl;
    cin >> opt;
    while (opt != 'd' && opt != 'n')
    {
      cout << "Aceasta nu este o optiune valida te rog introdu doar d sau n" << endl;
      cin.ignore();
      cin >> opt;
    }

  } while (opt != 'n');
}
`