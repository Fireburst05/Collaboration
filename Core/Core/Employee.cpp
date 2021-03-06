#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Employee.h"
#include "Manager.h"

Employee::Employee(std::string name, std::string gender, std::string date_of_birth)
	: Name(name), Gender(gender), Date_of_birth(date_of_birth) {
	time_t now = time(0);
	tm* localtm = localtime(&now);
	Employee::Join_date = 
		(localtm->tm_mday >= 10 ? std::to_string(localtm->tm_mday) : ("0" + std::to_string(localtm->tm_mday))) +
		(localtm->tm_mon >= 10 ? std::to_string(localtm->tm_mday + 1) : ("0" + std::to_string(localtm->tm_mday + 1))) +
		std::to_string(1900 + localtm->tm_year);
	Employee::Title = "Employee";
	std::cout << "Profile created. (" << Employee::Name << ")" << std::endl;
}
std::string Employee::getName() {
	return Employee::Name;
}
std::string Employee::getGender() {
	return Employee::Gender;
}
std::string Employee::getDate_of_birth() {
	return Employee::Date_of_birth;
}
std::string Employee::getJoin_date() {
	return Employee::Join_date;
}
std::string Employee::getTitle() {
	return Employee::Title;
}
float Employee::getSalary() {
	return Employee::Salary;
}
unsigned int Employee::getWorkingID() {
	if (Employee::Active_state == true) return Employee::WorkingID;
	else std::cout << "Worker has not been activated yet.";
}
unsigned short Employee::getAge() {
	time_t now = time(0);
	tm* localtm = localtime(&now);
	unsigned short temp = Employee::Date_of_birth[Employee::Date_of_birth.length() - 1] - 48;
	for (unsigned short a = 1; a < 4; a++) {
		temp += (Employee::Date_of_birth[Employee::Date_of_birth.length() - 1 - a] - 48) * pow(10, a);
	}
	Employee::Age = 1900 + localtm->tm_year - temp;
	return Employee::Age;
}
unsigned short Employee::getHeight() {
	return Employee::Height;
}
unsigned short Employee::getWeight() {
	return Employee::Weight;
}
bool Employee::getActive_state() {
	return Employee::Active_state;
}
void Employee::setSalary(float salary, Manager& object) {
	if (object.getActive_state() == true) Employee::Salary = salary * (100 + Employee::Productivity_bonus) / 100;
	else std::cout << "Access denied. (Manager's state is deactivated)" << std::endl;
}
void Employee::setProductivity_bonus(float productivity_bonus, Manager& object) {
	if (object.getActive_state() == true) {
		Employee::Productivity_bonus = productivity_bonus;
		Employee::Salary = Employee::Salary * (100 + Employee::Productivity_bonus) / 100;
	}
	else std::cout << "Access denied. (Manager's state is deactivated)" << std::endl;
}
void activateWorkingDocument(Employee& object, float salary, unsigned short height, unsigned short weight) {
	srand(time(0));
	object.Salary = salary;
	object.Height = height;
	object.Weight = weight;
	object.WorkingID = rand() % 10000000;
	object.Active_state = true;
	std::cout << "Profile activated. (" << object.Name << ")" << std::endl;
}