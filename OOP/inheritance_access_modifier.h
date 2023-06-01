#pragma once

namespace multiple_inheritance_access_modifier {
  class A {
  public:
    int a = 0;
  protected:
    int b = 0;
  private:
    int c = 0;
  };

  class B {
  public:
    int x = 0;
  protected:
    int y = 0;
  private:
    int z = 0;

  };

  class C : A, public B {
  public:
  protected:
  private:
  };

  struct D : A, B {
  public:
  protected:
  private:
  };

  void test() {
    C o1;
    o1.x;
    //o1.y;
    //o1.z;
    //o1.a;
    //o1.b;


    D o2;
    o2.x;
    //o2.y;
    //o2.z;
    o2.a;
    //o2.b;
    //o2.c;
  }
}