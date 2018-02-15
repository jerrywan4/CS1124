/*
Jerry Wan
Rec 8
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include <iostream>

namespace Bklyn_Poly
{
    class Course;

    class Student
    {
    private:
        std::string name;
        std::vector<Course*> courses;

    public:
        Student(const std::string &nm);
        std::string get_name() const;
        std::vector<Course*> get_courses();
        bool get_enrolled(Course *c);
        void enroll(Course *c);
        void drop(Course *c);
    };
}

#endif
