#include "header.hpp"
#include "source2.hpp"

IntWrapper Dummy::SOME_STATIC_VARIABLE = IntWrapper();

int source2()
{
  return ++staticVal;
}