#include <iostream>

using namespace std;

template<typename T>
class Object
{
public:
  Object() :m_value(0) {}

  void IncValue() { ++m_value; }
  void DecValue() { --m_value; }

private:
  friend ostream& operator<<(ostream& os, const Object& obj)
  {
    os << obj.m_value;
    return os;
  }

  T m_value;
};

template<typename T>
using ToMemFuncPtr = void(Object<T>::*)();

int main(int argc, const char* argv[])
{
  void(Object<double>:: * memFuncPtr1)() = &Object<double>::IncValue;
  ToMemFuncPtr<double> memFuncPtr2 = &Object<double>::IncValue;

  Object<double> obj;
  cout << obj << endl;
  (obj.*memFuncPtr1)();
  (obj.*memFuncPtr2)();
  cout << obj << endl;
}