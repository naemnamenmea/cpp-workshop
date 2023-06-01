#pragma once

#include <bits/stdc++.h>

namespace OOP {
	template<typename T>
	std::string get_iterator_type(T it) {

		if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::input_iterator_tag))	  return "Input";
		else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::output_iterator_tag))        return "Output";
		else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::forward_iterator_tag))       return "Forward";
		else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::bidirectional_iterator_tag)) return "Bidirectional";
		else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::random_access_iterator_tag)) return "Random Access";

		return "missing";
	}

	void exploreIteratorsTypes() {

		std::array<int, 1> a = { 2 };
		std::vector<int> v = { 1,3,5,2,-2 };
		std::deque<int> d = { 1,0,9,3,93 };
		std::forward_list<int> fl = { -1,3,0,32 };
		std::list<int> l;
		std::string str;

		std::set<int> s;
		std::map<int, int> m;

		std::unordered_map<int, int> um;
		std::unordered_set<int, int> us;

		auto it = a.begin();
		auto it1 = v.begin();
		auto it2 = d.begin();
		auto it3 = fl.begin();
		auto it4 = l.begin();
		auto it9 = str.begin();

		auto it5 = s.begin();
		auto it6 = m.begin();

		auto it7 = us.begin();
		auto it8 = um.begin();

		std::cout << "\nSequence Containers:\n\n";
		std::cout << "array::begin         () returns a " << get_iterator_type(it) << " Iterator.\n";
		std::cout << "vector::begin        () returns a " << get_iterator_type(it1) << " Iterator.\n";
		std::cout << "deque::begin         () returns a " << get_iterator_type(it2) << " Iterator.\n";
		std::cout << "forward_list::begin  () returns a " << get_iterator_type(it3) << " Iterator.\n";
		std::cout << "list::begin          () returns a " << get_iterator_type(it4) << " Iterator.\n";
		std::cout << "string::begin        () returns a " << get_iterator_type(it9) << " Iterator.\n";

		std::cout << "\nAssociative Containers:\n\n";
		std::cout << "set::begin           () returns a " << get_iterator_type(it5) << " Iterator.\n";
		std::cout << "map::begin           () returns a " << get_iterator_type(it6) << " Iterator.\n";

		std::cout << "\nUnordered Associative Containers:\n\n";
		std::cout << "unordered_map::begin () returns a " << get_iterator_type(it7) << " Iterator.\n";
		std::cout << "unordered_set::begin () returns a " << get_iterator_type(it8) << " Iterator.\n";

	}
}