#include "oop_02.h"

Student::Student(string name, unsigned int age)
{
    this->name = name;
    this->age = age;
}
Student::~Student()
{
    cout << "End of story" << endl;
}
