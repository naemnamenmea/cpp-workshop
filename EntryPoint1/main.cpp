#include "source1.hpp"
#include "source2.hpp"
#include "header.hpp"
#include <iostream>

extern int b;

using namespace std;

int main()
{
  cout << source1() << endl;
  cout << source2() << endl;
  cout << b << endl;
  cout << Dummy::SOME_STATIC_VARIABLE << endl;
  return 0;
}