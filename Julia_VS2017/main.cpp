#include "pch.h"
#include <iostream>

#include "bar.h"

using namespace std;

// simple function callback
bool foo(int x)
{
  cout << "foo function called: x == " << x << endl;
  return true;
}

int main(int argc, char *argv[])
{
  /* required: setup the Julia context */
  jl_init();

  /* run Julia commands */
  jl_eval_string("print(sqrt(2.0))");
  cout << endl;

  // ========== Questions: ==============
  // I need to estabilish two-way connection between cpp and Julia code:

  // 1. How to pass foo function to Julia and call it back from Julia?
  foo(7);

  // 2. How to pass CBar object to Julia?
  CBar bar_obj;
  
  // 3. How to call CBar object method bar_obj.foo() from Julia?
  bar_obj.foo(7);
  
  // 4. How to pass IBar interface object to Julia?
  IBar * ibar = (IBar*)&bar_obj;

  // 5. How to call IBar interface object method ibar->foo() from Julia?
  ibar->foo(7);

  // ====================================
  
  /* notify Julia that the program is about to terminate */
  jl_atexit_hook(0);
  return 0;
}
