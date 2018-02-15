/*
Akash Ravindran
Rec 9*/

#include "Directory.h"

namespace emp
{
    Directory::Directory() : capacity(2), size(0), entries(new Entry*[2])
    {
        for (size_t i = 0; i < size; i++)
            entries[i] = nullptr;
    }

    Directory::Directory(const Directory &d)
    {
        std::cout << "\n===Copy constructor===\n";
        size = d.size;
        capacity = d.capacity;
        entries = new Entry*[capacity];
        for (size_t i = 0; i < size; i++)
            entries[i] = new Entry(*d.entries[i]);
        std::cout << "\n===End copy constructor===\n";
    }

    Directory::~Directory()
    {
        std::cout << "\n===Destructor===\n";
        for (size_t i = 0; i < size; i++)
        {
            entries[i] = nullptr;
            delete entries[i];
        }
        delete[] entries;
        std::cout << "\n===End destructor===\n";
    }

    void Directory::add(const std::string &nm, unsigned rm, unsigned ph, Position &p)
    {
        if (size == capacity)
        {

            Entry** tmp = new Entry*[capacity *= 2];
            for (size_t i = 0; i < size; i++)
                tmp[i] = entries[i];
            delete[] entries;
            entries = tmp;


        }
        entries[size] = new Entry(nm, rm, ph, p);
        ++size;
    }

    std::ostream &operator<<(std::ostream &os, const Directory &d)
    {
        for (size_t i = 0; i < d.size; i++)
            os << *d.entries[i] << "\n";
        return os;
    }

    Directory& Directory::operator=(const Directory &d)
    {
        std::cout << "\n===Assignment===\n";
        if (this != &d)
        {
            for (size_t i = 0; i < size; i++)
            {
                entries[i] = nullptr;
                delete entries[i];
            }
            delete[] entries;
            size = d.size;
            capacity = d.capacity;
            entries = new Entry*[capacity];
            for (size_t i = 0; i < size; i++)
                entries[i] = new Entry(*d.entries[i]);
        }
        std::cout << "\n===End assignment===\n";
        return *this;
    }

    unsigned Directory::operator[](const std::string &nm)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (entries[i]->get_name() == nm)
                return entries[i]->get_phone();
        }
        return 0;
    }
}
