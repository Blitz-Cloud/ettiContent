---
title: O clasa pentru a usura afisarea de numere pe un ecran led 2x 8 segmente
date: 2025-04-08T03:00:00+03:00
subject: 
description: 'Clasele nu sunt terminate iar codul in linii mari este menit sa fie utilizat ca un model pentru o implementare proprie'
tags: []
uniYearAndSemester: 12
---



```cpp
#include <Arduino.h>
class DisplayLED
{
private:
  byte leds;
  int latchPin, clockPin, dataPin;
  int *devBoardGPIO;                                                                                                                     // nr pinurilor de GPIO, acestia vor fi adaugati in oridinea urmatoare pct,br,bm,bl,tl,tm,tr,m
  int binaryBits[8] = {0, 0, 0, 0, 0, 0, 0, 0};                                                                                          // vector folosit in cazul in care in care registrul de shiftare nu este folosit
  int numsInBinary[10] = {126, 72, 61, 109, 67, 103, 119, 76, 127, 79};                                                                  // sunt reprezentate nr de la 0 la 9 ca suma de puteri ale lui 2 dupa cum sunt asociate segmentele ecranului cu led uri ca puteri ale lui 2
  int alphabetInBinary[27] = {95, 115, 54, 121, 55, 23, 119, 83, 18, 120, 0, 50, 0, 0, 126, 31, 79, 17, 103, 51, 122, 0, 0, 91, 75, 61}; // sunt reprezentate literele alfabetului de la a la z,( exceptii fiind k,m,n,v si w) ca suma de puteri ale lui 2 dupa cum sunt asociate segmentele ecranului cu led uri ca puteri ale lui 2
  int hasShiftRegister = 0;                                                                                                              // libraria a fost constuita cu 74HC595 ca registru de shiftare
  void initializePins()                                                                                                                  // initializeaza pinilor de date pentrua folosi placa
  {
    if (hasShiftRegister)
    {
      pinMode(latchPin, OUTPUT);
      pinMode(dataPin, OUTPUT);
      pinMode(clockPin, OUTPUT);
    }

    for (int i = 0; i < 8 && !hasShiftRegister; i++)
    {
      pinMode(devBoardGPIO[i], OUTPUT);
    }
  }

  void updateShiftRegister()
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
  }
  void generateBinaryArray(int num, int binaryArray[8])
  {

    for (int i = 7; i >= 0; --i)
    {
      int powerOfTwo = 1 << i;
      if (num >= powerOfTwo)
      {
        binaryArray[7 - i] = 1;
        num -= powerOfTwo;
      }
      else
      {
        binaryArray[7 - i] = 0;
      }
    }
  }

public:
  DisplayLED(int latch = 0, int clock = 0, int data = 0, int hasRegister = 0) : latchPin(latch), clockPin(clock), dataPin(data), hasShiftRegister(hasRegister)
  {
    initializePins();
    leds = 0;
    if (hasRegister)
    {
      updateShiftRegister();
    }
    else
    {
      devBoardGPIO = new int[8];
    }
  }
  void resetDisplay()
  {
    if (hasShiftRegister)
    {
      leds = 0;
      updateShiftRegister();
    }
    else
    {
      for (int i = 0; i < 8; i++)
      {
        digitalWrite(devBoardGPIO[i], LOW);
      }
    }
  }

  void showNumber(int num)
  {
    resetDisplay();
    if (hasShiftRegister)
    {
      leds = numsInBinary[num];
      updateShiftRegister();
    }
    else
    {
      generateBinaryArray(num, binaryBits);
      for (int i = 0; i < 8; i++)
      {
        if (numsInBinary[i])
        {
          digitalWrite(devBoardGPIO[i], HIGH);
        }
      }
    }
  }
  void showCharacter(char c)
  {
    resetDisplay();
    if (hasShiftRegister)
    {
      leds = alphabetInBinary[int(toupper(c)) - 65];
      updateShiftRegister();
    }
    else
    {
      generateBinaryArray(int(toupper(c) - 65), binaryBits);
      for (int i = 0; i < 8; i++)
      {
        if (numsInBinary[i])
        {
          digitalWrite(devBoardGPIO[i], HIGH);
        }
      }
    }
  }
  ~DisplayLED()
  {
    delete devBoardGPIO;
  }
};

// int Numere_Pentru_LED_Display[10] = {128, 18, 188, 182, 194, 230, 238, 50, 256, 242};

class Display2Digits : public DisplayLED
{
private:
  DisplayLED display{};
  int gndDis1, gndDis2;
  int contentLength;
  int pozArray;

  void setState(int dis1, int dis2)
  {
    if (dis1)
    {
      digitalWrite(gndDis1, LOW);
    }
    else
    {
      digitalWrite(gndDis1, HIGH);
    }
    if (dis2)
    {
      digitalWrite(gndDis2, LOW);
    }
    else
    {
      digitalWrite(gndDis2, HIGH);
    }
  }

  void generateContentArray(unsigned int num, int *&contentLength, int *&content)
  {
    contentLength = new int;
    *contentLength = 0;
    int numCopy = num, k = 1;
    Serial.println("Lungime");
    Serial.println(numCopy);
    while (num > 0)
    {
      num /= 10;
      *contentLength = *contentLength + 1;
    }
    Serial.println(numCopy);
    // cout << *contentLength << endl;
    num = numCopy;
    content = new int[*contentLength];
    while (num)
    {
      content[*contentLength - k] = num % 10;
      k++;
      num /= 10;
    }
  }

public:
  Display2Digits(int latch, int clock, int data, int hasRegister, int gndD1, int gndD2) : display(latch, clock, data, hasRegister), gndDis1(gndD1), gndDis2(gndD2)
  {
    pinMode(gndD1, OUTPUT);
    pinMode(gndD2, OUTPUT);
  }
  // vreau sa afisez mai mult de o litera si sau text
  // trebuie sa fie capabil sa faca multiplexare
  // incep cu 2 caractere / 2 cifre

  void showNumberOld(int num)
  {

    contentLength = 0;
    if (num < 10)
    {
    }
    else
    {
      int numCopy = num;
      while (num)
      {
        num /= 10;
        contentLength++;
      }
      int *content = new int[contentLength];
      num = numCopy;
      int k = 0;
      while (num)
      {
        content[contentLength - k - 1] = num % 10;
        k++;
        num /= 10;
      }
      static unsigned long time = millis();
      for (pozArray = 0; pozArray < contentLength; pozArray = pozArray + 2)
      {
        Serial.println(content[pozArray]);
        while (millis() - time <= 500)
        {

          display.resetDisplay();
          setState(1, 0);
          display.showNumber(content[pozArray]);
          delay(5);
          display.resetDisplay();
          setState(0, 1);

          display.showNumber(content[pozArray + 1]);
          delay(5);
        }
      }
      delete[] content;
    }
  }

  void showNumber(unsigned int num, int duration = 1000)
  {
    int i, *length = nullptr, *content = nullptr;
    generateContentArray(num, length, content);
    Serial.println(*length);
    Serial.println();
    // for (i = 0; i < *length; i++)
    // {
    //   Serial.println(content[i]);
    //   delay(1000);
    // }

    for (i = 0; i < *length - *length % 2; i = i + 2)
    {
      unsigned long time = millis();
      while (millis() - time < 1000)
      {
        display.resetDisplay();
        setState(1, 0);
        display.showNumber(content[i]);
        delay(5);
        display.resetDisplay();
        setState(0, 1);
        display.showNumber(content[i + 1]);
        delay(5);
      }
    }
    if (i == *length - 1)
    {
      unsigned long time = millis();
      while (millis() - time < 1000)
      {
        display.resetDisplay();
        setState(0, 1);
        display.showNumber(content[i]);
      }
    }
    setState(0, 0);

    delete length;
    delete[] content;
    delay(2500);
  }
};

int dis1 = 2;
int dis2 = 3;

Display2Digits display{5, 6, 4, 1, dis2, dis1};
// DisplayLED display{5, 6, 4, 1};
void setup()
{
  // pinMode(dis1, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  display.showNumber(65536);
  delay(2000);
}
```