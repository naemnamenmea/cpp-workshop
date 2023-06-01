#include <iostream>

using namespace std;

//#define __ExtrovertClass__
//#define __IntrovertClass1__
#define __IntrovertClass2__

#ifdef __ExtrovertClass__
template<typename T>
class Object
{
public:
  Object() :m_value(0) {}

  void IncValue() { ++m_value; }
  void DecValue() { --m_value; }

private:
  template<typename U>
  friend ostream& operator<<(ostream&, const Object<U>&);

  T m_value;
};

template<typename T>
ostream& operator<<(ostream& os, const Object<T>& obj)
{
  Object<int> objInt;
  objInt.m_value;
  Object<double> objDouble;
  objDouble.m_value;
  Object<float> objFloat;
  objFloat.m_value;

  os << obj.m_value;
  return os;
}
#endif

#ifdef __IntrovertClass1__
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
    Object<double> objDouble;
    objDouble.m_value;
    //Object<int> objInt;
    //objInt.m_value;
    //Object<float> objFloat;
    //objFloat.m_value;

    os << obj.m_value;
    return os;
  }

  T m_value;
};
#endif

#ifdef __IntrovertClass2__
template<typename T>
class Object;
template<typename T>
ostream& operator<<(ostream&, const Object<T>&);

template<typename T>
class Object
{
public:
  Object() :m_value(0) {}

  void IncValue() { ++m_value; }
  void DecValue() { --m_value; }

private:
  friend ostream& operator<< <>(ostream& os, const Object& obj);

  T m_value;
};

template<typename T>
ostream& operator<<(ostream& os, const Object<T>& obj)
{
  //Object<int> objInt;
  //objInt.m_value;
  //Object<double> objDouble;
  //objDouble.m_value;
  //Object<float> objFloat;
  //objFloat.m_value;

  os << obj.m_value;
  return os;
}
#endif

int main(int argc, const char* argv[])
{
  Object<double> obj;
  cout << obj << endl;
  obj.IncValue();
  cout << obj << endl;
  obj.DecValue();
  cout << obj << endl;
}