#pragma once

#include <iostream>
#include <functional>

using namespace std;

namespace callbacks {
  /*
  * —пособы указать тип функции как аргумента:
  * 1.void f(void(*func)(...args...))
  * 2. template <class Func> void f(Func func)
  * 3. void f(function<void(...args...)> func)
  *
  * —пособы передать функцию в функцию:
  * 1. f([](){})
  * 2. struct my_struct { void operator()(int x) {cout << x << endl;} };
  * void f(void(*func)(int), int x) { func(x); }
  * f([](int x){return my_struct{}(x);}, 4);
  * 3. void func() {}   ==>>    f(&func)
  *
  * —пособы объ€вить функциональную переменную:
  * 1. void (*func)(); // создаетс€ функциональна€ переменна€ func  | func = &f;
  * 2. function<void()> func; | func = &f
  * 3. auto func = [](){};
  * 4. func_type func = ...
  *
  * —пособы объ€вить функциональный тип:
  * 1. typedef void (*func)(); // создаетс€ функциональный тип | func g = &f;
  * 2. using func = void (*)(); // создаетс€ функциональный тип | func g = &f;
  *
  * struct my_struct { void operator()() {} }; | my_struct func; func();
  *
  */
  void(*function_var)(size_t);
  using some_func = void(*)(size_t);
  struct Dummy {
    Dummy() {}
    Dummy(bool) {}
    void operator()(size_t) { cout << "from Dummy" << endl; }
  };

  void apply_v1(void(*func)(size_t), size_t times) {
    func(times);
  }

  void f1(void(*func)(int), int x) {
    func(x);
  }

  void apply_v2(some_func f, size_t times) {
    f(times);
  }

  template <class Func>
  void apply_v3(Func f, size_t times) {
    f(times);
  }

  void f(size_t times) {
    std::cout << "It works" + string(times, '!') << std::endl;
  }


  void callbacks() {
    some_func f_pointer = &f;
    function<void(size_t)> f_new_pointer = &f;


    f_pointer(5);
    apply_v1(f, 10);
    f_new_pointer(15);
    apply_v2(f, 20);

    apply_v2(f_pointer, 20);

    Dummy dummy;

    apply_v1([](size_t x) {return Dummy{}(x); }, 25);
    apply_v2([](size_t x) {return Dummy{}(x); }, 30);
    apply_v3(dummy, 30);
    function_var = &f;
    function_var(3);
  }
}