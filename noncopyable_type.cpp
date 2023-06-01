#include <string_view>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;

struct NoncopyableInt {
	int value;
	NoncopyableInt() = default;

	NoncopyableInt(const NoncopyableInt&) = delete;
	NoncopyableInt& operator=(const NoncopyableInt&) = delete;

	NoncopyableInt(NoncopyableInt&&) = default;
	NoncopyableInt& operator=(NoncopyableInt&&) = default;
};

bool operator == (const NoncopyableInt& lhs, const NoncopyableInt& rhs) {
	return lhs.value == rhs.value;
}

ostream& operator << (ostream& os, const NoncopyableInt& v) {
	return os << v.value;
}

int main() {

  vector<NoncopyableInt> v{ NoncopyableInt{} };
  v.push_back(NoncopyableInt{});

	return 0;
}