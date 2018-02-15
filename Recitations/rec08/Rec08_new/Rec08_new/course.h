/*
Jerry Wan
Rec 8
*/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>

namespace Bklyn_Poly
{
    class Student;

    class Course
    {
    private:
        std::string name;
        std::vector<Student*> students;

    public:
        Course(const std::string &nm);
        std::string get_name() const;
        void enroll(Student *s);
        void kick(Student *s);
        void cancel();
        //void print_report(std::ostream &os) const;
        void print_report() const;
    };
}

#endif
