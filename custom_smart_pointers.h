#pragma once

#include <iostream>

using namespace std;

class Object {
public:
  int x;
  Object(int x = 0) : x(x) {
    cout << "Object " << x << endl;
  }
  ~Object() {
    cout << "~Object " << x << endl;
  }
};

template<class T>
class UniquePtr {
public:
  T* ptr;

  UniquePtr(T* p) : ptr(p) {
  }
  UniquePtr(const UniquePtr<T>&) = delete;
  UniquePtr& operator=(const UniquePtr<T>&) = delete;

  ~UniquePtr() {
    delete ptr;
  }
};

template<class T>
class WeakPtr;

template<class T>
class SharedPtr {
public:
  T* ptr;
  size_t* count;

  SharedPtr(T* p) : ptr(p), count(new size_t(1)) {}
  SharedPtr(const SharedPtr<T>& sp) : ptr(sp.ptr), count(sp.count) {
    ++(*count);
  }
  SharedPtr(const WeakPtr<T>& wp) : ptr(wp.ptr), count(wp.count) {
    ++(*count);
  }

  T* operator->() const {
    return ptr;
  }

  operator bool() const {
    return ptr != nullptr;
  }

  ~SharedPtr() {
    if (--(*count) == 0) {
      delete count;
      delete ptr;
    }
  }

  size_t use_count() const {
    return *count;
  }
};

template<class T>
class WeakPtr {
public:
  T* ptr;
  size_t* count;

  WeakPtr(const WeakPtr<T>& wp) : ptr(wp.ptr), count(wp.count) {}
  WeakPtr(const SharedPtr<T>& sp) :ptr(sp.ptr), count(sp.count) {}

  SharedPtr<T> lock() {
    return SharedPtr<T>(*this);
  }

  size_t use_count() const {
    return ptr ? count : 0;
  }
};

void test_smart_pointers() {
  UniquePtr<Object> up(new Object(5));
  SharedPtr<Object> sp1(new Object(7));
  cout << sp1.use_count() << endl;
  SharedPtr<Object> sp2(sp1);
  cout << sp1.use_count() << endl;
  cout << sp2.use_count() << endl;
  {
    WeakPtr<Object> wp(sp1);
    cout << sp1.use_count() << endl;
    if (auto sp = wp.lock()) {
      cout << sp1.use_count() << endl;
      cout << sp->x << endl;
    }
  }
  /*
    Object 5
    Object 7
    1
    2
    2
    2
    3
    7
    ~Object 7
    ~Object 5
  */
}