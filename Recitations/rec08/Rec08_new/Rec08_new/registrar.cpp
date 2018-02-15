/*
Jerry Wan
Rec 8
*/


#include "Registrar.h"


using namespace std;

namespace Bklyn_Poly {
    
    void Registrar::add_student(<#const std::string &nm#>)(const string& name){
        students.push_back(new Student(name));
    }
    
    Student* Registrar::findStudent(const string& student){
        for (Student* sptr : students){
            if (student == sptr->getName()){
                return sptr;
                break;
            }
        }
        return nullptr;
    }
    
    void Registrar::add_course(const string& name){
        catalog.push_back(new Course(name));
    }
    
    void Registrar::cancel_course(const string& name){
        for (size_t i = 0; i < catalog.size(); i++){
            if (name == catalog[i]->getName()) {
                while (i+1 < catalog.size()) {
                    catalog[i] = catalog[i+1];
                    i++;
                }
                catalog.pop_back();
            }
        }
    }
    
    Course* Registrar::findCourse(const string& course){
        for (Course* cptr : catalog){
            if (course == cptr->getName()){
                return cptr;
                break;
            }
        }
        return nullptr;
    }
    
    void Registrar::enroll_in_course(const string& student, const string& course){
        Course* aCourse = findCourse(course);
        Student* aStudent = findStudent(student);
        aCourse->enrollInThisCourse(aStudent);
    }
    
    void Registrar::printReport() const{
        for (Course* cptr : catalog){
            cptr->displayCourse();
        }
    }
    
    void Registrar::purge() {
        for (Course* cptr : catalog){
            delete cptr;
        }
        catalog.clear();
        for (Student* sptr : students){
            delete sptr;
        }
        students.clear();
    }
    
    ostream& operator<< (ostream& outs, const Registrar& r){
        r.printReport(); 
        return outs;
    }
    
}