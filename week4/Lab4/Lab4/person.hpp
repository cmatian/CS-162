/******************************************************************
 ** Name: Christopher Matian
 ** OID: 933308644
 **
 ** Header specification and function prototypes for Person
 ** class and functions.
 **
 ** PERSON.CPP
 *****************************************************************/

#ifndef person_hpp
#define person_hpp

#include "validation.hpp"


/******************************************************************
 ** PERSON - BASE CLASS
 *****************************************************************/
class Person {
protected:
    string name;
    int age;
    
public:
    // Constructor
    Person(string, int);
    
    // Destructor
    ~Person();
    
    // Virtual Base Class Functions - Person
    virtual void do_work();
    virtual void showPerson();
    
    // Getters
    string getName();
    int getAge();
};


/******************************************************************
 ** STUDENT - DERIVED CLASS OF PERSON
 *****************************************************************/
class Student : public Person {
    
private:
    float gpa;
    
public:
    // Constructor
    Student(string, int);
    
    // Virtual Derived Class Functions - Student
    virtual void do_work();
    virtual void showPerson();
    
    // Setter
    float setGPA();
    
    // Getter
    float getGPA();
};


/******************************************************************
 ** INSTRUCTOR - DERIVED CLASS OF PERSON
 *****************************************************************/
class Instructor : public Person {
private:
    float rating;
    
public:
    Instructor(string, int);
    
    // Virtual Derived Class Functions - Instructor
    virtual void do_work();
    virtual void showPerson();
    
    // Setter
    float setRating();
    
    
    // Getter
    float getRating();
    
};

#endif
