/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Re-useable functions for the Person class
 **
 ** PERSON.CPP
 *****************************************************************/

#include "person.hpp"


// Person Base Class

Person::Person(string name, int age) {
    this->name = name;
    this->age = age;
}

// Unusued Destructor - not needed
Person::~Person() {
    
}

// Do work Function
void Person::do_work() {
    
}

// Get Person Name
string Person::getName() {
    return name;
}

// Get Person Age
int Person::getAge() {
    return age;
}

// COUT Show Person
void Person::showPerson() {}



// Student Derived Class of Person
Student::Student(string name, int age) : Person(name, age) {
    this->gpa = setGPA();
}

// Student Do Work Function that overrides the person do_work() function
void Student::do_work() {
    int hours;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(1, 8);
    
    hours = dis(gen);
    
    
    cout << name << " did " << hours << " hours of homework." << endl;
}


// Randomly set the student GPA
float Student::setGPA() {
    float min = 0.0;
    float max = 4.0;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(min, max);
    
    float output = roundf((dis(gen)) * 100) / 100;
    return output;
}

// Get the student GPA
float Student::getGPA() {
    return gpa;
}

// Student showPerson() function that overrides the base class function
void Student::showPerson() {
    cout << "Name: " << name << endl;
    cout << setw(5) << ' ' << "Type: Student" << endl;
    cout << setw(5) << ' ' << "Age: " << age << endl;
    cout << setw(5) << ' ' << "GPA: " << gpa << endl;
}

// Instructor
Instructor::Instructor(string name, int age) : Person(name, age) {
    this->rating = setRating();
}

float Instructor::setRating() {
    float min = 0.0;
    float max = 5.0;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(min, max);
    
    float output = roundf((dis(gen)) * 10) / 10;
    return output;
}

void Instructor::do_work() {
    int hours;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(1, 8);
    
    hours = dis(gen);
    
    cout << name << " graded papers for " << hours << " hours." << endl;
}

void Instructor::showPerson() {
    cout << "Name: " << name << endl;
    cout << setw(5) << ' ' << "Type: Instructor" << endl;
    cout << setw(5) << ' ' << "Age: " << age << endl;
    cout << setw(5) << ' ' << "Rating: " << rating << endl;
}

float Instructor::getRating() {
    return rating;
}






