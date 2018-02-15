/*
Jerry Wan
Rec 8
*/

#include "Student.h"
#include "Course.h"

using namespace Bklyn_Poly;
using namespace std;

Student::Student(const string &nm) : name(nm) {}
string Student::get_name() const { return name; }
vector<Course*> Student::get_courses() { return courses; }
bool Student::get_enrolled(Course *c)
{
    bool enrolled = false;
    for (size_t i = 0; i < courses.size(); i++)
    {
        if (c->get_name() == courses[i]->get_name())
        {
            enrolled = true;
            break;
        }
    }
    return enrolled;
}
void Student::enroll(Course *c)
{
    // assumes this function to be used by the course
    bool enrolled = false;
    for (size_t i = 0; i < courses.size(); i++)
    {
        if (c->get_name() == courses[i]->get_name())
        {
            enrolled = true;
            break;
        }
    }
    if (enrolled)
        cout << "Student is already in course\n";
    else
        courses.push_back(c);
}
void Student::drop(Course *c)
{
    // Assumes this function to be used by the course
    bool enrolled = false;
    int loc;
    for (size_t i = 0; i < courses.size(); i++)
    {
        if (c->get_name() == courses[i]->get_name())
        {
            enrolled = true;
            loc = i;
            break;
        }
    }
    if (enrolled)
    {
        //courses[loc]->kick(this);
        courses[loc] = nullptr;
        courses.erase(courses.begin() + loc);
    }
}
