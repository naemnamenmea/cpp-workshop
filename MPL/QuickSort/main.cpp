// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "QuickSort.hpp"

int main()
{
    setlocale(LC_ALL, "RUS");
	srand((unsigned int)time(NULL));
    
    std::vector<int> v{ 15,1,9,0,-4,5 };

	QuickSort<int>(v);
	//QuickSort<int>(v, [](const int& a, const int& b) {return a > b;});
	//QuickSort<int>(v, 0, v.size() - 1, [](const int& a, const int& b) {return a < b;});
	for (auto i : v) //std::cout << i << ' '; std::cout << std::endl;
	std::cout << std::endl;


	std::vector<Student> stds(21, Student());
	Student::init(stds);

	QuickSort<Student>(stds);
	//QuickSort<Student>(stds, [](const Student& a, const Student& b) {return a.getMark() > b.getMark();});
	//QuickSort<Student>(stds, 0, stds.size() - 1, [](const Student& a, const Student& b) {return a.getMark() < b.getMark();});
	for (auto i : stds) //std::cout << i << std::endl;
	std::cout << std::endl;
    return 0;
}

