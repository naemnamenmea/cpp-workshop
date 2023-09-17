#include "my_testing_tools.hpp"
#include <string>
#include <charconv>
#include <optional>

using namespace std;

void Print(string_view sv, optional<int> _stoi, optional<int> _from_chars)
{
  cout << "s=\"" << sv << "\"; ";
  cout << "stoi: \"" << (_stoi ? to_string(*_stoi) : "null") << "\"; ";
  cout << "from_chars: \"" << (_from_chars ? to_string(*_from_chars) : "null") << '\"';
  cout << endl;
}

void TTest(const string& s)
{
  string_view sv = s;

  size_t pos1;
  optional<int> v1, v2;
  try
  {
    v1 = stoi(s, &pos1);
  }
  catch (...)
  {

  }
  int tmp;
  auto [pos2, errc] = from_chars(sv.data(), sv.data() + sv.size(), tmp);
  if (pos2 != sv.data())
  {
    v2 = make_optional(tmp);
  }
  //ASSERT_EQUAL(*v1, *v2);
  //ASSERT_EQUAL(sv.data() + pos1, pos2);
  Print(sv, v1, v2);
}

TEST(from_chars_vs_stoi, firstTest)
{
  TTest("123");
  TTest(" 10");
  TTest("");
  TTest("01");
  TTest("-01");
}