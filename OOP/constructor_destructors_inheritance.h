#pragma once

#include "copy_of_compex_obj.h"
#include <bits/stdc++.h>

using namespace std;

namespace OOP {
#define self(x) #x

  struct R {
    int x;
    int y;
    R(int x, int y) :x(x), y(y) { std::cout << "R::R x= " << x << "; y= " << y << std::endl; }
    ~R() { std::cout << "~R::R " << std::endl; }
  };

  struct G {
    int x;
    static const int c = 3;
    G(int x) :x(x) { std::cout << "G::G " << x << std::endl; }
    ~G() { std::cout << "~G::G " << std::endl; }
  };

  struct D {
    int x;
    D(int x) : x(x) { std::cout << "D::D " << x << std::endl; }
    ~D() { std::cout << "~D::D " << std::endl; }
  };

  struct B {
    int x;
    B(int x) :x(x) { std::cout << "B::B " << x << std::endl; }
    ~B() { std::cout << "~B::B " << std::endl; }
  };

  struct C : D, B {
    C() :B(r.x), g(9), r(g.c, g.x), D(7) { std::cout << "C::C " << std::endl; }
    ~C() { std::cout << "~C::C " << std::endl; }
    R r;
    G g;
  };
  //------------------------------------------------------------------------
  struct AA {
    int x;
    AA() :x(0) { std::cout << " AA::AA " << std::endl; }
    AA(int x) :x(x) { std::cout << "AA custom ctor " << x << std::endl; }
    AA(const AA& e) :x(e.x) { std::cout << "AA copy ctor " << std::endl; }
    AA(AA&& e) noexcept :x(move(e.x)) { std::cout << "AA move ctor " << std::endl; }
    AA operator=(const AA&) { std::cout << "copy AA::operator= " << std::endl; return *this; }
    AA operator=(AA&&) noexcept { std::cout << "move AA&&::operator= " << std::endl; return *this; }
    ~AA() { std::cout << "~AA::AA " << std::endl; }
  };

  struct TMP {
    int var;
  };

  struct BB : public TMP {
    BB(int x, int y)
      :a(x)
    {
      var = y + 2;
      std::cout << "BB::BB " << a.x << " TMP::var " << var << std::endl;
    }
    BB(const string&) :a(0) {
      std::cout << "BB::BB custom " << a.x << " TMP::var " << var << std::endl;
    }
    ~BB() { std::cout << "~BB::BB " << std::endl; }

    static void Test() {
      std::cout << "Test called " << std::endl;
    }

    const AA a = AA(4);
  };

  //------------------------------------------------------------------------
  void constructor_destructor_inheritance() {

    C* c = new C;
    delete c;
    cout << "------------" << endl;
    BB b1 = BB(9, -1);
    cout << "------------" << endl;
    BB b2 = BB{ "" };
  }

  //-------------------------------------

  copy_of_complex_obj::C copy_elision_rvo() {
    return copy_of_complex_obj::C();
  }

  copy_of_complex_obj::C copy_elision_nrvo() {
    copy_of_complex_obj::C g;
    return g;
  }

  void copy_constructor() {
    cout << self(copy_elision_rvo) << endl;
    auto x = copy_elision_rvo();
    cout << self(copy_elision_nrvo) << endl;
    auto y = copy_elision_nrvo();
  }

  void create_from_temp() {
    {
      cout << "------------" << endl;
      cout << "Create from RVO" << endl;
      AA var = []() -> AA { return {}; }();
    }
    cout << "------------" << endl;
    {
      cout << "Create from NRVO" << endl;
      AA var = []() {AA res; return res; }();
      cout << "::before" << endl;
      cout << "::after" << endl;
    }
  }

  void assign_from_temp() {
    {
      cout << "------------" << endl;
      cout << "Assign RVO after creation" << endl;
      AA var;
      cout << "::before" << endl;
      var = []() -> AA { return {}; }();
      cout << "::after" << endl;
    }
    cout << "------------" << endl;
    {
      cout << "Assign NRVO after creation" << endl;
      AA var;
      cout << "::before" << endl;
      var = []() {AA res; return res; }();
      cout << "::after" << endl;
    }
  }

}