#include <iostream>
#include <cstring>

using namespace std;

class Licenta
{
protected:
  char nume[16], facultate[16], specializare[16];
  float medie;

public:
  Licenta();
  Licenta(char nume[16], char facultate[16], char specializare[16], float medie);
  void afisare()
  {
    cout << nume << " " << facultate << " " << specializare << " " << medie << endl;
  }
};

Licenta::Licenta(char nume[16], char facultate[16], char specializare[16], float medie)
{
  strcpy(Licenta::nume, nume);
  strcpy(Licenta::facultate, facultate);
  strcpy(Licenta::specializare, specializare);
  Licenta::medie = medie;
}

class Masterat : public Licenta
{
public:
};

int main()

{
  char nume[] = "test", facultate[] = "testFacultate", specilizare[] = "nebun pe roti";
  float medie = 0.1;
  Licenta test{nume, facultate, specilizare, medie};
  Masterat master{nume, facultate, specilizare, medie};
  test.afisare();
  master.afisare();
  return 0;
}
`