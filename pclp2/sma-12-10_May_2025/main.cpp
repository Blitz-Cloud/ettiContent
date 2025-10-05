
```c
#include <iostream>
#include <cmath>
using namespace std;

void calculateSumInWindow(int length, int smaWindow, double data[],
                          double *&sum, double (*func)(double, int))
{
  int i, j, poz = 0;
  double suma;
  sum = new double[length - smaWindow + 1];
  for (i = smaWindow - 1; i < length; i++)
  {
    suma = 0.0;
    for (j = 0; j < smaWindow; j++)
    {
      suma += data[i - smaWindow + 1 + j];
    }
    sum[poz++] = func(suma, smaWindow);
  }
}

void calculateSumOfSquaresInWindow(int length, int smaWindow, double data[],
                                   double *&sum)
{
  int i, j, poz = 0;
  double suma;
  sum = new double[length - smaWindow + 1];
  for (i = smaWindow - 1; i < length; i++)
  {
    suma = 0.0;
    for (j = 0; j < smaWindow; j++)
    {
      suma += pow(data[i - smaWindow + 1 + j], 2);
    }
    sum[poz++] = suma;
  }
}

// Modified: No longer used. `num` is the sum, the `windowSize` determines what we want to return
double calculateSum(double num, int windowSize) { return num; }

double calculateSma(double num, int windowSize) { return num / windowSize; }

double calculatePow2(double num, int windowSize) { return num * num; }

using namespace std;

int main()
{
  int swarmDetected = 0;
  double *sum = nullptr;
  double *sma = nullptr;
  double *sumOfSquares = nullptr; // Name changed for clarity
  double *stdDev = nullptr;       // Added to store the standard deviation
  int size = 20;
  double v[size] = {1, 2, 3, 5, 8, 7, 6, 5, 3, 2, 4, 5, 3, 5, 8, 9, 10, 8, 9, 6};
  int windowSize = 2; // Explicitly define the window size
  double lastStd = 0.0;
  // Calculate sum of the data inside windows
  calculateSumInWindow(size, windowSize, v, sum, calculateSum);

  // Calculate SMA based on the data sum
  calculateSumInWindow(size, windowSize, v, sma, calculateSma);

  // Calculate the sum of squares for the numbers
  calculateSumOfSquaresInWindow(size, windowSize, v, sumOfSquares);

  // Allocate the correct memory space
  stdDev = new double[size - windowSize + 1];

  for (int i = 0; i < size - windowSize + 1; i++)
  {
    stdDev[i] = sumOfSquares[i] / windowSize - sma[i] * sma[i];
    // Check if it is negative due to floating point errors
    if (stdDev[i] < 0)
    {
      stdDev[i] = 0;
    }
    stdDev[i] = sqrt(stdDev[i] * windowSize / (windowSize - 1));

    if (lastStd == 0.0)
    {
      lastStd = stdDev[i];
    }
    else
    {
      cout << "Stdev " << stdDev[i] << endl;
      cout << swarmDetected << endl;
      if (stdDev[i] < lastStd)
      {
        cout << "Scadere" << endl;
        swarmDetected = 0;
      }
      else if (stdDev[i] > lastStd && stdDev[i] > 0.4 && !swarmDetected)
      {
        cout << "Roieste cacatul" << endl;
        swarmDetected = 1;
      }
      else if (stdDev[i] < 0.4 && swarmDetected)
      {
        cout << "Revenire la normal" << endl;
        swarmDetected = 0;
      }

      lastStd = stdDev[i];
    }
  }

  // Properly deallocate memory
  delete[] sma;
  delete[] sum;
  delete[] sumOfSquares;
  delete[] stdDev;

  return 0;
}

```