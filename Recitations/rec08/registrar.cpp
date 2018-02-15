/*
Jerry Wan
Rec 8
*/

#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <vector>
#include <string>
#include <iostream>

namespace Bklyn_Poly
{
    class Student;
    class Course;

    class Registrar
    {
    private:
        std::vector<Student*> students;
        std::vector<Course*> catalog;

    public:
        void add_course(const std::string &nm);
        void cancel_course(const std::string &nm);
        void add_student(const std::string &nm);
        void enroll_in_course(const std::string &snm, const std::string &cnm);
        //void print_report(std::ostream &os) const;
        void print_report() const;
        void purge();
        friend std::ostream &operator<<(std::ostream &os, const Registrar &r);
    };
}

#endif
