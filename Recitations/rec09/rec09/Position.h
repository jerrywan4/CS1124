/*Jerry Wan
Rec9
*/

#ifndef POSITION_H
#define POSITION_H

#include <string>

namespace emp
{
    class Position
    {
    private:
        std::string title;
        double salary;

    public:
        Position(const std::string &t, double s);
        std::string get_title() const;
        double get_salary() const;
        void change_salary(double d);
    };
}

#endif