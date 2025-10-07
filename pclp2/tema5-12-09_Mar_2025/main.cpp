#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
  int luna[3], ceas[3];
  cout << "Programul 5" << endl;
  cout << "Sa se introduca ziua lunii, luna si anul. ziua lunii poate sa aiba valori de la 1 la 31, luna ia valori de la 1 la 12, iar anul este si el un numar" << endl;
  cin >> luna[0] >> luna[1] >> luna[2];
  // aici sunt trate cazurile in care anul este bisec sau nu
  if (luna[2] % 4 == 0)
  {
    while (luna[1] == 2 && luna[0] > 29)
    {
      cout << "Acest an este bisect, insa februarie nu are cum sa aiba mai mult de 29 de zile asa ca te rog sa introduci o zi calendaristica valida" << endl;
      cin >> luna[0];
    }
  }
  else
  {
    while (luna[1] == 2 && luna[0] > 28)
    {
      cout << "Acest an este bisect, insa februarie nu are cum sa aiba mai mult de 28 de zile asa ca te rog sa introduci o zi calendaristica valida" << endl;
      cin >> luna[0];
    }
  }
  // verific ca luna anului sa fie valida
  while (luna[1] > 12)
  {
    cout << "Intr un an sunt maxim 12 luni, asta cel putin cand acest program a fost scris in anul 2025, optiunile valide sunt numere de la 1 la 12" << endl;
    cin >> luna[1];
  }

  // verific ca ziua introdusa sa fie corecta
  while (luna[1] % 2 == 1 && luna[0] > 31)
  {
    cout << "Luna " << luna[1] << " are numai 31 de zile asa ca te rog sa introduci o zi calendaristica, aceasta este un numar de la 1 la 31" << endl;
    cin >> luna[0];
  }

  while (luna[1] % 2 == 0 && luna[0] > 30)
  {
    cout << "Luna " << luna[1] << " are numai 30 de zile asa ca te rog sa introduci o zi calendaristica, aceasta este un numar de la 1 la 30" << endl;
    cin >> luna[0];
  }

  cout << "Sa se introduca ora, minutul si secunda" << endl;
  // imi doresc ca pe prima pozitie sa am cea mai putin semnificativa informatie, iar pe ultima sa o am pe cea mai semnificativa
  cin >> ceas[2] >> ceas[1] >> ceas[0];

  while (ceas[2] > 24)
  {
    cout << "Sunt doar 24 ore intr-o zi asa ca daca nu esti de pe alta planeta de rog sa introduci un nr de la 1 la 24, iar daca esti de pe alta planeta, atunci nu cred ca te pot ajuta cu acest program intr un fel semnificativ" << endl;
    cin >> ceas[2];
  }
  while (ceas[1] > 60)
  {
    cout << "Sunt doar 60 de minute intr o ora, asa ca te rog sa te confomezi si sa introduci o valoare pentru minute valida" << endl;
    cin >> ceas[1];
  }
  while (ceas[0] > 60)
  {
    cout << "Sunt doar 60 de secunde intr un minut, asa ca te rog sa te conformezi sa introduci o valoare pentru secunde valida" << endl;
    cin >> ceas[0];
  }
  while (1)
  {
    sleep(1);
    ceas[0]++;
    system("clear");
    // controlul secundelor
    if (ceas[0] > 59)
    {
      ceas[0] = 1;
      ceas[1]++;
    }
    // controlul minutelor
    if (ceas[1] > 59)
    {
      ceas[1] = 1;
      ceas[2]++;
    }
    // controlul orelor
    if (ceas[2] > 23)
    {
      ceas[2] = 0;
      luna[0]++;
    }
    // daca este februarie si anul este bisect
    if ((luna[0] > 29 && luna[1] == 2 && luna[2] % 4 == 0) || (luna[0] > 28 && luna[1] == 2 && luna[2] % 4 == 1))
    {
      luna[0] = 1;
      luna[1]++;
    }
    // tratarea in celelalte cazuri
    if (luna[0] > 31 && luna[1] % 2 == 1 || luna[0] == 30 && luna[1] % 2 == 0)
    {
      luna[0] == 1;
      luna[1]++;
    }
    if (luna[1] > 12)
    {
      luna[1] == 1;
      luna[2]++;
    }
    cout << "Data: " << luna[0] << " " << luna[1] << " " << luna[2] << endl;
    cout << "Ora: " << ceas[2] << " " << ceas[1] << " " << ceas[0] << endl;
  }

  return 0;
}