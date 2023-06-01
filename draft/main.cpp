#include <vector>
#include <cassert>

#include "stl_containers_write.hpp"
#include "test_runner.h"

using namespace std;
class Solution {
public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    vector<vector<char>> res(board);
    int m = static_cast<int>(res.size());
    int n = static_cast<int>(res[0].size());

    int r = click[0];
    int c = click[1];

    if (res[r][c] == 'M')
    {
      res[r][c] = 'X';
      return res;
    }

    auto visitorFunc = [](vector<vector<char>>& board, int r, int c, int m, int n) -> bool {
      if (board[r][c] != 'E')
        return false;

      int bombsCnt = GetBombNearbyCnt(board, r, c, m, n);
      if (bombsCnt > 0)
      {
        board[r][c] = '0' + static_cast<char>(bombsCnt);
        return false;
      }

      board[r][c] = 'B';
      return true;
    };

    Visit(res, r, c, m, n, visitorFunc);

    return res;
  }

private:
  static int GetBombNearbyCnt(vector<vector<char>>& board, int r, int c, int m, int n)
  {
    int res = 0;

    auto visitorFunc = [&res](const vector<vector<char>>& board, int r, int c, int m, int n) {
      m; n;
      if (board[r][c] == 'M')  ++res;
    };

    ApplyToNearbyCells(board, r, c, m, n, visitorFunc);

    return res;
  }

  template<typename CellVisitorFunc>
  static void ApplyToNearbyCells(vector<vector<char>>& board, int r, int c, int m, int n, CellVisitorFunc visitorFunc)
  {
    if (r < 0 || r >= m || c < 0 || c >= n)
      return;

    if (r - 1 >= 0 && c - 1 >= 0)
      visitorFunc(board, r - 1, c - 1, m, n);
    if (r - 1 >= 0)
      visitorFunc(board, r - 1, c, m, n);
    if (r - 1 >= 0 && c + 1 < n)
      visitorFunc(board, r - 1, c + 1, m, n);
    if (c - 1 >= 0)
      visitorFunc(board, r, c - 1, m, n);
    if (c + 1 < n)
      visitorFunc(board, r, c + 1, m, n);
    if (r + 1 < m && c - 1 >= 0)
      visitorFunc(board, r + 1, c - 1, m, n);
    if (r + 1 < m)
      visitorFunc(board, r + 1, c, m, n);
    if (r + 1 < m && c + 1 < n)
      visitorFunc(board, r + 1, c + 1, m, n);
  }

  template<typename CellVisitorFunc>
  static void Visit(vector<vector<char>>& board, int r, int c, int m, int n, CellVisitorFunc visitorFunc)
  {
    if (r < 0 || r >= m || c < 0 || c >= n)
      return;

    if (!visitorFunc(board, r, c, m, n))
      return;

    ApplyToNearbyCells(board, r, c, m, n, [visitorFunc](vector<vector<char>>& board, int r, int c, int m, int n) {
      Visit(board, r, c, m, n, visitorFunc);
      });
  }
};

void Test1()
{
  using Board = vector<vector<char>>;
  vector<int> click = { 3, 0 };
  Solution sol;
  Board board = {
    {'E', 'E', 'E', 'E', 'E'},
    {'E', 'E', 'M', 'E', 'E'},
    {'E', 'E', 'E', 'E', 'E'},
    {'E', 'E', 'E', 'E', 'E'} };
  Board expected = {
    {'B', '1', 'E', '1', 'B'},
    {'B', '1', 'M', '1', 'B'},
    {'B', '1', '1', '1', 'B'},
    {'B', 'B', 'B', 'B', 'B'} };
  Board result = sol.updateBoard(board, click);
  ASSERT_EQUAL(result, expected);
}

void Test2()
{
  using Board = vector<vector<char>>;
  vector<int> click = { 1, 2 };
  Solution sol;
  Board board = {
    {'B', '1', 'E', '1', 'B'},
    {'B', '1', 'M', '1', 'B'},
    {'B', '1', '1', '1', 'B'},
    {'B', 'B', 'B', 'B', 'B'} };
  Board expected = {
    {'B', '1', 'E', '1', 'B'},
    {'B', '1', 'X', '1', 'B'},
    {'B', '1', '1', '1', 'B'},
    {'B', 'B', 'B', 'B', 'B'} };
  Board result = sol.updateBoard(board, click);
  ASSERT_EQUAL(result, expected);
}

void RunAllTests()
{
  TestRunner tr;
  RUN_TEST(tr, Test1);
  RUN_TEST(tr, Test2);
}

int main()
{
  RunAllTests();

  return 0;
}