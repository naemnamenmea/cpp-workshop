#pragma once

#include <iostream>
#include <string>

namespace OOP {

#define TEST(var,...) Test var = Test{__VA_ARGS__ }

  class resource
  {
  private:
    int x;
  public:
    resource();
    resource(int v);
    friend std::ostream& operator<<(std::ostream& os, const resource& r);
  };

  resource::resource()
    :x{ 0 }
  {}

  resource::resource(int v)
    : x{ v }
  {}
  std::ostream& operator<<(std::ostream& os, const resource& r)
  {
    return os << r.x;
  }


  class Test {
  private:
    size_t _size;
    resource* _p;
  public:
    std::string _id;
    static int cnt;

    Test();
    ~Test();

    Test(const std::initializer_list<int>& init_list);
    Test(size_t size);

    Test(const Test& tmp);
    Test(Test&& tmp) noexcept;

    Test& operator=(const Test& obj);
    Test& operator=(Test&& obj) noexcept;

    resource getResource();
  };

  int Test::cnt = 0;

  Test::Test(size_t size)
    : _size(size), _p{ new resource[size] }, _id(std::to_string(++Test::cnt))
  {    
    std::cout << "Custom constructor #" << _id << " called" << std::endl;
  }

  Test::Test()
    :_p(nullptr), _size(0), _id(std::to_string(++Test::cnt))
  {
    std::cout << "Default constructor #" << _id << " called" << std::endl;
  }

  Test::~Test()
  {
    std::cout << "Destructor #" << _id << " called" << std::endl;
    if (_p != nullptr) {
      delete[] _p;
    }
  }

  Test::Test(Test&& tmp) noexcept
    :_p(nullptr), _size(0), _id(std::to_string(++Test::cnt))
  {
    std::swap(_p,tmp._p);
    std::swap(_id,tmp._id);
    std::swap(_size,tmp._size);
    std::cout << "Move constructor&& #" << _id << " called" << std::endl;
  };

  Test::Test(const Test& obj)
    :_size(obj._size),    _p(new resource[obj._size]), _id(std::to_string(++Test::cnt))
  {
    std::cout << "Copy constructor& #" << _id << " called" << std::endl;
    std::copy(obj._p, obj._p + _size, _p);
  };

  Test& Test::operator=(const Test& obj)
  {
    std::cout << "Assign operator for #" << _id << " called" << std::endl;
    if (this != &obj) {
      delete[] _p;

      _size = obj._size;
      _p = new resource[_size];
      std::copy(obj._p, obj._p + _size, _p);
    }

    return *this;
  }

  Test& Test::operator=(Test&& obj) noexcept
  {
    std::cout << "Move operator for #" << _id << " called" << std::endl;
    if (this != &obj) {
      delete[] _p;

      _p = obj._p;
      _size = obj._size;
      obj._size = 0;
      obj._p = nullptr;
    }

    return *this;
  }

  Test::Test(const std::initializer_list<int>& init_list)
  {
    _id = std::to_string(++Test::cnt);
    std::cout << "Initialize list #" << _id << " called" << std::endl;
  };

  resource Test::getResource()
  {
    return *_p;
  }

  Test returnTest()
  {
    TEST(t0);
    return t0;
  }

  Test returnTestAtReturn()
  {
    TEST(r);
    return r;
  }

  void constructor_copy_assign() {

//#line 1
    //returnTest();

    //returnTestAtReturn();
    //TEST(t1, returnTest());
    //TEST(t2, returnTestAtReturn());
    //TEST(t4, t2);
    //t4 = t2;
    //TEST(var_name, std::move(t4));

    //std::cout << t4.getResource() << std::endl; // crash
  };
}