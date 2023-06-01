#pragma once

#include <iostream>

using namespace std;

namespace copy_of_complex_obj {
  struct A {
    A() { std::cout << " AA::AA " << std::endl; }
    A(const A&) { std::cout << " AA copy ctor " << std::endl; }
    A(A&&) noexcept { std::cout << " AA move ctor " << std::endl; }
    A& operator=(const A&) { std::cout << " AA assignment operator " << std::endl; return *this; }
    A& operator=(A&&) noexcept { std::cout << " AA move operator " << std::endl; return *this; }
    ~A() { std::cout << "~AA::AA " << std::endl; }
  };

  struct B : A {
    B() { std::cout << " BB::BB " << std::endl; }
    B(const B&)  { std::cout << " BB copy ctor " << std::endl; }
    B(B&&) noexcept { std::cout << " BB move ctor " << std::endl; }
    B& operator=(const B&) { std::cout << " BB assignment operator " << std::endl; return *this; }
    B& operator=(B&&) noexcept { std::cout << " BB move operator " << std::endl; return *this; }
    ~B() { std::cout << "~BB::BB " << std::endl; }
  };

  struct C : B {
    C() { std::cout << " CC::CC " << std::endl; }
    C(const C&) { std::cout << " CC copy ctor " << std::endl; }
    C(C&&) noexcept { std::cout << " CC move ctor " << std::endl; }
    C& operator=(const C&) { std::cout << " CC assignment operator " << std::endl; return *this; }
    C& operator=(C&&) noexcept { std::cout << " CC move operator " << std::endl; return *this; }
    ~C() { std::cout << "~CC::CC " << std::endl; }
  };

  void copy_of_complex_obj() {
    C o1;
    C o2 = move(o1);
  }
}