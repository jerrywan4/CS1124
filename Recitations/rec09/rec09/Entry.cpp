/*
Akash Ravindran
Rec 9*/

#include "Entry.h"

namespace emp
{
    Entry::Entry(const std::string &nm, unsigned rm, unsigned ph, Position &p)
        : name(nm), room(rm), phone(ph), pos(&p) {}
    std::ostream &operator<<(std::ostream &os, const Entry &e)
    {
        os << e.name << " " << e.room << " " << e.phone;
        return os;
    }
    std::string Entry::get_name() const { return name; }
    unsigned Entry::get_phone() const { return phone; }
}
