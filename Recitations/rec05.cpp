/*
rec05.cpp
Programmer:Jerry Wan
This program models the way that lab workers keep up with student grades
*/

#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class TimeSlot{
public:
   TimeSlot(const string& dayParameter, const unsigned& hourParameter) :
      day(dayParameter), hour(hourParameter)
      {}
   void display(ostream& os = cout) const {
      os << day << " ";
      if (hour == 0){
         os << "12AM";
      }
      else if (hour < 12){
         os << hour << "AM";
      }
      else{
         os << (hour - 12) << "PM";
      }
   }
protected:
private:
   const string day;
   const unsigned hour;
};

class Student{
public:
   Student(const string& nameParameter) :
      name(nameParameter), grades(13, -1)
      {}
   void display(ostream& os = cout) const {
      os << "Student: " << name << "; Grades:";
      for (size_t i = 0; i < grades.size(); ++i){
         os << " " << grades[i];
      }
   }
   string getName() const {
      return name;
   }
   void setGrade(const int& weekParameter, const int& gradeParameter){
      grades[weekParameter] = gradeParameter;
   }
protected:
private:
   const string name;
   vector<int> grades;
};

class Section{
public:
   Section(const string& nameParameter, const string& dayParameter, const unsigned& hourParameter) :
      name(nameParameter), slot(dayParameter, hourParameter)
      {}
   void addStudent(const string& nameParameter){
      Student* studentPtr = new Student(nameParameter);
      students.push_back(studentPtr);
   }
   void loadStudentsFromFile(const string& inputParameter){
      ifstream ifs(inputParameter);
      if (!ifs){
         cerr << "Could not open file!";
         exit(1);
      }
      string eachLine;
      while (getline(ifs, eachLine)){
         Student* studentPtr = new Student(eachLine);
         students.push_back(studentPtr);
      }
   }
   void display(ostream& os = cout) const {
      os << "Section: " << name << "; ";
      slot.display(os);
      os << endl;
      for (size_t i = 0; i < students.size(); ++i){
         students[i]->display(os);
         os << endl;
      }
      os << endl;
   }
   void addGrade(const string& nameParameter, const int& gradeParameter, const int& weekParameter) const {
      for (size_t i = 0; i < students.size(); ++i){
         if (students[i]->getName() == nameParameter){
            students[i]->setGrade(weekParameter, gradeParameter);
         }
      }
   }
   void reset(){
      for (size_t i = 0; i < students.size(); ++i){
         delete students[i];
      }
      students.clear();
   }
protected:
private:
   const string name;
   const TimeSlot slot;
   vector<Student*> students;
};

class LabWorker{
public:
   LabWorker(const string& name) : name(name)
   {}
   void addSection(const Section& secParam){
      lab = &secParam;
   }
   void displayGrades(ostream& os = cout) const{
      os << name << " has ";
      lab->display(os);
   }
   void addGrade(const string& nameParameter, const int& gradeParameter, const int& weekParameter){
      lab->addGrade(nameParameter, gradeParameter, weekParameter);
   }
protected:
private:
   const string name;
   const Section* lab;
};

int main() {

   // lab workers
   LabWorker moe("Moe");
   LabWorker jane("Jane");

   // sections and setup and testing
   Section secA2("A2", "Tuesday", 16);
   //secA2.loadStudentsFromFile( "A2.txt" );
   secA2.addStudent("John");
   secA2.addStudent("George");
   secA2.addStudent("Paul");
   secA2.addStudent("Ringo");

   cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
   secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
   moe.addSection(secA2);
   moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked

   Section secB3("B3", "Thursday", 11);
   //secB3.loadStudentsFromFile( "B3.txt" );
   secB3.addStudent("Thorin");
   secB3.addStudent("Dwalin");
   secB3.addStudent("Balin");
   secB3.addStudent("Kili");
   secB3.addStudent("Fili");
   secB3.addStudent("Dori");
   secB3.addStudent("Nori");
   secB3.addStudent("Ori");
   secB3.addStudent("Oin");
   secB3.addStudent("Gloin");
   secB3.addStudent("Bifur");
   secB3.addStudent("Bofur");
   secB3.addStudent("Bombur");

   cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
   secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
   jane.addSection(secB3);
   jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


   // setup is complete, now a real world scenario can be written in the code
   // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

   // week one activities  
   cout << "\nModeling week: 1\n";
   moe.addGrade("John", 7, 1);
   moe.addGrade("Paul", 9, 1);
   moe.addGrade("George", 7, 1);
   moe.addGrade("Ringo", 7, 1);
   cout << "End of week one\n";
   moe.displayGrades();

   // week two activities
   cout << "\nModeling week: 2\n";
   moe.addGrade("John", 5, 2);
   moe.addGrade("Paul", 10, 2);
   moe.addGrade("Ringo", 0, 2);
   cout << "End of week two\n";
   moe.displayGrades();

   //test that reset works  // NOTE: can we check that the heap data was dealt with?
   cout << "\ntesting reset()\n";
   secA2.reset();
   secA2.display();
   moe.displayGrades();



} // main