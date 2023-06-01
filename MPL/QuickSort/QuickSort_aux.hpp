#pragma once
#ifndef __QuickSort_aux__
#define __QuickSort_aux__

#include <vector>
#include <string>

class Student {
protected:
	int num;
	std::string name;
	std::string patronymic;
	std::string surname;
	int mark;
public:
	int getMark() const;
	void setMark(const int& val);
    int getNum() const;
	void setNum(const int& val);
	friend std::ostream& operator<<(std::ostream& os, Student student);
	friend bool operator<(const Student& a, const Student& b);

	static void init(std::vector<Student>& students);
	static void printStudents(std::vector<Student> students);
};

extern std::vector<std::string> names;

#endif // __QuickSort_aux__