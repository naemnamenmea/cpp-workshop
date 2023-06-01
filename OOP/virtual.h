#pragma once

#include <iostream>

using namespace std;

namespace OOP {
  class Unit {
  public:
    Unit() {}
    virtual void Init() const = 0;

    string name;
  };

  void Unit::Init() const {
    cout << "Base" << endl;
  }

  class Human : public Unit {
  public:
    virtual void Init() const override = 0;
  };

  class Dwarf : public Unit {
  public:
    virtual void Init() const override = 0;
  };

  class Elf : public Unit {
  public:
    virtual void Init() const override = 0;
  };

  void Human::Init() const {
    cout << "DerivedFirst" << endl;
  }

  class Women : public Human {
  public:
    void Init() const override {
      Human::Init();
    }
  };

  void f(Unit& b) {
    b.Init();
  }

  void virtual_FAQ() {
    Women ds;
    f(ds);
  }
}