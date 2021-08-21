#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

using namespace std;

class person
{
public:
    string name;
    int age;
    int height;
    person(string, int, int);
    person();
};

#endif