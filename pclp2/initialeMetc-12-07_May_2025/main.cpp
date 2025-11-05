#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
  char initiale[9] = "TPIAIAC";
  int suma = 0;
  for (int i = 0; i < strlen(initiale); i++)
  {
    cout << initiale[i] << endl;
    suma += int(initiale[i]);
  }
  cout << suma % 100 + 1 << endl;
  return 0;
}