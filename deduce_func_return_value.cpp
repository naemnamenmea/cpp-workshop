#include <iostream>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <string>
#include <vector>
#include <cmath>

#ifdef LOCAL_LAUNCH
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
#endif

typedef long long ll;

using namespace std;

template<typename Func, typename ReturnType=typename decltype(std::function(Func()))::result_type>
ReturnType returnTemplatedValue(Func func)
{
  return func();
}

double returnDouble() {
  return {};
}

int main() {
  double x = 11235;
  auto func = [x]() {return x; };
  
  std::cout << returnTemplatedValue(func) << std::endl;
  typename decltype(std::function(returnDouble))::result_type y = 4;
  std::cout << y << std::endl;

  return 0;
}
