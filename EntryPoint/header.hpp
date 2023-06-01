#pragma once

class IntWrapper
{
public:
  operator int()
  {
    return value;
  }
  int& operator++()
  {
    return ++value;
  }
private:
  int value;
};

class Dummy
{
public:
  static IntWrapper SOME_STATIC_VARIABLE;
  static inline IntWrapper var2 = IntWrapper();
  //static const IntWrapper var1 = IntWrapper();
  static const int var3 = 5;
};

static IntWrapper staticVal;