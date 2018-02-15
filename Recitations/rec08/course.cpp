/*
Jerry Wan
Rec 8
*/

#include "Student.h"
#include "Course.h"
#include <iostream>

using namespace Bklyn_Poly;
using namespace std;

Course::Course(const string &nm) : name(nm) {}
string Course::get_name() const { return name; }
void Course::enroll(Student *s)
{
    if (s->get_enrolled(this))
        cout << "Student is already enrolled in course\n";
    else
    {
        s->enroll(this);
        students.push_back(s);
    }
}
void Course::kick(Student *s)
{
    bool enrolled = false;
    int loc;
    for (size_t i = 0; i < students.size(); i++)
    {
        if (s->get_name() == students[i]->get_name())
        {
            loc = i;
            enrolled = true;
            break;
        }
    }
    if (enrolled)
    {
        students[loc]->drop(this);
        students[loc] = nullptr;
        students.erase(students.begin() + loc);
    }
}
void Course::cancel()
{
    // assumes this function to be used only by the registrar
    students.clear();
}
//void Course::print_report(ostream &os) const
void Course::print_report() const
{
    cout << "Course name: " << name << "\n";
    cout << "Students in course: \n";
    for (size_t i = 0; i < students.size(); i++)
        cout << "\t" << students[i]->get_name() << "\n";
}
