#include <iostream>

using namespace std;

class Dreothunghi;
class Patrat;
class Paralelogram
{
private:
  int inaltime;

protected:
  int lungime, latime;

public:
  Paralelogram(int inaltime = 2, int lungime = 2, int latime = 2)
  {
    Paralelogram::inaltime = inaltime;
    Paralelogram::lungime = lungime;
    Paralelogram::latime = latime;
  }
  Paralelogram(Paralelogram &obj)
  {
    inaltime = obj.inaltime;
    lungime = obj.lungime;
    latime = obj.latime;
  }
  ~Paralelogram() {}
  int aria()
  {
    return inaltime * lungime;
  }

  friend Patrat transforma(Paralelogram &);
};

class Drepthunghi : public Paralelogram
{

public:
  Drepthunghi(int lungime = 0, int latime = 0) : Paralelogram(0, lungime, latime) {}
  Drepthunghi(Paralelogram &obj) : Paralelogram(obj)
  {
  }
  int aria()
  {
    return lungime * latime;
  }
  void afisare()
  {
    cout << lungime << " " << latime << endl;
  }
  friend Drepthunghi increment(Drepthunghi &);
};

class Patrat : public Drepthunghi
{
private:
  int latura;

public:
  Patrat(int latura) : Drepthunghi(latura, latura)
  {
    Patrat::latura = latura;
  }
};

Patrat transforma(Paralelogram &obj)
{
  int dimensiuni = (obj.lungime + obj.latime) / 2;
  return Patrat{dimensiuni};
}
Drepthunghi increment(Drepthunghi &obj)
{
  int lungime = obj.lungime * 2;
  int latime = obj.latime * 2;
  return Drepthunghi{lungime, latime};
}
int main()
{
  Paralelogram paral;
  int n;
  cin >> n;
  Drepthunghi vector[n];
  vector[0] = paral;

  for (int i = 1; i < n; i++)
  {
    vector[i] = increment(vector[i - 1]);
  }
  Patrat ptr = transforma(paral);
  cout << "Aria paral " << paral.aria() << endl;
  cout << "Arii drepthunghiuri " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << vector[i].aria() << " ";
  }
  cout << endl;
  cout << "aria patrat " << ptr.aria();
}
