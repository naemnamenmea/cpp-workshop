#pragma once
#ifndef __QuickSort__
#define __QuickSort__

#include <functional>
#include <vector>

#include "QuickSort_aux.hpp"

inline int rand(int p, int q) {
	return (p + rand() % (q - p + 1));
}

template <class T>
using Comparator = std::function<bool(const T&, const T&)>;

template <class T>
void QuickSort(std::vector<T>& v, Comparator<T> comp = [](const T& a, const T& b) {return a < b;}) {
	QuickSort(v, 0, v.size() - 1, comp);
}

template <class T>
void QuickSort(std::vector<T>& v, int left, int right, Comparator<T> comp = [](const T& a, const T& b) {return a < b;}) {
	if (left < right) {
		int index = Partition(v, left, right, comp);
		QuickSort(v, left, index - 1, comp);
		QuickSort(v, index + 1, right, comp);
	}
}

template <class T>
int Partition(std::vector<T>& v, int left, int right, Comparator<T> comp) {
	int t = rand(left, right); // 'left' and 'right' inclusive
	std::swap(v[t], v[right]);

	int index = left - 1;
	T pivot = v[right];
	for (int i = left; i < right; i++) {
		if (!comp(pivot, v[i])) // ~ if( v[i] <= pivot ) --> ascending sort
			std::swap(v[++index], v[i]);
	}
	std::swap(v[++index], v[right]);
	return index;
}

#endif // __QuickSort__