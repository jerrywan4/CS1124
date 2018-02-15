#ifndef DIRECTORY_H
#define DIRECTORY_H
/* 
Akash Ravindran
Rec 9
*/

#include "Position.h"
#include "Entry.h"

namespace emp
{
    class Directory
    {
    private:
        Entry **entries;
        size_t size;
        size_t capacity;

    public:
        Directory();
        Directory(const Directory &d);
        ~Directory();
        void add(const std::string &nm, unsigned rm, unsigned ph, Position &p);
        friend std::ostream &operator<<(std::ostream &os, const Directory &d);
        Directory &operator=(const Directory &d);
        unsigned operator[](const std::string &nm);
    };
}

#endif