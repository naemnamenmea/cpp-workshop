#include "segment_tree.hpp"
#include "matrix.hpp"

#include <iostream>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define LOCAL_LAUNCH
#ifdef LOCAL_LAUNCH
#include <fstream>
#endif

typedef long long ll;

using namespace std;
using namespace std::placeholders;

template<class T>
struct TreeNode
{
  typedef T ValueType;

  TreeNode(const T& modifyOnSegmentValue)
    : m_modifyOnSegmentValue(modifyOnSegmentValue),
    m_isAlreadyModified(true),
    m_calcOnSegmentValue(modifyOnSegmentValue)
  {}
  TreeNode()
    : m_modifyOnSegmentValue(1),
    m_isAlreadyModified(false),
    m_calcOnSegmentValue(0)
  {}

  T m_calcOnSegmentValue;
  T m_modifyOnSegmentValue;
  bool m_isAlreadyModified;
};

template<class T>
void Modify(typename SegmentTree<T>::Node& node, const T& value)
{
  node = typename SegmentTree<T>::Node(value);
}

template<class T>
typename SegmentTree<T>::Node Calculate(const typename SegmentTree<T>::Node& leftChild, const typename SegmentTree<T>::Node& rightChild, const T mod)
{
  typename SegmentTree<T>::Node res;
  res.m_mul = (leftChild.m_mul * rightChild.m_mul, mod);
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_LAUNCH
  ifstream ifs("C:/Users/Andrew/source/repos/C++Workshop/sample/input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  int MOD, n, m;
  cin >> MOD >> n >> m;

  using Mtrx = SquareMatrix<int, 2>;
  using NodeType = TreeNode<Mtrx>;
  vector<Mtrx> a(n, Mtrx());
  for (size_t i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  SegmentTree<NodeType> segTree(&Modify<NodeType>, std::bind(Calculate<NodeType>, _1, _2, MOD));
  segTree.Build(a);

  for (size_t i = 0; i < m; ++i)
  {
    size_t l, r;
    cin >> l >> r;

    auto res = segTree.Calculate(l - 1, r);
    cout << res.m_calcOnSegmentValue << endl;
  }

  return 0;
}
