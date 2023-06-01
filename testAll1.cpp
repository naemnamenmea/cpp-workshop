//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <memory>
#include <map>
#include <algorithm>
#include <functional>
#include <future>

#include "test_runner.h"
#include "OOP/constructor_destructors_inheritance.h"
#include "OOP/inheritance_access_modifier.h"
#include "OOP/iterators_types.h"
//#include "OOP/oop.h"
#include "OOP/virtual.h"
#include "DataStructures/graphs.h"

typedef long long ll;

using namespace std;

class Base {
public:
	int x;
	Base()
		:x(-7) {}
	virtual void f() {
		cout << "f called from Base" << endl;
	}
};

class Derived : public Base {
public:
	int x;
	Derived()
		:x(6) {}
	void f() {
		cout << "f called from Derived" << endl;
	}
};

void g(Base* base) {
	base->f();
}

class Pr {
public:
  static int x ;
  string Get_string() {
    return s;
  }
private:
  string s = "some value";
};

int Pr::x = 4;

int main() {

	//Derived derived;
	//g(&derived);
   
	//{
	//	using AdjMaxtix =  vector<vector<int>>;

	//	AdjMaxtix graph = {
	//		{0,1,1,1,1},
	//		{0,0,0,1,0},
	//		{0,0,0,1,1},
	//		{0,0,0,0,1},
	//		{0,0,0,0,0}
	//	};

	//	int n = graph.size();
	//	list<int> res;
	//	vector<COLOR> color(n, COLOR::WHITE);

	//	cout << res;
	//}

  Pr a;
  cout << a.x << endl;;
  cout << a.Get_string() << endl;;

	return 0;
}