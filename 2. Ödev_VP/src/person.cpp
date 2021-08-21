#include "person.hpp"
#include <iostream>

using namespace std;

person::person(string name, int age, int height)
{
	this->name = name;
	this->age = age;
	this->height = height;
}
person::person()
{
	this->name = "";
	this->age = 0;
	this->height = 0;
}
