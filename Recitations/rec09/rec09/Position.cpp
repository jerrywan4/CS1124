/*
Akash Ravindran
Rec 9*/

#include "Position.h"

namespace emp
{
    Position::Position(const std::string &t, double s) : title(t), salary(s) {}
    std::string Position::get_title() const { return title; }
    double Position::get_salary() const { return salary; }
    void Position::change_salary(double d) { salary = d; }
}
