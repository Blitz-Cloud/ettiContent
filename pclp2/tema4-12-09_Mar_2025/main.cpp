#include <iostream>

using namespace std;

int main()
{
  // nu a fost testat suficient programul posibile erori legate de nr maxim de persoane
  const int nr_maxim_de_persoane = 10;
  char NUME[nr_maxim_de_persoane][17], PREN[nr_maxim_de_persoane][17];
  int TEL[nr_maxim_de_persoane], nr_persoane, index_curent = 0;
  char opt;
  cout << "Programul 4" << endl;
  do
  {
    cout << "Cate persoane doriti sa introduceti, pot fi introduse maxim " << nr_maxim_de_persoane - index_curent << " persoane in agenda la acest moment" << endl;
    cin >> nr_persoane;
    while (nr_persoane + index_curent > nr_maxim_de_persoane)
    {
      if (index_curent == nr_maxim_de_persoane)
      {
        cout << "Nr maxim de persoane a fost atins, nu mai sunt posibile alte adaugari in agenda" << endl;
        break;
      }
      cout << "Optiunea introdusa este invalida, nr de persoane care pot fi introduse in agenda este de maxim " << nr_maxim_de_persoane << endl;
      cout << "Mai pot fi introduse " << nr_maxim_de_persoane - index_curent << " persoane" << endl;
      cin >> nr_persoane;
    }
    int final_index = index_curent + nr_persoane;
    for (index_curent; index_curent < final_index; index_curent++)
    {
      cout << "Introduceti numele persoanei " << index_curent + 1 << endl;
      cin.get();
      cin.get(NUME[index_curent], 16);

      cout << "Introduceti prenumele persoanei " << index_curent + 1 << endl;
      cin.get();
      cin.get(PREN[index_curent], 16);

      cout << "Introduceti nr de telefon al persoanei " << index_curent + 1 << endl;
      cin >> TEL[index_curent];
    }
    cout << "Agenda telefonica:" << endl;
    for (int i = 0; i < index_curent; i++)
    {
      cout << "Persoana " << i + 1 << " " << NUME[i] << " " << PREN[i] << " " << TEL[i] << endl;
    }
    cout << "Mai doriti inca o interogare. Optiuni valide d si n" << endl;
    cin.get();
    cin.get(opt);
    while (opt != 'n' && opt != 'd')
    {
      cout << "Optiune invalida, te rog introduce d sau n" << endl;
      cin.get();
      cin.get(opt);
    }
  } while (opt != 'n');
  return 0;
}