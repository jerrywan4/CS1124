/*
Akash Ravindran
Rec 9 
*/

#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <iostream>
#include "Position.h"

namespace emp
{
    class Entry
    {
    private:
        std::string name;
        unsigned room;
        unsigned phone;
        Position *pos;

    public:
        Entry(const std::string &nm, unsigned rm, unsigned ph, Position &p);
        friend std::ostream &operator<<(std::ostream &os, const Entry &e);
        std::string get_name() const;
        unsigned get_phone() const;
    };
}

#endif