#include <tuple>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>

#include "QuickSort_aux.hpp"

void Student::printStudents(std::vector<Student> students) {
	for (auto i : students) std::cout << i << std::endl;
}

void Student::init(std::vector<Student>& students) {
        int cnt = 0;
	for (std::vector<Student>::iterator i = students.begin(); i != students.end(); ++i)	{
		i->setMark( rand() % 100 );
                i->setNum( ++cnt );
		if (!names.empty()) {
			i->name = names.back();
			names.pop_back();
		}
		else i->name = "null";
	}
}

std::ostream& operator<<(std::ostream& os, Student student) {
	//return os << student.surname << " " << student.name[0] << ". " << student.patronymic[0] << ". <" << student.mark << ">";
	return os << std::setw(2) << student.getNum() 
		<< ". " << std::left << std::setw(20) << student.name 
		<< " : " << student.mark;
}

int Student::getMark() const {
	return this->mark;
}

void Student::setMark(const int& val) {
	this->mark = val;
}

int Student::getNum() const {
	return this->num;
}

void Student::setNum(const int& val) {
	this->num = val;
}

bool operator<(const Student& a, const Student& b) {
	return a.getMark() < b.getMark();
}

std::vector<std::string> names{
	"Валентин Зинченко",
	"Денис Игнатенко",
	"Максим Гербер",
	"Анастасия Балицкая",
	"Танюшка Орлова",
	"Дарья Маркова",
	"Эдем Ибрагимов",
	"Дмитрий Сиделёв",
	"Дима Апашанский",
	"Алие Челебиева",
	"Айсель Шерфединова",
	"Женя Фенина",
	"Валера Олисеенко",
	"Антон Ступников",
	"Анатолий Валеев",
	"Дима Киселёв",
	"Сергей Гордон",
	"Алексей Бугаёв",
	"Александр Шаганский",
	"Мухаммед Исмаилов",
	"Олег Аяксов",
	"Дмитрий Сидиропуло",
	"Никита Гончаров",
	"Дмитрий Моисеенко",
	"Илья Сирота",
	"Антон Мельничук",
	"Сергей Тоберт",
	"Александр Егоров",
	"Владимир Павлюков",
	"Сардор Жалилов",
	"Данил Ополоник",
	"Юля Ивлева",
	"Оксана Соколова"
};