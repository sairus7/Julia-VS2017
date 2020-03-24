#pragma once
#include "pch.h"
#include <iostream>

using namespace std;

class IBar
{
public:
  virtual bool foo(int x) = 0;
};

class CBar : public IBar
{
private:
  int counter = 0;

public:
  bool foo(int x)
  {
    counter++;
    cout << counter << " foo method called: x == " << x << endl;
    return true;
  }
};
