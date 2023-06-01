#pragma once

#include<iostream> 

using namespace std;

namespace OOP {
  class Base {
  protected:
    int x;
  public:
    Base() :x(-1) {
      cout << "Base" << endl;
    }
  };

  class Derived1 : public /*virtual*/ Base {
  protected:

  public:
    Derived1() {
      cout << "Derived1" << endl;
      x = 1;
    }
  };

  class Derived2 : public virtual Base {
  protected:

  public:
    Derived2() {
      cout << "Derived2" << endl;
      x = 2;
    }
  };

  class DerivedMain : public Derived1/*, public Derived2*/ {
  protected:

  public:
    DerivedMain() {
      cout << "DerivedMain" << endl;
      cout << x;
    }
  };

  void virtual_inheritance() {
    DerivedMain d;
  }
}